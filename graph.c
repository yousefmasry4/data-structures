#include <stdio.h>
#include <stdlib.h>

struct adjlistnode{
	int dast;
	struct adjlistnode *next;
};
struct adjlist{
	struct adjlistnode *head;
};
struct graph{
    int v;
	struct adjlist *arr;
};
struct adjlistnode* newadlist(int dast){
	struct adjlistnode* new=(struct adjlistnode*)malloc(sizeof(struct adjlistnode));
	new->dast=dast;
	new->next=NULL;
	return new;
}
struct graph* creatgraph(int v){
	struct graph* graph=(struct graph*)malloc(sizeof(struct graph));
	graph->v=v;
	graph->arr=(struct adjlist*)malloc(v * sizeof(struct adjlist));
	for(int i=0 ;i<v;i++){
		graph->arr[i].head=NULL;
	}
	return graph;
}
void addedge(struct graph* graph,int src,int dest){
	struct adjlistnode* new=newadlist(dest);
	new->next=graph->arr[src].head;
	graph->arr[src].head=new;

	new=newadlist(src);
	new->next=graph->arr[dest].head;
	graph->arr[dest].head=new;
}
void printgraph(struct graph* graph){
	for(int i=0;i< graph->v;i++){
		struct adjlistnode* new=graph->arr[i].head;
		printf("%d",i);
		while(new){
			printf("->%d",new->dast);
			new=new->next;
		}
		printf("\n-----------------------------------\n");
	}
}
int git(struct graph* graph,int v,int s,int x,int c,int www){
	int pre=0;
	struct adjlistnode* new=graph->arr[v].head;
	 //   printf("main = %d\n",v);
        while(new && x == 0){
		//	printf("->%d",new->dast);
			if(new->dast == s){
				x=1;
				return 1;
			}
			pre=new->dast;
			break;
			}
			c++;
			if(x == 0 && c < www){
				return git(graph,pre,s,x,c,www);
			}
}
int main(){
	int z,y,x,v,m,s;
	scanf("%d",&v);
	scanf("%d",&x);
	struct graph* graph=creatgraph(v);
    for(int i=0;i<x;i++){
		scanf("%d %d",&m,&y);
		addedge(graph,m,y);
	}
	scanf("%d %d",&y,&s);
	printgraph(graph);
	int ans=git(graph,y,s,0,0,x);
	(ans == 2)?printf("no"):printf("yes");
}
