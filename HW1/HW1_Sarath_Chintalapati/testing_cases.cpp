#include<iostream> 
#include<string>


int main()
{
	int length;
	// input the number of cases to be tested
	std::cin >> length;
	
	std::string words[10000];

	for (int i = 0; i < length; i++)
	{
		std::cin >> words[i];

	}

	for (int i = 0; i < length; i++)
	{
		std::cout << "Case " << i << ":\n";
		std::cout << "Echo: " << words[i] << "\n";

	}
	return 0;
}