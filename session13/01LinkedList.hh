#pragma once
#include<iostream>
#include<string>
using namespace std;

//template<typename T>
class LinkedList{
	private:
		class Node{ 
			//Our LinkedList point to a Node, contain node definition,  doesn't contain a node
		public:
			Node* next;
			string val;
			Node(Node* n, const string& v): next(n), val(v){
			}
		
		};
		Node* head;
	public:
		LinkedList();
		void addFirst(const string& v) ;
		void addLast(const string& v) ;
		void removeFirst() ;
		//friend ostream& operator<<(ostream& s, const LinkedList<T>& list){ //old complier
		friend std::ostream& operator<<(std::ostream& s, const LinkedList& list); //c++11

};
