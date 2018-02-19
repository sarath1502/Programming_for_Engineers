#include <iostream>
#include <string>
#include <map>

#include "contact.h"

std::ostream& operator<<(std::ostream &os, const Contact &c){
        // ADD: print information about contact "c"
	//os<<
	return os;
}

// READ: http://en.cppreference.com/w/cpp/container/map
using ContactManager = std::map<std::string, Contact>;

// read first and last name and return those string through the reference arguments
// NOTE: reuse this function in places you need to read first and last name
void read_name(std::string &first, std::string &last){

}

void list_contacts(const ContactManager &contacts)
{
        // ADD: check if the "contacts" is empty and handle it
        // READ: http://en.cppreference.com/w/cpp/container/map/empty

	if (contacts.empty())
		std::cout << "Contacts Empty\n";

        for (auto &key_value_pair : contacts) 
		{
                Contact const &c = key_value_pair.second;
                // ADD: print only names
				std::cout << c.last_name  << ", " << c.first_name<<"\n";
        }
}

// if contact exists you have to overwrite it with the new contact
// READ: http://en.cppreference.com/w/cpp/container/map/operator_at

void add_contact(ContactManager &contacts)
{
	ContactManager cont;
	std::string first_name, last_name, phone_number, email;
	std::cout << "first name:";
	std::cin >> first_name;
	std::cout << "last_name:";
	std::cin >> last_name;
	std::cout << "phone number";
	std::cin >> phone_number;
	std::cout << "email";
	std::cin >> email;

	cont(first_name, last_name, phone_number, email);


}

// READ: http://en.cppreference.com/w/cpp/container/map/erase
void remove_contact(ContactManager &contacts)
{

}

void find_contact(const ContactManager &contacts){
        std::string first_name, last_name;
        // ADD: read first and last name
		std::cout<<

        // values in map are ordered by key, so last name must go first
        std::string const key = last_name + first_name;
        auto it = contacts.find(key);

        if (it == std::end(contacts)) {
                // ADD: handle case when contact is not in variable "contacts"
        } else {
                // it->first is the key, it->second is the value in the std::map
                Contact const &c = it->second;

                // ADD: print contact information
        }
}

int main(){
	std::string cmd;
	Contact cont;
	ContactManager contacts;
	do {
		if (cmd == "exit"){
			break;
		} else if (cmd == "list"){
			list_contacts(contacts);
		} else if (cmd == "add"){
			add_contact(contacts);
		} else if (cmd == "remove"){
			remove_contact(contacts);
		} else if (cmd == "find"){
			find_contact(contacts);
		}
		std::cout << "> ";
	} while (std::cin >> cmd);
	return 0;
}

