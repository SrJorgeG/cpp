#pragma once

#include <iostream>
#include <cmath>
#include <string>

class Fixed
{
private:
	int _rawBits;
	static const int _decimals = 8;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	~Fixed();
	Fixed&				operator=(const Fixed& other);

	bool				operator>(const Fixed& other) const;
	bool				operator<(const Fixed& other) const;
	bool				operator>=(const Fixed& other) const;
	bool				operator<=(const Fixed& other) const;
	bool				operator==(const Fixed& other) const;
	bool				operator!=(const Fixed& other) const;
	Fixed				operator+(const Fixed& other) const;
	Fixed				operator-(const Fixed& other) const;
	Fixed				operator*(const Fixed& other) const;
	Fixed				operator/(const Fixed& other) const;
	Fixed&				operator++();
	Fixed				operator++(int);
	Fixed&				operator--();
	Fixed				operator--(int);
	static Fixed&		min(Fixed& a, Fixed& b);			
	static const Fixed&	min(const Fixed& a, const Fixed& b);			
	static Fixed&		max(Fixed& a, Fixed& b);			
	static const Fixed&	max(const Fixed& a, const Fixed& b);			
	int					getRawBits() const;
	void				setRawBits(int const raw);
	float 				toFloat() const;
	int					toInt() const;
	
	
};
std::ostream&		operator<<(std::ostream& os, const Fixed& toPrint);
