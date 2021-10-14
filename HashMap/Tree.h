/*
 * Tree.h
 *
 *  Created on: Nov 12, 2020
 *      Author: stani
 */

#ifndef TREE_H_
#define TREE_H_

struct TreeNode{
	int data;
	TreeNode *left,*right;

};

class Tree {
	TreeNode *root;
	void displayTree(TreeNode* node);
	void deleteInternalNode(int x);
public:
	Tree();
	void insert(int x);
	TreeNode* search(int x);
	void deleteNode(int x);
	void insert(int x, TreeNode* node);
	void displayTree();
	bool isempty();
	void destroyTree(TreeNode* node);
	TreeNode* getRoot();
	~Tree();
};

#endif /* TREE_H_ */
