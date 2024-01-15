#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

int	file_copy(char **av) {
	string new_file = string(av[1]) + ".replace";

	ifstream source_fd(av[1]);	//opening of the source
	if (!source_fd.is_open()) {
		cout << "Error during the oppening of source file." << endl;
		return (1);
	}

	ofstream dest_fd(new_file.c_str());	//opening of the destination
	if (!dest_fd.is_open()) {
        cout << "Error during the oppening of destination file." << endl;
		source_fd.close();
        return 1;
	}

	dest_fd << source_fd.rdbuf();	//writting

	dest_fd.close();			//closing
	source_fd.close();			//closing
	return (0);
}

int	main(int ac, char **av) {
	if (ac != 4) {
		cout << "3 arguments needed" << endl;
		return (1);
	}
	if (file_copy(av) == 1) {
		cout << "Error during the copy" << endl;
		return (1);
	}
	cout << "No problem" << endl;
	return (0);
}