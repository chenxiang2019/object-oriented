#include "calculation.h"
#include "calculator.h"
#include "print.h"

#include<string>
#include<string.h>
#include<queue>
#include<stdlib.h>
#include<iostream>
using namespace std;
int bitjudge=0;

int main(int argc,char*argv[])    //不通过命令行输入时通过Input类来输入 
{
    queue<string> que; // type:queue<string>
    
	Scan Sc;    // Define a "Scan" object:"Sc".
    Print Put;  // Define a "Print" object "Put".
    Calculation Ca; // Define a "Calculation" object "Ca".
    
    string str=argv[argc-1];  
    
    if(strcmp(argv[1],"-a")==0) //判断是否有输入'-a' 
    {
    	que.push(str);
    	Put.pout(que);    // printf que.
    }
    
    while(!que.empty())que.pop();  // 清空que 
     
	que=Sc.ToStringQueue(argv[argc-1]);
    
    if(!que.empty()) 
    cout<<Ca.carryout(que)<<endl;
    else //出错 
    cout<<"error"<<endl;
    
    return 0;
}

