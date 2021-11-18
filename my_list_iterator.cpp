// TODO: define your my_list_iterator here
#include "my_list_iterator.h"
#include <iostream>
#include <list>
using namespace std;

my_list_iterator::my_list_iterator(my_list* b, bool end) {
	list = b;
	e = end;
	if (e) {
		curr_node = nullptr;
	}
	else {
		curr_node = list->get_first();
	}
}

my_list_iterator::my_list_iterator(const my_list_iterator& other) 
	: list(other.list), curr_node(other.curr_node), e(other.e){}

int& my_list_iterator::operator*() {
	if (curr_node == nullptr) {
		throw exception("Current Node is Empty");
	}

	else {
		
		return curr_node->getValue();
	}
}

bool my_list_iterator::operator==(const my_list_iterator other) const {
	if (this->list != other.list) {
		throw exception("Two iterator points to different my_list");
	}
	else {
		if (this->curr_node == other.curr_node) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool my_list_iterator::operator!=(const my_list_iterator other) const {
	if (this->list != other.list) {
		throw exception("Two iterator points to different my_list");
	}
	else {
		if (this->curr_node == other.curr_node) {
			return false;
		}
		else {
			return true;
		}
	}
}

my_list_iterator& my_list_iterator::operator++() {
	
	if (e) {
		
		throw exception("This is the end of the list");
		
	}
	else {
		
		curr_node = curr_node->getNext();
		if (curr_node == nullptr) {
			e = true;
		}
		return *this;
	}
}

my_list_iterator& my_list_iterator::operator--() {
	if (e) {
		curr_node = list->get_last();
		e = false;
		return *this;
	}
	else {
		if (curr_node->getPrevious() == nullptr) {
			throw exception("It is the first one, there's no more ListNode");
		}
		else {
			curr_node = curr_node->getPrevious();
			return *this;
		}
	}
}

ListNode* my_list_iterator::get_mem() {
	return curr_node;
}

bool my_list_iterator::is_end() {
	if (e) {
		return true;
	}
	else {
		return false;
	}
}