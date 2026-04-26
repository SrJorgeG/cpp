#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <sstream>

class PhoneBook
{
private:
    Contact _contacts[8];
    int _count;
    int _index;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContacts() const;
    void displayContact(int index) const;
};

#endif
