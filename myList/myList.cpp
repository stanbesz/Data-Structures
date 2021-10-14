/*
 * myList.cpp
 *
 *  Created on: Nov 9, 2020
 *      Author: stani
 */

#include "myList.h"
#include <sstream>
void sayhi(){
	std::cout<<"Hi!!!"<<std::endl;
}

LinkedList::LinkedList():begin(nullptr){}

LinkedList::LinkedList(int x){

	begin = new Node;
	begin->info=x;
	begin->next=nullptr;

}

void LinkedList::insert(int x,int value){
	Node *pre=new Node;
	Node *cur=new Node;
	Node *temp=new Node;
	cur=begin;

	for(int i=1;i<value;i++){
	   pre=cur;
	   cur=cur->next;
	}
	temp->info=x;
	pre->next=temp;
	temp->next=cur;

	std::cout<<" Inserted "<<x<<"At "<<value<<" position. "<<std::endl;
}
void LinkedList::push(int x){//to the fron

	Node* node = new Node;
	node->info=x;
	node->next=begin;
	begin=node;
	std::cout<<"Added in the front!"<<std::endl;
}
void LinkedList::append(int x){//to the back
	Node *node = new Node;
	node->info = x;
	node->next=nullptr;
	Node *last = begin;
	if(last==nullptr){
		std::cout<<"Added in the front!"<<std::endl;
		begin=node;
		return;
	}
	while(last->next!=nullptr){
		last=last->next;
	}
	std::cout<<"Added on the back"<<std::endl;
	last->next=node;

}
void LinkedList::delete_first()
  {
    Node *temp=new Node;
    temp=begin;
    begin=begin->next;
    delete temp;
    temp=nullptr;
  }
void LinkedList::delete_last()
 {
   Node *current=new Node;
   Node *previous=new Node;
   current=begin;
   while(current->next!=nullptr)
   {
     previous=current;
     current=current->next;
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
void LinkedList::delete_position(int pos)
  {
    Node *current=new Node;
    Node *previous=new Node;
    current=begin;
    for(int i=1;i<pos;i++)
    {
      previous=current;
      current=current->next;
    }
    previous->next=current->next;
    delete current;
    current=nullptr;
  }
std::string LinkedList::displayList(Node *node){
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
std::string LinkedList::displayList(){
	return displayList(begin);
}
bool LinkedList::isEmpty(){
	return (begin==nullptr);
}
LinkedList::~LinkedList(){
	Node* node=begin;
	while(node!=nullptr){
		Node *temp=node;
		node=node->next;
		delete temp;
		temp=nullptr;

	}
}
