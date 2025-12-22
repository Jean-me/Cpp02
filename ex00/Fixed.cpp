#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) // Fixed b(a); または Fixed b = a;（新しいオブジェクトの生成時）
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)                              // a = a;などの自己代入チェック
        this->_fixedPointValue = other.getRawBits(); // Ex: bのValueにaのValueを代入
    return *this;                                    // 連鎖代入を可能にする (a = b = c)
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}
