#include <iostream>
#include <queue>
#include "ALGraph_Create.cpp"

void BFS(ALGraph & G, int v)
{
	int distance[MAX_SIZE];
	queue<int> que;

	for(int i = 0; i < G.vexnum; i++)
		distance[i] = INF;

	que.push(v);
	distance[v] = 0;
	cout << "Path:" << v << " ";

	while(!que.empty()){
		int cur = que.front();
		que.pop();

		ArcNode * p = G.vertices[cur].firstarc;
		while(p){
			if(distance[p->adjvex] == INF){
				cout << p->adjvex << " ";
				distance[p->adjvex] = distance[cur] + 1;
				que.push(p->adjvex);
			}
			p = p->nextarc;
		}
	}

	cout << endl << "Min_distance:";
	for(int i = 0; i < G.vexnum; i++)
		cout << distance[i] << " ";
}


void solve()
{
	ALGraph G;
	CreateUDG(G);
	BFS(G, 0);
}

