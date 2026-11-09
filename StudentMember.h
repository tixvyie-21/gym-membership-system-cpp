#pragma once
#include "Member.h"

// Student plan: cheaper monthly fee, extra 5% off for 3+ months.
class StudentMember : public Member {
private:
    static constexpr double MONTHLY_FEE = 700;
    std::string college;

public:
    StudentMember(const std::string& name, const std::string& phone, int months,
                  const std::string& college)
        : Member(name, phone, months), college(college) {}

    const std::string& getCollege() const { return college; }

    double calculateFee(int months) const override {
        double total = MONTHLY_FEE * months;
        return months >= 3 ? total * 0.95 : total;
    }

    std::string getPlanName() const override { return "Student"; }

    std::string getBenefits() const override {
        return "Gym floor access (6 AM - 6 PM), valid college ID required (" + college + ")";
    }
};
