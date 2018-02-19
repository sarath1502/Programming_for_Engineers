#include<iostream>
#include<math.h>
#include<string>
#include<cstring>
#include<algorithm>

int main() {
	int num, length,fl_length;
	std::cin >> length;
	for (int i = 0; i < length; i++)
	{
		std::string names,welcome="* Welcome to my program *";
		std::getline(std::cin, names);
		std::cout << "Case " << i << ":\n";
		fl_length = std::max(welcome.length(), (names.size()) + 9);
		// first line
		for (int p = 0; p < fl_length; p++)
			std::cout << "*";
		std::cout << "\n";
		// second line
		for (int p = 0; p < fl_length; p++)
		{
			if (p == 0 || p == (fl_length - 1))
				std::cout << "*";
			else
				std::cout << " ";
		}
		std::cout << "\n";
		//third line
		std::cout << "* Hello, " << names;
		if (fl_length < (9 + names.size()))
			std::cout << "*";
		else
			std::cout << std::string(fl_length - (9 + names.size()), ' ');
		std::cout << "*" << "\n";
		//fourth line
		std::cout << "* Welcome to my program";
		if (fl_length < (welcome.length() - 1))
			std::cout << "*";
		else 
			std::cout << std::string(fl_length - (welcome.length()-1), ' ');

		std::cout << "*\n";
		// fifth line
		for (int p = 0; p < fl_length; p++)
			std::cout << "*";
		std::cout << "\n";
		
	}
	return 0;
}
