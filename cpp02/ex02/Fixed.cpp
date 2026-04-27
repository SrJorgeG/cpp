#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{	
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _rawBits(value << _decimals)
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
	return (_rawBits >> _decimals);
}

std::ostream& operator<<(std::ostream& os, const Fixed& toPrint)
{
	os << toPrint.toFloat();
	return os;
}

bool				Fixed::operator>(const Fixed& other) const
{
	return (_rawBits > other._rawBits);
}

bool				Fixed::operator<(const Fixed& other) const
{
	return (_rawBits < other._rawBits);
}

bool				Fixed::operator>=(const Fixed& other) const
{
	return (_rawBits >= other._rawBits);
}

bool				Fixed::operator<=(const Fixed& other) const
{
	return (_rawBits <= other._rawBits);
}

bool				Fixed::operator==(const Fixed& other) const
{
	return (_rawBits == other._rawBits);
}

bool				Fixed::operator!=(const Fixed& other) const
{
	return (_rawBits != other._rawBits);
}

Fixed				Fixed::operator+(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits(this->_rawBits + other._rawBits);
	return result;
}

Fixed				Fixed::operator-(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits(this->_rawBits - other._rawBits);
	return result;
}

Fixed				Fixed::operator*(const Fixed& other) const
{
	Fixed	result;
	long long aux;
	aux = (long long)this->getRawBits() * (long long)other.getRawBits();
	result.setRawBits(aux >> _decimals);
	return result;
}

Fixed				Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	long long aux;
	if (!other.getRawBits())
		return Fixed();
	aux = ((long long)this->getRawBits() << _decimals) / (long long)other.getRawBits();
	result.setRawBits(aux);
	return result;
}

Fixed&				Fixed::operator++()
{
	_rawBits++;
	return	*this;
}

Fixed				Fixed::operator++(int)
{
	Fixed	temp(*this);
	_rawBits++;
	return	temp;
}

Fixed&				Fixed::operator--()
{
	_rawBits--;
	return	*this;
}

Fixed				Fixed::operator--(int)
{
	Fixed	temp(*this);
	_rawBits--;
	return	temp;
}

Fixed&				Fixed::min(Fixed& a, Fixed& b)
{
	return ((a < b) ? a : b); 	
}

const Fixed&		Fixed::min(const Fixed& a, const Fixed& b)
{
	return ((a < b) ? a : b); 	
}

Fixed&				Fixed::max(Fixed& a, Fixed& b)
{
	return ((a > b) ? a : b); 	
}

const Fixed&		Fixed::max(const Fixed& a, const Fixed& b)
{
	return ((a > b) ? a : b); 	
}
