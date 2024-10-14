#include <iostream>

int main (const int argc, char **argv)
{
	std::string argument;

	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	for (int i = 1; argv[i] ; i++)
	{
		argument = argv[i];
		for (long unsigned int j = 0; j < argument.length(); j++)
		{
			char c =  std::toupper(argument[j]);
			std::cout << c;
		}
	}
	std::cout << std::endl;
	return 0;

}
