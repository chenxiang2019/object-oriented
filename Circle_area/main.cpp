#include "circle_area.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main()
{
	double r;
	
	Circle_area area;
	
	r = area.Input();
	
	if(r < 0)
	{
		cout << "Input Error!" << endl;
		return 0;
	}
	
	double s;
	
	s = area.Calculate(r);
	
	cout << "The circle's area is : " << setprecision(4) << s << endl;
	
	return 0;
}

