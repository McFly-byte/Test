#include<iostream>
#include<cstring>
 
using namespace std;

char a[21];

bool isKey();
bool aeiou(char ch);
bool besides(char ch);

int main()
{
	
	while(cin>>a){
		if(strlen(a)==3&&a[0]=='e'&&a[1]=='n'&&a[2]=='d')
			break;
		if(isKey())
		{
			cout<<'<'<<a<<"> is acceptable."<<endl;
		}
		else
			cout<<'<'<<a<<"> is not acceptable."<<endl;
		memset(a,0,21);
	}
	return 0;
}

bool isKey()
{
	int len = strlen(a);
	bool isHave = false;
	for(int i=0;i<len;i++)
	{
		if(a[i]==a[i+1] && a[i]!='e' && a[i]!='o')
			return false;
		if(aeiou(a[i]))
			isHave = true;
	}
	if(!isHave)	return false; 
	int i=0;
	while(i<len-2)
	{
		if(aeiou(a[i])&&aeiou(a[i+1])&&aeiou(a[i+2]))
			return false;
		else if(besides(a[i])&&besides(a[i+1])&&besides(a[i+2]))
			return false;
		i++;
	}
	return true;
}

bool aeiou(char ch)
{
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
		return true;
	return false;
}

bool besides(char ch)
{
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
		return false;
	return true;
}

