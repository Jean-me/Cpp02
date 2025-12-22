#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    Fixed();                              // A default constructor that initializes the fixed-point number value to 0.
    Fixed(const Fixed &other);            // A copy constructor.
    Fixed &operator=(const Fixed &other); // A copy assignment operator overload.

    ~Fixed(); // A destructor.

    int getRawBits(void) const;     // returns the raw value of the fixed-point value.
    void setRawBits(int const raw); // sets the raw value of the fixed-point number.
};

#endif
