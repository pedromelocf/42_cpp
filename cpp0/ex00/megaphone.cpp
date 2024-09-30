#include <iostream>

int main (const int argc, char **argv)
{
	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	for (int i = 1; argv[i] ; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			argv[i][j] = toupper(argv[i][j]);
		std::cout << argv[i];
		if (argv[i + 1])
			std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}
