#include "Trainer.h"

#include <algorithm>
#include <iomanip>
#include <sstream>
#include <stdexcept>

int Trainer::nextId = 1;

Trainer::Trainer(const std::string& name, const std::string& specialization)
    : id(nextId++), name(name), specialization(specialization) {}

void Trainer::addClient(Member* m) {
    if (isFull()) {
        throw std::logic_error(name + " already has " + std::to_string(MAX_CLIENTS) + " clients.");
    }
    clients.push_back(m);
}

void Trainer::removeClient(Member* m) {
    clients.erase(std::remove(clients.begin(), clients.end(), m), clients.end());
}

std::string Trainer::toString() const {
    std::ostringstream os;
    os << "[T" << id << "] " << std::left << std::setw(12) << name
       << " | " << std::setw(18) << specialization
       << " | Clients: " << clients.size() << "/" << MAX_CLIENTS;
    return os.str();
}
