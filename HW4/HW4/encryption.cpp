#include<iostream>
#include<math.h>
#include<string>
#include<cstring>
#include<cctype>

void encrypt(std::string &str)
{
	for (int i = 0; i < int(str.length()); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'm')
			str[i] += 13;
		else if (str[i] > 'm' && str[i] <= 'z')
			str[i] -= 13;
		if (str[i] >= 'A' && str[i] <= 'M')
			str[i] += 13;
		else if (str[i] > 'M' && str[i] <= 'Z')
			str[i] -= 13;
	}
}

int main() {
	int length;
	std::string i_str;
	std::cin >> length;
	for (int i = 0; i < length; i++)
	{
		std::cout << "Case " << i << ":\n";
		std::cin >> i_str;;
		encrypt(i_str);
		std::cout <<i_str << "\n";

	}
	return 0;
}