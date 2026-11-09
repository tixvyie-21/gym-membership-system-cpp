#pragma once
#include <ctime>
#include <string>
#include "Payable.h"

class Trainer;   // forward declaration (Trainer.h also refers to Member)

/*
 * ABSTRACT CLASS: a general "member" that cannot be instantiated directly.
 * Concrete plans (Basic, Premium, Student) inherit from it.
 *
 * OOP concepts used:
 *  - Abstraction    : pure virtual functions getPlanName(), getBenefits(), calculateFee()
 *  - Encapsulation  : private data + public getters / validated setters
 *  - Interface      : inherits Payable
 *  - Inheritance    : subclasses reuse everything defined here
 */
class Member : public Payable {
private:
    static int nextId;              // static: shared by all members

    const int id;                   // const: never changes after construction
    std::string name;
    std::string phone;
    std::time_t joinDate;
    std::time_t expiryDate;
    Trainer* trainer;               // association (not owned)
    int visits;

    static std::time_t addMonths(std::time_t base, int months);

protected:
    // protected constructor: only subclasses can call it
    Member(const std::string& name, const std::string& phone, int months);

public:
    virtual ~Member() = default;    // virtual destructor: needed for polymorphic delete

    // a Member owns a unique ID, so copying makes no sense
    Member(const Member&) = delete;
    Member& operator=(const Member&) = delete;

    // ---------- Pure virtual: every plan must define these ----------
    virtual std::string getPlanName() const = 0;
    virtual std::string getBenefits() const = 0;

    // Polymorphism hook with a default; Premium overrides it.
    virtual bool canHaveTrainer() const { return false; }

    // ---------- Business logic ----------
    bool isActive() const;
    long daysLeft() const;
    void renew(int months);
    void checkIn();                 // throws MembershipExpiredException

    // ---------- Getters / validated setters (encapsulation) ----------
    int getId() const { return id; }
    const std::string& getName() const { return name; }
    const std::string& getPhone() const { return phone; }
    std::time_t getJoinDate() const { return joinDate; }
    std::time_t getExpiryDate() const { return expiryDate; }
    Trainer* getTrainer() const { return trainer; }
    int getVisits() const { return visits; }

    void setName(const std::string& newName);      // throws std::invalid_argument
    void setPhone(const std::string& newPhone);    // throws std::invalid_argument
    void setTrainer(Trainer* t) { trainer = t; }

    std::string toString() const;
    static std::string formatDate(std::time_t t);
};
