#ifndef __STRINGHELPER_H__
#define __STRINGHELPER_H__
#include <string>
#include <sstream>

std::string IntToString(int value)
{
	std::ostringstream str;
	str << value;
	std::string text(str.str());

	return text;
}
#endif