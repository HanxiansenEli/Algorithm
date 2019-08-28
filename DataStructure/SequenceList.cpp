#include <iostream>

using namespace std;

class SqList{
public:
	SqList(int max_size = 64);
	void CreateSqList(int length);	// 创建顺序表 
	bool ListInsert(int i, int e);	// 插入元素 
	bool ListDelete(int i, int & e);	// 删除元素 
	int LocateElem(int e) const;		// 定位元素位置 
	void Display() const;				// 显示函数
	
private:
	int * data;
	int length;
	int max_size;
	void ChangeMaxSize(int new_maxsize);	// 动态修改数组大小 
};

SqList::SqList(int max_size)
{
	data = new int[max_size];
	this->length = 0;
	this->max_size = max_size;
}

void SqList::CreateSqList(int length)
{
	if(length > max_size)
		ChangeMaxSize(length * 2);
		
	for(int i = 0; i < length; i++)
		cin >> this->data[i];
	
	this->length = length;
}

void SqList::ChangeMaxSize(int new_maxsize)
{
	int * new_data = new int[new_maxsize * 2];
	for(int i = length - 1; i >= 0; i--){
		new_data[i] = data[i];
	}
	
	int * temp = data;
	data = new_data;
	delete []temp;
}

bool SqList::ListInsert(int i, int e)
{
	if(i < 1 || i > length + 1)
		return false;
	if(length >= max_size)
		ChangeMaxSize(max_size * 2);
	for(int k = length; k >= i; k--)
		data[k] = data[k-1];
	data[i-1] = e;
	length++;
	return true;
}

bool SqList::ListDelete(int i, int & e)
{
	if(i < 1 || i > length)
		return false;
	if(length < max_size / 2)
		ChangeMaxSize(max_size / 2);
	e = data[i-1];
	for(int k = i; k < length; k++)
		data[k-1] = data[k];
	length--;
	return true;
}

int SqList::LocateElem(int e) const
{
	int k = 0;
	while(k < length && data[k++] != e);
	if(k == length)
		return -1;
	else
		return k + 1;
}

void SqList::Display() const
{
	for(int i = 0; i < length; i++)
		cout << data[i] << " ";
}

bool SqList::Del_Min(int & e)
{
	if(!length)
		return false;
		
	int Min_index = 0;
	for(int i = 0; i < length; i++){
		if(data[i] < data[Min_index])
			Min_index = i;
	}
	swap(data[length-1], data[Min_index]);
	e = data[length-1];
	length--;
}

void SqList::Reverse()
{
	for(int i = 0; i < length / 2; i++){
		swap(data[i], data[length - i - 1]);
	}
}

int main()
{
	// 1 2 3 4 5 6 7 8 9 10
	int element;
	SqList L(9);
	L.CreateSqList(10);
	// L.ListInser(10, 3);
	// L.ListDelete(1, element);
	// L.Del_Min(element);
	// cout << element << endl;
	// L.Reverse();
	L.Display();
 } 
