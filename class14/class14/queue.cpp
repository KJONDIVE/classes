#include "queue.h"

Queue::Queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}


Queue::~Queue() {
    //delete[] arr;
}


int Queue::dequeue()
{

    if (isEmpty())
    {
        cout << "Err: empty\n";
        exit(-1);
    }

    int x = arr[front];

    front = (front + 1) % capacity;
    count--;

    return x;
}


void Queue::enqueue(int item)
{

    if (isFull())
    {
        cout << "Err: full\n";
        exit(-1);
    }

    rear = (rear + 1) % capacity;
    arr[rear] = item;

    count++;
}


int Queue::peek()
{
    if (isEmpty())
    {
        cout << "Err: empty\n";
        exit(-1);
    }
    return arr[front];
}


int Queue::size() {
    return count;
}


bool Queue::isEmpty() {
    return (size() == 0);
}


bool Queue::isFull() {
    return (size() == capacity);
}

void Queue::print(Queue s) {
    while (s.size() != 0) {
        cout << s.dequeue() << '\t';
    }
    cout << endl;
}

Queue Queue::remove_value(int value) {
    Queue new_q(capacity);
    int e;
    while (!isEmpty())
    {
        e = dequeue();
        if (e != value) {
            new_q.enqueue(e);
        }
    }
    return new_q;
}

Queue Queue::insert(int pos, int value)
{
    Queue new_q;
    //cout << "SIZE " << size() << endl;
    for (size_t i = 1; i < pos; i++)
    {
        new_q.enqueue(dequeue());
    }
    new_q.enqueue(value);
    //cout << "SIZE " << size() << " " << new_q.size() << endl;
    while (!isEmpty())
    {
        new_q.enqueue(dequeue());
    }
    //cout << "SIZE " << size() << " " << new_q.size() << endl;

    return new_q;
}
