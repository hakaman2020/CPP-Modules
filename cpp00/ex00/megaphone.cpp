#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (size_t i = 1; argv[i] != NULL; i++)
		{
			for (size_t j = 0; argv[i][j] != '\0'; j++)
			{
				if (islower(argv[i][j]))
				{
					std::cout << (char) toupper(argv[i][j]);
				}
				else
					std::cout << (char) argv[i][j];
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
