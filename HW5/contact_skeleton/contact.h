#pragma once

#include <string>

// only declarations; there should be no code that executes
class Contact {
public:
	// ADD: member variable to hold first and last name, email, and phone number
	std::string first_name, last_name, email, phone_number;
	Contact();
	Contact(std::string const &first_name, std::string const &last_name, std::string const &phone_number, std::string const &email);
};