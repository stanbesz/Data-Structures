/*
 * Tree.cpp
 *
 *  Created on: Nov 12, 2020
 *      Author: stani
 */

#include "Tree.h"

#include <iostream>

Tree::Tree():root(nullptr) {
	std::cout<<"Created Tree"<<std::endl;
	// TODO Auto-generated constructor stub

}
void Tree::deleteNode(int x){
	deleteInternalNode(x);
}
void Tree::deleteInternalNode(int x){
	TreeNode* prev;
	TreeNode *node = root;
	//delete if only root exists
	if(x==root->data&&root->right==nullptr&&root->left==nullptr){
		delete root;
		root=nullptr;
		return;
	}
	else if(root==nullptr){//case if root == nullptr
		std::cout<<"Tree is empty!"<<std::endl;
		return;
	}
	else{//case if there are nodes


	while(node->data!=x){//node to be replaced
		if(node->data>x){
			prev=node;
			node=node->left;
		}
		else if(node->data<x){
			prev=node;
			node=node->right;
		}
		else{
			break;
		}
		//node is node to be deleted

	}
//
		if(node->right==nullptr&&node->left==nullptr){
			if(prev->left==node){
				prev->left=nullptr;
				delete node;
				node=nullptr;
				return;
			}
			if(prev->right==node){
				prev->right=nullptr;
				delete node;
				node=nullptr;
				return;
			}

		}
		else if(node->right==nullptr){//right subtree if root is bigger than to be deleted node
			node->data = node->left->data;
			delete node->left;
			node->left=nullptr;
			return;
		}
		else if(node->left==nullptr){
			node->data = node->right->data;//reverse logic for this one
			delete node->right;
			node->right=nullptr;
			return;
		}
		else{
			TreeNode* succParent = node;

			// Find successor
			TreeNode* succ = node->right;
	      while (succ->left != NULL) {
			    succParent = succ;
			    succ = succ->left;
			 }

	      // Delete successor.  Since successor
	      // is always left child of its parent
	      // we can safely make successor's right
	      // right child as left of its parent.
	      // If there is no succ, then assign
	      // succ->right to succParent->right
			if (succParent != node){
				succParent->left = succ->right;
			}
			else{
			succParent->right = succ->right;
			}
			// Copy Successor Data to root
			node->data = succ->data;

			// Delete Successor and return root
			std::cout<<"Deleted: "<<succ<<std::endl;
			delete succ;
			succ=nullptr;

		}

	}

}
void Tree::insert(int x,TreeNode* node){
	if(x<node->data){
		if(node->left!=nullptr){
			insert(x,node->left);
		}
		else{
			TreeNode* leaf = new TreeNode;
			leaf->data = x;
			leaf->left=nullptr;
			leaf->right=nullptr;
			node->left=leaf;

		}
	}
	else if(x>=node->data){
		if(node->right!=nullptr){
			insert(x,node->right);
		}
		else{
			TreeNode* leaf = new TreeNode;
			leaf->data = x;
			leaf->left=nullptr;
			leaf->right=nullptr;
			node->right=leaf;
		}
	}
}
void Tree::insert(int x){
	if(root!=nullptr)
	    insert(x, root);
	  else
	  {
	    root=new TreeNode;
	    root->data=x;
	    root->left=nullptr;
	    root->right=nullptr;
	  }


}
TreeNode* Tree::getRoot(){
	return this->root;
}
TreeNode* Tree::search(int x){
	TreeNode *node = root;
	while(node!=nullptr){
		if(node->data<x){
			node=node->right;
		}
		else if(node->data>x){
			node=node->left;
		}
		else{
			break;
		}
	}
	if(node==nullptr){
		std::cout<<"No Node!"<<std::endl;
		return nullptr;
	}
	return node;

}
void Tree::displayTree(){
	displayTree(root);
}
void Tree::displayTree(TreeNode *node){
	if(node!=nullptr){
		displayTree(node->left);
		std::cout<<node->data<<" ";
		displayTree(node->right);
	}

}

bool Tree::isempty(){
	return (root==nullptr);
}
void Tree::destroyTree(TreeNode *node){
	if(node){
	destroyTree(node->left);
	destroyTree(node->right);
	delete node;
	node=nullptr;
	}

}
Tree::~Tree() {
	destroyTree(root);
	// TODO Auto-generated destructor stub
}

