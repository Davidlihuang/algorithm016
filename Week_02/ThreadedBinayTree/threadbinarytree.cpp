#include "threadbinarytree.h"

using namespace std;
//二叉树的创建、销毁、复制和线索化
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
		//当前结点没有左孩子，左孩子域指向其前驱
		if (T->lchild == nullptr) {
			T->LTag = 1;
			T->lchild = pre;
		}
		//前驱结点没有右孩子，右孩子域指向其后继
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
		pre = Thr;                 //pre指向头结点
		InThreadingTree(T);    //中序线索化二叉树
		pre->rchild = Thr;         //线索化后pre指向最后一个结点
		pre->RTag = 1;
	}
	Thr->rchild = pre;
}

//遍历二叉树
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