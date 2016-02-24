#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<string>
#include<queue>
#include<stdlib.h>
#include<iostream>
using namespace std;
/*
 * No description
 */
 
class Input
{
	public:
		string Get();
};

class Print
{
	public:
		void pout(queue<string>que);//type:queue<string>
};

class Scan
{
	// private section
	public:
	    queue<string>ToStringQueue(string input);//type:queue<string>
};

#endif // CALCULATOR_H

