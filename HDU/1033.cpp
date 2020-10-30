#include<iostream>
#include<string>

using namespace std;

static int useA = 0;
static int useV = 0;

struct locate
{
	int x;
	int y;
};

int init(locate*paper,int j)//j=i+2;
{
	if(paper[j-1].x-paper[j-2].x==10)
	{
		return 1;
	}
	else if(paper[j-1].x-paper[j-2].x==-10)
	{
		return 3;
	}
	else if(paper[j-1].y-paper[j-2].y==10)
	{
		return 0;
	}
	else if(paper[j-1].y-paper[j-2].y==-10)
	{
		return 2;
	}
	else
	{
		return 100;
	}
}

void lineTo(char a,locate*paper,int j)//j=i+2;
{
	if(a=='A')
	{
		switch(init(paper,j))
		{
			case 3:
				paper[j].y=paper[j-1].y+10;
				paper[j].x=paper[j-1].x;
				break;
			case 2:
				paper[j].x=paper[j-1].x-10;
				paper[j].y=paper[j-1].y;
				break;
			case 1:
				paper[j].y=paper[j-1].y-10;
				paper[j].x=paper[j-1].x;
				break;
			case 0:
				paper[j].x=paper[j-1].x+10;
				paper[j].y=paper[j-1].y;
				break;
			default:
				break;
		}
	}
    else if(a=='V')
	{
		switch(init(paper,j))
		{
			case 3:
				paper[j].y=paper[j-1].y-10;
				paper[j].x=paper[j-1].x;
				break;
			case 2:
				paper[j].x=paper[j-1].x+10;
				paper[j].y=paper[j-1].y;
				break;
			case 1:
				paper[j].y=paper[j-1].y+10;
				paper[j].x=paper[j-1].x;
				break;
			case 0:
				paper[j].x=paper[j-1].x-10;
				paper[j].y=paper[j-1].y;
				break;
			default:
				break;
		}
	}	
}

int main()
{
	string order;//向其中输入A&V 
	while(cin>>order)
	{
		cout<<"300 420 moveto"<<endl;
		cout<<"310 420 lineto"<<endl;
		
		locate paper[202];
		paper[0].x=300;paper[0].y=420;
		paper[1].x=310;paper[1].y=420;//跟踪变化 
		
		for(int i=0;i<order.size();i++)
		{
			lineTo(order[i],paper,i+2);
			cout<<paper[i+2].x<<' '<<paper[i+2].y<<' '<<"lineto"<<endl;
		}//一步一步走A&V 
		
		cout<<"stroke"<<endl;
		cout<<"showpage"<<endl;
	}
	return 0;
 } 
