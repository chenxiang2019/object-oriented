#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d",&a,&b);
	c=a+b;
	if(c<0)
	{
	    c=-c;
		printf("-");	
	}
	if(c<1000)printf("%d\n",c);
	else if(c>1000 && c<1000000)printf("%d,%d",c/1000,c%1000);
	else printf("%d,%d,%d\n",c/1000000,(c%1000000)/1000,c%1000);
	return 0;
}
