Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is 
equal.
Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
  
Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subset.
  
  //top-down approch:-
  bool helper(vector<int> item , int n, int W,vector<vector<int>>&dp){
        if(W==0)return true;
        if(n==0)return false;
        if(dp[n][W]!=-1)return dp[n][W];
        if(item[n-1] <= W){
            return dp[n][W]=helper(item, n-1, W-item[n-1],dp)||helper(item,n-1,W,dp);
        }else{
            return dp[n][W]=helper(item,n-1,W,dp);
        }
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum = 0;
        for(int i=0; i<n; i++)
            sum+=nums[i];
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        if(sum%2 != 0){
            return false;
        }else{
            return helper(nums , n, sum/2,dp);
        }
    }

//Bottom-up approch

bool isSubsetPoss(vector<int> arr, int n, int sum) {
	bool t[n + 1][sum + 1]; // DP - matrix
	// initialization
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0)
				t[i][j] = false;
			if (j == 0)
				t[i][j] = true;
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] <= j)
				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][sum];
}

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int W = 0;
        for (int i=0 ; i<n ; i++ ) {
            W += nums[i];
        }
        if(W % 2 != 0){
            return false;
        }else{
            return isSubsetPoss(nums,n,W/2);
        }
    }
