/*
 * DoubleList.cpp
 *
 *  Created on: Nov 11, 2020
 *      Author: stani
 */

#include "DoubleList.h"
#include <sstream>

void sayhi2(){
	std::cout<<"Hello again!"<<std::endl;
}

DoubleLinkedList::DoubleLinkedList():begin(nullptr){}

DoubleLinkedList::DoubleLinkedList(int x){
	begin = new NodeDouble;
	begin->info = x;
	begin->prev = nullptr;
	begin->next = nullptr;
}
void DoubleLinkedList::insert(int x){
	NodeDouble *node = begin;
	NodeDouble *xnode = new NodeDouble;
	xnode->info = x;
	xnode->next = nullptr;
	xnode->prev = nullptr;
	if(xnode->info>node->info){
		node=node->next;
	}
	else{
		xnode->next = begin;
		begin = xnode;
	}
	NodeDouble* prev = begin;
	while(xnode->info>node->info){
		prev=prev->next;
		node=node->next;

	}
	node->prev=xnode;
	xnode->next=node;
	xnode->prev=prev;
	prev->next=xnode;
	std::cout<<"Inserted somewhere!"<<std::endl;
}
void DoubleLinkedList::insert(int x,int value){
	NodeDouble *pre=new NodeDouble;
	NodeDouble *cur=new NodeDouble;
	NodeDouble *temp=new NodeDouble;
	cur=begin;

	for(int i=1;i<value;i++){
	   pre=cur;
	   cur=cur->next;
	   cur->prev = pre;
	}
	temp->info=x;
	pre->next=temp;
	temp->next=cur;
	temp->prev=pre;

	std::cout<<" Inserted "<<x<<"At "<<value<<" position. "<<std::endl;
}
void DoubleLinkedList::delete_first()
  {
    NodeDouble *temp=new NodeDouble;
    temp=begin;
    begin=begin->next;
    delete temp;
    temp=nullptr;
  }
void DoubleLinkedList::delete_last()
 {
   NodeDouble *current=new NodeDouble;
   NodeDouble *previous=new NodeDouble;
   current=begin;
   while(current->next!=nullptr)
   {
     previous=current;
     current=current->next;
     current->prev=previous;
   }
   previous->next=nullptr;
   delete current;
   if(current==begin){
   	   current=nullptr;
   	   begin=nullptr;
      }
      else{
   	   current=nullptr;
      }
 }
void DoubleLinkedList::delete_position(int pos)
  {
    NodeDouble *current=new NodeDouble;
    NodeDouble *previous=new NodeDouble;
    current=begin;
    for(int i=1;i<pos;i++)
    {
      previous=current;
      current=current->next;
      current->prev=previous;
    }
    previous->next=current->next;
    current->prev=previous;
    delete current;
    current=nullptr;

  }
void DoubleLinkedList::push(int x){//add infront

	std::cout<<"Added on the front!"<<std::endl;
	NodeDouble *node = new NodeDouble;
	node->info = x;
	node->prev = nullptr;
	node->next=begin;
	if(begin!=nullptr){
	begin->prev=node;
	}
	begin = node;
}
void DoubleLinkedList::append(int x){//add to the back
	std::cout<<"Added on the back!"<<std::endl;
	NodeDouble *node = new NodeDouble;
	node->info = x;
	node->next = nullptr;
	node->prev=nullptr;
	NodeDouble *last = begin;
	if(begin==nullptr){
		begin=node;
		return;
	}
	while(last->next!=nullptr){
		last=last->next;
	}
	last->next=node;
	node->prev=last;
}
std::string DoubleLinkedList::displayList(NodeDouble *node){
	std::stringstream res;
	while(node!=nullptr){
		res<<node->info;
		res<<"->";
		node=node->next;
	}
	if(node==nullptr){
	res<<"nope";
	}
	return res.str();
}
std::string DoubleLinkedList::displayList(){
	return displayList(begin);
}
bool DoubleLinkedList::isEmpty(){
	return (begin==nullptr);
}
DoubleLinkedList::~DoubleLinkedList(){
	NodeDouble* node=begin;
		while(node!=nullptr){
			NodeDouble *temp=node;
			node=node->next;
			delete temp;
			temp=nullptr;

		}
}
