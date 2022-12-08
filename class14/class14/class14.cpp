#include <iostream>
#include "list.h"
#include "queue.h"
#include "my_stack.h"

void test_stack() {
	Stack pt(10);

	cout << "Stack: \n";
	cout << "Push 1: \n";
	pt.push(1);
	cout << "Push 2: \n";
	pt.push(2);
	Stack::print(pt);

	cout << "Pop element: " << pt.pop() << endl;
	cout << "Pop element: " << pt.pop() << endl;
	cout << "Size: " << pt.size() << endl;

	cout << "Push 3: "<< endl;
	pt.push(3);
	Stack::print(pt);

	cout << "Top: " << pt.peek() << endl;
	cout << "Size: " << pt.size() << endl;

	cout << "Pop element: " << pt.pop() << endl;
	Stack::print(pt);

	if (pt.isEmpty()) {
		cout << "The stack is empty\n";
	}
	else {
		cout << "The stack is not empty\n";
	}

	pt.push(1);
	pt.push(2);
	pt.push(2);
	pt.push(5);
	pt.push(3);
	cout << "New stack: \n";
	Stack::print(pt);

	pt = pt.remove_value(2);
	cout << "Removing value = 2: \n";
	Stack::print(pt);

	cout << "Insert at pos 2 value 99: \n";
	pt.insert(2, 99);
	Stack::print(pt);
}

void test_list() {
	List obj = List();
	obj.add(25);
	obj.add(50);
	obj.add(90);
	obj.add(40);

	cout << "List: \n";
	obj.print();

	cout << "Add back: \n";
	obj.add(55);
	obj.print();

	cout << "Add front: \n";
	obj.push_front(50);
	obj.print();
	
	cout << "Insert 5 position: \n";
	obj.insert(5, 60);
	obj.print();
	
	cout << "Remove front: \n";
	obj.remove_front();
	obj.print();
	
	cout << "Remove back: \n";
	obj.remove_last();
	obj.print();
	
	cout << "Remove pos 4: \n";
	obj.remove(4);
	obj.print();

	cout << endl;

	obj.add(1);
	obj.add(2);
	obj.add(2);
	obj.add(3);
	obj.add(5);

	cout << "New list: \n";
	obj.print();

	obj = obj.remove_value(2);
	cout << "Removing value = 2: \n";
	obj.print();

	cout << "Insert at pos 2 value 99: \n";
	obj.insert(2, 99);
	obj.print();
}

void test_queue() {
	Queue q(10);

	cout << "Queue: \n";
	cout << "Add 1: \n";
	cout << "Add 2: \n";
	cout << "Add 3: \n";
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	cout << "Size: " << q.size() << endl;
	Queue::print(q);

	cout << "Front element: " << q.peek() << endl;
	cout << "Remove front: " << q.dequeue() << endl;

	cout << "Add 4: \n";
	q.enqueue(4);
	Queue::print(q);

	cout << "Size: " << q.size() << endl;

	cout << "Remove front: " << q.dequeue() << endl;
	cout << "Remove front: " << q.dequeue() << endl;
	cout << "Remove front: " << q.dequeue() << endl;
	Queue::print(q);

	if (q.isEmpty()) {
		cout << "The queue is empty\n";
	}
	else {
		cout << "The queue is not empty\n";
	}

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(2);
	q.enqueue(5);
	q.enqueue(3);
	q.enqueue(4);
	cout << "New queue: \n";
	Queue::print(q);

	q = q.remove_value(2);
	cout << "Removing value = 2: \n";
	Queue::print(q);

	cout << "Insert at pos 2 value 99: \n";
	q = q.insert(2, 99);
	Queue::print(q);
}

int main()
{
    std::cout << "-------- Stack test ------------------------\n";
	test_stack();
    
    std::cout << "-------- Queue test ------------------------\n";
	test_queue();

    std::cout << "-------- List test -------------------------\n";
	test_list();
}

