#include "Fixed.hpp"

Fixed::Fixed(void): _value(0){
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const & src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::Fixed(int const n){
	std::cout << "Int constructor called" << std::endl;
	this->_value = n << _fractionalBits; 
	return;
}

//To convert to fixed point from a floating point
//* multiply the floating point number with 2^n (where n is the number of fractional bits)
//* round it to the nearest integer.

Fixed::Fixed(float const fn){
	std::cout << "Float constructor called" << std::endl;
	int result = roundf(fn * (float)(1 << this->_fractionalBits));
	this->_value = result;
 	return;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed& Fixed::operator=(Fixed const & rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
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