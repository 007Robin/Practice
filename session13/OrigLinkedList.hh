#pragma once
#include<iostream>

template<typename T>
class LinkedList{
private:
	class Node{ //Our LinkedList point to a Node, contain node definition,  doesn't contain a node
		public:
			Node* next;
			T val;
			Node(Node* next, const T& v) : next(next), val(v){}
	};
	Node* head;

public:
	LinkedList(){
		head = nullptr;
	}
	void addFirst(const T& v) {
/* 		//use constructor shorter code
		Node* temp = new Node();
		(*temp).next = head;
		temp->val = v;
		head = temp;
*/		head = new Node(head, v);
	}
	void addLast(const T& v) {
		if(head == nullptr) {
			head = new Node(nullptr, v);
			return;
		}
		Node* p;
		for(p = head; p->next != nullptr; p = p->next)
			;
		// p should be pointing to last element
		p->next = new Node(nullptr, v);
	}
	void removeFirst() {
		Node* temp = head;
		head = head->next; //if head is null. head->next make no sense
		delete temp;	//must memory delete
	}
	friend std::ostream& operator<<(std::ostream& s, const LinkedList<T>& list){ //old complier
//		friend ostream& operator<<(ostream& s, const LinkedList& list){ //c++11
		for(Node* p = list.head; p != nullptr; p = p->next){ //p++ only memery adress +1, must p = p->next
			s << p->val;
		}
		return s;
	}
};
