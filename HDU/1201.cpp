#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

bool isRun(int year)
{
	if(!(year%4))
	{
		if(!(year%400))
			return true;
		else if((!(year%100))&&(year%400))
			return false;
		else if((!(year%4))&&(year%100))
			return true;
	}
	else
		return false;
}

int calculate(int year,int mon,int day)
{
	int borndays = 0;
	for(int i=1;i<=18;i++)
	{
		if(mon<=2)
		{
			if(isRun(year+i-1))
				borndays+=366;
			else
				borndays+=365;
		}
		else
		{
			if(isRun(year+i))
				borndays+=366;
			else
				borndays+=365;
		}
	}
	
	return borndays;
}

int main()
{
	int T; cin>>T;
	char date[20];
	for(int i=0;i<T;i++)
	{
		cin>>date;
		int year = atoi(strtok(date,"-"));
		int month = atoi(strtok(NULL,"-"));
		int day = atoi(strtok(NULL,"-"));
		if(month==2&&day==29)
		{
			cout<<-1<<endl;
			continue;
		}
		cout<<calculate(year,month,day)<<endl;
	}
}
