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

#include <iostream>
#include <vector>
#include <climits>
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
