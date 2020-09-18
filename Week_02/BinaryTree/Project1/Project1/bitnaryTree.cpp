#include "binarytree.h"

using namespace std;
//������
void CreateTree(Bitree& T)
{
	ElemType ch;
	cin >> ch;
	if (ch == '#') {
		T = nullptr;
	}
	else {
		T = new TreeNode;
		if (T == nullptr) exit(OVERFLOW);
		T->data = ch;
		CreateTree(T->lchild);
		CreateTree(T->rchild);
	}
}
//������
void CopyTree(Bitree& NewT, Bitree& T)
{
	if (T != nullptr) {
		NewT = new TreeNode;
		NewT->data = T->data;
		CopyTree(NewT->lchild, T->lchild);
		CopyTree(NewT->rchild, T->rchild);
	}
	else {
		NewT = nullptr;
		return;
	}
}
//������
void DestroyTree(Bitree& T) {
	if (T != nullptr) {
		DestroyTree(T->lchild);
		DestroyTree(T->rchild);
		cout <<"Delete: "<< T->data << endl;
		delete T;
		T = nullptr;

	}
}

//�ݹ������
void PreOrderTraverse(Bitree T)
{
	if (T != nullptr) {
		cout << T->data << " ";
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
void InOrderTraverse(Bitree T)
{
	if (T != nullptr) {
		InOrderTraverse(T->lchild);
		cout << T->data << " ";
		InOrderTraverse(T->rchild);
	}
}
void AftOrderTraverse(Bitree T)
{
	if (T != nullptr) {
		AftOrderTraverse(T->lchild);
		AftOrderTraverse(T->rchild);
		cout << T->data << " ";
	}
	
}
//�ǵݹ������
void PreOrederTraverseNoRecurse(Bitree T)
{
	stack<TreeNode*> s;
	TreeNode* p = T;
	while (p != nullptr || !s.empty()) {
		while (p != nullptr) {
			cout << p->data << " ";
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty()) {
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
}
void InOrderTraverseNoRecurse(Bitree T)
{
	stack<Bitree> s;
	Bitree p = T;
	while (p != nullptr || !s.empty()) {
		while (p != nullptr) {
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty()) {
			p = s.top();
			cout << p->data << " ";
			s.pop();
			p = p->rchild;
		}
	}
}
void AftOrderTraverseNoRecurse(Bitree T)
{
	stack<Bitree> s;

	Bitree top = nullptr;
	Bitree cur = T;
	Bitree pre = nullptr;

	if (T != nullptr) {
		while (cur || !s.empty()) {
			while (cur) {
				s.push(cur);
				cur = cur->lchild;
			}
			top = s.top();
			if (top->rchild == nullptr || top->rchild == pre) {
				cout << top->data << " ";
				pre = top;
				s.pop();
			}
			else {
				cur = top->rchild;
			}
		}
	}

}

//�������
void LayerTraverseNoRecurse(Bitree T)
{
	//1�����ڵ���� 2�����ڵ���ӣ������亢�ӽ�����  3�����Ӳ�������Ԫ�غ������
	if (T) {
		Bitree p = T;
		queue<Bitree> Que;
		Que.push(p);
		while (!Que.empty()) {
			p = Que.front();
			cout << p->data << " ";
			Que.pop();
			if (p->lchild) Que.push(p->lchild);
			if (p->rchild) Que.push(p->rchild);
		}
	}
}

//���Һ��ӷ�ʵ���������
void PreorderLrchildTraverse(Bitree T)
{
	if (T) {
		stack<Bitree> s;
		Bitree p = T;
		s.push(p);
		while (!s.empty())
		{
			p = s.top();
			cout << p->data << " ";
			s.pop();
			if (p->rchild) s.push(p->rchild);
			if (p->lchild) s.push(p->lchild);
		}
	}
}

//���Ҷ�ӽ��
void TreeLeavesPreOrder(Bitree T) {
	if (T) {
		if (T->lchild == nullptr && T->rchild == nullptr) {
			cout << T->data << " ";
		}
		TreeLeavesPreOrder(T->lchild);
		TreeLeavesPreOrder(T->rchild);
	}
}
void TreeLeavesInOrder(Bitree T){
	if (T) {
		TreeLeavesPreOrder(T->lchild);
		if (T->lchild == nullptr && T->rchild == nullptr) {
			cout << T->data << " ";
		}
		TreeLeavesPreOrder(T->rchild);
	}
}
void TreeLeavesAftOrder(Bitree T) {
	if (T) {
		TreeLeavesPreOrder(T->lchild);
		TreeLeavesPreOrder(T->rchild);
		if (T->lchild == nullptr && T->rchild == nullptr) {
			cout << T->data << " ";
		}
	}
}
//��ȡ�������
int TreeDepth(Bitree T) {

	if (T) {
		int hl, hr, maxh;
		hl = TreeDepth(T->lchild);
		hr = TreeDepth(T->rchild);
		maxh = (hl > hr) ? hl : hr;
		return (maxh + 1);
	}
	else {
		return 0;
	}
}

//��ȡ�ܽ����
int NodesOfTree(Bitree T)
{
	
	if (T != nullptr) {
		int numL = 0,numR=0;
		numL = NodesOfTree(T->lchild);
		numR = NodesOfTree(T->rchild);
		return (numL + numR + 1);
	}
	else {
		return 0;
	}
}
//���
void NodesNumOfZeroDegree(Bitree T, int& d)
{
	if (T != nullptr) {
		if ((T->lchild == nullptr) && (T->rchild == nullptr)) {
			d++;
		}
		NodesNumOfZeroDegree(T->lchild, d);
		NodesNumOfZeroDegree(T->rchild, d);
	}
	else {
		return;
	}
}
void NodesNumOfTwoDegree(Bitree T, int& d) {
	int zero = 0;
	NodesNumOfZeroDegree(T, zero);
	d = zero - 1;
}

void NodesNumOfOneDegree(Bitree T, int& d){
	int nums = 0, twoDegree = 0, zeroDegree =0;
	nums = NodesOfTree(T);
	NodesNumOfTwoDegree(T,twoDegree);
	NodesNumOfZeroDegree(T,zeroDegree);
	d = nums - twoDegree - zeroDegree;
}

void GetDegree(Bitree T, int& zero, int& one, int& two) {
	NodesNumOfZeroDegree(T, zero);
	NodesNumOfOneDegree(T, one);
	NodesNumOfTwoDegree(T, two);
}

