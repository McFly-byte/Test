#include<iostream>  //高精度加法（有额外的输出） 
#include<cstring>

using namespace std;

char a[1001],b[1001],c[1001]={0};

void plu()
{
	static int id = 1;
	cin>>a>>b;
	cout<<"Case "<<id++<<":"<<endl;
	int la = strlen(a), lb = strlen(b), lc = la>=lb?la:lb;
	int i,j,k;
	for(i = la-1,j = lb-1,k = lc; i >= 0||j>=0 ;i--,j--,k--)
	{
		if(i>=0&&j>=0)
				c[k]+=((a[i]-48) + (b[j] - 48));
		else if (j<0)
			c[k] += (a[i]-48);
		else if (i<0)
		    c[k] += (b[j]-48);
	
				if(c[k]>9)
					{
						c[k-1] +=1;
						c[k] -= 10;
					}
	}
	cout<<a<<" + "<<b<<" = ";
	if(c[0]) 
	{
		for( i=0;i<=lc;i++)
		{
			cout<<int(c[i]);
		}
	}
	else 
		for(k=1;k<=lc;k++)
		{
			cout<<int(c[k]);
		}
	cout<<endl;
	memset(a,0,1001);memset(b,0,1001);memset(c,0,1001);
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		plu();
		if(i!=n)
			cout<<endl;
	}
	return 0;
 } 
