#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;


int main()
{
	
	int x,a,seed;
	cout<<"���������ӣ�";
	cin>>seed;
	if(seed<=0)
	{
		srand(time(0));
		seed=time(0)/10000;
	}
	else
	{
		srand(seed/20);
	}
	x=seed%rand();
	
	cout<<"\n\n\n����0~"<<seed<<"֮��\n\n";
	while(1)
	{	
		cout<<"\n������: " ;
		cin>>a;
		if(a>x) cout<<"\n���ˣ�\n";
		if(a<x) cout<<"\nС�ˣ�\n";
		if(a==x) {cout<<"\n\n\n\n��ϲ�㣬�¶��ˣ�\n\n\n";	break;}
		if(a<=0) {cout<<"\n\nExit!\n\n";	return 0;}
	}
}
