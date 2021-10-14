/*
 * mymath.cpp
 *
 *  Created on: Nov 6, 2020
 *      Author: stani
 */
#include "mymath.h"


Stack::Stack(){
	top=-1;
}

void Stack::push(int x){
	if(top==1000-1){
		std::cout<<"Stack is full!"<<std::endl;
	}
	else{
		std::cout<<"Added "<<x<<std::endl;
		top++;
		arr[top]=x;
	}
}
bool Stack::isEmpty(){
	if(top<0){
		std::cout<<"Stack is empty!"<<std::endl;
		return true;
	}
	else{
		std::cout<<"Stack not empty!"<<std::endl;
		return false;
	}
}
int Stack::pop(){
	if(top<0){
		std::cout<<"Stack Underflow!"<<std::endl;
		return 0;
	}
	int value = 0;
	value = arr[top--];
	return value;
}
int Stack::peek(){
	if(top<0){
		std::cout<<"Stack is empty!"<<std::endl;
		return 0;
	}
	else{
	return arr[top];
	}
}
void Stack::display(){
	for(int i = top;i>=0;i--){
		std::cout<<arr[i]<<"->";
	}
	std::cout<<"null"<<std::endl;
}
int mult(int a,int b){
	return a*b;
}


