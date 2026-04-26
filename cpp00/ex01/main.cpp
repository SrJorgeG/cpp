#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;
    std::string input;

    do
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "Getline Error, Exiting" << std::endl;
            break;
        }
        if (input == "ADD")
            phonebook.addContact();
        else if (input == "SEARCH")
            phonebook.searchContacts();
        else if (input == "EXIT")
            std::cout << "Goodbye!" << std::endl;
        else
            std::cout << "Unknown command" << std::endl;
    } while (input != "EXIT");
    return 0;
}
