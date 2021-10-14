/*
 * myQueue.h
 *
 *  Created on: Nov 11, 2020
 *      Author: stani
 */

#ifndef MYQUEUE_H_
#define MYQUEUE_H_


void sayhi3();

struct NodeQ{
	int data = 0;
	NodeQ *next;
};
class Queue{
private:
	int size = 5;
	int amount = 0;
	NodeQ *begin;
	NodeQ *end;
public:
	Queue();
	Queue(int x);
	void enqueue(int x);
	int front();
	int back();
	void display();
	void dequeue();
	bool isEmpty();
	~Queue();
};

#endif /* MYQUEUE_H_ */
