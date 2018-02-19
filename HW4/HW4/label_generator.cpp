#include<iostream>
#include<math.h>
#include<string>
#include<cstring>
#include<cctype>


class LabelGenerator
{
private:
	int temp;
	std::string label;

public: 
	
		LabelGenerator(const std::string &prefix, int start)
	{
		label = prefix;
		temp = start;
	}

		std::string next_label()
		{
			return(label+std::to_string(temp++));
			
		}
};

int main() {
	int length, low = 0, high = 0;
	std::string label;
	std::cin >> length;
	for (int i = 0; i < length; i++)
	{
		std::cout << "Case " << i << ":\n";
		std::cin.ignore();
		 std::getline(std::cin,label);
		// std::cin >> label;
		std::cin >> low >> high;
		LabelGenerator point_numbers(label, low);
		for (int j = low; j <= high; j++) {
			std::cout << point_numbers.next_label();
			if (j < high)
				std::cout << " ";
		}
		std::cout << "\n";
		
	}
	return 0;
}