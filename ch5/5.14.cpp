#include <iostream>
#include <string>

int main()
{
	int repetition = 1;
	int occur = 1;
	std::string largest;
	std::string s;
	std::string temp;

	while (std::cin >> s)
	{
		if (temp != s)
		{
			temp = s;	
		}
		else
		{	
			++occur;
			if (occur > repetition)
			{
				repetition = occur;
				largest = s;
			}				
		}
	}
	if (repetition > 1)
		std::cout << largest << "occured: " << repetition;
	else
		std::cout << "no repetiotion";

	return 0;
}
