#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "clase.h"

int main() 
{
    AddressBook addressBook;

    addressBook.addContact(new Friend("John Doe", "1990-01-01", "1234567890", "123 Elm Street"));
    addressBook.addContact(new Acquaintance("Jane Smith", "0987654321"));
    addressBook.addContact(new Colleague("Jim Brown", "1122334455", "Tech Corp", "456 Oak Street"));

    Contact* contact = addressBook.searchContactByName("Jane Smith");
    if (contact)
    {
        std::cout << "Found contact: " << contact->getName() << std::endl;
    }
    else 
    {
        std::cout << "Contact not found" << std::endl;
    }

    std::vector<Friend*> friends = addressBook.getFriends();
    std::cout << "Friends in address book:" << std::endl;
    for (auto friendContact : friends) {
        std::cout << friendContact->getName() << std::endl;
    }

    addressBook.deleteContactByName("Jim Brown");

    return 0;
}
