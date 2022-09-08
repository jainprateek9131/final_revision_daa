Question: Given an array arr[] of integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}, sum = 10
Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10}

int CountSubsetsWithSum(int arr[], int n, int sum) {
	int t[n + 1][sum + 1]; // DP - matrix
	// initialization
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0)
				t[i][j] = 0;
			if (j == 0)
				t[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] <= j)
				t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j]; //is sum exist only add +
			else
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][sum];
}
