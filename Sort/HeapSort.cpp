#include <iostream>

using namespace std;

const int MAX_SIZE = 64;

struct Elem{
	int key;	// 关键字 
};

// 维护堆的性质递归算法 
void MaxHeap1(Elem A[], int k, int len)
{
    int largest;
    int left = k * 2 + 1;	// 左孩子结点 
    int right = k * 2 + 2;	// 右孩子结点 
 
    if(left <= len && A[k].key < A[left].key)
        largest = left;
    else
        largest = k;
    if(right <= len && A[largest].key < A[right].key)
        largest = right;
    if(k != largest)
    {
        swap(A[k].key, A[largest].key);
        MaxHeap1(A, largest, len);
    }
}

// 维护堆的性质非递归算法  
void MaxHeap2(Elem A[], int k, int len)
{
	Elem temp = A[k];
	for(int i = 2 * k; i <= len; i *= 2)
	{
		// 如果该结点的左孩子小于该结点的右孩子 
		if(i < len && A[i].key < A[i+1].key) i++;
		
		if(temp.key >= A[i].key) break;	 // 该结点左右孩子都小于该结点, 满足堆的性质, 跳出循环 
		else{
			A[k] = A[i];		// 	不满足, 则将左(右)孩子结点与根节点进行交换 
			k = i;				//	此时被交换的孩子结点可能不满足堆的性质, 进行循环遍历 
		}
	}
	A[k] = temp; 
}

// 建堆
void BuildMaxHeap(Elem A[], int len)
{
	for(int k = len / 2; k > 0; k--)
		MaxHeap1(A, k - 1, len - 1); 
}

// 堆排序 
void HeapSort(Elem A[], int len)
{
	BuildMaxHeap(A, len);
	// 每次堆中取出最大元素(A[0]), 再维护堆的性质 
	for(int i = len - 1; i > 0; i--)
	{
		swap(A[i], A[0]);
		len--;
		MaxHeap1(A, 0, len - 1);
	}
}

void solve()
{
	Elem A[MAX_SIZE];
	
	int T[] = {46,38,19,45,55,92,24,46,90,23,13,199,234,123,487,617};
	int len = sizeof(T)/sizeof(int);
	
	for(unsigned int i = 0; i < len; i++)
		A[i].key = T[i];
	
	HeapSort(A, len - 1);
	for(unsigned int i = 0; i < len; i++)
		cout << A[i].key << " ";
}

int main()
{
	 solve();
}
