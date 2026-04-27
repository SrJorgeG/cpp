#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{	
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _rawBits(value * 256)
{	
	std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _rawBits(roundf(value * 256))
{	
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _rawBits(other.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		setRawBits(other.getRawBits());
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return	_rawBits;
}

void	Fixed::setRawBits( int const raw )
{
	_rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (_rawBits / 256.0f);
}

int Fixed::toInt(void) const
{
	return (_rawBits >> 8);
}

std::ostream& operator<<(std::ostream& os, const Fixed& toPrint)
{
	os << toPrint.toFloat();
	return os;
}
