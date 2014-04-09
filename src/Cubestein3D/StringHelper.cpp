#include "StringHelper.h"

std::string IntToString(int value)
{
	std::ostringstream str;
	str << value;
	std::string text(str.str());

	return text;
}


//Split operations from http://stackoverflow.com/questions/236129/how-to-split-a-string-in-c

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
{
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim))
	{
		elems.push_back(item);
	}
	return elems;
}


std::vector<std::string> split(const std::string &s, char delim)
{
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}