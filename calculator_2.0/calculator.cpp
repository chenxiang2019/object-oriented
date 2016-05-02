//==============================//
//代码主体部分：calculator      // 
//文件名称：calculator.cpp      //
//作者：031502209               //
//更新时间：2016/4/2  4/5       //
//博客：qq952693358             //
//==============================//

//==================================//
//说明：该部分对输入的[input]字符串 //
//进行了一次字符的遍历和<判断>:     //
// <判断大部>                       //
// <判断小部>                       //
//以及一次输入错误的判断：          //
//bool error                        //  
//==================================//
#include "calculator.h"
#include<string>
#include<queue>
#include<stdlib.h>
#include<iostream>
using namespace std;
extern int bitjudge;

// type:queue<string>
queue<string> Scan::ToStringQueue(string input)
{
    string s;  
    
    queue<string> que;
    
    bool error = true;    //用于检验是否出错.
    
    bool is_Connected = true;   //用于特判'-'号 
    //======is_Connected说明=======//
	//is_Connected=false:          //
	//不与数字相连，单独处理       // 
	//is_Connected=true:           //
	//与数字相连                   // 
    //=============================//
    
	int n;
	int i,j;
	int judge = 0;
	
    n = input.size();  //n = string's length.
    
    for(i = 0;i < n; i++)     
    {
    	//=====================//
    	//判断：               //
		//输入数字是否超过十位 //
    	//=====================//
    	if(bitjudge >= 10)
    	{
    		cout << "error" << endl;
    		error = false;  //input error
    		break;
    	}
    	
    	//===================//
    	// <判断大部>：      // 
    	//说明：遇到了符号'-'//
		//即input[i] == '-'  //
		//===================//
        if(input[i] == '-')
        {
        	bitjudge = 0;   //stop the count
        	
            judge = 1;      //judge=1代表遇见'-'  
            
            if(s != "") 
            {
            	que.push(s);  //把之前字符串存储的内容push 
            	is_Connected = false; //is_Connected置false 代表不与数字连接 
            }
            
            s.clear();    //清空字符串s 
            
            s += input[i]; 
            continue;
        }
        
        //=====================//
    	// <判断大部>：        // 
    	//说明：没有遇到符号'-'//
		//即input[i] != '-'    //
		//=====================//
        else
        {
        	//===========================//
        	// <判断小部>:               // 
			//input[i-1] == '-';         //
			//即之前遇到了符号'-'        //  
			//(注：此时用judge=1来表示 ) //
			//===========================//
			
            if(judge == 1)    
            {
            	//1.此时input[i]不是数字//
                if(input[i] == '(' || input[i] == ')'
				|| input[i] == '+' || input[i] == '*'
				|| input[i] == '/' || input[i] == '=')
                {
                	bitjudge = 0;  //stop the count 
                	
                    judge = 0;
                    
                    if(s != "")
                    {
                    	que.push(s);
                    	is_Connected = true; //'-'号后面没有遇到数字 转回true 
                    }
                    
                    s.clear();
                    
                    s += input[i];
                    
                    que.push(s); 
                    s.clear();     
                }
                
                //2.此时input[i]是数字// 
                else
                {
                	bitjudge++;
                	
                	if(is_Connected)        //如果允许与数字相连 s+='-' 
                	{
                		s += input[i];
                		
                		is_Connected = false; //'-'号已经特判过了 
                		              //暂时置false处理接下来的数字 
                	}
                    else
                    {
                    	if(s == "-")       //如果'-'不允许与数字相连 
                    	{
                    		que.push(s); //push'-' 
                    	    s.clear();
                    	}
                    	
                    	s += input[i]; 
                    }
                    continue;
                }
            }
            
            //===========================//
        	// <判断小部>:               // 
			//input[i-1] != '-';         //
			//即之前没有遇到符号'-'      //  
			//(注：此时用judge=0来表示 ) //
			//===========================//

            else   
            {
            	//1.此时input[i]不是数字//
                if(input[i] == '(' || input[i] == ')'
				|| input[i] == '+' || input[i] == '*'
				|| input[i] == '/' || input[i] == '=')
                {	
                    bitjudge = 0;  //stop the count
                    
                    if(input[i] == '(')  //是左括号允许 is_Connected置true 
                    is_Connected = true; 
                    else is_Connected = false; //非左括号不允许 
					 
                	if(s != "")
                    que.push(s);
                    s.clear();
                    
                    s += input[i];
                    
                    que.push(s);
                    s.clear();
                }
                
                //2.此时input[i]是数字// 
                else
                {
                	bitjudge++;
                    s += input[i];
                    continue;
                }
            }
            
        }
    }
    
    if(s != "" && error)
    que.push(s);
    
    s.clear();
    
    return que;
}


