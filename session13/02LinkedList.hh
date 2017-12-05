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
	public:
		LinkedList();
		void addFirst(const T& v) ;
		void addLast(const T& v) ;
		void removeFirst() ;
		//friend ostream& operator<<(ostream& s, const LinkedList<T>& list){ //old complier
//		friend std::ostream& operator<<(std::ostream& s, const LinkedListi<T>& list); //c++11

		friend std::ostream& operator<<(std::ostream& s, const LinkedList<T>& list){
			Node* p;
			for(p = list.head; p != nullptr; p = p->next){
				s << p->val << " ";
			}
			return s;
		}

};
