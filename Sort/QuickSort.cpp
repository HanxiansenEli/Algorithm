#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE = 64;

struct Elem{
	int key;	// 关键字 
};

void QuickSort(Elem * A, int low, int high)
{
	
	if(low < high)
	{
		int i = low, j = high;
		
		int random_pivot = (rand() % (high-low+1)) + low;	// 加入随机化 
		swap(A[random_pivot], A[low]);
		
		int pivot = A[low].key;
		
		while(i < j){
			while(i < j && A[j].key >= pivot)	
				--j;
			swap(A[i], A[j]);
			while(i < j && A[i].key <= pivot)	// j与pivot位置已经互换 
				++i;
			swap(A[i],A[j]);
		}
		
		QuickSort(A, low, i-1);
		QuickSort(A, i+1, high);	
	}
}

void solve()
{
	Elem A[MAX_SIZE];
	srand(time(0));
	
	int T[] = {46,38,19,45,55,92,24,46,90,23,13,199,234,123,487,617};
	int len = sizeof(T)/sizeof(int);
	
	for(unsigned int i = 0; i < len; i++)
		A[i].key = T[i];
	
	QuickSort(A, 0, len - 1);
	for(unsigned int i = 0; i < len; i++)
		cout << A[i].key << " ";
}

int main()
{
	solve();
 } 
