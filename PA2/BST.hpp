#ifndef BST_HPP
#define BST_HPP

#include <iostream>

#include "BSTNode.hpp"

template <class T>
class BST {
public: // DO NOT CHANGE THIS PART.
    BST();
    BST(const BST<T> &obj);

    ~BST();

    BSTNode<T> *getRoot();

    void insert(const T &data);
    void remove(const T &data);
    BSTNode<T> *find(const T &data);
    void printInorder();

    BST<T> &operator=(const BST<T> &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.
    void printInorder(BSTNode<T> *node);
    void copy(BSTNode<T> *curr);
    void insertHelper(BSTNode<T> *&curr, const T &val);
    BSTNode<T> * findHelper(BSTNode<T> *curr, T data);
    void removeHelper(BSTNode<T> *&curr, T data);
    T getMinimum(BSTNode<T> *curr);
    void chop(BSTNode<T> *curr);

private: // DO NOT CHANGE THIS PART.
    BSTNode<T> *root;
};

#endif //BST_HPP

template <class T>
BST<T>::BST() {
    root = NULL;
}

template <class T>
BST<T>::BST(const BST<T> &obj) {
    root = NULL;
    copy(obj.root);
}

template <class T>
void BST<T>::copy(BSTNode<T> *curr)
{
     if(curr)
     {
        insert(curr->data);
        copy(curr->left);
        copy(curr->right);
     }
}



template <class T>
BST<T>::~BST() {
    chop(root);
}

template <class T>
void BST<T>::chop(BSTNode<T> *curr)
{
    if (curr == NULL) {
        delete curr;
        return;
    }
    else {
        chop(curr->left);
        chop(curr->right);
        delete curr;
    }

}



template <class T>
T BST<T>::getMinimum(BSTNode<T> *curr)
{
	if (curr->left == NULL)
	{
		return curr->data;
	}
	else
	{
		return getMinimum(curr->left);
	}
}

template <class T>
BSTNode<T> *BST<T>::getRoot() {
    return root;
}

template <class T>
void BST<T>::insert(const T &data) {
    insertHelper(root, data);
}

template <class T>
void BST<T>::insertHelper(BSTNode<T> *&curr, const T &val) 
{
    if(curr == NULL) {
        curr = new BSTNode<T>(val, NULL, NULL); 
        return;
    }
    else if (curr->data > val) {
        insertHelper(curr->left, val);
    }
    else if (curr->data < val) {
        insertHelper(curr->right, val);
    }
}

/*template <class T>
void BST<T>::insert(const T &data) {
    BSTNode<T> *nodeToInsert = insertHelper(root, data);
    if (nodeToInsert->data > data) {
        nodeToInsert->left = new BSTNode<T>(data, NULL, NULL);
    }
    else {
        nodeToInsert->right = new BSTNode<T>(data, NULL, NULL);
    }
}

template <class T>
BSTNode<T> *BST<T>::insertHelper(BSTNode<T> *curr, T data) 
{
    if((curr->data > data && curr->left == NULL) || (curr->data < data && curr->right == NULL)){
        return curr;
    }
    else if (curr->data > data) {
        return insertHelper(curr->left, data);
    }
    else if (curr->data < data) {
        return insertHelper(curr->right, data);
    }
}*/

template <class T>
void BST<T>::remove(const T &data) {
    removeHelper(root, data);
}

template <class T>
void BST<T>::removeHelper(BSTNode<T> *&curr, T data)
{
	if (curr == NULL)
	{
		return;
	}
	else if (curr->data > data)
	{
		removeHelper(curr->left, data);
	}
	else if (curr->data < data)
	{
		removeHelper(curr->right, data);
	}
	else
	{
		if (curr->left && curr->right)
		{
			curr->data = getMinimum(curr->right);
			removeHelper(curr->right, curr->data);
		}
		else
		{
			BSTNode<T>* temp = curr;
			if (curr->left)
			{
				curr = curr->left;
			}
			else
			{
				curr = curr->right;
			}
			delete temp;
		}
	}
}

template <class T>
BSTNode<T> *BST<T>::find(const T &data) {
    return findHelper(root, data);
}

template <class T>
BSTNode<T> *BST<T>::findHelper(BSTNode<T> *curr, T data) 
{
    if (curr == NULL) {
        return NULL;
    }
    else if(curr->data == data) {
        return curr;
    }
    else if (curr->data < data) {
        findHelper(curr->right, data);
    }
    else {
        findHelper(curr->left, data);
    }
}

template <class T>
void BST<T>::printInorder() {

    if (root == NULL) {
        std::cout << "{}" << std::endl;
    } else {
        std::cout << "{" << std::endl;
        printInorder(root);
        std::cout << std::endl << "}" << std::endl;
    }
}

template <class T>
void BST<T>::printInorder(BSTNode<T> *node) {

    if (node == NULL)
        return;

    printInorder(node->left);
    if (node->left) {
        std::cout << "," << std::endl;
    }
    std::cout << "\t" << node->data;
    if (node->right) {
        std::cout << "," << std::endl;
    }
    printInorder(node->right);
}

template <class T>
BST<T> &BST<T>::operator=(const BST<T> &rhs) {
    if(this != &rhs)
     {
          chop(root);
          root=NULL;
          copy(rhs.root);
     }
     return *this;
}
