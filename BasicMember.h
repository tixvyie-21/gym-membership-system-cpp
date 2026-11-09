#pragma once
#include "Member.h"

// INHERITANCE: BasicMember "is a" Member.
// POLYMORPHISM: provides its own version of calculateFee(), getPlanName(), getBenefits().
class BasicMember : public Member {
private:
    static constexpr double MONTHLY_FEE = 1000;

public:
    BasicMember(const std::string& name, const std::string& phone, int months)
        : Member(name, phone, months) {}

    double calculateFee(int months) const override {
        return MONTHLY_FEE * months;            // no discount
    }

    std::string getPlanName() const override { return "Basic"; }

    std::string getBenefits() const override {
        return "Gym floor access (6 AM - 10 PM)";
    }
};
