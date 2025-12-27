#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) // コンストラクタ
{
}

Fixed::Fixed(const int intValue)
{
    this->_fixedPointValue = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    this->_fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) // Fixed a(42.5f);からの➺ Fixed b(a); とか
{
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) // Fixed.hppで宣言があるので↑でも機能する
{
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed() // デストラクタ
{
}

int Fixed::getRawBits(void) const
{
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const // Fixed～をFloatに戻す//Fixed~はIntなので、floatに型変換してから計算しないとint ÷ int = int（整数除算）になる
{
    return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const // FixedをIntに戻す
{
    return this->_fixedPointValue >> _fractionalBits;
}

// Comparison operators　比較オペレーター・true or false
bool Fixed::operator>(const Fixed &other) const // a > b
{
    return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const // a < b
{
    return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const // a >= b
{
    return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const // a <= b
{
    return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const // a == b
{
    return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const // a != b
{
    return this->_fixedPointValue != other._fixedPointValue;
}

// Arithmetic operators 算術オペレーター
Fixed Fixed::operator+(const Fixed &other) const // a + b
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const // a - b
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const // a * b
{
    Fixed result;
    long long temp = static_cast<long long>(this->_fixedPointValue) *
                     static_cast<long long>(other._fixedPointValue); // long longで安全に保存）
    result.setRawBits(static_cast<int>(temp >> _fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const // a / b
{
    Fixed result;
    long long temp = (static_cast<long long>(this->_fixedPointValue) << _fractionalBits) /
                     static_cast<long long>(other._fixedPointValue);
    result.setRawBits(static_cast<int>(temp));
    return result;
}

// Increment/Decrement operators
Fixed &Fixed::operator++()
{
    this->_fixedPointValue++; // 前置インクリメン (++a)、固定小数点数の内部値を1増やす。実際の値は 1/256 (≈0.00390625) 増える
    return *this;             // 前置: Fixed& （参照を返す = 効率的）
}

Fixed Fixed::operator++(int) // 後置～ の古い値を返してから増やす、intは前置と後置を区別するダミー
{
    Fixed temp(*this);        // 現在の値をコピーして保存
    this->_fixedPointValue++; // 自分自身を増やす
    return temp;              // 古い値を返す(後置: Fixed （コピーを返す
}

Fixed &Fixed::operator--()
{
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_fixedPointValue--;
    return temp;
}

// Static member functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b; // a < b なら a を返し、そうでなければ b を返す
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
