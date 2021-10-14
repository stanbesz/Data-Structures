/*
 * HashTable.h
 *
 *  Created on: Nov 12, 2020
 *      Author: stani
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <list>

void bye();

class HashTable {
	int Buckets = 0;
	std::list<int> *lists;
public:
	HashTable();
	HashTable(int x);
	int hashfunction(int x);
	void insertItem(int x);
	void deleteItem(int key);
	void displayItems();
	void destroyTable();
	bool isEmpty();
	~HashTable();
};

#endif /* HASHTABLE_H_ */
