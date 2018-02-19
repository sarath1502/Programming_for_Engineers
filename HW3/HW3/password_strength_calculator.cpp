#include<iostream>
#include<math.h>
#include<string>
#include<cstring>
#include<cctype>

int calc_pass(std::string password)
{
	int score, strength;
	score = password.length();
	int count_lowercase = 0, count_uppercase = 0, count_number = 0, count_punctuation = 0, count_rule = 0;
	for (int j = 0; j < password.length(); j++)
	{
		if (std::islower(password[j]))
			count_lowercase++;
		if (std::isupper(password[j]))
			count_uppercase++;
		if (std::isdigit(password[j]))
			count_number++;
		if (std::ispunct(password[j]))
			count_punctuation++;
	}

	if (count_lowercase > 0)
	{
		score++;
		count_rule++;
	}

	if (count_uppercase > 0)
	{
		score++;
		count_rule++;
	}
	if (count_number > 0)
	{
		score++;
		count_rule++;
	}
	if (count_punctuation > 0)
	{
		score = score + 2;
		count_rule++;
	}
	count_rule--;
	strength = score * pow(2, count_rule);
	return strength;
}

int main() {
	int length, n;
	std::string password;
	std::cin >> length;
	for (int i = 0; i < length; i++)
	{
		std::cout << "Case " << i << ":\n";
		std::cin >> password;
		int strength_f;
		strength_f = calc_pass(password);
		std::cout << "Strength: " << strength_f << "\n";

	}
	return 0;
}
