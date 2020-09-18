#include "threadbinarytree.h"

int main() {
	using namespace std;
	ThreadTree T=nullptr;
	ThreadTree ThreadHead = nullptr;
	cout << "createBinaryTree:";
	createBinaryTree(T);
	cout << "\npreorder Traverse tree: ";
	PreOrderTraverse(T);
	ThreadingBinaryTree(ThreadHead, T);
	cout << "\nthreaded tree Traverse: ";
	InOrderTraverse_thr(ThreadHead);
	return 0;
}