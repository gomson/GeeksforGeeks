// Kadane's Algorithm
// http://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

// Largest Sum Contiguous Subarray
// http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

/*
Given an array containing both negative and positive integers. Find the contiguous sub-array with maximum sum.
 
Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
 
Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.
 
Constraints:
1 ≤ T ≤ 40
1 ≤ N ≤ 100
-100 ≤ A[i] <= 100
 
Example:
Input
2
3
1 2 3
4
-1 -2 -3 -4

Output
6
-1
*/

#include <bits/stdc++.h>
using namespace std;

int largestSumContiguousSubarray(vector<int>& nums) {
	long long result = INT_MIN, c = INT_MIN;
	for (const auto &i : nums) {
		c = max(c + i, (long long)i);
		result = max(result, c);
	}
	return result;
}

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> nums;
		while (N--) {
			int x;
			cin >> x;
			nums.push_back(x);
		}
		cout << largestSumContiguousSubarray(nums) << '\n';
	}
	return 0;
}
