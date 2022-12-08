#pragma once
#include <iostream>
using namespace std;

#define DEFAULT_SIZE 1000

struct Queue
{
    int* arr;
    int capacity;
    int front; // начало
    int rear; // конец
    int count;

public:
    Queue(int size = DEFAULT_SIZE);
    ~Queue();

    int dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
    static void print(Queue);
    Queue remove_value(int);
    Queue insert(int, int);
};
