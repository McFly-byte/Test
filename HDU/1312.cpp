#include<iostream>//经典DFS（马の写了快仨小时2.19） 

using namespace std;

struct node{
	char bit;
	bool isNew;
};

int W,H;
int path = 0;
int pathcop = 0; 
node maze[21][21] = {0};					 //不用动态数组，先开个大的固定数组 
bool flag;									//，再往里面填东西

bool dfs(int ai,int aj)//H行，W列; 
{
	if(maze[ai][aj].isNew == false)
		return false;
	if(maze[ai][aj].bit=='#')
		return false;
	maze[ai][aj].isNew = false;		
	pathcop++;
	if(ai!=0)
		flag = dfs(ai-1,aj);//上 
		
	if(aj!=0)								//这里用if而非else if 
		flag = dfs(ai,aj-1);//左 
		
	if(ai!=H-1)
		flag = dfs(ai+1,aj);//下 
			
	if(aj!=W-1)
		flag = dfs(ai,aj+1);//右 

	path = max(path,pathcop);				//这句其实鸡肋 
	return false;
 } 

int main()
{
	while(cin>>W>>H&&(W||H)){
	
	pathcop = path = 0;
	int ati,atj;
	for(int i = 0; i<H; i++)
		for(int j = 0; j<W; j++)
			{
				cin>>maze[i][j].bit;
				maze[i][j].isNew = true;
				if(maze[i][j].bit=='@')
				{
					ati = i;
					atj = j;
				}
			
			}
	dfs(ati,atj);
	cout<<path<<endl;
			
	}
	return 0;
}
