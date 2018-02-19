#include<iostream>
#include<cmath>
using Array = int[256];

int main()
{
	int length, n;
	Array ipt;
	std::cin >> length;

	for (int i = 0; i < length; i++)
	{
		std::cout << "Case " << i << ":\n";
		std::cin >> n;
		for (int j = 0; j < n; j++)
		{
			std::cin >> ipt[j];
		}
		int max = 0, min = std::numeric_limits<int>::max();
		for (int p = 0; p < n; p++)
		{
			if (ipt[p] > max)
				max = ipt[p];
			if (ipt[p] < min)
				min = ipt[p];
		}
		std::cout << "Min: " << min << "\n";
		std::cout << "Max: " << max << "\n";
	}
	return 0;
}

