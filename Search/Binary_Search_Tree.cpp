#include <iostream>

using namespace std;

struct BSTNode{
	int key;
	BSTNode *lchild, *rchild;
};

// 递归插入
bool BSTInsert1(BSTNode ** T, int key)
{
	if(*T == NULL)
	{
		BSTNode * s = new BSTNode;
		s->key = key;
		s->lchild = s->rchild = NULL;
		*T = s;
	}
	if(key == (*T)->key)
		return false;
	if(key < (*T)->key)
		return BSTInsert1( &((*T)->lchild), key);
	if(key > (*T)->key)
		return BSTInsert1( &((*T)->rchild), key);
    return true;
}

// 非递归插入
bool BSTInsert2(BSTNode ** T, int key)
{
	BSTNode * p = *T;
	BSTNode * q = NULL;
	BSTNode * s = new BSTNode;

	s->key = key;
	s->lchild = s->rchild = NULL;

	// 定位到待插入结点
	while(p != NULL)
	{
		q = p;
		if(key < p->key)
			p = p->lchild;
		else if(key > p->key)
			p = p->rchild;
		else
			return false;
	}

	if(q == NULL)	// 树空
		*T = s;
	else if(s->key < q->key)
		q->lchild = s;
	else
		q->rchild = s;
    return true;
}

// 创建二叉排序树
void BSTCreate(BSTNode ** T)
{
	*T = NULL;
	int key;
	while(cin >> key)
		BSTInsert2(T, key);
}

// 查找递归
BSTNode * BSTSearch1(BSTNode * T, int key)
{
	if(T == NULL || T->key == key)
		return T;
	if(key < T->key)
		return BSTSearch1(T->lchild, key);
	else
		return BSTSearch1(T->rchild, key);
}

// 查找非递归
BSTNode * BSTSearch2(BSTNode * T, int key)
{
	BSTNode * p = T;
	while(p != NULL && p->key != key)
	{
		if(key < p->key)
			p = p->lchild;
		else
			p = p->rchild;
	}
	return p;
}

// 寻找最大关键字元素
BSTNode * BSTMax(BSTNode * T)
{
	if(T == NULL)
		return T;
	BSTNode * p = T;
	while(p->rchild != NULL)
		p = p->rchild;
	return p;
}

// 寻找最小关键字元素
BSTNode * BSTMin(BSTNode * T)
{
	if(T == NULL)
		return T;
	BSTNode * p = T;
	while(p->lchild != NULL)
		p = p->lchild;
	return p;
}

// 删除
bool BSTDelete(BSTNode ** T, int key)
{
	BSTNode ** p = T;
	BSTNode * f = NULL;

	// p指针定位到待删除结点
	while(*p && (*p)->key != key)
	{
		f = (*p);
		if((*p)->key < key)
			p = &((*p)->rchild);
		else
			p = &((*p)->lchild);
	}

	// 没找到
	if(p == NULL)
		return false;

	BSTNode * q = *p;
	// 情况一: p的左右子树都不为空
	if(((*p)->lchild) && ((*p)->rchild))
	{
		// p结点: 待删除结点
		// s结点：替换待删除结点
		// q结点: 替换待删除结点的父结点

		BSTNode * s = (*p)->lchild;
		// 在待删除结点的左子树中查找直接前驱, 也就是最右下角结点
		// 当然咯, 也可以找直接后继, 就是s->lchild
		while(s->rchild)
		{
			q = s;
			s = s->rchild;
		}

		(*p)->key = s->key; // 替换待删除结点

		if(q != (*p))
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		delete s;

		return true;
	}

	 // 情况二: 若被删除结点没有左子树或右子树, 则将左子树或者右子树直接
	 // 插到被删除结点的父节点处
	else if((*p)->rchild && (*p)->lchild == NULL){
		if(f->rchild->key == (*p)->key)
			f->rchild = (*p)->rchild;
		else
			f->lchild = (*p)->rchild;
	}
	else if((*p)->lchild && (*p)->rchild == NULL){
		if(f->rchild->key == (*p)->key)
			f->rchild = (*p)->lchild;
		else
			f->lchild = (*p)->lchild;
	}

	// 情况三: 被删除结点是叶子结点
	else{
		if(f == NULL)		// 如果是根节点
			T = NULL;
	}

	delete q;

	return true;
}

int main()
{
    /*
	// 64 45 88 36 47 78 99 38 52 37 50
	BSTNode * T;
	BSTCreate(&T);
	BSTNode * res = BSTSearch2(T, 100);
	if(res == NULL) cout << "Not found";
	else			cout << res->key;

	cout << BSTDelete(&T, 52) << endl;
	BSTNode * res = BSTSearch1(T, 52);
	cout << res->key;
	*/
}
