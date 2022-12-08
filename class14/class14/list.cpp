#include "list.h"

List::List()
{
	head = NULL;
	tail = NULL;
}
void List::add(int value)
{
	Node* temp = new Node;
	temp->data = value;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

int List::get(int pos) {
	Node* current = head;
	int cur_pos = 0;
	while (cur_pos != pos) {
		current = current->next;
		cur_pos++;
	}
	return current->data;
}
void List::print()
{
	Node* temp = new Node;
	temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
	cout << endl;
}
void List::push_front(int value)
{
	Node* temp = new Node;
	temp->data = value;
	temp->next = head;
	head = temp;
}
void List::insert(int pos, int value)
{
	Node* pre = new Node;
	Node* cur = new Node;
	Node* temp = new Node;
	cur = head;
	if (pos == 1) {
		temp->data = value;
		temp->next = head;
		head = temp;
		return;
	}
	for (int i = 1; i < pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	temp->data = value;
	pre->next = temp;
	temp->next = cur;
}
void List::remove_front()
{
	Node* temp = new Node;
	temp = head;
	head = head->next;
	delete temp;
}
void List::remove_last()
{
	Node* current = new Node;
	Node* previous = new Node;
	current = head;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	tail = previous;
	previous->next = NULL;
	delete current;
}
void List::remove(int pos)
{
	Node* current = new Node;
	Node* previous = new Node;
	current = head;
	for (int i = 1; i < pos; i++)
	{
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
}

List List::remove_value(int value) {
	List new_l;

	Node* current = head;
	while (current != NULL) {
		if (value != current->data) {
			new_l.add(current->data);
		}
		current = current->next;
	}
	return new_l;
}