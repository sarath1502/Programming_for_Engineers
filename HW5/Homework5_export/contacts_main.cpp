#include <iostream>
#include <string>
#include <map>

// you must create contact.h where you put your class Contact
#include "contact.h"

std::ostream& operator<<(std::ostream &os, const Contact &c){

	return os;
}

using ContactManager = std::map<std::string, Contact>;

void read_name(std::string &first, std::string &last){

}

void list_contacts(const ContactManager &contacts){

}

// if contact exists you have to overwrite it with the new contact
void add_contact(ContactManager &contacts){

}

void remove_contact(ContactManager &contacts){

}

void find_contact(const ContactManager &contacts){

}

int main1(){
	std::string cmd;
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

