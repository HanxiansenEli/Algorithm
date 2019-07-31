#include <iostream>

using namespace std;

const int MAX_SIZE = 64;
const int INF = 32767;

struct SSTable{
	int elem[MAX_SIZE];
	int table_len;
};
 
int Search_Seq(SSTable & ST, int key)
{
	int lo;
	ST.elem[0] = key;	// 设置哨兵
	for(lo = ST.table_len; ST.elem[lo] != key; lo--);
	return lo;
}

void solve()
{
	/*测试样例 
		7 9
		2 1 4 6 7 3 5
	*/ 
	
	SSTable ST;
	int key;
	cin >> ST.table_len >> key;	// 输入数组长度和关键字 
	for(int i = 1; i <= ST.table_len; i++)
		cin >> ST.elem[i];
		
	int res = Search_Seq(ST, key);
	if(res)	cout << res;
	else	cout << "Not found" << endl;
}

int main()
{
	solve();
}
