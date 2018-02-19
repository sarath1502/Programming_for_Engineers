#include<iostream>
#include<cmath>


int main()
{
	int length, n;
	double f, f_prime, i_root, f_root, thold_input, thold_calc;
	std::cin >> length;

	for (int i = 0; i < length; i++)
	{
		std::cin >> i_root >> n >> thold_input;
		thold_calc = std::numeric_limits<double>::max();
		std::cout << "Case " << i << ":\n";
		int j;
		for (j = 0; j < n && thold_calc > thold_input; j++)
		{
			f = std::pow(i_root, 5) + 6 * std::pow(i_root, 4) + 3 * std::pow(i_root, 3) - i_root - 50;
			f_prime = 5 * std::pow(i_root, 4) + 24 * std::pow(i_root, 3) + 9 * std::pow(i_root, 2) - 1;
			f_root = i_root - (f / f_prime);
			thold_calc = abs((f_root - i_root) / f_root);
			i_root = f_root;
		}
		std::cout << "root at x = " << f_root << " with error " << thold_calc << " after " << j << " iterations\n";	}	return 0;}

