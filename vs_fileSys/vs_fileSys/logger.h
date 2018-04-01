#pragma once
#include"Main.h"
#ifndef iostream
#define iostream
#include<iostream>
#endif
class logger
{
	string src="[NoDefine]";
public:
	logger();
	logger(string name);
	~logger();
	void debug(string msg);
	void error(string msg);
};

