#include <iostream>

using namespace std;

const int MAX_SIZE = 64; 

struct Elem{
	int key;	// 关键字 
};

void InsertSort(Elem A[], int len)
{
	for(int i = 2; i < len; i++){
		// 若待插入元素比有序序列最后一个元素大, 则无需插入 
		if(A[i].key < A[i-1].key){
			A[0] = A[i];	// 放置哨兵 
			int j = i - 1; 
			for(; A[0].key < A[j].key; --j)	// 从有序序列末端扫描 
				A[j+1] = A[j];
			A[j+1] = A[0]; 
		}
	}
}

void solve()
{
	Elem A[MAX_SIZE];
	int T[] = {5, 2, 4, 6, 4, 1, 3, 2, 4 ,6 ,11, 23, 12, -99};
	int len = sizeof(T)/sizeof(int);
	
	for(unsigned int i = 0; i < len; i++)
		A[i+1].key = T[i];
	
	InsertSort(A, len + 1);
	for(unsigned int i = 1; i < len; i++)
		cout << A[i].key << " ";
}

int main()
{
	solve();
 } 
 
