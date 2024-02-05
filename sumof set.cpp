#include<iostream>
using namespace std;
int s[10],d,n,set[10],count=0;
void dipslay(int)
int flag = 0;
int main()
{
	int subset(int,int);
	int i;
	cout<<"enter the number of elements:";
	cin>>n;
	cout<<"enter the elements :";
	for(i=0;i<n;i++)
	cin>>s[i];
	cout<<"The sum of the subset is:";
	cin>>d;
	cout<<"The output is :";
	subset(0,0);
	if(flag==0)
	cout<<" the output is note possible";
}
int subset(int sum,int i)
{
	if(sum==d)
	{
	flag==1;
	display(count);
	return 0;
}
	if (sum>d ||i>=n)
	return 1;
	else
	{
	set[count]=s[i];
	count++;
	subset(sum+s[i],i+1);
	count--;
	subset(sum,i+1);
}
}
void display(int count)
	int i;
	cout<<"{"
	for(i=0;i<count;i++)
	cout<<set[i]<<",";
	cout<<"}"
}



