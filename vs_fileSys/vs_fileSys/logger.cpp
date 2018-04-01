#include "logger.h"

logger::logger()
{
}

logger::logger(string name)
{
	src = name;
}

logger::~logger()
{
}

void logger::debug(string msg)
{
	cout << src << ':' <<"[DEBUG]"<< msg << endl;
}

void logger::error(string msg)
{
	cout << src << ':' << "[ERROR]" << msg << endl;
}
