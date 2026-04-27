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
	Fixed&			operator=(const Fixed& other);
	int				getRawBits( void ) const;
	void			setRawBits( int const raw );
	float 			toFloat( void ) const;
	int				toInt( void ) const;
	
	
};
std::ostream&		operator<<(std::ostream& os, const Fixed& toPrint);
