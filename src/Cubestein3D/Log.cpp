#include "Log.h"
#include <iostream>
#include <time.h>
#include "Parameters.h"

////////////////////////////////////////
// Methods
////////////////////////////////////////
void Log::Message(std::string message)
{
	Add(LOG_ALL, message);
}

void Log::Debug(std::string message)
{
	Add(LOG_HIGH, message);
}

void Log::Warning(std::string message)
{
	Add(LOG_NORMAL, message);
}

void Log::Error(std::string message)
{
	Add(LOG_LOW, message);
}

void Log::Add(int level, std::string message)
{
	if (level <= VERBOSE_LEVEL)
	{
		time_t rawtime;
		struct tm * timeinfo;

		time(&rawtime);
		timeinfo = localtime(&rawtime);
		char* chartime = new char[256];
		asctime_s(chartime, 256, timeinfo);
		int size = strlen(chartime);
		chartime[size - 1] = '\0'; // Remove \n

		std::cout << "[" << chartime << "]: " << message << std::endl;
	}
}
