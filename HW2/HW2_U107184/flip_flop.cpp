#include<iostream>
#include<math.h>

int main(){
	int num,a,b,length,start,sec;
	std::cin >> length;
	for (int i = 0; i < length; i++)
	{
		std::cout << "Case " << i << ":\n";
		std::cin >> start >> sec >> a >> b;
		for (int i = start; i <(start+sec); i++)
		{
			if (i%a == 0)
				std::cout << "flip";
			if (i%b == 0)
				std::cout << "flop";
			if (i%a != 0 && i%b != 0)
				std::cout << i;
			std::cout << "\n";

		}
		
	}
	return 0;
}