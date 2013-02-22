// this is the first code where i am going to use the concepts of 
// vectors and queue ! :D
#include<stdio.h>
#include<string.h>
// include the libraries ! 
#include<vector>
#include<queue>
// the using one is only for like using import.function or simply function
using namespace std;
int visited[10002];
int color[10002];
int parent[10002];
// this is how we define the vectors ! :D ! 
queue <int>q;
vector <int>v[10002];
int check(int k){
//	printf("enterinf gor --> %d\n ",k);
	visited[k]=1;
	color[k]=1;
	q.push(k);
	int i;
	int flag=1;
	while(!q.empty()){
		k=q.front();
		q.pop();
//		printf("entering -- >%d\n",k);
		for(i=0;i<v[k].size();i++){
			int u=v[k][i];
			// what to do ???????
			if(visited[u]==0){
			parent[u]=parent[k]+1;
//			printf("for eightbour --> %d for k--> %d value of u --> %d\n",u,k,parent[u]);
				visited[u]=1;
//				color[u]=3-color[k];
				q.push(u);
			}
		}
	}
	return flag;
}

// c++ is cool bro ! 
int main(){
	int test;
	int hell;
		// do the stuff here ! 
		int a ,i;
		int b;
		
		scanf("%d",&a);
		for(i=0;i<a;i++)
			v[i].clear();
		b=a-1;
		while(b--){
			int x,y;
			scanf("%d %d",&x,&y);
			// so simply building the link list here ! :D 
			v[x].push_back(y);
			v[y].push_back(x);
		}
		// Now checking for bipartite ! 
		// we have two arrays visited and color thing ! 
		// empty those ! 
		// andd now i am going to use the mmset function which i learned earlier ! :D
		// cool ! 
/*		for(i=0;i<a+1;i++){
			printf("printfing for %d ",i);
		print(i);
		}*/
		int max=0;
		int j;
		for(i=0;i<a;i++){
			memset(visited,0,4*(a+2));
			memset(parent,0,4*(a+2));
			check(i);
			for(j=1;j<a+1;j++){
				if(parent[j]>max)
					max=parent[j];
//			if(visited[i]==0)
//			if(check(i)==0){
//				printf("here for %d\n",i);
//		 	//	break;
//			}
		}
		}
		printf("%d\n",max);
}
