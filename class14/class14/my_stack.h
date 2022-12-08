#pragma once
#include <iostream>
using namespace std;

#define DEFAULT_SIZE 100

struct Stack
{
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size = DEFAULT_SIZE);
    ~Stack();                       

    void push(int);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();
    static void print(Stack);

    Stack remove_value(int);
    void insert(int, int);
};

