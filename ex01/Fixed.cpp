#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) // A constructor
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) // A constructor that takes a constant floating-point number
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) // It converts float to the fixed-point value. A constructor that takes a constant floating-point number as a parameter
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) // ◦ Acopy constructor.
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) //  Acopy assignment operator overload.上書きするかんじ
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed() // A destructor
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const // A member function float toFloat( void ) const;
{
    return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const // A member function int toInt( void ) const
{
    return this->_fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) // Output stream operator overload.
{
    // out << fixed.toFloat() = std::cout << 42.421875f...てことです。a.toInt()ではこの関数は呼ばれない。
    out << fixed.toFloat();
    // mainの、std::cout << "a is " << a << std::endl;このコードで、a = Fixed( 1234.4321f )のfixedクラスオブジェクトであり、FixedPoint(int)として値を保持しているため、再度floatに戻してる
    return out;
}
