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

//二叉树的创建、销毁、复制和线索化
void createBinaryTree(ThreadTree& T); 
void destoryThreadBinaryTree(ThreadTree& T); 
void copyThreadBinaryTree(ThreadTree& newT, ThreadTree& oldT); 
void InThreadingTree(ThreadTree T); //普通线索化
void ThreadingBinaryTree(ThreadTree& Thr, ThreadTree T); //带头节点的线索化

//遍历二叉树
void PreOrderTraverse(ThreadTree T); 
void InOrderTraverse_thr(ThreadTree T);
void PostOrderTraverse(ThreadTree T);

//二叉树的属性

#endif
