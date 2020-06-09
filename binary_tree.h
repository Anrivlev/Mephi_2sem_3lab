#pragma once

template <class T>
class BinaryTree
{
private:
	struct node
	{
		node* parent = nullptr;
		node* left = nullptr;
		node* right = nullptr;
		T elem = T(0);
	}
	node* root = nullptr;
	int size = 0;
	
private:
	void destructor(node* nodePtr)
	{
		if (nodePtr == nullptr) return;
		if (nodePtr->left != nullptr)
		{
			destructor(nodePtr->left);
			delete nodePtr->left;
		}
		if (nodePtr->right != nullptr)
		{
			destructor(nodePtr->right);
			delete nodePtr->right;
		}
	}
	node* search(const T elem)
	{
		node* nodePtr = this->root;
		while(nodePtr != nullptr)
		{
			if(elem < nodePtr->elem)
			{
				nodePtr = nodePtr->left;
			}
			else if(elem > nodePtr->elem)
			{
				nodePtr = nodePtr->right;
			}
			else return nodePtr;
		}
		return nullptr;
	}
	void erase_(node* delNode_)
	{
		node* delNode = delNode_;
		if (delNode == nullptr) return;
		if (delNode->right == nullptr && delNode->left == nullptr)
		{
			if (delNode == this->root)
			{
				delete delNode;
				this->root = nullptr;
			}
			else
			{
				if (delNode->parent->right == delNode) delNode->parent->right = nullptr;
				else delNode->parent->left = nullptr;
				delete delNode;
			}
		}
		else if (delNode->right != nullptr && delNode->left == nullptr)
		{
			if (delNode == this->root)
			{
				delNode->right->parent = nullptr;
				this->root = delNode->right;
			}
			else
			{
				if (delNode->parent->left == delNode) delNode->parent->left = delNode->right;
				else delNode->parent->right = delNode->right;
				delNode->right->parent = delNode->parent;
			}
			delete delNode;
		}
		else if (delNode->right == nullptr && delNode->left != nullptr)
		{
			if (delNode == this->root)
			{
				delNode->left->parent = nullptr;
				this->root = delNode->left;
			} else
			{
				if (delNode->parent->left == delNode) delNode->parent->left = delNode->left;
				else delNode->parent->right = delNode->left;
				delNode->left->parent = delNode->parent;
			}
			delete delNode;
		}
		else if (delNode->right != nullptr && delNode->left != nullptr)
		{
			node* swapNode = next(delNode);
			T tmp_value = delNode->key;
			delNode->key = swapNode->key;
			swapNode->key = tmp_value;
			this->erase_(swapNode);
		}
	}

public:
	BinaryTree() = default;
	BinaryTree(const T rootElem)
	{
		this->root = new node;
		this->root->elem = rootElem;
		size = 1;
	}
	~BinaryTree()
	{
		destrustor(this->root);
		size = 0;
		delete this->root;
	}
	void add(const T elem)
	{
		node* nodePtr = this->root;
		this->size++;
		if(this->root == nullptr)
		{
			this->root = new node;
			this->root->elem = elem;
			return;
		}
		while(nodePtr != nullptr)
		{
			if(elem < nodePtr->elem)
			{
				if(nodePtr->left != nullptr)
				{
					nodePtr = nodePtr->left;
				} else
				{
					nodePtr->left = new node;
					nodePtr->left->elem = elem;
					nodePtr->left->parent = nodePtr;
					break;
				}
			} else
			{
				if(nodePtr->right != nullptr)
				{
					nodePtr = nodePtr->right;
				} else
				{
					nodePtr->right = new node;
					nodePtr->right->elem = elem;
					nodePtr->right->parent = nodePtr;
					break;
				}
			}
		}
	}
	void erase(T elem)
	{
		node* delNode = search(elem);
		if(delNode == nullptr) return;
		
		erase_(del_node);
		this->size--;
	}
	T minimum()
	{
		if (this->root == nullptr) return T(0);
		node* nodePtr = this->root;
		while (nodePtr->left != nullptr)
		{
			nodePtr = nodePtr->left;
		}
		return nodePtr->elem;
	}
	T maximum()
	{
		node* nodePtr = this->root;
		if(this->root == nullptr)
		{
			return T(0);
		}
		while(nodePtr->right != nullptr)
		{
			nodePtr = nodePtr->right;
		}
		return nodePtr->elem;
	}
	bool exist(const T elem)
	{
		if(search(elem) != nullptr)
		{
			return true;
		}
		else return false;
	}
	void dfs()
	{
		if(this->root == nullptr) return;
		dfs(this->root);
		std::cout << "\nROOT " << this->root->elem;
	}
}