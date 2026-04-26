#include <iostream>
#include <string>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac != 4)
		return 1;
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	if (s1.empty())
		return (1);
	std::ifstream input(filename.c_str());
	if (!input.is_open())
	{
		std::cerr << "Cannot open input file" << std::endl;
		return (1);
	}
	std::string outFile = filename + ".replace";
	std::ofstream output(outFile.c_str());
	if (!output.is_open())
	{
		std::cerr << "Cannot open output file" << std::endl;
		return (1);
	}
	std::string line;
	std::string newLine;
	size_t	oldFound;
	size_t	found;
	while (std::getline(input, line))
	{
		newLine.clear();
		oldFound = 0;
		found = line.find(s1, oldFound);
		while (found != std::string::npos)
		{
			newLine.append(line.substr(oldFound, found - oldFound));
			newLine.append(s2);
			oldFound = found + s1.length();
			found = line.find(s1, oldFound);
		}
		newLine.append(line.substr(oldFound));
		output << newLine << std::endl;
	}
	return (0);
}
