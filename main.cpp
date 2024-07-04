#include<iostream>

using namespace std;
//定义节点结构
typedef struct BSTNode
{
	int data;
	struct BSTNode* left;
	struct BSTNode* right;

}Node;


//创建新节点
Node* createNode(int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

//插入节点
Node* insertBSTNode(Node* root,int data)
{
	if (root == NULL)
	{
		return createNode(data);
	}
	if (data < root->data)
	{
		root->left = insertBSTNode(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = insertBSTNode(root->right, data);
	}

	return root;
}

//找到最小节点
Node* findMin(Node* root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}


//删除节点
Node* deleteNode(Node* root, int data)
{
	if (root == NULL) return root;

	if (data < root->data)
	{
		root->left = deleteNode(root->left,data);
	}
	else if (data > root->data)
	{
		root->right = deleteNode(root->right, data);
	}
	else
	{
		//找到了
		if (root->left == NULL)
		{
			Node* temp = root->right;
			delete(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			Node* temp = root->left;
			delete(root);
			return temp;
		}
		//如果左右节点都存在
		Node* temp = findMin(root->right); //找到该节点的后继的最小节点
		root->data = temp->data;
		root->right= deleteNode(root->right,temp->data);
	}
	return root;
}


//中序遍历
void inorderTraversal(Node* root)
{
	if (root != NULL)
	{
		inorderTraversal(root->left);
		cout << root->data << " ";
		inorderTraversal(root->right);
	}
}



//BST的生成
Node* generateBST(int* data, int size)
{
	Node* root = NULL;
	for (int i = 0; i < size; i++)
	{
		root = insertBSTNode(root,data[i]);
	}
	return root;
}



int main() {
	int data[] = { 23,54,67,13,33,78,91 };
	int size = sizeof(data) / sizeof(data[0]);

	Node* root = generateBST(data, size);


	std::cout << "中序遍历: ";
	inorderTraversal(root);
	std::cout << std::endl;

	std::cout << "插入节点 25:\n";
	insertBSTNode(root, 25);
	inorderTraversal(root);
	std::cout << std::endl;

	std::cout << "删除节点 23:\n";
	root = deleteNode(root, 23);
	inorderTraversal(root);
	std::cout << std::endl;

	std::cout << "删除节点 33:\n";
	root = deleteNode(root, 33);
	inorderTraversal(root);
	std::cout << std::endl;

	std::cout << "删除节点 25:\n";
	root = deleteNode(root, 25);
	inorderTraversal(root);
	std::cout << std::endl;


	return 0;
}
