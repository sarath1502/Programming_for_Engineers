#include<iostream> 
#include<iomanip>
#include<math.h>


int main()
{
	int length, n;
	// input the number of cases to be tested
	std::cin >> length;

	for (int i = 0; i < length; i++)
	{
		std::cout << "Case " << i << ":\n";
		std::cin >> n;
		double sum = 0.0;
		for (int j = 0; j < n; j++)
		{
			sum = sum + (pow(-1,j)) / (2.0 * j + 1);
		}
		sum = sum * 4;
		std::cout << "Pi estimated as: ";
		std::cout << std::fixed << std::setprecision(8) << sum << "\n";
	}
	return 0;
}
