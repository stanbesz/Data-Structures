/*
 * myQueue.cpp
 *
 *  Created on: Nov 11, 2020
 *      Author: stani
 */

#include <iostream>

#include "myQueue.h"

void sayhi3(){
	std::cout<<"Hi for 3rd time!"<<std::endl;
}

Queue::Queue():begin(nullptr),end(nullptr){}

Queue::Queue(int x){
	amount++;
	begin = new NodeQ;
	begin->data=x;
	begin->next = nullptr;

	end=begin;
}
int Queue::front(){
	if(begin==nullptr){
		return 0;
	}
	else{
	return begin->data;
	}
}
int Queue::back(){
	if(end==nullptr){
			return 0;
		}
		else{
		return end->data;
		}
}
void Queue::dequeue(){
	if(begin!=nullptr){
		std::cout<<"Removed last"<<std::endl;

	NodeQ *node = begin;
	if(begin==end){
		begin=nullptr;
		end=nullptr;
		delete node;
		amount--;
	}
	else{
	begin=begin->next;
	delete node;
	amount--;
		}
	}
	else{
		std::cout<<"Queue empty!"<<std::endl;
	}
}

void Queue::enqueue(int x){
	NodeQ *node = new NodeQ;
	node->data = x;
	node->next = nullptr;
	amount++;
	if(amount>size){
		std::cout<<"Overflow"<<std::endl;
		return;
	}
	if(end==nullptr){
		std::cout<<"Added infront!"<<std::endl;
		end=node;
		begin=node;
	}
	else{
		std::cout<<"Added infront again!"<<std::endl;
		end->next=node;
		end=node;
	}

}
void Queue::display(){
	NodeQ *node = begin;
	while(node!=nullptr){
		std::cout<<node->data<<"->";
		node=node->next;
	}
	std::cout<<"null"<<std::endl;
}
bool Queue::isEmpty(){
	if(begin==end){
		return true;
	}
	else{
		return false;
	}
}
Queue::~Queue(){
	while(begin!=nullptr){
		NodeQ *node=begin;
		begin=begin->next;
		delete node;
	}
}
