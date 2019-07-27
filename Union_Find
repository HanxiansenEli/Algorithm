#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

// 并查集数据结构 
class Union_Find{
public:
	UF(int N);
	
	// 返回连通分支数
	int connected_count(){
		return count;
	}
	
	// 判断是否连通 
	bool connected(int p, int q){
		return id[p] == id[q];
	}
	int find(int p);
	
	// 合并 
	void union(int p, int q);
private:
	int N;
	int count;
	int * id;
	int * weight;
};

Union_Find::Union_Find(int N): N(N)
{
	count = N;
	id = new int [N];
	weight = new int [N];
	for(int i = 0; i < N; i++){
		id[i] = i;
		weight[i] = 1;
	}
}

int Union_Find::find(int p)
{
	while(p != id[p])
	{
		id[p] = id[id[p]]; // 路径压缩
		p = id[p];
	}
	return p;
}

void Union_Find::union(int p, int q)
{
	int proot = find(p);
	int qroot = find(q);
	if(proot == qroot)
		return;
	
	// 小树向大树靠 
	if(weight[proot] < weight[qroot])
	{
		id[proot] = qroot;
		weight[qroot] += weight[proot];
	}
	else
    {
        id[qroot] = proot;
        weight[proot] += weight[qroot];
    }
    --count;
}
