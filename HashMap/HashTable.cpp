/*
 * HashTable.cpp
 *
 *  Created on: Nov 12, 2020
 *      Author: stani
 */

#include "HashTable.h"

#include <iostream>

void bye(){
	std::cout<<"Goodbye!"<<std::endl;
}
HashTable::HashTable():Buckets(0),lists(nullptr){}

HashTable::HashTable(int x) {
	Buckets=x;
	lists = new std::list<int>[Buckets];

}
int HashTable::hashfunction(int x){
	return (x % Buckets);
}
void HashTable::insertItem(int x){
  int index = hashfunction(x);
  lists[index].push_back(x);

}
void HashTable::deleteItem(int key){
	int index = hashfunction(key);
	std::list<int>::iterator i;
	for(i = lists[index].begin();i!=lists[index].end();++i){
		if((*i)==key){
			break;
		}
	}
	if(i!=lists[index].end()){
		lists[index].erase(i);
	}
}
void HashTable::displayItems(){
	for(int i = 0;i<Buckets;i++){
		std::cout<<i<<": ";
		for(auto it:lists[i]){
			std::cout<<"->"<<it;
		}
		std::cout<<std::endl;
	}
	std::cout<<"Nothing here!"<<std::endl;
}
void HashTable::destroyTable(){
	for(int i = 0;i<Buckets;i++){
			lists[i].clear();
		}
		delete[] lists;
		lists=nullptr;
		Buckets=0;
}
bool HashTable::isEmpty(){
	if(Buckets==0&&lists==nullptr){
		return true;
	}
	else{
		return false;
	}
}
HashTable::~HashTable() {
	if(lists!=nullptr){
	for(int i = 0;i<Buckets;i++){
		lists[i].clear();
	}
	delete[] lists;
	lists=nullptr;
	Buckets=0;
	}
	else{
		return;
	}
}

