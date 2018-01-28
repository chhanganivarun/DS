#include<iostream>
using namespace std;
#include"stck.h"


int getMin(Stack &S);
int getMax(Stack &S);

int main()
{
	Stack S;
	int n;
	cout<<"Enter number of integers:";
	cin>>n;
	cout<<"Enter "<<n<<" integers:";
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		S.push(x);
	}
	S.print();
	if(S.isEmpty())
	{
		cout<<"Empty Stack!!\nAborting!!\n";
		return -1;
	}
	cout<<"Min is :"<<getMin(S)<<"\nMax is :"<<getMax(S)<<endl;
	return 0;
}

int getMin(Stack &S)
{
	Stack temp;
	int ret=S.top->data;
	while(S.top)
	{
		int x=S.pop();
		temp.push(x);
		if(x<ret)
			ret=x;
	}
	while(temp.top)
	{
		S.push(temp.pop());
	}
	return ret;
}

int getMax(Stack &S)
{
	Stack temp;
	int ret=S.top->data;
	while(S.top)
	{
		int x=S.pop();
		temp.push(x);
		if(x>ret)
			ret=x;
	}
	while(temp.top)
	{
		S.push(temp.pop());
	}
	return ret;
}

