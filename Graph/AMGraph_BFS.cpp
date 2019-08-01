#include <iostream>
#include <queue>
#include "AMGraph_Create.cpp"

void BFS(AMGraph & G, int v)
{
	int distance[MAX_SIZE]; // 路径距离
	queue<int> que;

	for(int i = 0; i < G.vexnum; i++)
		distance[i] = INF;

	que.push(v);
	distance[v] = 0;
	cout << "Path:"<< v << " ";	// 输出起始点 

	while(!que.empty()){
		int cur = que.front();
		que.pop();

		for(int k = 0; k < G.vexnum; k++){
				if(G.arcs[cur][k] != INF && distance[k] == INF){
					cout << k << " ";
					distance[k] = distance[cur] + 1;
					que.push(k);
				}
			}
		}

	cout << endl << "Min_distance:";
	for(int i = 0; i < G.vexnum; i++)
		cout << distance[i] << " ";
}

void solve()
{
	AMGraph G;
	CreateUDN(G);
	BFS(G, 0);
}

