#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
	os << nd->data;
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
	if (head == nullptr)
		head = new Node(d, nullptr);
	else if(head->next == nullptr)
		head->next = new Node(d, nullptr);
	else
		add_at_end(head->next, d);
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
	if(curr == nullptr)
		os << "nullptr" << endl;
	else{
		os << curr << " --> ";
		print_list(os, curr->next);
	}
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
	head = new Node(d, head);
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
	if (head == nullptr)
		return nullptr;
    else if (head->next == nullptr)
		return head;
	else 
		return last(head->next);

}

bool del_head(Node*& head){
	if (head) {
		Node* second = head->next;
		delete head;
		head = second;
		return true;
	}
	return false;
}

bool del_tail(Node*& head) {
	if (head == nullptr)
		return false;
	else if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return true;
	}
	else 
		return del_tail(head->next);
}

Node* duplicate(Node* head) {
	if (head == nullptr)
			return nullptr;
	else {
		return new Node(head->data, duplicate(head->next));
	}
}

Node* reverse(Node* curr, Node* new_next) {
	if (!curr)
		return new_next;
	else
		return reverse(curr->next, new Node(curr->data, new_next));
}

Node* join(Node*& list1, Node* list2) {
	if (list1) {
		Node* p = last(list1);
		p->next = list2;
	} 
	else
		list1 = list2;
	return list1;
}