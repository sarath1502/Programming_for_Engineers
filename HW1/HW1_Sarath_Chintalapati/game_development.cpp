#include<iostream>
#include<math.h>

int main()
{
	short n;
	short initial_health, final_health, diff_health, max_health; 
	max_health = std::numeric_limits<short>::max();
	initial_health = 32000;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> diff_health;
		std::cout << "Case " << i << ":\n";
		if (diff_health >= 0 && short(initial_health + diff_health) <= 0)
		{
			std::cout << "no healing the boss to kill it!\n";
			std::cout << "boss health is " << max_health << "\n";
		}
			

		else
		{
			final_health = initial_health + diff_health;
			if (final_health <= 0)
			{
				final_health = 0;

				std::cout <<"boss health is 0\n"<<"the boss is dead!\n";
			}
			else std::cout << "boss health is " << final_health << "\n";
		}
			

		
	}
		


		
	return 0;

}