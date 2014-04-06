#pragma once
#include <string>
#include "Definitions.h"

class Log
{
	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		static void Message(std::string message);
		static void Debug(std::string message);
		static void Warning(std::string message);
		static void Error(std::string message);
	private:
		static void Add(int level, std::string message);
};