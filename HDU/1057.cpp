#include<iostream>

using namespace std;

int origin[22][22] = {0};
int temp[22][22] = {0};
int D[16] = {0};

int tmrChange(int i, int j)
{
	int K = origin[i][j] + origin[i-1][j] + origin[i][j+1]
						 + origin[i+1][j] + origin[i][j-1];
	return K;
}

char reverse(int n)
{
	if(n==3)
	{
		return '#';
	}
	if(n==2)
		return 'X';
	if(n==1)
		return '!';
	if(n==0)
		return '.';
}

int main()
{
	int n;
	cin>>n;
	while(n--){
	int day;
	cin>>day;
	int i = 0, j = 0;
	for(  i = 0; i < 16; i++ )
		cin>>D[i];
	i = 0;
	while( i < 22 && j < 22 ){
		origin[0][j] = 0;
		origin[21][j] = 0;
		origin[i][0] = 0;
		origin[i][21] = 0;
		i++;j++;
	}
	for( i = 1; i <= 20; i++ )
		for( j = 1; j <= 20; j++ )
			cin>>origin[i][j];
	int k = 0;
	while(day--){
		for( i = 1; i <= 20; i++ )
			for( j = 1; j <= 20; j++ )
			{
				k = tmrChange(i,j);
				temp[i][j] = origin[i][j] + D[k];
				if(temp[i][j]>3)
					temp[i][j] = 3;
				if(temp[i][j]<0)
					temp[i][j] = 0;
			}
		for( i = 1; i <= 20; i++ )
			for( j = 1; j <= 20; j++ )
			{
				origin[i][j] = temp[i][j];
			}
	}
	for( i = 1; i <= 20; i++ )
	{
		for( j = 1; j <= 20; j++ )
		{
			cout<<reverse(origin[i][j]);
		}
		cout<<endl;
	}
	if(n)
		cout<<endl;
}
}
