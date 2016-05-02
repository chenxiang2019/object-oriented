//==============================//
//文件名称：calculator.h        //
//作者：031502209               //
//更新时间：2016/3/30           //
//博客：qq952693358             //
//==============================//
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<string>
#include<queue>
#include<stdlib.h>
#include<iostream>
using namespace std;

//===============================//
//class:Scan
//包含：函数ToStringQueue 
//函数类型：queue<string> 
//说明：输出函数单独放在这个类里 
//===============================//
class Scan
{
    // private section
    public:
        queue<string>ToStringQueue(string input);
};

#endif // CALCULATOR_H
