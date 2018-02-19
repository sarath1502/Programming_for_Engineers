#include<iostream>
#include<math.h>
#include<cstring>

int reverse_number(int number)
{
	int temp, reverse_num = 0;
	while (number != 0)
	{
		temp = number % 10;
		number = number / 10;
		reverse_num = reverse_num * 10 + temp;
	}
	return reverse_num;
}

int main() {
	int num, length, num_rev;
	std::cin >> length;
	for (int i = 0; i < length; i++)
	{
		std::cout << "Case " << i << ":\n";
		std::cin >> num;
		if (std::cin.fail() || num < 0)
		{
			std::cout << "Invalid input\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
			
		else
		{
			num_rev = reverse_number(num);
			std::cout << num_rev << "\n";
		}
			
	}
}
