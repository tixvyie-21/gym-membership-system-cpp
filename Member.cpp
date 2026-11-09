#include "Member.h"
#include "Trainer.h"
#include "Exceptions.h"

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <stdexcept>

int Member::nextId = 1001;

Member::Member(const std::string& name, const std::string& phone, int months)
    : id(nextId++), trainer(nullptr), visits(0) {
    setName(name);
    setPhone(phone);
    joinDate = std::time(nullptr);
    expiryDate = addMonths(joinDate, months);
}

std::time_t Member::addMonths(std::time_t base, int months) {
    std::tm t = *std::localtime(&base);
    t.tm_mon += months;
    t.tm_isdst = -1;                 // let the system decide about daylight saving
    return std::mktime(&t);          // mktime normalises month overflow
}

std::string Member::formatDate(std::time_t t) {
    char buf[16];
    std::tm* tmv = std::localtime(&t);
    std::strftime(buf, sizeof(buf), "%Y-%m-%d", tmv);
    return buf;
}

bool Member::isActive() const {
    return std::time(nullptr) <= expiryDate;
}

long Member::daysLeft() const {
    double secs = std::difftime(expiryDate, std::time(nullptr));
    return secs <= 0 ? 0 : static_cast<long>(secs / 86400);
}

void Member::renew(int months) {
    // If still active, extend from the old expiry date; otherwise start today.
    std::time_t base = isActive() ? expiryDate : std::time(nullptr);
    expiryDate = addMonths(base, months);
}

void Member::checkIn() {
    if (!isActive()) {
        throw MembershipExpiredException(
            name + "'s membership expired on " + formatDate(expiryDate) + ". Please renew.");
    }
    ++visits;
}

void Member::setName(const std::string& newName) {
    // trim spaces on both sides
    auto notSpace = [](unsigned char c) { return !std::isspace(c); };
    auto first = std::find_if(newName.begin(), newName.end(), notSpace);
    auto last = std::find_if(newName.rbegin(), newName.rend(), notSpace).base();
    if (first >= last) {
        throw std::invalid_argument("Name cannot be empty.");
    }
    name.assign(first, last);
}

void Member::setPhone(const std::string& newPhone) {
    bool ok = newPhone.size() == 10 &&
              std::all_of(newPhone.begin(), newPhone.end(),
                          [](unsigned char c) { return std::isdigit(c); });
    if (!ok) {
        throw std::invalid_argument("Phone must be exactly 10 digits.");
    }
    phone = newPhone;
}

std::string Member::toString() const {
    std::ostringstream os;
    os << "[" << id << "] " << std::left << std::setw(15) << name
       << " | " << std::setw(8) << getPlanName()      // virtual call -> polymorphism
       << " | Phone: " << phone
       << " | Expires: " << formatDate(expiryDate)
       << " (" << (isActive() ? "ACTIVE, " + std::to_string(daysLeft()) + " days left"
                              : std::string("EXPIRED")) << ")"
       << " | Visits: " << visits
       << " | Trainer: " << (trainer ? trainer->getName() : std::string("None"));
    return os.str();
}
