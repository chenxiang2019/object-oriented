#include "print.h"
#include<stack>
#include<string>
#include<queue>
#include<stdlib.h>
#include<iostream>
using namespace std;

//==========================//
//judgeerror函数：          //
//判断"("和")"是否匹配      //
//不匹配的话输出error       //
//==========================// 
bool judgeerror(stack<string> sign)
{
	string s_top; 
	stack<string> store; //遇右括号push 遇左括号pop 
	
    while(!sign.empty())
    {
    	s_top=sign.top();
    	sign.pop();
    	if(s_top==")")
    	{
    		store.push(s_top);
    		continue;
    	}
    	if(s_top=="(")
    	{
    		if(store.empty())return false; 
    		
    		store.pop();
    		continue;
    	}
    }
    if(store.empty())return true;
    else return false;
} 

void Print::pout(queue<string> que)
{
	stack<string> sign;   //用于存储"(" 和 ")" ,之后进行匹配判断 
	
	queue<string> store;  
	store=que;  //用另外一个队列 找"("和")" 
	 
	while(!store.empty())
	{
		if(store.front()== "(" || store.front()==")")
		{
			sign.push(store.front()); //压入用于匹配判断的栈			
		}
		store.pop();
	}
	
	if(judgeerror(sign))    // "(" 与 ")"匹配 进行输出 
	{
		while(!que.empty()) // "que" is not empty
        {
            cout << que.front();
        
		    que.pop();
        }
	}
	else  // "(" 与 ")" 匹配错误 
    {
    	cout<<"error"<<endl;
    }
}

