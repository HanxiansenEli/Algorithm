#include <iostream>
using namespace std;

const int MAX_SIZE = 64;

struct Elem{
	int key;	// 关键字 
};

void SelectSort(Elem * A, int len)
{
	for(int i = 0; i < len - 1; i++){
		int min_index = i;
		for(int j = i + 1; j < len; j++){
			if(A[min_index].key > A[j].key) min_index = j;
		}
		if(min_index != i)	swap(A[i], A[min_index]);
	}
}

void solve()
{
	Elem A[MAX_SIZE];
	
	int T[] = {46,38,19,45,55,92,24,46,90,23,13,199,234,123,487,617};
	int len = sizeof(T)/sizeof(int);
	
	for(unsigned int i = 0; i < len; i++)
		A[i].key = T[i];
	
	SelectSort(A, len);
	for(unsigned int i = 0; i < len; i++)
		cout << A[i].key << " ";
}

int main()
{
	solve();
 } 
