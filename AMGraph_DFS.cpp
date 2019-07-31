#include <iostream>
#include "AMGraph_Create.cpp"

void DFS(AMGraph & G, bool * flag, int v)
{
	cout << v << " ";
	flag[v] = true;
	for(int k = 0; k < G.vexnum; k++){
		if(!flag[k] && G.arcs[v][k] != INF){
			DFS(G, flag, k);
		}
	}
}

void solve()
{
	AMGraph G;
	CreateUDN(G);
	bool flag[MAX_SIZE];
	for(int i = 0; i < G.vexnum; i++)
		flag[i] = false;
	DFS(G, flag, 0);
}
