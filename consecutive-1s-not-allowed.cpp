// Count number of binary strings without consecutive 1's
// http://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/

/*
Consecutive 1's not allowed
http://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed/0
Problem Description:
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. Output your answer mod 10^9 + 7.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contain an integer N representing length of the binary string.

Output:
Print the count number of binary strings without consecutive 1’s of length N.

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 70

Example:
Input:
2
3
2

Output:
5
3

Explaination:
For first test case 5 strings are (000, 001, 010, 100, 101)
For second test case 3 strings are (00,01,10)
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
#include <queue> // std::queue::front; std::queue::back; std::queue::pop; std::queue::push
#include <set> // std::set::count; std::set::find; std::set::equal_range; std::set::lower_bound; std::set::upper_bound
#include <map> // std::map::count; std::map::find; std::map::equal_range; std::map::lower_bound; std::map::upper_bound
#include <unordered_set>
#include <unordered_map>
#include <utility> // std::pair; std::make_pair
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

int countStrings(int N) {
    vector<size_t> a(N + 1, 0), b(N + 1, 0);
    a.at(0) = 0;
    b.at(0) = 1;
    for (int i = 1; i <= N; i++) {
        a.at(i) = b.at(i - 1);
        b.at(i) = a.at(i - 1) + b.at(i - 1);
    }
    return (a.at(N) + b.at(N)) % 1000000007;
}

int main(void) {
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
	    cin >> N;
	    cout << countStrings(N) << '\n';
	}
	return 0;
}
