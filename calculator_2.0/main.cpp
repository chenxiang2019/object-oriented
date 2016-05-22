#include "calculation.h"
#include "calculator.h"
#include "print.h"
#include "file_operate.h" 
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <iostream>
using namespace std;

int bitjudge = 0;

int main(int argc,char*argv[]) 
{
    //判断是否为文件操作 
	bool need_file = false; 
	
    if(strcmp(argv[1],"-f") == 0)  
    {
    	need_file = true;
    }
    
    //需要进行文件操作 
    if(need_file)  
    {
    	File_Operate FO;
    	FO.getsfile = argv[argc-2]; //输入文件名 
    	FO.putsfile = argv[argc-1]; //输出文件名 
		
		FO.Fileoperate();
    }
    
    //无须进行文件操作 
    else
    {
	    Scan Sc;    
        Print Put;  
        Calculation Ca;
    
    	queue<string> que;
    	
    	string str = argv[argc-1];  
    
        if(strcmp(argv[1],"-a") == 0) //判断是否有输入'-a' 
        {
    	    que.push(str);
    	    Put.pout(que); // printf que.
        }
    
        while(!que.empty())
	    que.pop(); // 清空que 
     
	    que = Sc.ToStringQueue(argv[argc-1]);
    
        if(!que.empty()) 
        cout << Ca.carryout(que) << endl;
        else //出错 
        cout << "error" << endl;
    }
    
    return 0;
}

