
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>
#include <vector>
//#include "leaker.h"

using namespace std;

template<typename T>
class LinkedList {

	public:
		// a public node class
		class Node {
			public:
				// data memebers for the node
				T data;
				Node* next;
				Node* prev;
				// default constructor
				Node(T data = T()) {
					this->data = data;
					next = nullptr;
					prev = nullptr;
				}
			private:
				friend class LinkedList;
		};
		
		//default constructor for linked list class
		LinkedList() {

			head = nullptr;
			tail = nullptr;
			node_count = 0;

		}
		//copy constructor for the linked list class
		LinkedList(const LinkedList& list) {
			// reset the heads and tails to null
			head = nullptr;
			tail = nullptr;
			node_count = list.node_count;
			// rebuild the linked list by copying rhs values 
			for (Node* temp = list.head; temp != nullptr; temp = temp->next) {
				AddTail(temp->data);
			}

		}
		
		//destructor
		~LinkedList() {
			Clear();
		}

		/*============== Helper =================*/

		// checks if lhs node equals to rhs node
		bool operator!= (const LinkedList<T>& rhs) const {
			return !(*this == rhs);
		}

		// move constructor 
		LinkedList(LinkedList<T>&& rhs) {
			head = rhs->head;
			tail = rhs->tail;
			node_count = rhs->node_count;
			rhs->head = nullptr;
			rhs->tail = nullptr;
			rhs->node_count = 0;
		}

		// move assignment operator
		LinkedList& operator= (LinkedList<T>&& rhs) {
			
			this->Clear();

			head = rhs->head;
			tail = rhs->tail;
			node_count = rhs->node_count;
			rhs->head = nullptr;
			rhs->tail = nullptr;
			rhs->node_count = 0;

			return (*this);
		}

		/*============ Behaviours ==============*/
	
		// prints linked lists forwards, backwards
		void PrintForward() const;
		void PrintReverse() const;

		// rescusive forward print
		void PrintForwardRecursive(const Node* node) const {
			if (node == nullptr) {
				return;
			}
			cout << node->data << endl;
			PrintForwardRecursive(node->next);
		}
		// rescusive backward print
		void PrintReverseRecursive(const Node* node) const {
			if (node == nullptr) {
				return;
			}
			cout << node->data << endl;
			PrintReverseRecursive(node->prev);

		}

		/*============ Accessors ==============*/

		// gives how many nodes there in the list
		unsigned int NodeCount() const;

		// return the pointer to head
		const Node* Head() const {
			return head;
		}
		Node* Head() {
			return head;
		}

		// return the pointer to tail
		const Node* Tail() const {
			return tail;
		}
		Node* Tail() {
			return tail;
		}

		// returns the pointer to node at the i-index
		const Node* GetNode(unsigned int index) const {
			
			if (index >= node_count) {
				throw out_of_range("GetNode: Index out of bounds.");
			}
			//make temprory node quals to tail
			Node* current = tail;
			unsigned int n = 0;
			// iterate with previous and
			// add the counter and check if counter equals to the index
			while (current != nullptr) {
				if (n == index) {
					return (current);
				}
				n++;
				current = current->prev;
			}
			return (current); // return the temp Node*
		}

		Node* GetNode(unsigned int index) {
			
			if (index >= node_count) {
				throw out_of_range("GetNode: Index out of bounds.");
			}
			Node* current = tail;
			unsigned int n = 0;
			while (current != nullptr) {
				if (n == index) {
					return (current);
				}
				n++;
				current = current->prev;
			}
			return (current);

		}

		// get the vector container to store matching rhs values
		void FindAll(vector<Node*>& outData, const T& value) const {
			//iterate, check if values are same, push back
			for (Node* temp = head; temp != nullptr; temp = temp->next) {
				if (temp->data == value) {
					outData.push_back(temp);
				}
			}

		}

		// find the single node matching rhs data
		const Node* Find(const T& data) const {

			for (Node* temp = head; temp != nullptr; temp = temp->next) {
				if (temp->data == data) {
					return (temp);
				}
			}
			return (nullptr);
			
		}

		Node* Find(const T& data) {
			
			for (Node* temp = head; temp != nullptr; temp = temp->next) {
				if (temp->data == data) {
					return (temp);
				}
			}
			return (nullptr);
		}
		
		/*============ Insertion ==============*/

		// add or create head node with rhs data
		void AddHead(const T& data);
		void AddNodesHead(const T* data, unsigned int count);

		// add or create tail node with rhs data
		void AddTail(const T& data);
		void AddNodesTail(const T* data, unsigned int count);

		// insert a node after a lhs node with rhs data
		void InsertAfter(Node* node, const T& data);
		void InsertBefore(Node* node, const T& data);

		// insert a node at a specific index with lhs data
		void InsertAt(const T& data, unsigned int index);

		/*============= Removal ===============*/

		// removes all the nodes in the list
		void Clear();

		// removes head node, and re-assigns head
		bool RemoveHead();
		// removes tail node, and re-assigns tail
		bool RemoveTail();

		// remove all the node that match with rhs data, and returns count of node removed
		unsigned int Remove(const T& data);
		// remove a node at an index, returns true if successful
		bool RemoveAt(unsigned int index);

		/*============ Operators ==============*/

		// allows node accessbility with [] operator
		const T& operator[] (unsigned int index) const;
		T& operator[] (unsigned int index);

		// compares all the values in the rhs list with local object, returns true if all same
		bool operator== (const LinkedList<T>& rhs) const;

		// copy assignement operator
		LinkedList& operator= (const LinkedList<T>& rhs) {
			//self-reference
			if (this == &rhs) {
				return *this;
			}
			//delete all the existing nodes
			Clear();

			//new(this) LinkedList(rhs);
			// re-copy the elements from rhs and create a list
			Node* temp = rhs.head;
			while (temp != nullptr) {
				AddTail(temp->data);
				temp = temp->next;
			}

			return *this;
		}
	// data members	
	private:
		Node* head;
		Node* tail;
		unsigned node_count;

};

/*============ Behaviours defintions ==============*/
template<typename T>
void LinkedList<T>::PrintForward() const {

	for (Node* temp = head; temp!= nullptr; temp = temp->next) {
		cout << temp->data << endl;
	}

}

template<typename T>
void LinkedList<T>::PrintReverse() const {

	for (Node* temp = tail; temp != nullptr; temp = temp->prev) {
		cout << temp->data << endl;
	}

}

/*============ Accessors defintions ==============*/

template<typename T>
unsigned int LinkedList<T>::NodeCount() const {
	return(node_count);
}

/*============ Insertion defintions ==============*/

template<typename T>
void LinkedList<T>::AddHead(const T& data) {
	// make a temprory node with value passed 
	try {
		Node* temp = new Node(data);
		// check if head exists,  if no, create one and point head-tail to it
		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			//otherwise make temps next to head and readjust head
			temp->next = head;
			head = temp;
			temp->next->prev = temp;
		}
		node_count++; //node count up
	}
	catch (exception& e) {
		cout << "AddHead: " << e.what() << endl;
	}
	
}

template<typename T>
void LinkedList<T>::AddTail(const T& data) {
	try {
		// same logic as AddHead, except for tail
		Node* temp = new Node(data);
		if (tail == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			temp->prev = tail;
			tail = temp;
			temp->prev->next = temp;
		}
		node_count++;
	}
	catch(exception &e) {
		cout << "AddTail: " << e.what()  << endl;
	}
	
}

template<typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) {
	// iterate backwards in the array and create nodes and link them 
	// before head node
	for (int i = (int)(count - 1); i >= 0; i--) {
		try {
			AddHead(*(data + i)); //call existing add head function to add them
		}
		catch (exception& e) {
			cout << "AddNodesHead: " << e.what() << endl;
		}
	}
}

template<typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) {

	//same as AddNodeshead, but adds array after tail
	for (unsigned int i = 0; i < count; i++) {
		try {
			AddTail(*(data + i));
		}
		catch (exception& e) {
			cout << "AddNodesTail: " << e.what() << endl;
		}
	}
}

template<typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data) {

	try {
		// if list is empty, return nothing
		if (head == nullptr) {
			return;
		}
		// make temprory node and connect the head 
		// and prev pointers
		Node* temp = new Node(data);
		temp->next = node->next;
		node->next = temp;
		temp->prev = node;

		//if node doesn't point to null, points the 
		// neighbor's prev pointer to temp
		if (node->next != nullptr) {
			node->next->prev = temp;
		}
		// connect lhs node to temp 
		node->next = temp;
		// if lhs node is tail, make temp node tail
		if (node == tail) {
			tail = temp;
		}
		
	}
	catch(exception& e) {
		cout << "InsertAfter: " << e.what() << endl;
	}

	node_count++;

}

template<typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data) {
	try {

		// same concept as InsertAfter
		// except it checks for tail and prev pointers
		// and adds the Node before lhs node.
		if (tail == nullptr) {
			return;
		}
		
		Node* temp = new Node(data);
		temp->prev = node->prev;
		temp->next = node;

		if (node->prev != nullptr) {
			node->prev->next = temp;
		}

		if (node == head) {
			head = temp;
		}

	}
	catch (exception& e) {
		cout << "InsertAfter: " << e.what() << endl;
	}

	node_count++;
}

template<typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index) {

	// insertAt checks if the given idex is invalid
	if (index > node_count || index < 0) {
		throw out_of_range("InsertAt: Index out of bounds.");
	} 
	// if index is 0, at node the before head, make new node head
	else if (index == 0) {
		InsertBefore(head, data);
	}
	//if index is the end, at node the after tail, make new node tail
	else if (index == node_count) {
		InsertAfter(tail, data);
	}
	else {
		//if node is anywher else, move pointer where lhs nodes needs
		// to be inserted. Then create a new node and insert it.
		node_count++;
		
		Node* temp = new Node(data);
		Node* temp_curr = head;

		for (unsigned int i = 0; i < (index - 1); i++) {
			temp_curr = temp_curr->next;
		}

		temp->next = temp_curr->next;
		temp->prev = temp_curr;
		temp->next->prev = temp;
		temp_curr->next = temp;

	}
	
	return;

}

/*=============   Removal definitions ================*/

template<typename T>
void LinkedList<T>::Clear() {
	
	//delete nodes by iterating
	Node* temp = nullptr;
	while (head != nullptr) {
		temp = head->next;
		delete head;
		head = nullptr;
		head = temp;
	}
	tail = nullptr;
	node_count = 0;
}

template<typename T>
bool LinkedList<T>::RemoveHead() {
	try{
		//check if node is empty
		if (node_count == 0) {
			return (false);
		}
		// remove head if only head exist
		else if (node_count == 1 || (head == tail)) {

			delete head;
			node_count--;
			head = nullptr;
			tail = nullptr;

			return (true);
		}
		// if more node exists move head's next pointer
		// remove old head
		else{
			node_count--;
			Node* temp = head->next;
			temp->prev = nullptr;
			delete head;
			head = temp;
			return (true);
		}

		return (false);
	}
	catch (exception& e) {
		cout << "RemoveHead: " << e.what() << endl;
	}
	
}

template<typename T>
bool LinkedList<T>::RemoveTail() {
	try{
	// same as removeHead() but we move tail	 
		if (node_count == 0) {
			return (false);
		}
		else if (node_count == 1 || (head == tail)) {

			delete tail;
			node_count--;
			head = nullptr;
			tail = nullptr;

			return (true);
		}
		else {
			node_count--;
			Node* temp = tail->prev;
			temp->next = nullptr;
			delete tail;
			tail = temp;
			return (true);
		}

		return (false);
	}
	catch (exception& e) {
		cout << "RemoveTail: " << e.what() << endl;
	}
	
}

template<typename T>
unsigned int LinkedList<T>::Remove(const T& data) {

	// remove all the nodes whose data are rhs data
	if (node_count == 0|| head == nullptr || tail == nullptr) {
		throw runtime_error("Remove: List is empty.");
	}

	// vector that holds all the nodes with the data
	vector<LinkedList<T>::Node*> temp_del_nodes;
	
	FindAll(temp_del_nodes, data);

	unsigned int n_removed = 0;

	for (unsigned int i = 0; i < temp_del_nodes.size(); i++) {
		
		// if at head, move the head
		if (head == temp_del_nodes.at(i)){
			head = temp_del_nodes.at(i)->next;
		}
		//if the node is not last, adjust pointers, and make connect it's adjacent neighbor
		if (temp_del_nodes.at(i)->next != nullptr) {
			temp_del_nodes.at(i)->next->prev = temp_del_nodes.at(i)->prev;
		}
		//if the node is not first, adjust pointers, and make connect it's adjacent neighbor
		if (temp_del_nodes.at(i)->prev != nullptr) {
			temp_del_nodes.at(i)->prev->next = temp_del_nodes.at(i)->next;
		}
		// delete the temp node
		delete temp_del_nodes.at(i);
		n_removed++;
	}
	//update the nodes in the list
	node_count = node_count - n_removed;

	return (n_removed);
}

template<typename T>
bool LinkedList<T>::RemoveAt(unsigned int index) {
	try{
		// check the index
		if (index >= node_count || node_count == 0) {
			return (false);
			//throw out_of_range("InsertAt: Index out of bounds.");
		}
		// if head and tail are null, return false
		else if (head == nullptr || tail == nullptr) {
			return (false);
		}
		else {
			// create temp pointer
			unsigned int i = 0;
			Node* temp = nullptr;

			// move the pointer until index
			for (temp = head; i < index; ) {
				temp = temp->next;
				i++;
			}
			//if temp pointer previus exist, adjust pointers
			if (temp->prev != nullptr) {
				temp->prev->next = temp->next;
			}
			//else make it head
			else {
				head = temp->next;
			}

			//if temp pointer next exist, adjust pointers
			if (temp->next != nullptr) {
				temp->next->prev = temp->prev;
			}

			delete temp;
			return(true);
		}

		node_count--;
		return (false);
	}
	catch (exception& e) {
		cout << "RemoveAt: " << e.what() << endl;
	}
}

/*============ Operators defintions ==============*/

template<typename T>
const T& LinkedList<T>::operator[] (unsigned int index) const {
	
	// check the range
	if (index >= node_count) {
		throw out_of_range("operator[]: Index out of bounds.");
	}

	//move using head, when index matches, return the data
	unsigned int i = 0;
	Node* temp = nullptr;

	for (temp = head,i=0; i != index;) {
		temp = temp->next;
		i++;
	}
	return temp->data;
}

template<typename T>
T& LinkedList<T>::operator[] (unsigned int index) {

	if (index >= node_count) {
		throw out_of_range("operator[]: Index out of bounds.");
	}

	unsigned int i = 0;
	Node* temp = nullptr;

	for (temp = head, i = 0; i != index; ) {
		temp = temp->next;
		i++;
	}
	return temp->data;
}

template<typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const {
	// compares the data from data in rhs list
	// first check if they both have same node count
	if (node_count == rhs.node_count) {

		// if head is missing, it's prbably empty
		if (head == nullptr) {
			return (true);
		}
		// point to head in both lists and compare data
		Node* temp_np1 = head;
		Node* temp_np2 = rhs.head;

		while(temp_np1 != nullptr) {
			
			if (temp_np1->data == temp_np2->data) {
				return true;
			}
			
			temp_np1 = temp_np1->next;
			temp_np2 = temp_np2->next;
		}
	}

	return (false);
}

#endif /*_LINKEDLIST_H*/
