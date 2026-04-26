#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{	
	std::cout << "Default constructor called" << std::endl;
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
