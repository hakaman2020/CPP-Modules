#include <iostream>
#include "Fixed.hpp"

int	main(void){

Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;

std::cout << b << std::endl;

std::cout << Fixed::max( a, b ) << std::endl;

//test the different functions
//comparisons
// Fixed c = 10.5f;
// Fixed d = -10.5f;

// std::cout << "c is " << c << std::endl;
// std::cout << "d is " << d << std::endl;
// std::cout << "Comparison" << std::endl;
// std::cout << "> " << (c > d) << std::endl;
// std::cout << "< " << (c < d) << std::endl;
// std::cout << ">= " << (c >= d) << std::endl;
// std::cout << "<= " << (c <= d) << std::endl;
// std::cout << "== " <<  (c == d) << std::endl;
// std::cout << "!= " <<  (c != d) << std::endl;

// //arithmetic operators
// std::cout <<"\nAritmetic" << std::endl;
// std::cout << "+ " <<(c + d) << std::endl;
// std::cout << "- " << (c - d) << std::endl;
// std::cout << "* " << (c * d) << std::endl;
// std::cout << "/ " << (c / d) << std::endl;

// //increment / decrement
// std::cout << "\nIncrement/decrement" << std::endl;
// std::cout << "++c " << ++c << std::endl;
// std::cout << "c++ " << c++ << " " << c << std::endl;
// std::cout << "--c " << --c << std::endl;
// std::cout << "c-- " << c-- << " " << c << std::endl;

// //min max
// std::cout << "\nMin Max" << std::endl;
// std::cout << "Min " << Fixed::min(c, d) << std::endl;
// std::cout << "Max " << Fixed::max(c, d) << std::endl;

// Fixed const e = c;
// Fixed const f = d;
// std::cout << "Min Max const" << std::endl;
// std::cout << "Min " << Fixed::min(e, f) << std::endl;
// std::cout << "Max " << Fixed::max(e, f) << std::endl;

return (0);
}