#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

enum ContactType { FRIEND, ACQUAINTANCE, COLLEAGUE };

class Contact {
protected:
    std::string name;
public:
    Contact(std::string name) : name(name) {}
    virtual ~Contact() {}
    std::string getName() const { return name; }
    virtual ContactType getType() const = 0;
};

class Friend : public Contact
{
private:
    std::string dob;
    std::string phoneNumber;
    std::string address;
public:
    Friend(std::string name, std::string dob, std::string phoneNumber, std::string address)
        : Contact(name), dob(dob), phoneNumber(phoneNumber), address(address) {}
    std::string getDob() const { return dob; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getAddress() const { return address; }
    ContactType getType() const override { return FRIEND; }
};

class Acquaintance : public Contact
{
private:
    std::string phoneNumber;
public:
    Acquaintance(std::string name, std::string phoneNumber)
        : Contact(name), phoneNumber(phoneNumber) {}
    std::string getPhoneNumber() const { return phoneNumber; }
    ContactType getType() const override { return ACQUAINTANCE; }
};

class Colleague : public Contact 
{
private:
    std::string phoneNumber;
    std::string company;
    std::string address;
public:
    Colleague(std::string name, std::string phoneNumber, std::string company, std::string address)
        : Contact(name), phoneNumber(phoneNumber), company(company), address(address) {}
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getCompany() const { return company; }
    std::string getAddress() const { return address; }
    ContactType getType() const override { return COLLEAGUE; }
};

class AddressBook
{
private:
    std::vector<Contact*> contacts;
public:
    ~AddressBook() {
        for (auto contact : contacts) {
            delete contact;
        }
    }

    void addContact(Contact* contact) {
        contacts.push_back(contact);
    }

    void deleteContactByName(const std::string& name) {
        contacts.erase(std::remove_if(contacts.begin(), contacts.end(), [&](Contact* contact) {
            if (contact->getName() == name) {
                delete contact;
                return true;
            }
            return false;
            }), contacts.end());
    }

    Contact* searchContactByName(const std::string& name) const {
        for (auto contact : contacts) {
            if (contact->getName() == name) {
                return contact;
            }
        }
        return nullptr;
    }

    std::vector<Friend*> getFriends() const {
        std::vector<Friend*> friends;
        for (auto contact : contacts) {
            if (contact->getType() == FRIEND) {
                friends.push_back(static_cast<Friend*>(contact));
            }
        }
        return friends;
    }
};