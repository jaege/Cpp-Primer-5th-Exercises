#include <iostream>
int main() {
	int bg = 0, ed = 0;
	std::cout << "Enter the number of begin and end:" << std::endl;
	std::cin >> bg >> ed;
	if (bg <= ed) {
	while (bg <= ed)
		std::cout << bg++ << " ";
	std::cout << std::endl;
}
	else {
		while (ed <= bg)
			std::cout << ed++ << " ";
		std::cout << std::endl;
	}
	return 0;
}
