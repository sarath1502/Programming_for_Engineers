#include<iostream>
#include<math.h>
#include<string>
#include<cstring>
#include<algorithm>

int main() {
	int num, length, fl_length;
	std::cin >> length;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string names="void", welcome;
	for (int i = 0; i < length; i++)
	{
		std::cout << "Case " << i << ":\n";
		welcome = "* Welcome to my program *";
		std::getline(std::cin,names);
		fl_length = std::max(welcome.size(), (names.size()) + 9);
		// first line
		if (fl_length <= (welcome.size()))
		{
			for (int p = 0; p < fl_length; p++)
				std::cout << "*";
			std::cout << "\n";
		}
		else
		{
			for (int p = 0; p <= fl_length + 1; p++)
				std::cout << "*";
			std::cout << "\n";
		}
		
		// second line

		if (fl_length <= (welcome.size()))
		{
			for (int p = 0; p < fl_length; p++)
			{
				if (p == 0)
					std::cout << "*";
				else if (p == (fl_length-1))
					std::cout << "*";
				else
					std::cout << " ";
			}
			std::cout << "\n";
		}
		else
		{
			for (int p = 0; p < fl_length; p++)
			{
				if (p == 0)
					std::cout << "*";
				if (p == (fl_length - 1))
					std::cout << " *";
				else
					std::cout << " ";
			}
			std::cout << "\n";
		}
		
		//third line
		if (fl_length <= (welcome.size()))
		{
			std::cout << "* Hello, " << names;
			if (fl_length < (9 + names.size()))
				std::cout << "*";
			else
				std::cout << std::string(fl_length - (11 + names.size()), ' ');
			std::cout << " *" << "\n";
		}
		else
		{
			std::cout << "* Hello, " << names;
			if (fl_length < (9 + names.size()))
				std::cout << "*";
			else
				std::cout << std::string(fl_length - (9 + names.size()), ' ');
			std::cout << " *" << "\n";
		}
		
		//fourth line
		std::cout << "* Welcome to my program";
		if (fl_length <= (welcome.size()))
			std::cout << " *";
		else
		{
			std::cout << std::string(fl_length - (welcome.size() - 2), ' ');
			std::cout << " *";
		}
			
		std::cout << "\n";

		// fifth line
		if (fl_length <= (welcome.size()))
		{
			for (int p = 0; p < fl_length; p++)
			{
				if (p == 0)
					std::cout << "*";
				else if (p == (fl_length - 1))
					std::cout << "*";
				else
					std::cout << " ";
			}
			std::cout << "\n";
		}
		else
		{
			for (int p = 0; p < fl_length; p++)
			{
				if (p == 0)
					std::cout << "*";
				if (p == (fl_length - 1))
					std::cout << " *";
				else
					std::cout << " ";
			}
			std::cout << "\n";
		}



		//sixth line
		if (fl_length <= (welcome.size()))
		{
			for (int p = 0; p < fl_length; p++)
				std::cout << "*";
			std::cout << "\n";
		}
		else
		{
			for (int p = 0; p <= fl_length + 1; p++)
				std::cout << "*";
			std::cout << "\n";
		}
	}
	return 0;
}
