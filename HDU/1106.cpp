#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

char a[1001];
long long b[500];

void bpAout(long long b[],int n)
{
	for(int i=n-1;i>0;i--)
		for(int j=0;j<i;j++)
			if(b[j]>b[j+1])
			{
				int tmp = b[j];
				b[j] = b[j+1];
				b[j+1] = tmp;
			}
	for(int i=0;i<n;i++)
	{
		cout<<b[i];
		if(i!=n-1)
			cout<<' ';
	}
}

int main()
{
	while(cin>>a){
		int i=0;
		char *p = strtok(a,"5");
		while(p!=NULL){
			b[i] = atoi(p);
			i++;
			p = strtok(NULL,"5");	
		}
		bpAout(b,i);
		cout<<endl;
	}
	return 0;
 } 
