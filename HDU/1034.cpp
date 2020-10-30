#include<iostream>
using namespace std;

struct stu
{
	int candy;
	stu * myNext;
};

bool isAverage(stu*ps)//ps___a[0];
{
	int num = ps->candy;
	while(ps->myNext!=NULL)
	{
		ps=ps->myNext;
		if(ps->candy!=num)
		{
			return false;
		}
	}
	return true;
}

int shiftAndCandy(stu *a , int N)//返回最后每人手里糖果数； 
{
	int count=0;
	while(1){
	
	if(isAverage(a))
	{
		cout<<count<<' ';
		return a[0].candy;
	}
	else
	{
		count++;
	int step = a[0].candy;
	
	for(int i=0;i<N;i++)
	{
		if(i==N-1)
		{
			a[N-1].candy/=2;
			a[N-1].candy+=step/2;
		}
		else 
		{
			a[i].candy/=2;
			a[i].candy+=a[i+1].candy/2;
		}
		if(a[i].candy%2==1)
		{
			a[i].candy++;
		}
	}
	
   }
}
}

int main()
{
	while(1){
	int N;
	cin>>N;
	
	if(N==0)
	{
		break;
	}//0 to break; 
	
	stu a[N];
	for(int i=N-1;i>=0;i--)
	{
		cin>>a[i].candy;
		if(i!=N-1)
		{
			a[i].myNext=&a[i+1];
		}
		else
		{
			a[i].myNext=NULL;
		}
	}
	
	int candies=shiftAndCandy(a,N);
	cout<<candies<<endl;
	
	
	
	
	
	}
	return 0;
 } 
