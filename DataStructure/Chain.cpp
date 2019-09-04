#include <iostream>
#include <fstream>

using namespace std;

struct Node{
	int data;
	struct Node * next;
};

class Chain{
public:
	Chain();									// 构造函数
	Chain(const Chain & L);						// 拷贝构造函数 
	~Chain();									// 析构函数 
	void Create_front();						// 前插法创建链表
	void Create_rear();							// 后插法创建链表
	bool GetElem(int i, int & element) const;   // 获取第i个元素
	int  LocateElem(int values) const;          // 获取values值的位置
	bool Insert(int i, int element);    		// 插入
	bool Delete(int i, int & element);          // 删除
	void Display();                        		// 打印
	
	void Reverse();								// 逆置 
	void Test();								// 测试 
private:
	Node * head;
	int length;
};

Chain::Chain()
{
	head = new Node;
	head->next = NULL;
	length = 0;
}

Chain::Chain(const Chain & L)
{
	Node * p = this->head->next;
	Node * q = L.head;
	while(p != NULL){
		Node * s = new Node;
		s->data = p->data;
		q->next = s;
		q = s;
	}
	q->next = NULL;
} 


Chain::~Chain()
{
	Node * p = head->next;
	while(p != NULL){
		Node * temp = p;
		p = p->next;
		delete[]temp;
	}
}

void Chain::Create_front()
{
	ifstream fin;
	fin.open("data.txt", ios::in);  // 数据存储在data.txt文本中
 
	int temp;
	Node * p = head;
	while (fin >> temp)
	{
		Node * q = new Node;
		q->data = temp;
		q->next = p->next;
		p->next = q;
		length++;                 // 计数
	}
	fin.close();
} 

void Chain::Create_rear()
{
	ifstream fin;
	fin.open("data.txt", ios::in);
 
	int temp;
	Node * p = head;
	while (fin >> temp)
	{
		Node * q = new Node;
		q->data = temp;
		q->next = NULL;
		p->next = q;
		p = q;
		length++;
	}
	fin.close();
}

bool Chain::GetElem(int i, int & element) const
{
	if (i > length || i <= 0)
		return false;
 
	Node * p = head->next;
	for (int i = 0; i < i - 1; ++i)
		p = p->next;
	element = p->data;
	return true;
}

int Chain::LocateElem(int values) const
{
	int i = 0;
	Node * p = head;
	while (p && p->data != values)
	{
		p = p->next;
		i++;
	}
	if (i > length + 1)
		return -1;
	return i;
}

bool Chain::Insert(int i, int element)
{
	if (i < 0 || i > length + 1)
		return false;
 
	Node * p = head;
	int ret = 1;
	while (p && ret < i)
	{
		p = p->next;
		ret++;
	}
 
	Node * q = new Node;
	q->data = element;
	q->next = p->next;
	p->next = q;
	length++;
	return true;
}

bool Chain::Delete(int i, int & element)
{
	if (i < 0 || i > length){
		return false;
	}
 
	Node * p = head;
	int ret = 0;
 
	while (p->next && ret < i - 1)
	{
		p = p->next;
		ret++;
	}
 
	Node * q = p->next;
	p->next = q->next;
	element = q->data;
	delete q;
	length--;
	return true;
}

void Chain::Display()
{
	Node * p = head->next;
	while(p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}


void Chain::Test()
{
	int id;
	cout << "1. front_create" << endl << "2.rear_create" << endl;
	cin >> id; 
	cout << "Input data:";
	if(id == 1)
		Create_front();
	else
		Create_rear();
	
	cout << endl << "0. exit" << endl << "1. GetElem" << endl << "2. Insert" \
	<< endl << "3. Delete" << endl << "4. Display" << endl;
	int flag = true;
	while(true){
		if(!flag)
			break;
		int id;
		cin >> id;
		switch(id){
			case 0:{
				flag = false;
				break;
			}
			case 1:{
				int element, i;
				cout << "Input the location:";
				cin >> i;
				if(!GetElem(i, element))
					cout << endl << "Not Found" << endl;
				else
					cout << endl << element << endl;
				break;
			}
			case 2:{
				int element, i;
				cout << "Input location and element:";
				cin >> i >> element;
				if(Insert(i, element))
					cout << endl << "Successful" << endl;
				else
					cout << endl << "Fail" << endl;
				break;
			}
			case 3:{
				int element, i;
				cout << "Input location:";
				cin >> i;
				if(Delete(i, element))
					cout << endl << "Successful" << endl;
				else
					cout << endl << "Fail" << endl;
				break;
			}
			case 4:{
				Display();			
				break;
			}
		}
	}
}

int main()
{
	Chain C;
	C.Test();
}
