/*
 * mymath.h
 *
 *  Created on: Nov 6, 2020
 *      Author: stani
 */

#ifndef MYMATH_H_
#define MYMATH_H_
#include <iostream>


int mult(int,int);

class Stack{

private:
	int arr[1000];
	int top = 0;
public:

	Stack();
	void push(int x);
	bool isEmpty();
	int pop();
	int peek();
	void display();
};



#endif /* MYMATH_H_ */
