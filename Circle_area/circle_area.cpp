#include "circle_area.h" 
#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

/*
 * Input():
 * 用于输入圆的半径的方法。 
 */

double Circle_area :: Input()
{
	double r;
	
	cout << "Please input the radius of a circle : ";  
	cin >> r;
	
	return r;
}

/*
 * Calculate():
 * 用于计算圆的面积的方法。 
 */

double Circle_area :: Calculate(double r)
{
	double S = 0;
	
	S = pi*r*r;
	
	return S;
}

