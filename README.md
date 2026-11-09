# Gym Membership Management System (C++, OOP)

A console application that manages gym members, plans, trainers, renewals and
check-ins. Built to demonstrate core Object-Oriented Programming concepts in C++.

## How to build and run

```bash
g++ -std=c++17 -Wall -Wextra -o gym *.cpp
./gym            # on Windows: gym.exe
```

Requires a C++17 compiler (g++, clang++ or MSVC). Or use the included `Makefile`:

```bash
make
./gym
```

## Features
- Add members on Basic, Premium or Student plans (fee calculated per plan)
- List / search / remove members
- Renew memberships (extends from the old expiry date if still active)
- Check-in tracking (blocked for expired members)
- Assign personal trainers (Premium only, max 5 clients each)
- View expired memberships and total revenue

## OOP concepts and where to find them

| Concept | Where |
|---|---|
| **Abstraction** | `Member` is an abstract class: pure virtual `getPlanName()`, `getBenefits()` |
| **Interface** | `Payable` (only pure virtual functions), inherited by `Member` |
| **Inheritance** | `BasicMember`, `PremiumMember`, `StudentMember` inherit from `Member` |
| **Polymorphism (overriding)** | Each plan overrides `calculateFee()`, `getBenefits()`; `PremiumMember` overrides `canHaveTrainer()` |
| **Polymorphism (base pointer)** | `std::unique_ptr<Member> m = std::make_unique<PremiumMember>(...)` in `main.cpp`; `Gym` only uses `Member` |
| **Virtual destructor** | `virtual ~Payable()` and `virtual ~Member()` so derived objects are destroyed correctly |
| **Encapsulation** | Private data, getters, validated setters (`setName`, `setPhone`) |
| **Association / composition** | `Gym` owns Members and Trainers; `Trainer` keeps pointers to its client Members |
| **Static members** | `nextId` counters in `Member` and `Trainer` generate unique IDs |
| **const correctness** | `const int id`, `const` member functions, `override` keyword |
| **Custom exceptions** | `GymException`, `MembershipExpiredException`, `MemberNotFoundException` |
| **Exception handling** | `try` / `catch` in `main()` |
| **RAII / smart pointers** | `std::unique_ptr` in `Gym`: no manual `new` / `delete` |
| **STL containers** | `std::vector<std::unique_ptr<Member>>`, `std::vector<std::unique_ptr<Trainer>>` |
| **Forward declaration** | `class Trainer;` in `Member.h` breaks the Member <-> Trainer include cycle |

## Fee rules
| Plan | Monthly | Discount |
|---|---|---|
| Basic | Rs. 1000 | none |
| Premium | Rs. 2000 | 10% off for 6+ months |
| Student | Rs. 700 | 5% off for 3+ months |

## File overview
| File | Purpose |
|---|---|
| `Payable.h` | Interface |
| `Exceptions.h` | Custom exception classes |
| `Member.h / Member.cpp` | Abstract base class |
| `BasicMember.h`, `PremiumMember.h`, `StudentMember.h` | Concrete plans |
| `Trainer.h / Trainer.cpp` | Trainer class |
| `Gym.h / Gym.cpp` | Manager class (business logic) |
| `main.cpp` | Console menu |

## Ideas to extend (good for your GitHub)
1. Save/load data to a file (text/CSV or binary serialization) so data persists
2. Add a `Payment` class with receipts and payment history
3. Use `operator<<` overloading instead of `toString()`
4. Add unit tests with Catch2 or GoogleTest for `calculateFee()` and `renew()`
5. Use SQLite for storage
6. Build a GUI with Qt

## Class diagram (simplified)

```
        <<interface>> Payable
                ^
                |
        <<abstract>> Member  ---- has-a ---->  Trainer*
         ^       ^       ^
         |       |       |
  BasicMember PremiumMember StudentMember

  Gym ---- owns ----> vector<unique_ptr<Member>>, vector<unique_ptr<Trainer>>
  main ---- uses ----> Gym
```
