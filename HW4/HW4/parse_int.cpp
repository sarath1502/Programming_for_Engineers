#include<iostream>
#include<math.h>
#include<string>
#include<cstring>
#include<cctype>
#include<limits>

bool pos, neg;

bool parse_int(const std::string &str, int &val)
{
	pos = false; neg = false;
	int count = 0;
	val = 0;
	if (str[0] == '+' || std::isdigit(str[0]))
		{
			pos = true;
			
		}
	if (str[0] == '-')
		{
			neg = true;
			
		}

	for (int i = 0; i < int(str.length()); i++)
	{
		
		
		if (std::isdigit(str[i]))
		{

			if (pos == true)
			{
				if (val > std::numeric_limits<int>::max() / 10 || val > std::numeric_limits<int>::max() - (str[i] - '0'))
					return false;
				else
					val = val * 10;
					val = val + str[i] - '0';
			}
			
			if (neg == true)
			{
				if (val < std::numeric_limits<int>::lowest() / 10 || val < std::numeric_limits<int>::lowest() + (str[i] - '0'))
					return false;
				else 				
					val = val * 10;
					val = val -( str[i] - '0');
			}
			
			
			count++;
		}
		
			
	}

		
		if (count >= int(str.length()) - 1)
		{
			return true;
			
		}
			
		else return false;
		
		
		
}


int main()
{
	int length, val;
	bool is_valid;
	std::string str;
	std::cin >> length;
	for (int i = 0; i < length; i++)
	{
		std::cout << "Case " << i << ":\n";
		std::cin >> str;
		is_valid = parse_int(str, val);
		if (is_valid)
			std::cout << val << "\n";
		else
			std::cout << "Parsing failed\n";

	}
	return 0;
}