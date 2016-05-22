#include "calculation.h"
#include "calculator.h"
#include "print.h"
#include "file_operate.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream> //注:这里需要包含头文件<fstream> 
using namespace std;

//==================================//
//说明：
//      进行文件输入输出操作    
//==================================//

void File_Operate::Fileoperate()
{
	Scan Sc;    
    Print Put;  
    Calculation Ca;
	
	ifstream infile; 
    ofstream outfile;
    
    //打开文件 
    infile.open(getsfile.c_str(),ios::in); 
    outfile.open(putsfile.c_str(),ios::out);
    	
    string get_str;
    	
    while(!infile.eof()) //未处理到文件尾 
    {
    	getline(infile,get_str); //读入数据 
    		
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
