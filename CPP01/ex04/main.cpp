#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

void	replace(std::string file, std::string oldStr, std::string newStr)
{
	std::ifstream		ifs(file);
	std::ofstream		ofs(file + ".replace");
	std::string			content;
	std::size_t			occurence;

	while (getline(ifs, content))
	{
		occurence = 1;
		while (occurence >= 0)
		{
			occurence = content.find(oldStr);
			if (occurence < content.size())
			{
				for (size_t i = 0; i < occurence; i++)
					ofs << content[i];
				ofs << newStr;
			}
			else
			{
				ofs << content;
				break ;
			}
			content = content.substr(occurence + oldStr.size());
		}
		ofs << std::endl;
	}
	ifs.close();
	ofs.close();
}

int main(int ac, char **av)
{
	std::string	empty = "";

	if (ac != 4)
	{
		std::cout << "This program needs 3 arguments: [filename] [string1] [string2]" << std::endl;
		return 1;
	}
	if (av[2] == empty || av[3] == empty)
	{
		std::cout << "The string should not be empty." << std::endl;
		return 1;
	}
	replace(av[1], av[2], av[3]);
	return 0;
}