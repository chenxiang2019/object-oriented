//==============================//
//文件名称：
//      print.h             
//作者：
//      031502209               
//更新时间：
//      2016/3/30 4/5       
//博客：
//      qq952693358             
//==============================//
#ifndef PRINT_H
#define PRINT_H
#include <stack>
#include <string>
#include <queue>
#include <stdlib.h>
#include <iostream>
using namespace std;

//===============================//
//class:
//      Print                    
//包含：
//      queue<string> pout
//说明：
//      输出函数单独放在这个类里 
//===============================//
class Print
{
    public:
        void pout(queue<string> que);
};

#endif // PRINT_H

