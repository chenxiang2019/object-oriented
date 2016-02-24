#include "calculator.h" // class's header file
#include<string>
#include<queue>
#include<stdlib.h>
#include<iostream>
using namespace std;

int t=0;//Using global variable "t";

string Input::Get()
{
	string s;
	cin>>s;
	return s;
}

queue<string>Scan::ToStringQueue(string input)//type:queue<string>
{
    int n=input.length(),m=0,i,j;
    queue<string>que;
    string s;
    for(i=0;i<n;i++) // Error: n has no define; 
    {
	    if(t>10) // such as "10,000,000,000"
	    {
		    cout<<"Error"<<endl;
		    break;
	    }
		
	    if(input[i]=='-' || input[i]=='+' || input[i]=='(' || input[i]==')' || input[i]=='/' || input[i]=='*')
	    {
		    t=0; // stop the count
			
			if(s!="")//avoid null string
		    que.push(s);
		    s=""; // s.clear(); 
			
		    s+=input[i];
			
		    que.push(s);
		    s="";
	    }
	    else
	    {
		    t++;
		    s+=input[i];
		    continue;
	    }
    }
    
	que.push(s);
	s.clear();
    
    return que;
}

void Print::pout(queue<string>que)
{
    if(t<=10) // ifnormal
    {
	    while(que.empty()==0) // "que" is not empty
	    {
	        cout<<que.front()<<endl;
            que.pop();
	    }
    }
}

int main()
{
    queue<string>que;//type:queue<string>
    Scan Sc; // Define a "Scan" object:"Sc".
    Print Put; // Define a "Print" object "Put".
    Input Ge;// Define a "Input" object "Ge".
    string input;

    input=Ge.Get();//receieve input.
    que=Sc.ToStringQueue(input);//receieve que.
    
    Put.pout(que);//printf que.
    return 0;
}
//-100+(98-97)*2
