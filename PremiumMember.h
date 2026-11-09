#pragma once
#include "Member.h"

// Premium plan: higher fee, 10% discount for 6+ months, and a personal trainer.
class PremiumMember : public Member {
private:
    static constexpr double MONTHLY_FEE = 2000;

public:
    PremiumMember(const std::string& name, const std::string& phone, int months)
        : Member(name, phone, months) {}

    double calculateFee(int months) const override {
        double total = MONTHLY_FEE * months;
        return months >= 6 ? total * 0.90 : total;
    }

    bool canHaveTrainer() const override { return true; }   // overrides default (false)

    std::string getPlanName() const override { return "Premium"; }

    std::string getBenefits() const override {
        return "24x7 access, personal trainer, steam & sauna, diet plan";
    }
};
