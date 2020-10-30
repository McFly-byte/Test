#include<iostream>
#include<cstring>

using namespace std;

int n, result = 0;

bool game(int n,char a[][5],int b[],int c[]);
bool isBfit(int n,char*ss,int m);
bool isAfit(int n,char*ss,int m);

int main()
{
	while(cin>>n&&n!=0)
	{
		char a[n][5];
		int b[n], c[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		 } 
		 result = 0;
		for(int i=1000;i<10000;i++)
		{
			bool flag = game(i,a,b,c);
			if(flag&&result==0)
			{
				result=i;
			}
			else if(flag&&result!=0)
			{
				result=0;
				break;
			}
		} 
		if(result) cout<<result<<endl;
		else cout<<"Not sure"<<endl;
	}
	return 0;
 } 
 
bool game(int z,char a[][5],int b[],int c[])
{
	for(int i=0;i<n;i++)
	{
		if(isBfit(z,a[i],c[i])==false||isAfit(z,a[i],b[i])==false)
		{
			return false;
		}
	}
	return true;
}

bool isBfit(int z,char*ss,int m)
{
	int i = 0, count = 0;
	char placen[5] = {0};
	while(z)
	{
		placen[i] = char(z%10 + 48);
		z /= 10;
		i++;
	}
	for(i=0;i<4;i++)
	{
		if(ss[i] == placen[3-i])
			count++;
	}
	if(count == m)
		return true;
	return false;
}

bool isAfit(int z,char*ss,int m)
{
	int i = 0,count = 0;
	char placen[5];
	while(z)
	{
		placen[i] = char(z%10 + 48);
		z /= 10;
		i++;
	}
	for(i=0;i<4;i++){
		for(int j=0;j<4;j++)
		{
			if(placen[j]==ss[i])
			{
				placen[j] = '\0';
				count++;
				break;
			}
		}
	}
	if(count==m) { 
		return true;
	}
	return false;
}
