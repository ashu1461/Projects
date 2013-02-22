#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> a[100002];
int visited[100002];
//int color[2000];
queue<int> Q;
int bfs(int u)
{
	int flag=1;
	visited[u]=1;
	Q.push(u);
	while(!Q.empty())
	{
		u=Q.front();    
		Q.pop();
		for(int i=0;i<a[u].size();i++) 
		{ int v=a[u][i];
			if(visited[v]==0)
			{ visited[v]=1;
				Q.push(v);
			} 
		}
	}
	return flag;
}
int main()
{
	int N,M,u,v,ans,flag,k;
	int test;
	scanf("%d",&test);
	for(k=1;k<=test;k++)
	{ 
		scanf("%d",&N);
		scanf("%d",&M);
	//	flag=1;
		for(int i=0;i<N;i++) a[i].clear();
		while(M--)
		{
			scanf("%d",&u);
			scanf("%d",&v);
			a[v].push_back(u);
			a[u].push_back(v);
		}
		memset(visited,0,4*N);
	//	memset(color,0,4*N);
		int counter=0;
		for(int i=0;i<N;i++)
		{

			if(visited[i]==0){
				bfs(i);
				counter++;

		}
		}

			printf("%d\n",counter);
	}


}
