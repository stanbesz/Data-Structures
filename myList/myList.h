/*
 * myList.h
 *
 *  Created on: Nov 9, 2020
 *      Author: stani
 */

#ifndef MYLIST_H_
#define MYLIST_H_

#include <iostream>
#include <string>

void sayhi();

struct Node{
	int info;
	Node* next;
};

class LinkedList{
	Node* begin;
	std::string displayList(Node* node);
public:
	LinkedList();
	LinkedList(int x);
	void insert(int pos, int value);
	void push(int x);
	void append(int x);
	void delete_first();
	void delete_last();
	void delete_position(int pos);
	bool isEmpty();
	std::string displayList();
	~LinkedList();

};

#endif /* MYLIST_H_ */
