#pragma once
#include <memory>
#include <string>
#include <vector>

#include "Exceptions.h"
#include "Member.h"
#include "Trainer.h"

/*
 * The "manager" class. It owns the members and trainers and exposes the
 * operations the menu calls. It stores members as unique_ptr<Member>, i.e.
 * through the abstract base type, so it never needs to know which plan a
 * member has (POLYMORPHISM through a common parent type).
 * unique_ptr also gives automatic memory cleanup (RAII): no manual delete.
 */
class Gym {
private:
    std::string name;
    std::vector<std::unique_ptr<Member>> members;
    std::vector<std::unique_ptr<Trainer>> trainers;
    double totalRevenue = 0;

public:
    explicit Gym(const std::string& name) : name(name) {}

    const std::string& getName() const { return name; }
    double getTotalRevenue() const { return totalRevenue; }

    // ---------- Members ----------
    Member& addMember(std::unique_ptr<Member> m, int months);
    Member& findMember(int id) const;                 // throws MemberNotFoundException
    void removeMember(int id);                        // throws MemberNotFoundException
    double renewMember(int id, int months);           // returns the fee collected
    void checkIn(int id);                             // may throw either exception

    const std::vector<std::unique_ptr<Member>>& getMembers() const { return members; }
    std::vector<const Member*> getExpiredMembers() const;

    // ---------- Trainers ----------
    void addTrainer(std::unique_ptr<Trainer> t);
    const std::vector<std::unique_ptr<Trainer>>& getTrainers() const { return trainers; }
    Trainer& findTrainer(int id) const;               // throws MemberNotFoundException
    void assignTrainer(int memberId, int trainerId);
};
