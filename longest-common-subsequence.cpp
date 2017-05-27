// Longest Common Subsequence
// http://practice.geeksforgeeks.org/problems/longest-common-subsequence/0

/*
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .


Output:
For each test case print the length of longest  common subsequence of the two strings .


Constraints:
1<=T<=30
1<=size(str1),size(str2)<=100


Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2

Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2
*/

#include <bits/stdc++.h>
using namespace std;

int LCS(string str1, int m, string str2, int n) {
	vector<vector<int>> OPT(2, vector<int>(n + 1, 0));
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			int k = i % 2;
			if (i == 0 or j == 0) {
				OPT[k][j] = 0;
			}
			else if (str1[i - 1] == str2[j - 1]) {
				OPT[k][j] = 1 + OPT[1 - k][j - 1];
			}
			else {
				OPT[k][j] = max(OPT[1 - k][j], OPT[k][j - 1]);
			}
		}
	}
	return OPT[m % 2][n];
}

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		int m, n;
		cin >> m >> n;
		string str1, str2;
		cin >> str1 >> str2;
		cout << LCS(str1, m, str2, n) << '\n';
	}
	return 0;
}