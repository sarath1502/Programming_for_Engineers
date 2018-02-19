#include "contact.h"

Contact::Contact()
{
	// ADD: initialize to empty contact
	this->last_name, this->last_name, this->phone_number, this->email = " ";
};


Contact::Contact(std::string const &first_name, std::string const &last_name, std::string const &phone_number, std::string const &email)
{
        // ADD: initialize contact using constructor arguments
	this->first_name = first_name;
	this->last_name = last_name;
	this->phone_number = phone_number;
	this->email = email;
};