#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class SqList{
public:
	SqList(int max_size = 64);			// 构造函数 
	SqList(const SqList & L);			// 拷贝构造函数 
	~SqList();							// 析构函数
	void Create(int length);			// 创建顺序表 
	bool Insert(int i, int e);			// 插入元素
	bool Delete(int i, int & e);		// 删除元素 
	int LocateElem(int e) const;		// 定位元素位置 
	void Display() const;				// 打印 
	void Sort(int low, int high);		// 排序 
	bool Del_Min(int & e);				// 从顺序表删除最小的元素, 并将最后位置的元素放在首位
	bool Del_S_T(int low, int end);		// 删除[low, end]区间的值 
	bool Del_X(int e);					// 删除顺序表中所有值为x的值
	bool Del_Same();					// 删除有序表中重复的值 
	void Reverse();						// 元素逆置
	void Test();						// 测试函数
	void Combine(SqList & L);			// 将两个有序表合成一个有序表
	int Binary_Search(int low, int high, int sea) const;// 二分查找 
private:
	int * data;
	int length;
	int max_size;
	void ChangeMaxSize(int new_maxsize);	// 动态修改数组大小
	void QuickSort(int low, int high); 
};

SqList::SqList(int max_size)
{
	// 初始化 
	data = new int[max_size];
	this->length = 0;
	this->max_size = max_size;
}

SqList::SqList(const SqList & L)
{
	// 拷贝构造函数 
	this->data = new int [L.max_size];
	this->length = L.length;
	this->max_size = L.max_size;
	for(int i = 0; i < length; i++)
		this->data[i] = L.data[i];
}

SqList::~SqList()
{
	// 删除数组 
	delete[] data;
	data = NULL;	
}

void SqList::Create(int length)
{
	if(length > max_size) 
		ChangeMaxSize(length);
		
	for(int i = 0; i < length; i++)
		cin >> this->data[i];
	this->length = length;
}

void SqList::ChangeMaxSize(int new_maxsize)
{
	// 按照new_maxsize长度开辟新数组空间 
	int * new_data = new int[new_maxsize];
	for(int i = length - 1; i >= 0; i--){
		new_data[i] = data[i];
	}
	
	int * temp = data;
	data = new_data;
	delete []temp;
}
 
bool SqList::Insert(int i, int e)
{
	// 插入函数 
	if(i < 0 || i > length + 1)
		return false;
	if(length >= max_size)
		ChangeMaxSize(max_size * 2); 	// length > max_size, 扩充至2 * max_size 
	for(int k = length; k >= i; k--)
		data[k] = data[k-1];
	data[i-1] = e;
	length++;
	return true;
}

bool SqList::Delete(int i, int & e)
{
	if(i < 1 || i > length)
		return false;
	if(length < max_size / 2)	// length < max_size, 缩减至max_size / 2 
		ChangeMaxSize(max_size / 2);
	e = data[i-1];
	for(int k = i; k < length; k++)
		data[k-1] = data[k];
	length--;
	return true;
}

int SqList::LocateElem(int e) const
{
	// 按值索引 
	int k = 0;
	while(k < length && data[k] != e)	k++;
	if(k == length)
		return -1;
	else
		return k+1;
}

void SqList::Display() const
{
	for(int i = 0; i < length; i++)
		cout << data[i] << " ";
	cout << endl;
}

bool SqList::Del_Min(int & e)
{ 
	if(!length)
		return false;
		
	int Min_index = 0;
	
	// 查找最小元素位置 
	for(int i = 0; i < length; i++){
		if(data[i] < data[Min_index])
			Min_index = i;
	}
	
	// 最小元素与末尾元素交换位置 
	swap(data[length-1], data[Min_index]);
	e = data[length-1];
	length--;
}

void SqList::Reverse()
{
	// 将数组的前半段与后半段交换 
	for(int i = 0; i < length / 2; i++){
		swap(data[i], data[length - i - 1]);
	}
}

bool SqList::Del_X(int e)
{
	if(!length)
		return false;
	// 删除所有值为x的元素 
	int k = 0;
	for(int i = 0; i < length; i++){
		if(data[i] != e){
			data[k++] = data[i];
		}
	}
	length = k;
	return true;
}

void SqList::QuickSort(int low, int high)
{	
	if(low < high){
		int pivot = (rand() % (high-low+1)) + low;	// 随机化pivot 
		swap(data[pivot], data[low]);
		
		int random_pivot = data[low];
		
		int p1 = low, p2 = high;
		while(p1 < p2){
			while(p1 < p2 && data[p2] >= random_pivot) 
				p2--;
			swap(data[p2], data[p1]);
			while(p1 < p2 && data[p1] <= random_pivot)
				p1++;
			swap(data[p1], data[p2]);
		}
		QuickSort(low, p1-1);
		QuickSort(p1+1, high);
	}
}

void SqList::Sort(int low, int high)
{
	QuickSort(low, high);
}

bool SqList::Del_S_T(int low, int high)
{
	if(low > high || length == 0)
		return false;
	int k = 0;
	for(int i = 0; i < length; i++)
	{
		// 与Del_Min差距在于判断条件 
		if(!(data[i] >= low && data[i] <= high)){
			data[k++] = data[i];
		}
	}
	length = k;
	return true;
}

bool SqList::Del_Same()
{
	// 删除相同值, 先排序, 后设置两个指针扫描数组 
	if(length <= 0)
		return false;
	Sort(0, length - 1);
	
	int k = 0;
	for(int j = 1; j < length; j++){
		if(data[k] != data[j]){
			data[++k] = data[j];
		}
	}
	
	length = k + 1;
	return true;
}

void SqList::Combine(SqList & L)
{
	// 将两个顺序表排序 
	this->Sort(0, this->length - 1);
	L.Sort(0, L.length - 1);
	
	int * new_data = new int[this->length + L.length];
	
	int p1 = 0;
	int p2 = 0;
	
	int k = 0;
	while(p1 < this->length && p2 < L.length){
		if(this->data[p1] < L.data[p2]){
			new_data[k++] = this->data[p1++];
		}
		else{
			new_data[k++] = L.data[p2++];
		}
	}
	
	while(p1 < this->length){
		new_data[k++] = this->data[p1++];
	}
	while(p2 < L.length){
		new_data[k++] = L.data[p2++];
	}
	
	int * temp = data;
	this->data = new_data;
	this->length = this->length + L.length;
	delete[] temp;
}

int SqList::Binary_Search(int low, int high, int sea) const
{
	int i = low, j = high;
	while(i <= j){
		int mid = (low + high) / 2;
		if(data[mid] == sea)
			return mid + 1;
		else if(data[mid] > sea)
			high = mid - 1;
		else
			low = mid + 1; 
	}
	return -1;
}

void SqList::Test()
{	
	int len;
	cout << "Input the length of sequential list:";
	cin >> len;
	cout << endl <<"Input data:";
	Create(len);
	
	cout << endl << "0. exits" << endl << "1. Insert" << endl << "2. Delete" <<  endl << "3. LocateElem" \
	<< endl << "4. Display" << endl << "5. Del_Min" << endl << "6. Reverse" << endl << "7. Del_X" \
	<< endl << "8. Sort" << endl  << "9. Del_S_T" << endl << "10. Del_Same" << endl << "11. Combine" << endl << \
	"12. Binary_Search" << endl;
	
	int flag = true;
	while(true)
	{
		int id;
		if(!flag)
			break;
		cin >> id;
		switch(id){
			case 0:{
				flag = false;
				break;
			}
			case 1:{
				int i, element;
				cout <<"Input location, element:";
				cin >> i >> element;
				if(Insert(i, element))
					cout << endl << "Sucessful" << endl;
				else
					cout << endl << "Fail" << endl;
				break;
			}
			case 2:{
				int i, element;
				cout << "Input location:";
				cin >> i;
				if(Delete(i, element))
					cout << endl << "Sucessful" << endl;
				else
					cout << endl <<"Fail" << endl;
				break;
			}
			case 3:{
				int element;
				cout <<"Input element:";
				cin >> element;
				cout << endl << LocateElem(element) << endl;
				break;
			}
			case 4:{
				Display();
				break; 
			}
			case 5:{
				int element;
				cout << "Input element:";
				cin >> element;
				Del_Min(element);
				cout << endl << element << endl;
				break;
			}
				
			case 6:{
				Reverse();
				cout << "Successful" << endl;
				break;
			}
			case 7:{
				int element;
				cout << "Input element:";
				cin >> element;
				if(Del_X(element))
					cout << endl << "Successful" << endl;
				else
					cout << endl << "Fail" << endl;
				break;
			}
			case 8:{
				srand(time(0));
				Sort(0, length - 1);
				cout << "Successful" << endl;
				break;
			}
			case 9:{
				int value1, value2;
				cout << "Input low_value, high_value2:";
				cin >> value1 >> value2;
				if(Del_S_T(value1, value2))
					cout << endl << "Successful" << endl;
				else
					cout << endl << "Fail" << endl;
			}
			case 10:{
				if(Del_Same())
					cout << endl << "Successful" << endl;
				else
					cout << endl << "Fail" << endl;
				break;
			}
			case 11:{
				SqList L2;
				int length;
				cout << "Create new SequenceList, Input length:";
				cin >> length;
				cout << endl << "Input data:";
				L2.Create(length);
				Combine(L2);
				cout << endl << "Successful" << endl;
				break;
			}	
			case 12:{
				int element;
				cout << "Input Element to Search:";
				cin >> element;
				
				int res = Binary_Search(0, length - 1, element);
				if(!res)
					cout << endl << "Not Found" << endl;
				else
					cout << endl << res << endl;
				break;
			}
		}
	}
}

int main()
{
	SqList L1;
	L1.Test();
 } 
