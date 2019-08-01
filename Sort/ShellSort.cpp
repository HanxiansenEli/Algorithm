#include <iostream>

using namespace std;

const int MAX_SIZE = 64;

struct Elem{
	int key;	// 关键字 
};

void ShellSort(Elem A[], int len)
{
	for(int d = len / 2; d >= 1; d /= 2){
		for(int i = d + 1; i <= len; i++){
			if(A[i].key < A[i-d].key){
				A[0] = A[i];
				int j = i - d;
				for(; j > 0 && A[0].key < A[j].key; j -= d)
					A[j+d] = A[j];
				A[j+d] = A[0];
			}
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
	
	ShellSort(A, len + 1);
	for(unsigned int i = 1; i < len; i++)
		cout << A[i].key << " ";
}

int main()
{
	solve();
} 

