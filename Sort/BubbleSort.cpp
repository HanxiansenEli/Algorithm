#include <iostream>

using namespace std;

const int MAX_SIZE = 64;

struct Elem{
	int key;	// 关键字 
};

void BubbleSort(Elem A[], int len)
{
	for(int i = 0; i < len-1; i++)
	{
		bool flag = false; // 冒泡排序提前终止
		for(int j = len-1; j > i; j--)
		{
			if(A[j-1].key > A[j].key){
				swap(A[j-1], A[j]);
				flag = true;
			}
		 }
		 if(!flag) return;
	} 
}

void solve()
{
	Elem A[MAX_SIZE];
	int T[] = {5, 2, 4, 6, 4, 1, 3, 2, 4 ,6 ,11, 23, 12, -99};
	int len = sizeof(T)/sizeof(int);
	
	for(unsigned int i = 0; i < len; i++)
		A[i].key = T[i];
	
	BubbleSort(A, len);
	for(unsigned int i = 0; i < len; i++)
		cout << A[i].key << " ";
}


int main()
{
	solve();
 } 
