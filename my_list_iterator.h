#pragma once
// TODO: declare your my_list_iterator class here
#include "my_list.h"

class my_list_iterator {
public:
	my_list_iterator(my_list*, bool end);
	my_list_iterator(const my_list_iterator&);
	int& operator*();
	bool operator==(const my_list_iterator compare_against) const;
	bool operator!=(const my_list_iterator compare_against) const;
	my_list_iterator& operator++();
	my_list_iterator& operator--();

	ListNode* get_mem();
	bool is_end();

private:
	friend class my_list;
	my_list* list;
	ListNode* curr_node;
	bool e;
};