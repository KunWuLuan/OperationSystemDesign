#pragma once
#ifndef main_h
#define main_h
#include"Main.h"
#endif // !main
#ifndef log
#define log
#include"logger.h"
#endif // !log

class Disk {
public:
	static fstream fileSys;
	static string fileSysPath;
	static const int diskCapacity;
public:
	static void init();
};
