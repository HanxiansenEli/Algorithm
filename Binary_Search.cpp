#include <iostream>

#define MAX_SIZE 64

using namespace std;

struct SSTable{
	int elem[MAX_SIZE];
	int table_len;
};

int Binary_Search(SSTable & ST, int key)
{
	int low = 1, high = ST.table_len;
	while(low <= high){
		int mid = (low + high) / 2;
		if(ST.elem[mid] == key)
			return mid;
		else if(ST.elem[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}

void solve()
{
	/*测试样例 
		7 17
		1 2 5 9 11 14 17
	*/ 
	
	SSTable ST;
	int key;
	cin >> ST.table_len >> key;	// 输入数组长度和关键字 
	for(int i = 1; i <= ST.table_len; i++)
		cin >> ST.elem[i];

	int res = Binary_Search(ST, key);
	if(res)	cout << res;
	else	cout << "Not found" << endl;
}
