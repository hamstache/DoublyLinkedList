#ifndef __DblLinkedList__DblLinkedList__
#define __DblLinkedList__DblLinkedList__

#include <iostream>
#include <string>
using namespace std;

template <typename T> class DblLinkedList;
template <typename T> std::ostream& operator <<(std::ostream&, DblLinkedList<T> const &);

template <typename T>
class DblLinkedList {
public:
    DblLinkedList();
	DblLinkedList(DblLinkedList<T> const& other);
	DblLinkedList<T>& operator=(DblLinkedList<T> const& other);
	~DblLinkedList();
    
	struct Node{
		Node(T val) : _val(val), _prev(nullptr), _next(nullptr) {}
		T _val;
        Node* _prev;
		Node* _next;
	};
    
	void push_front(T val);
	void push_back(T val);
    
	T pop_front();
	T pop_back();
    
	void insert(T val, Node* before);
	void deleteNode(Node* node);
	bool empty() const;
	const Node* front() const;
	const Node* back() const;
    size_t  size() const;
	friend ostream& operator<< <T> (ostream& os, DblLinkedList<T> const& list);
    
private:
	void copy(DblLinkedList<T> const& other);
	void deleteRest(Node* from);
    
private:
	size_t _size;
	Node* _head;
    Node* _tail;
};
//#include "LinkedListT.cpp"

template <class T>
DblLinkedList<T>::DblLinkedList() : _head(nullptr), _tail(nullptr) { }

template <class T>
DblLinkedList<T>::DblLinkedList(DblLinkedList<T> const& other) : _head(nullptr), _tail(nullptr) { copy(other); }


template <class T>
DblLinkedList<T>& DblLinkedList<T>::operator=(DblLinkedList<T> const& other) {
	if (this != &other){ copy(other); }
	return *this;
}


template <class T>
DblLinkedList<T>::~DblLinkedList() { deleteRest(_head); }

template <class T>
void DblLinkedList<T>::push_front(T val) {
	DblLinkedList<T>::Node *p = new Node(val);
	p->_next = _head;
	_head = p;
	_size++;
}

template <class T>
void DblLinkedList<T>::push_back(T val){
	if (_head == nullptr) { _head = new Node(val); ++_size; return; }        //not wrong, just not necessary
	typename DblLinkedList<T>::Node *p = _head;
	while (p->_next != nullptr)  { p = p->_next; }
	p->_next = new Node(val);
	++_size;
}

template <class T>
T DblLinkedList<T>::pop_front(){
	if (empty()) {
		throw std::out_of_range("out of range in LinkedListT<T>::pop_front()");
	}
	if (_head == nullptr){ throw std::out_of_range("..."); }
	//if (_size == 1){ _head->_next = new Node; ++_size; return ; }
    
	T result = _head->_val;
	typename ::DblLinkedList<T>::Node *pNext = _head->_next;
	delete _head;
	_head = pNext;
	return result;
}

template <class T>
T DblLinkedList<T>::pop_back(){
	if (empty()) {
		throw std::out_of_range("out of range in LinkedList<T>::pop_back()");
	}
	if (_size == 1){
		T result = _head->_val;
		_head = nullptr;
		delete _head;
		--_size;
		return result;
	}
	DblLinkedList<T>::Node *p = _head, *pPrev = _head;
	while (p->_next != nullptr) {
		pPrev = p;
		p = p->_next;
	}
	T result = p->_val;
	delete p;
	pPrev->_next = nullptr;
	--_size;
	return result;
}

template <class T>
void DblLinkedList<T>::insert(T val, Node* before){
    DblLinkedList<T>::Node *p = _head, *pPrev = _head;
    while (p-> _next != nullptr && p->_next != before) {
        pPrev = p;
        p = p->_next;
    }
    if (p->_next == nullptr) {return; }
	p = new Node(val);
    pPrev->_next = p;
    p->_prev = pPrev;
    p->_next = before;
	before->_prev = p;
    _size++;
	
}

template <class T>
void DblLinkedList<T>::deleteNode(Node* node){
	DblLinkedList<T>::Node *p = _head, *pPrev = _head;
	while (p->next != nullptr && p->_next != node){
		pPrev = p;
		p = p->_next;
	}
	if (p->_next == nullptr) { return; }            //node not found
	pPrev->_next = p->_next;
	delete p;
	_size--;
}

template <class T>
bool DblLinkedList<T>::empty() const { return _head == nullptr; }

template <class T>
void  DblLinkedList<T>::copy(const DblLinkedList<T>& other){
	deleteRest(_head);
	if (other._head == nullptr)  { _head = nullptr;  return; }
	_head = new Node(other._head->_val);
	DblLinkedList<T>::Node *p = _head, *pPrev = _head, *q = other._head;
	while (q->_next != nullptr)  {
		p = new Node(q->_next->_val);
		pPrev->_next = p;
		pPrev = p;
	}
	p->_next = nullptr;
}

template <class T>
void DblLinkedList<T>::deleteRest(Node* from) {
	typename DblLinkedList<T>::Node *p = _head, *pNext;
    
	if (_head == nullptr || from == nullptr) { return; }
	while (p->_next != nullptr){
		pNext = p->_next;
		delete p;
		p = pNext;
	}
	delete p;
}

template <class T>
const typename DblLinkedList<T>::Node* DblLinkedList<T>::front() const { return _head; }

template <class T>
const typename DblLinkedList<T>::Node* DblLinkedList<T>::back() const{
    DblLinkedList<T>::Node *p = _head, *pNext = _head;
	if (empty()) { return; }
	if (_size == 1) { return _head; }
	while (pNext != nullptr){ return *p; }
}

template <class T>
std::ostream& operator<<(std::ostream& os, DblLinkedList<T> const& list) {
	os << "DblLinkedList<T>[";
	if (list.empty()) { return os << "(empty)]" << std::endl; }
	os << "(";
	typename DblLinkedList<T>::Node*  p = list._head;
	while (p != nullptr) {
		os << p->_val;
		os << " ";
		p = p->_next;
	}
	//while the pointer is not equal to pval
	return  os << "]";
}


#endif

