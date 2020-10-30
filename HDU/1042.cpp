#include<iostream>//´óÊýµÄ½×³Ë 
#include<cstring>

using namespace std;

int a;
char en[35661];

inline int endlen();

int main()
{
	while(cin>>a){
		memset(en,0,35661);
		if(a==0||a==1){
			cout<<1<<endl;
			continue;
		}
		int n=a;
			int id = 0;
	while(n){
		en[id] = n%10;
		n /= 10;
		id++; 
	}
		
		for(int i = a-1; i>1 ; i--)
		{
			int k = 0,relay = 0,cmp = 0,len = endlen();
	while(1){
			cmp = i * en[k] + relay;
			relay = cmp / 10;
			en[k] = cmp%10;
			k++;
			if(en[k]==0&&k>=len&&relay==0) break;
		}
		}
		
		int l = endlen() -1 ;
		for(l;l>=0;l--)
		{
			cout<<char(en[l] + 48);
		}
		cout<<endl;
		
	}
	return 0;
 } 
 
inline int endlen()
{
	int len = 0,i=35660;
	while(en[i]==0){
		i--;
	}
	return i+1;
}
