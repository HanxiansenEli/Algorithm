#include <iostream>
#include "ALGraph_Create.cpp"


void DFS(ALGraph & G, bool * flag, int v)
{
	cout << v << " ";
	flag[v] = true;
	ArcNode * p = G.vertices[v].firstarc;

	while(p){
		if(!flag[p->adjvex])
			DFS(G, flag, p->adjvex);
		p = p->nextarc;
	}
}

void solve()
{
	ALGraph G;
	CreateUDG(G);
	bool flag[MAX_SIZE];
	
	for(int i = 0; i < G.vexnum; i++)
		flag[i] = false;
	DFS(G, flag, 0);
}

