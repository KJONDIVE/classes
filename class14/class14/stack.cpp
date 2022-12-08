#include "my_stack.h"


Stack::Stack(int size)
{
    arr = new int[size];
    capacity = size;
    top = -1;
}

Stack::~Stack() {
    //delete[] arr;
}

void Stack::push(int x)
{
    if (isFull())
    {
        cout << "Err: full\n";
        exit(-1);
    }

    arr[++top] = x;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Err: empty\n";
        exit(-1);
    }

    return arr[top--];
}

int Stack::peek()
{
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(-1);
    }
}

int Stack::size() {
    return top + 1;
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == capacity - 1;
}

void Stack::print(Stack s) {
    while (s.size() != 0) {
        cout << s.pop() << '\t';

    }
    cout << endl;
}

Stack Stack::remove_value(int value) {
    Stack new_s(capacity);
    Stack tmp(capacity);
    int e;
    while (!isEmpty()) {
        e = pop();
        if (e != value) {
            tmp.push(e);
        }
    }

    while (!tmp.isEmpty()) {
        new_s.push(tmp.pop());
    }

    return new_s;
}

void Stack::insert(int pos, int value)
{
    Stack tmp;
    while (pos != 1) {
        pos--;
        tmp.push(pop());
    }
    push(value);
    while (!tmp.isEmpty()) {
        push(tmp.pop());
    }
}

