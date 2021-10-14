/*
 * DoubleList.h
 *
 *  Created on: Nov 11, 2020
 *      Author: stani
 */

#ifndef DOUBLELIST_H_
#define DOUBLELIST_H_

#include <iostream>
#include <string>

void sayhi2();

struct NodeDouble{
	int info;
	NodeDouble* next;
	NodeDouble *prev;
	~NodeDouble(){
		info = 0;
		next=nullptr;
		prev=nullptr;
	}
};

class DoubleLinkedList{
private:
	NodeDouble* begin;
	std::string displayList(NodeDouble* node);
public:
	DoubleLinkedList();
	DoubleLinkedList(int x);
	void insert(int x);
	void insert(int x,int value);
	void push(int x);
	void append(int x);
	void delete_first();
	void delete_last();
	void delete_position(int pos);
	bool isEmpty();
	std::string displayList();
	~DoubleLinkedList();
};

#endif /* DOUBLELIST_H_ */
