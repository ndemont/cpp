#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

void	readFile(std::string file, std::string oldStr, std::string newStr)
{
	std::ifstream		ifs(file);
	std::ofstream		ofs(file + ".replace");
	std::string			content;
	std::size_t			occurence;

	(void)oldStr;
	(void)newStr;
	while (getline(ifs, content))
	{
		std::cout << content << std::endl;
		occurence = 1;
		while (occurence)
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
	if (ac != 4)
		return 1;
	readFile (av[1], av[2], av[3]);
	return 0;
}