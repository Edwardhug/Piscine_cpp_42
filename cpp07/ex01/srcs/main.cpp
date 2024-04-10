# include "../includes/iter.hpp"

int main() {
	char chartab[] = "chartab";
	std::string	string = "string";

	iter(chartab, 7, &test_print_function);
	std::cout << std::endl;
	iter(&string, 6, &test_print_function);
}