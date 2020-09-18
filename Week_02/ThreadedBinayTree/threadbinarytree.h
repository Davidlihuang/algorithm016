#pragma once
#ifndef THREADBINARYTREE_H_
#define THREADBINARYTREE_H_
#include <iostream>
#include <stack>
#include <queue>

typedef struct ThreadTreeNode* ThreadTree;
typedef char ElemType;
struct ThreadTreeNode
{
	ElemType data;
	ThreadTreeNode* lchild;
	ThreadTreeNode* rchild;
	int LTag;
	int RTag;
	ThreadTreeNode(ElemType ch)
		:data(ch), lchild(nullptr), rchild(nullptr), LTag(0), RTag(0) { }
};

//�������Ĵ��������١����ƺ�������
void createBinaryTree(ThreadTree& T); 
void destoryThreadBinaryTree(ThreadTree& T); 
void copyThreadBinaryTree(ThreadTree& newT, ThreadTree& oldT); 
void InThreadingTree(ThreadTree T); //��ͨ������
void ThreadingBinaryTree(ThreadTree& Thr, ThreadTree T); //��ͷ�ڵ��������

//����������
void PreOrderTraverse(ThreadTree T); 
void InOrderTraverse_thr(ThreadTree T);
void PostOrderTraverse(ThreadTree T);

//������������

#endif
