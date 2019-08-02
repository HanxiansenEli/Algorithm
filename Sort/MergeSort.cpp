#include <iostream>

using namespace std;

const int MAX_SIZE = 64;

struct Elem{
	int key;	// 关键字 
};

// 开辟新数组 
Elem temp[MAX_SIZE];

void Merge(Elem A[], int low, int mid, int high)
{
	for(int k = low; k <= high; k++)
		temp[k] = A[k];
		
	int i = low, j = mid + 1, k = i;
	
	while(i <= mid && j <= high){
		if(temp[i].key <= temp[j].key)
			A[k++] = temp[i++];
		else
			A[k++] = temp[j++];
	}
	
	// 剩余A或B有一个还有剩余元素
	while(i <= mid)
		A[k++] = temp[i++];
	while(j <= high)
		A[k++] = temp[j++];
}

void MergeSort(Elem A[], int low, int high)
{
	if(low < high){
		int mid = (low + high) / 2;
		MergeSort(A, low, mid);
		MergeSort(A, mid + 1, high);
		Merge(A, low, mid, high);
	}
}

void solve()
{
	Elem A[MAX_SIZE];
	
	int T[] = {46,38,19,45,55,92,24,46,90,23,13,199,234,123,487,617};
	int len = sizeof(T)/sizeof(int);
	
	for(unsigned int i = 0; i < len; i++)
		A[i].key = T[i];
	
	MergeSort(A, 0, len - 1);
	for(unsigned int i = 0; i < len; i++)
		cout << A[i].key << " ";
}

int main()
{
	solve();
 } 
