//==============================//
//文件名称：
//      calculation.h       
//作者：
//      031502209               
//更新时间：
//      2016/4/7            
//博客：
//      qq952693358             
//==============================//
#ifndef CALCULATION_H
#define CALCULATION_H
#include <stack>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

//===============================//
//class:
//      Calculation              
//包含：
//      double carryout
//作用：
//      执行计算功能 
//===============================//
class Calculation
{
	public:
        double carryout(queue<string> que);   
};

#endif // CALCULATION_H
