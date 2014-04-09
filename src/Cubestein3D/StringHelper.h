#pragma once

#include <string>
#include <sstream>
#include <vector>

std::string IntToString(int value);


//Split operations from http://stackoverflow.com/questions/236129/how-to-split-a-string-in-c

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);

