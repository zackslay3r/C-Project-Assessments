#pragma once

template<typename T>
//Linked List's DEMO
class ListNode {
public:
	// Each node stores a pointer to the next node in the list.
	ListNode* next;
	// Each node can store a pointer to the previous node in the list.
	// This is used for a double linked list.
	ListNode* prev;
	T value;
};


template<typename T>
class List {

public:


private:
	ListNode<T>* m_first;
	ListNode<T>* m_last;

};