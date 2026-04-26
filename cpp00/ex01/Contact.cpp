#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setFirstName(const std::string& firstName)
{
    _firstName = firstName;
}

void Contact::setLastName(const std::string& lastName)
{
    _lastName = lastName;
}

void Contact::setNickname(const std::string& nickname)
{
    _nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
    _phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret)
{
    _darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
    return _firstName;
}

std::string Contact::getLastName() const
{
    return _lastName;
}

std::string Contact::getNickname() const
{
    return _nickname;
}

std::string Contact::getPhoneNumber() const
{
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return _darkestSecret;
}

bool Contact::isEmpty() const
{
    return _firstName.empty() && _lastName.empty() && _nickname.empty()
        && _phoneNumber.empty() && _darkestSecret.empty();
}

void Contact::displaySummary(int index) const
{
    std::cout << std::setw(10) << ++index << "|";
    std::cout << std::setw(10) << std::right;
    if (_firstName.length() > 10)
        std::cout << _firstName.substr(0, 9) << ".";
    else
        std::cout << _firstName;
    std::cout << "|";
    if (_lastName.length() > 10)
        std::cout << _lastName.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << std::right << _lastName;
    std::cout << "|";
    if (_nickname.length() > 10)
        std::cout << _nickname.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << std::right << _nickname;
    std::cout << std::endl;
}

void Contact::displayFull() const
{
    std::cout << "First name: " << _firstName << std::endl;
    std::cout << "Last name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone number: " << _phoneNumber << std::endl;
    std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}
