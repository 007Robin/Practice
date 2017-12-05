#pragma once
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class LinkedList{
	private:
		class Node{ 
			//Our LinkedList point to a Node, contain node definition,  doesn't contain a node
		public:
			Node* next;
			T val;
			Node(Node* n, const T& v): next(n), val(v){
			}
		
		};
		Node* head;
/*	public:
		LinkedList();
		void addFirst(const T& v) ;
		void addLast(const T& v) ;
		void removeFirst() ;
		//friend ostream& operator<<(ostream& s, const LinkedList<T>& list){ //old complier
		friend std::ostream& operator<<(std::ostream& s, const LinkedList<T>& list); //c++11
*/
	public:
		LinkedList(){	
			head = nullptr;	
		}
		void addFirst(const T& v) {
			head = new Node(head, v);
		}
		void addLast(const T& v){
			if(head == nullptr){
				head = new Node(nullptr, v);
				return;
			}
			Node* p;
			for(p = head; p->next != nullptr; p=p->next)
				;
			p->next = new Node(nullptr, v);
		}
		void removeFirst(){
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		friend std::ostream& operator<<(std::ostream& s, const LinkedList<T>& list){
			Node* p;
			for(p = list.head; p != nullptr; p = p->next){
				s << p->val << " ";
			}
			return s;
		}

};
