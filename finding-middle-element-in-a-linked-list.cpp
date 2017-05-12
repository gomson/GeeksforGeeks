// Finding middle element in a linked list
// http://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
// http://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

/*
Given a singly linked list, find middle of the linked list. For example, if given linked list is 1->2->3->4->5 then output should be 3. 

If there are even nodes, then there would be two middle nodes, we need to print second middle element. For example, if given linked list is 1->2->3->4->5->6 then output should be 4.

Input:
You have to complete the method which takes one argument: the head of the linked list. You should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return data of linked list.  If linked list is empty, then return -1.

Constraints:
1 <=T<= 30
1 <=N<= 100
1 <=value<= 1000

Example:
Input:
2
5
1 2 3 4 5
6
2 4 6 7 5 1

Output:
3
7
*/

#include <iostream> // std::cout; std::cin
#include <fstream> // std::fstream::open; std::fstream::close; 
#include <cstdlib> // rand
#include <cassert> // assert
#include <cctype> // isalnum; isalpha; isdigit; islower; isupper; isspace; tolower; toupper
#include <cmath> // pow; sqrt; round; fabs; abs; log
#include <climits> // INT_MIN; INT_MAX; LLONG_MIN; LLONG_MAX; ULLONG_MAX
#include <cfloat> // DBL_EPSILON; LDBL_EPSILON
#include <cstring> // std::memset
#include <algorithm> // std::swap; std::max; std::min; std::min_element; std::max_element; std::minmax_element; std::next_permutation; std::prev_permutation; std::nth_element; std::sort; std::lower_bound; std::upper_bound; std::reverse
#include <limits> // std::numeric_limits<int>::min; std::numeric_limits<int>::max; std::numeric_limits<double>::epsilon; std::numeric_limits<long double>::epsilon;
#include <numeric> // std::accumulate; std::iota
#include <string> // std::to_string; std::string::npos; std::stoul; std::stoull; std::stoi; std::stol; std::stoll; std::stof; std::stod; std::stold; 
#include <list> // std::list::merge; std::list::splice; std::list::merge; std::list::unique; std::list::sort
#include <bitset>
#include <vector>
#include <deque>
#include <stack> // std::stack::top; std::stack::pop; std::stack::push
#include <queue> // std::queue::front; std::queue::back; std::queue::pop; std::queue::push; std::priority_queue; std::priority_queue::top; std::priority_queue::push; std::priority_queue::pop
#include <set> // std::set::count; std::set::find; std::set::equal_range; std::set::lower_bound; std::set::upper_bound
#include <map> // std::map::count; std::map::find; std::map::equal_range; std::map::lower_bound; std::map::upper_bound
#include <unordered_set>
#include <unordered_map>
#include <utility> // std::pair; std::make_pair
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

struct Node {
	int data;
	Node *next;
};

int getMiddle(Node *head) {
	if (!head) {
		return -1;
	}
	Node *it = head, *jt = head;
	while (jt and jt->next) {
		it = it->next;
		jt = jt->next;
		jt = jt->next;
	}
	return it->data;
}

#ifndef __main__
#define __main__
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l;
		cin >> l;
		Node *head, *it;
		for (int j = 0; j < l; j++) {
			if (j == 0) {
				head = new Node;
				cin >> head->data;
				it = head;
				head->next = NULL;
				continue;
			}
			it->next = new Node;
			it = it->next;
			it->next = NULL;
			cin >> it->data;
		}
		cout << getMiddle(head) << '\n';
	}
	return 0;
}
#endif