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
	
	double s;
	
	s = area.Calculate(r);
	
	cout << "The circle's area is : " << setprecision(4) << s <<endl;
	
	return 0;
}

