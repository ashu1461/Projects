// this is the first code where i am going to use the concepts of 
// vectors and queue ! :D
#include<stdio.h>
#include<string.h>
// include the libraries ! 
#include<vector>
#include<queue>
// the using one is only for like using import.function or simply function
using namespace std;
int visited[2000];
int color[2000];
// this is how we define the vectors ! :D ! 
queue <int>q;
vector <int>v[2000];
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
//			printf("for eightbour --> %d for k--> %d\n",u,k);
			if(color[u]==color[k]){
//	printf("same color -- %d %d\n",u,k);
		flag=0;
			//	return 0;
			}
			if(visited[u]==0){
				visited[u]=1;
				color[u]=3-color[k];
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
	scanf("%d",&test);
	for(hell=1;hell<=test;hell++){
		// do the stuff here ! 
		int a ,i;
		int b;
		
		scanf("%d %d",&a,&b);
		for(i=0;i<a;i++)
			v[i].clear();
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
		memset(visited,0,4*a);
		memset(color,0,4*a);
/*		for(i=0;i<a+1;i++){
			printf("printfing for %d ",i);
		print(i);
		}*/
		int flag=1;
		for(i=0;i<a;i++){
			if(visited[i]==0)
			if(check(i)==0){
//				printf("here for %d\n",i);
				flag=0;
		 	//	break;
			}
		}
		if(flag==0)
			printf("Scenario #%d:\nSuspicious bugs found!\n",hell);
		else
			printf("Scenario #%d:\nNo suspicious bugs found!\n",hell);
		}
}
