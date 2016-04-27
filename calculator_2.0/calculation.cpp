//==============================//
//代码主体部分：calculation     // 
//文件名称：calculation.cpp     //
//作者：031502209               //
//更新时间：2016/4/7            //
//博客：qq952693358             //
//==============================//

//==================================//
//说明：该部分分为两大块            //
//1.把原来的式子转换成为前缀表达式  //
//2.前缀表达式的计算                //
//==================================//
#include "calculation.h"
#include<stack>
#include<queue>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<sstream>

//======priority=======//
//说明：用于判断优先级 //
//=====================// 
int priority(string s)
{
    if(s=="(" || s== ")")return 0;
	if(s=="+" || s=="-")return 1;
	if(s=="*" || s=="/")return 2;
}

//======calculate======//
//说明：用于计算       //
//=====================// 
double calculate(string s,double a,double b)//double
{	
	if(s=="+")return b+a;
	if(s=="-")return b-a;
	if(s=="*")return b*a;
	
	if(s=="/" && a!=0)return b*1.0/a;
	else return 0;
}
//========代码主体========// 
double Calculation::carryout(queue<string> que)
{	
	stack<string> sign1,sign2;
	stack<string> signstore;//倒序 
	
	string s;
	string que_s;
	string sign1_top;
	
	if(que.front()=="-")
	signstore.push("0");
	
	//==========================//
	//从'='开始从右向左遍历     // 
	//所以用一个栈signstore实现 //
	//==========================//
	while(!que.empty())
	{
		signstore.push(que.front());
		que.pop();
	}
	
//-------------------------BEGIN-------------------------//	
    
    //======部分1======//
	//转换为前缀表达式 //
	//=================// 
	while(!signstore.empty())
	{
		s=signstore.top();
	    signstore.pop();
		
		if(s=="=")continue;
		if(s=="+" || s=="-" || s=="*" || s=="/" || s=="(" || s==")")
		{
			//=============说明=============// 
			//如果存在以下情况:             //
			//(1)s的优先级大于sign1栈顶元素 //
			//(2)s==")"                     //
			//(3)sign1为空栈                //
			//则:s直接push进sign1           //
			//==============================//
			
			//sign1为空栈  
			if(sign1.empty())
			{
				sign1.push(s);
				
				continue;
			}
			
			//s==")"
			if(s==")")
			{
				sign1.push(s);
				
				continue;
			}
			
			//=============说明=============// 
			//如果遇到左括号:               //
			//把sign1里面的字符push进sign2  //
			//直至遇见右括号                //
			//==============================//
			if(s=="(")
			{
			    while(sign1.top()!=")")
			    {
			    	sign2.push(sign1.top());
			    	
			    	sign1.pop();
			    }
				sign1.pop();//右括号出栈 
				continue;
			}
			
			//s的优先级大于sign1栈顶元素 //
			
			if(priority(s) > priority(sign1.top()))
			{
				sign1.push(s);
			    
				continue;
			}
		    
			//s的优先级小于sign1栈顶元素//
			
			//==============说明===============//
			//当遇到s的优先级小于栈顶元素时    // 
			//把sign1里面的字符从栈顶          //
			// push进sign2                     //
			//直到栈顶元素优先级大于s或者栈空  // 
			//=================================// 
			else if(priority(s) < priority(sign1.top()))
			{
				while(priority(s) < priority(sign1.top()))
				{
					sign1_top=sign1.top();
					
				    sign1.pop();
				    
				    sign2.push(sign1_top);
				    
				    if(sign1.empty())break;
				}
				sign1.push(s);
				continue;
			}
			else //优先级相同 且非"("括号")"直接入sign1 
			{
				if(s=="+" || s=="-" || s=="*" || s=="/")
				sign1.push(s);
			}
		}
		else //如果是数字的话 push进sign2 
		{
			sign2.push(s);
			continue;
		}
	}
	
	//将sign1中剩余的部分按顺序push进sign2 
	while(!sign1.empty())
	{
		sign2.push(sign1.top());
		sign1.pop();
	}
	
	//转换为前缀表达式 完成 
	
//-------------------------END-------------------------//	
	
	/*while(!sign2.empty())
	{
		cout<<sign2.top();
		sign2.pop();
	}
	
	cout<<endl;*/
	
	//========部分2========// 
	//计算前缀表达式       // 
	//=====================//
	
	//sign2逆序存放->sign_2 
    stack<string> sign_2;
	
	while(!sign2.empty())
	{
		sign_2.push(sign2.top());
		
		sign2.pop();
	}
	
	//使用stringstream 把字符串转换为数字 
	stringstream stream;
	double number;
	stack<double> numberstore;//存储数字的栈 
	string s2;
	
	numberstore.push(0);
	//计算部分 
	while(!sign_2.empty())
	{
		s2=sign_2.top();
		sign_2.pop();
		
		//遇到运算符 提取出numberstore栈顶两个元素进行计算
		//结果push进numberstore 
		if(s2=="+" || s2=="-" || s2=="*" || s2=="/")
		{
			double number1;
			number1=numberstore.top();
			numberstore.pop();
			
			double number2;
			number2=numberstore.top();
			numberstore.pop();
			
			double cal_number;
			cal_number=calculate(s2,number2,number1);
			
			numberstore.push(cal_number);
			
			continue;
		}
		else //遇到操作数 转换为数字之后入栈 
		{
			stream.str(s2);
			stream>>number;
			
			numberstore.push(number);
			stream.clear();
			
			continue;
		}
	}
	
	double value=0;
	
	if(!numberstore.empty())
	value=numberstore.top();//栈顶元素即最终结果
	 
	return value;
}

//-3+(9-((10-8)+(9-8*6/2+3)-10*10)*(8-(1+8/4+2)))+5*(1+(2+3)/5)/3
