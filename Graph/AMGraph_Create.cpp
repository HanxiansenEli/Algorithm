#include <iostream>

using namespace std;

const int MAX_SIZE = 64;
const int INF = 32767;

// 邻接矩阵
struct AMGraph{
	int vexs[MAX_SIZE];
	int arcs[MAX_SIZE][MAX_SIZE];
	int vexnum, arcnum;
};

// 创建邻接矩阵
void CreateUDN(AMGraph & G, bool flag = false)
{
	// flag = false, 创建有向图
	// flag = true, 创建无向图 
	cin >> G.vexnum >> G.arcnum;
	for(int i = 0; i < G.vexnum; ++i){
		cin >> G.vexs[i];
	}

	for(int i = 0; i < G.vexnum; i++)
		for(int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = INF;

	for(int k = 0; k < G.arcnum; k++){
		int i, j, weight;
		cin >> i >> j >> weight;
		G.arcs[i][j] = weight;
		
		if(flag)
			G.arcs[j][i] = weight;
	}
}

