#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

void	read_and_replace(char **av, ifstream &source_fd, ofstream &dest_fd) {
	string	line;
	size_t	lenght_to_remove;
	size_t	i;

	lenght_to_remove = strlen(av[2]);
	while (getline(source_fd, line)) {	//read source line by line
		i = line.find(av[2]);
		while (i != string::npos) {		//check if line.find find something
			line.erase(i, lenght_to_remove);	//remove av[2]
			line.insert(i, av[3]);				//insertav[3]
			i = line.find(av[2]);
		}
		dest_fd << line;
		if (!source_fd.eof())
			dest_fd << endl;
	}
}

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

	read_and_replace(av, source_fd, dest_fd);

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
	return (0);
}