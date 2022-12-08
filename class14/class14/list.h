#pragma once
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct List
{
private:
	Node* head, *tail;
public:
	List();
	void add(int);
	int get(int);
	void print();
	void remove(int);
	List remove_value(int);
	void remove_last();
	void remove_front();
	void insert(int, int);
	void push_front(int);
};