//==============================//
//文件名称：calculator.h 
//作者：031502209 
//更新时间：2016/3/23 
//博客：qq952693358 
//==============================//
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include<string>
#include<queue>
#include<stdlib.h>
#include<iostream>
using namespace std;

//==============================//
//class:Input 
//包含：输入函数Get 
//函数类型：string
//说明:输入函数单独放在这个类里 
//==============================//
class Input
{
    public:
        string Get();
};

//===============================//
//class:Print
//包含：输出函数Get 
//函数类型：queue<string> 
//说明：输出函数单独放在这个类里 
//===============================//
class Print
{
    public:
        void pout(queue<string> que); // type:queue<string>
};

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
        queue<string>ToStringQueue(string input);//type:queue<string>
};

#endif // CALCULATOR_H
