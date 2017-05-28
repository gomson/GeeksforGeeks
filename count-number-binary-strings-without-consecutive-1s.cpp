// Count number of binary strings without consecutive 1's
// http://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/
// http://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed/0

/*
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

#include <bits/stdc++.h>
using namespace std;

int countStrings(int N) {
	vector<size_t> f(max(N + 1, 2), 0);
	f[0] = 1;
	f[1] = 2;
	for (int i = 2; i <= N; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[N] % 1000000007;
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