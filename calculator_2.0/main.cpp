#include "calculation.h"
#include "calculator.h"
#include "print.h"

#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <iostream>
#include <fstream> //注:这里需要包含头文件<fstream> 
using namespace std;
int bitjudge = 0;

int main(int argc,char*argv[]) 
{
	Scan Sc;    
    Print Put;  
    Calculation Ca;
    
    //判断是否为文件操作 
	bool need_file = false; 
	
    if(strcmp(argv[1],"-f") == 0)  
    {
    	need_file = true;
    }
    
    //需要进行文件操作 
    if(need_file)  
    {
    	string getsfile = argv[argc-2];  //输入文件名 
    	string putsfile = argv[argc-1]; //输出文件名 
		     	
    	ifstream infile; 
    	ofstream outfile;
    	
    	//打开文件 
    	infile.open(getsfile.c_str(),ios::in); 
    	outfile.open(putsfile.c_str(),ios::out);
    	
    	string get_str;
    	
    	while(!infile.eof()) //未处理到文件尾 
    	{
    		getline(infile,get_str,'\n'); //读入数据 
    		
    		queue<string> que;
    		
    		que = Sc.ToStringQueue(get_str);
    		
    		double result=0;
    		
    		result = Ca.carryout(que);
    		
    		outfile << result << endl;
    	}
    	
    	//关闭文件 
    	infile.close();
    	outfile.close();
    }
    
    //无须进行文件操作 
    else
    {
    	queue<string> que;
    	
    	string str = argv[argc-1];  
    
        if(strcmp(argv[1],"-a") == 0) //判断是否有输入'-a' 
        {
    	    que.push(str);
    	    Put.pout(que);    // printf que.
        }
    
        while(!que.empty())
	    que.pop();  // 清空que 
     
	    que = Sc.ToStringQueue(argv[argc-1]);
    
        if(!que.empty()) 
        cout << Ca.carryout(que) << endl;
        else //出错 
        cout << "error" << endl;
    }
    
    return 0;
}

