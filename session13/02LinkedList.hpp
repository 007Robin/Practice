#include "02LinkedList.hh"

template<typename T>
LinkedList<T>::LinkedList(){
	head = nullptr;
}

template<typename T>
void LinkedList<T>::addFirst(const T& v){
	head = new Node(head, v);
}

template<typename T>
void LinkedList<T>::addLast(const T& v){
	if(head == nullptr){
		head = new Node(nullptr, v);
		return;
	}
	typename LinkedList<T>::Node* p;
	for(p = head; p->next != nullptr; p = p->next)
		;
	p->next = new Node(nullptr, v);
}

template<typename T>
void LinkedList<T>::removeFirst() {
	typename LinkedList<T>::Node* temp = head;
	head = head->next; //if head is null. head->next make no sense
	delete temp;    //must memory delete
}
/*
template<typename T>
std::ostream& operator<<(std::ostream& s, const LinkedList<T>& list){ //c++11
	typename LinkedList<T>::Node* p;
	for(p = list.head; p != nullptr; p = p->next){ //p++ only memery adress +1, must p = p->next
		s << p->val << " ";
	}
	return s;
}
*/
