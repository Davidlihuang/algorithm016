#include <iostream>
#include "binarytree.h"

int main()
{
	using namespace std;
	Bitree Tree;
	//create tree in pre order
	cout << "create treee in pre order" << endl;
	CreateTree(Tree);

	//traverse trees in recurve way
	cout << "\npre order traverse: ";
	PreOrderTraverse(Tree);
	cout<< "\nin order traverse: ";
	InOrderTraverse(Tree);
	cout << "\nAter order traverse: ";
	AftOrderTraverse(Tree);
	cout << endl;

	//traverse tree in non recurse way
	cout << "\nPreOrederTraverseNoRecurse:";
	PreOrederTraverseNoRecurse(Tree);
	cout << "\nInOrederTraverseNoRecurse:";
	InOrderTraverseNoRecurse(Tree);
	cout << "\nAftOrederTraverseNoRecurse:";
	AftOrderTraverseNoRecurse(Tree);
	cout << endl;

	cout << "\nLayerTraverseNoRecurse:";
	LayerTraverseNoRecurse(Tree);

	//左右孩子法实现先序遍历
	cout << "\nPreorderLrchildTraverse:";
	PreorderLrchildTraverse(Tree);
	cout << endl;

	//叶子结点
	cout << "\nget leaves in preorder:";
	TreeLeavesPreOrder(Tree);
	cout << "\nget leaves in inorder:";
	TreeLeavesInOrder(Tree);
	cout << "\nget leaves in postorder:" ;
	TreeLeavesAftOrder(Tree);
	cout << endl;

	//获取树的深度
	cout << "tree depth: "<<TreeDepth(Tree) << endl;
	//树的结点数
	int num = NodesOfTree(Tree);
	cout << "node number = " << num << endl;
	//树的度
	int zero=0, one=0, two=0;
	GetDegree(Tree, zero, one, two);
	cout << "Trees total number of diffrent degrees:\n ";
	cout << "zero degree nodes num:" << zero << endl;
	cout << "one degree nodes num:" << one << endl;
	cout << "two degree nodes num:" << two << endl<<endl;
	//复制树
	Bitree newTree;
	CopyTree(newTree, Tree);
	cout << "newTree: ";
	PreOrderTraverse(newTree);
	cout << endl<<endl;
	//销毁树
	DestroyTree(Tree);

	return 0;
}