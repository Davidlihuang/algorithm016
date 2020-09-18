#include "threadbinarytree.h"

using namespace std;
//�������Ĵ��������١����ƺ�������
void createBinaryTree(ThreadTree& T) {
	ElemType ch;
	cin >> ch;
	if (ch == '#') {
		T = nullptr;
	}
	else {
		T = new ThreadTreeNode(ch);
		if (T == nullptr) exit(OVERFLOW);
		createBinaryTree(T->lchild);
		createBinaryTree(T->rchild);
	}
}
void destoryThreadBinaryTree(ThreadTree& T) {

}
void copyThreadBinaryTree(ThreadTree& newT, ThreadTree& oldT) {

}

ThreadTree pre;
void InThreadingTree(ThreadTree T) {
	if (T) {
		InThreadingTree(T->lchild);
		//��ǰ���û�����ӣ�������ָ����ǰ��
		if (T->lchild == nullptr) {
			T->LTag = 1;
			T->lchild = pre;
		}
		//ǰ�����û���Һ��ӣ��Һ�����ָ������
		if (pre->rchild == nullptr) {
			pre->RTag = 1;
			pre->rchild = T;
		}
		pre = T; 
		InThreadingTree(T->rchild);
	}
}
void ThreadingBinaryTree(ThreadTree& Thr, ThreadTree T) {
	Thr = new ThreadTreeNode(' ');
	Thr->LTag = 0;
	Thr->RTag = 1;
	Thr->rchild = Thr;
	if (T == nullptr) {
		Thr->lchild = Thr;
	}
	else {
		Thr->lchild = T;
		pre = Thr;                 //preָ��ͷ���
		InThreadingTree(T);    //����������������
		pre->rchild = Thr;         //��������preָ�����һ�����
		pre->RTag = 1;
	}
	Thr->rchild = pre;
}

//����������
void PreOrderTraverse(ThreadTree T) {
	if (T) {
		cout << T->data << " ";
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
void InOrderTraverse_thr(ThreadTree T) {
	ThreadTree p;
	p = T->lchild;
	while (p != T) {
		while (p->LTag == 0) {
			p = p->lchild;
		}
		cout << " " << p->data << " ";
		while (p->RTag == 1 && p->rchild != T) {
			p = p->rchild;
			cout << p->data;
		}
		p = p->rchild;
	}
}
void PostOrderTraverse(ThreadTree T) {

}