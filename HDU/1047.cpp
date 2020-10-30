#include<iostream>
#include<cstring>

using namespace std;

int n;
int sum[101] = {0};
int cop[101] ;

void pls(string str);

int main()
{
	while(cin>>n&&n!=0){
	string target[n];
	for(int i=0;i<n;i++) 
	{
		cin>>target[i];
		pls(target[i]);
	}
	int len;
	for( len=100;len>0;len--)
	{
		if(sum[len]) break;
	}
	for(len;len>=0;len--){
		cout<<sum[len];
		sum[len] = 0;
	}
	cout<<endl<<endl;
	
	}
	return 0;
} 
 
void pls(string str)
{
	int i=0;
	int slen = str.length();
	for(int k=0;k<101;k++)
	{
		cop[k]=0;
	}
	for( ;i<slen;i++)
	{
		cop[i] = str[slen-1-i] - '0';
	}
	int relay = 0, j = 0, bt = 0;
	while(relay!=0||j<slen){
		sum[j] += (cop[j] + relay);
		relay = sum[j]/10;
		sum[j] %= 10;
		j++;
	}
}
