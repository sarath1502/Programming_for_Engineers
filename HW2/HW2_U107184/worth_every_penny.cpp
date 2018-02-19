#include<iostream> 
#include<cmath>
#include<vector>
#include<iomanip>


int main()
{
	int length;
	// input the number of cases to be tested
	std::cin >> length;
	for (int i = 0; i < length; i++)
	{
		unsigned long no_rings = 0;
		double bill_profit = 0.25, bill_sum = 0.25;
		unsigned long long actual_profit = 0, actual_sum = 0;
		double dec = 0.25;
		std::cout << "Case " << i << ":\n";
		std::cin >> no_rings;
		std::cout << no_rings << " rings were sold\n";
		for (int j =1; j < no_rings; j++)
		{
			bill_profit = 10 + bill_profit;
			bill_sum = bill_sum + bill_profit;
			actual_profit = 10 + actual_profit;
			actual_sum = actual_sum + actual_profit;
			dec = dec + 0.25;
			}
		//actual_sum = actual_profit + dec;
		std::cout << "Bill's program outputs\t" << std::fixed << std::setprecision(2) << bill_sum << "\n";
		//std::cout << "The exact profit is\t" << actual_sum << "." << dec-int(dec) << "\n";
		std::cout << "The exact profit is\t" << actual_sum + dec<<"\n";
			}
}
