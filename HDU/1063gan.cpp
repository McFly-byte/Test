#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

char ans[200] = {0};
int result[200];
int length = 0;

void high_mcl(char *a,char *b)
{
	int alen = strlen(a), blen = strlen(b), among = 0;
	
	for(int i = 0; i<alen; i++ )
		for(int j = 0; j<blen; j++)
		{
			if(result[i+j]==-1)
				result[i+j] = 0;
			among = (a[i] - '0') * (b[j] - '0') + result[i+j]; 
			if(among/10!=0&&result[i+j+1]==-1)
				result[i+j+1] = 0;
			result[i+j+1] += among/10;
			result[i+j] = among%10;
		}
 } 
 
int wtlength(int a[],int n = 200)
{
	int i = 0;
	for( i = n-1; i >= 0; i-- )
	{
		if(a[i]!=-1)
			break;
	}
	return i + 1;
}

int main()
{
	char target[10],b[10],*c;
	int n,dot = 0;
	bool iszero = false;
	while(cin>>target>>n){
		memset(result,-1,200*sizeof(int));
		memset(ans,0,200);
		memset(b,0,10);
		char str[10] = {0};
		
		if(n==0)
		{
			cout<<'1'<<endl;
			continue;
		}
		
if(target[0]=='.')
{
	int tlen = strlen(target);
	for(int i = tlen-1; i>=0; i--)
		target[i+1] = target[i];
	target[0] = '0';
}

if(strchr(target,'.')==NULL)
{
	int llen = strlen(target);
	target[llen] = '.';
	target[llen+1] = '0';
	target[llen+2] = '\0';
}
		
	strcpy(b,strtok(target,"."));
	c = strtok(NULL,".");	
	int integer = atoi(b),inta = atoi(c);
	if(integer==0&&inta==0)	
	{
		cout<<'0'<<endl;
		continue;
	}
		int bb = strlen(b);
	if(integer==0)
	{
		iszero = true;
		memset(b,0,bb);
		b[0] = '0';
	}//整数部分未必存在；
	else
	{
		memset(b,0,bb);

		int i=0;
		if(integer>9)
		{
			b[1] = char(integer%10 + '0');
			b[0] = char(integer/10 + '0');
		}
		else
			b[0] = char(integer + '0');
	}	
	dot = strlen(c);					
	for(dot; c[dot-1]=='0'; dot--) 
		c[dot-1] = '\0';//得到小数位数 c
	if(dot!=0)
		strcat(b,c);	

	int len = strlen(b);
	for(int k = 0; k<len; k++)
		str[len-1-k] = b[k];		
	strcpy(ans,str);
	for(int i = 1; i<n; i++)
	{
		high_mcl(ans,str);
		length = wtlength(result);	
		for(int j = 0; j < length; j++)
			ans[j] = char( result[j] + '0');
		memset(result,-1,200*sizeof(int));
	 } 
	 
	 	dot *= n;
		length = strlen(ans);
		for(int k = length-1; k>=0; k--)
		{
			if(iszero&&k==length-1)
			{
				continue;
				}	
			if(k == dot-1)
				cout<<'.';
			cout<<char(ans[k]);
		}
		cout<<endl; 
		memset(target,0,10);
	}
	return 0;	
}
