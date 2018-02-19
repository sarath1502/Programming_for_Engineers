#include<iostream>
#include<math.h>

int main()
{
	int n; 
	std::cin >> n;
	double num;
	float fin;

	for (int i = 0 ; i < n; i++)
	{
		std::cin >> num;
		std::cout << "Case " << i << ":\n";
		if ((num > std::numeric_limits<float>::max()) || (num < std::numeric_limits<float>::lowest()))
			std::cout << num << "  will overflow a float\n";
		else
		{
			fin = num;
			std::cout << num << " won't overflow a float, float = " << fin << "\n";
		}
	}
	return 0;
}