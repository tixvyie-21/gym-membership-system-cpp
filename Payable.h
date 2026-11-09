#pragma once

// INTERFACE (in C++: an abstract class with only pure virtual functions).
// Any class that inherits Payable must say how it calculates a fee
// for a given number of months.
class Payable {
public:
    virtual ~Payable() = default;
    virtual double calculateFee(int months) const = 0;
};
