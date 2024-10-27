#include <iostream>
using namespace std;

int main(void) {
	int temp = 0;
	int f, s = 0;

	// std::cout << "Input an integer: " << std::endl;
	// std::cout << "> ";
	// std::cin >> temp;

	std::cout << "Cpp standard version: " << __cplusplus << std::endl;
	temp = __cplusplus % 100000 % 10000;
	// std::cout << "temp % 10000 % 10000:" << temp << std::endl;

	f = temp / 1000;
	// std::cout << "temp / 1000 as f:" << f << std::endl;

	s = temp % 1000 / 100;
	// std::cout << "temp % 1000 / 100 as s:" << s << std::endl;

	std::cout << "This app is using C++" << f << s << std::endl;
	return 0;
}
