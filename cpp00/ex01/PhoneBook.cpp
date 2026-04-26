#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0), _index(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact()
{
    std::string input;
    Contact newContact;
    
    do
    {
        std::cout << "First name: " << ": ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "Getline Error, Exiting" << std::endl;
            return ;
        }
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    } while (input.empty());
    newContact.setFirstName(input);

    do
    {
        std::cout << "Last name: " << ": ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "Getline Error, Exiting" << std::endl;
            return ;
        }
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    } while (input.empty());
    newContact.setLastName(input);
    do
    {
        std::cout << "Nickname: " << ": ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "Getline Error, Exiting" << std::endl;
            return ;
        }
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    } while (input.empty());
    newContact.setNickname(input);
    do
    {
        std::cout << "PhoneNumber: " << ": ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "Getline Error, Exiting" << std::endl;
            return ;
        }
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    } while (input.empty());
    newContact.setPhoneNumber(input);
    do
    {
        std::cout << "DarkestSecret: " << ": ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "Getline Error, Exiting" << std::endl;
            return ;
        }
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    } while (input.empty());
    newContact.setDarkestSecret(input);
    
    _contacts[_index] = newContact;
    _index = (_index + 1) % 8;
    if (_count < 8)
        _count++;
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContacts() const
{
    std::string input;
    int index;
    
    if (!_count)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < _count; ++i)
        _contacts[i].displaySummary(i);
    do
    {
        std::cout << "Enter index to display: ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "Getline Error, Exiting" << std::endl;
            break;
        }
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
        index = 0;
        std::stringstream ss(input);
        if (!(ss >> index) || index <= 0 || index > _count)
        {
            std::cout << "Invalid index" << std::endl;
            continue;
        }
        displayContact(index);
    } while (input.empty() || index <= 0 || index > _count);
}

void PhoneBook::displayContact(int index) const
{
    if (--index < 0 || index >= _count)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    _contacts[index].displayFull();
}
