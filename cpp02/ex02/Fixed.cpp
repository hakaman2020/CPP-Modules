#include "Fixed.hpp"

Fixed::Fixed(void): _value(0){
	return;
}

Fixed::Fixed(Fixed const & src){
	*this = src;
	return;
}

Fixed::Fixed(int const n){
	this->_value = n << _fractionalBits; 
	return;
}

//To convert to fixed point from a floating point
//* multiply the floating point number with 2^n (where n is the number of fractional bits)
//* round it to the nearest integer.

Fixed::Fixed(float const fn){
	int result = roundf(fn * (float)(1 << this->_fractionalBits));
	this->_value = result;
 	return;
}

Fixed::~Fixed(void){
	return;
}

Fixed&	Fixed::operator=(Fixed const & rhs){
	this->_value = rhs.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const & rhs) const{
	if (this->_value > rhs._value){
		return (true);
	}
	return (false);
}

bool	Fixed::operator<(Fixed const & rhs) const{
	if (this->_value < rhs._value){
		return (true);
	}
	return (false);
}

bool	Fixed::operator>=(Fixed const & rhs) const{
	if (this->_value >= rhs._value){
		return (true);
	}
	return (false);
}

bool	Fixed::operator<=(Fixed const & rhs) const{
	if (this->_value <= rhs._value){
		return (true);
	}
	return (false);
}

bool	Fixed::operator==(Fixed const & rhs) const{
	if (this->_value == rhs._value){
		return (true);
	}
	return (false);
}

bool	Fixed::operator!=(Fixed const & rhs) const{
	if (this->_value != rhs._value){
		return (true);
	}
	return (false);
}

Fixed Fixed::operator+(Fixed const & rhs){
	Fixed result = this->toFloat() + rhs.toFloat();
	return (result);
}

Fixed Fixed::operator-(Fixed const & rhs){
	Fixed result = this->toFloat() - rhs.toFloat();
	return (result);
}

Fixed Fixed::operator*(Fixed const & rhs){
	Fixed result = this->toFloat() * rhs.toFloat();
	return (result);
}

Fixed Fixed::operator/(Fixed const & rhs){
	Fixed result = this->toFloat() / rhs.toFloat();
	return (result);
}

//prefix increment
Fixed& Fixed::operator++(){
	this->_value++;
	return *this;
}

//postfix increment
//in postfix increment the value being evaluated before increment
//so return a copy of the original before increment it.
Fixed	Fixed::operator++(int){
	Fixed temp = *this;
	this->_value++;
	return temp;
}

//prefix decrement
Fixed& Fixed::operator--(){
	this->_value--;
	return *this;
}

//postfix increment
//in postfix increment the value being evaluated before increment
//so return a copy of the original before increment it.
Fixed	Fixed::operator--(int){
	Fixed temp = *this;
	this->_value--;
	return temp;
}

//static functions to return min and max
Fixed& Fixed::min(Fixed & a, Fixed & b){
	if (a < b)
		return a;
	return b;
}

const Fixed & Fixed::min(Fixed const & a, Fixed const & b){
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed & a, Fixed & b){
	if (a > b)
		return a;
	return b;
}

const Fixed & Fixed::max(Fixed const & a, Fixed const & b){
	if (a > b)
		return a;
	return b;
}

//return the raw integer value of the fixed point value, thus the full integer
//binary that is stored in _value.
int Fixed::getRawBits(void) const{
	return this->_value;
}

void Fixed::setRawBits(int const raw){
	this->_value = raw;
}

//by dividing the _value by 2^n (where n is fractional bits) you will get the 
//floating point value
float	Fixed::toFloat(void) const{
	float result = (float) this->_value / (float)(1 << this->_fractionalBits);
	return result;
}

int	Fixed::toInt(void) const{
	return (this->_value >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& o, Fixed const & rhs){
	o << rhs.toFloat();
	return o;
}