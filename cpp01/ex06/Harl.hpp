#pragma once

#include <iostream>

enum Level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	UNKNOWN
};

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	Harl(/* args */);
	~Harl();
	void filter(std::string level);
};
