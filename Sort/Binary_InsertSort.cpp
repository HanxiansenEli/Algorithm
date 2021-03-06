。c#include <iostream>

using namespace std;

const int MAX_SIZE = 64;

struct Elem{
	int key;	// 关键字 
};

void InsertSort(Elem A[], int len)
{
	for(int i = 2; i < len; i++)
	{
		A[0] = A[i];
		int low = 1, high = i - 1;	// i-1之前的元素有序
		while(low <= high){
			int mid = (low + high) / 2;
			if(A[mid].key > A[0].key) high = mid - 1;
			else	low = mid + 1;
		}
		for(int j = i-1; j >= high + 1; --j)
			A[j+1] = A[j];
		A[high+1] = A[0];
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
 
