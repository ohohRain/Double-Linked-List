// TODO: define your my_list class here
#include "ListNode.h"
#include "my_list.h"
#include <iostream>
#include "my_list_iterator.h"
#include "vector";
using namespace std;

my_list::my_list()
	: first_node(nullptr), last_node(nullptr), list_size(0){
	//cout << "constructor of my_list" << endl;
}

my_list::~my_list() {
	this->clear();
	//cout << "destructor of my_list" << endl;
	
}

unsigned int my_list::get_size() {
	return list_size;
}

int& my_list::front() {
	if (this->get_size() == 0) {
		throw exception("Empty list");
	}
	return first_node->getValue(); 
}

int& my_list::back() {
	if (this->get_size() == 0) {
		throw exception("Empty list");
	}
	return last_node->getValue();
}

void my_list::push_back(int back) {
	class ListNode* newNode = new ListNode(nullptr, last_node, back);
	list_size += 1;
	if (last_node != nullptr) {
		last_node->setNext(newNode);
	}
	if (list_size == 1) {
		first_node = newNode;
	}
	last_node = newNode;

	//delete newNode;

}

void my_list::push_front(int front) {
	class ListNode* newNode = new ListNode(first_node, nullptr, front);
	list_size += 1;
	if (first_node != nullptr) {
		first_node->setPrevious(newNode);
	}
	if (list_size == 1) {
		last_node = newNode;
	}
	first_node = newNode;

	//delete newNode;
	
}

void my_list::pop_back() {
	if (this->get_size() == 0) {
		throw exception("Empty list");
	}

	else if (list_size == 1) {
		ListNode* p = get_last();
		first_node = nullptr;
		last_node = nullptr;
		delete p;
	}
	else {
		ListNode* p = get_last();
		last_node = last_node->getPrevious();
		last_node->setNext(nullptr);
		delete p;
	}
	
	
	list_size -= 1;
	
}

void my_list::pop_front() {
	if (this->get_size() == 0) {
		throw exception("Empty list");
	}
	else if (list_size == 1) {
		ListNode* p = get_last();
		first_node = nullptr;
		last_node = nullptr;
		delete p;
	}
	else {
		ListNode* p = get_first();
		first_node = first_node->getNext();
		first_node->setPrevious(nullptr);
		delete p;
	}
	

	list_size -= 1;
	
}

void my_list::clear() {
	while (this->get_size() != 0) {
		pop_front();
	}
}
//------------------------------------------
ListNode* my_list::get_first() {
	if (get_size() == 0) {
		return nullptr;
	}
	else {
		return first_node;
	}
	
}

ListNode* my_list::get_last() {
	if (get_size() == 0) {
		return nullptr;
	}
	else {
		return last_node;
	}
	
}

my_list::my_list(const my_list& other){
	if (other.first_node == nullptr) {
		return;
	}
	else {
		vector<int> v;
		ListNode* other_temp = other.first_node;
		while (other_temp != nullptr) {
			v.push_back(other_temp->getValue());
			other_temp = other_temp->getNext();
		}
		for (int value : v) {
			this->push_back(value);
		}
	}
}

my_list& my_list::operator=(const my_list& other) {
	if (this == &other) {
		return *this;
	}

	else if (other.first_node == nullptr) {
		this->clear();
		return *this;
	}
	else {
		this->clear();
		vector<int> v;
		ListNode* other_temp = other.first_node;
		while (other_temp != nullptr) {
			v.push_back(other_temp->getValue());
			other_temp = other_temp->getNext();
		}
		for (int value : v) {
			this->push_back(value);
		}
		return *this;
		
	}


}


my_list_iterator my_list::begin() {
	my_list_iterator l_it(this, false);
	return l_it;
}

my_list_iterator my_list::end() {
	my_list_iterator l_it(this, true);
	return l_it;
}

my_list_iterator my_list::insert(my_list_iterator l_it, int value) {
	//1. check if valid, l_it.list is the list it self
	if (l_it.list == this) {
	//2. If the list is empty, insert it as the first
		if (this->get_size() == 0) {
			class ListNode* node = new ListNode(nullptr, nullptr, value);
			first_node = node;
			last_node = node;
			l_it.curr_node = node;
			list_size++;
			return l_it;
		}
	//3. If end is true, insert at back
		else if (this->get_size() != 0 && l_it.e == true) {
			class ListNode* node = new ListNode(nullptr, nullptr, value);
			this->get_last()->setNext(node);
			node->setPrevious(this->get_last());
			last_node = node;
			l_it.curr_node = node;
			list_size++;
			l_it.e = false;
			return l_it;
		}
	//4.Insert front
		else if (l_it.curr_node == this->get_first()) {
			class ListNode* node = new ListNode(nullptr, nullptr, value);
			first_node = node;
			ListNode* curr = l_it.curr_node;
			curr->setPrevious(node);
			node->setNext(curr);
			l_it.curr_node = node;
			list_size++;
			return l_it;
		}
	
	//5. Else insert in between the list
		else {
			class ListNode* node = new ListNode(nullptr, nullptr, value);
			ListNode* curr = l_it.curr_node;
			node->setNext(curr);
			node->setPrevious(curr->getPrevious());
			curr->getPrevious()->setNext(node);
			curr->setPrevious(node);
			l_it.curr_node = node;
			list_size++;
			return l_it;
		}
	}
	
	else {
		throw exception("This is not a valid iterator");
	}
	
}

my_list_iterator my_list::erase(my_list_iterator l_it) {
	if (l_it.list == this) {
		if (l_it.e == true) {
			throw exception("Can't earse the node when past-the-end");
		}
		else {
			//erase the only node
			if (this->get_size() == 1) {
				this->pop_front();
				l_it.curr_node = nullptr;
				l_it.e = true;
				list_size--;
				return l_it;
			}
			//erase front
			else if (l_it.curr_node == this->get_first() && this->get_size() != 1) {
				l_it.curr_node = l_it.curr_node->getNext();
				this->pop_front();
				
				return l_it;
				
			}
			//erase last
			else if (l_it.curr_node == this->get_last() && this->get_size() != 1) {
				l_it.curr_node = nullptr;
				this->pop_back();
				l_it.e = true;
				
				return l_it;

			}
			else {
				ListNode* curr = l_it.curr_node;
				curr->getPrevious()->setNext(curr->getNext());
				curr->getNext()->setPrevious(curr->getPrevious());
				l_it.curr_node = curr->getNext();
				delete curr;
				list_size--;
				return l_it;
				
			}
		}
	}

	else {
		throw exception("This is not a valid iterator");
	}
}








