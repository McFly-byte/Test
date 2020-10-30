#include<iostream>
#include<cstring>

using namespace std;

char a[10001] = {0};
int j=0;

int recurring()
{
	int amount = 1;
	while(a[j]==a[j+1])
	{
		amount++;
		++j;	 
	}
	return amount;
}

int main()
{
	int n;
	cin>>n;
	int alne;
	int bullshit;
	for(int p=0; p<n ;p++)
	{
		cin>>a;
		alne = strlen(a);
		j=0;
		for(j;j<alne;j++)
		{
			bullshit = recurring();
			if(bullshit==1)
				cout<<a[j];
			else
				cout<<bullshit<<a[j];
		}
		cout<<endl;
		memset(a,0,1001);
	}
	return 0;
}
