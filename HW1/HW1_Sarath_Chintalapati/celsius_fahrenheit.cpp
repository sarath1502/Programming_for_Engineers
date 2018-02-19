#include<iostream>
#include<math.h>
#include<stdio.h>

int main()
{
	int n, temp_f[1000];
	int cel_int[1000];
	double cel_dou[1000];
	
	std::cin >> n;

	for (int i = 0 ; i < n; i++)
	{

		std::cin >> temp_f[i];
	}

	for (int i = 0; i < n; i++)
	{
		cel_dou[i] = double((temp_f[i] - 32)*(5.00000 / 9.00000));
		cel_int[i] = int(cel_dou[i]);

		std::cout << "Case " << i << ":\n";
		std::cout << temp_f[i] << "F = " << cel_int[i]<<"C\n";
		std::cout << temp_f[i] << "F = " << cel_dou[i] << "C\n";
	}
	return 0;
}
