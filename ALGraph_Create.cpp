#include <iostream>

using namespace std;

// 边表
struct ArcNode{
	int adjvex;
	struct ArcNode * nextarc;
	int weight;
};

// 顶点表
struct VNode{
	int data;
	ArcNode * firstarc;
};

// 邻接链表
struct ALGraph{
	VNode vertices[MAX_SIZE];
	int vexnum, arcnum;
};

// 创建邻接链表
void CreateUDG(ALGraph & G, bool flag = false)
{
	// flag = false, 创建有向图
	// flag = true, 创建无向图 
	cin >> G.vexnum >> G.arcnum;
	for(int i = 0; i < G.vexnum; ++i){
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	for(int k = 0; k < G.arcnum; ++k){
		int i, j, weight;
		cin >> i >> j >> weight;
		struct ArcNode * p = new ArcNode;
		struct ArcNode * q = new ArcNode;
		p->adjvex = j;
		p->weight = weight;
		p->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p;
		
		if(flag)
		{
			q->adjvex = i;
			q->weight = weight;
			q->nextarc = G.vertices[j].firstarc;
			G.vertices[j].firstarc = q;
		}
	}
}
