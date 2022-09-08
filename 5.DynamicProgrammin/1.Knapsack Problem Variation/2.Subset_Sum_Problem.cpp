Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 
 Example 1:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with sum = 9, 4+3+2 = 9
  
Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 60
Output: 1 
Explanation: Here there exists a subset with sum = 60, 34+12+5+4+3+2 = 60
  
Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 30
Output: 0 
Explanation: There is no subset with sum 30.
//recursive + memoization --> top down approch
  bool helper(int n, vector<int>arr, int W ,vector<vector<int>>&dp){
        // code here
        if(W==0)return 1;
        if( n==0){
            return 0;
        }
        if(dp[n][W]!=-1){
           return dp[n][W];
       }
       if(W >= arr[n-1]){
           return dp[n][W]=helper(n-1,arr,W-arr[n-1],dp)||
                          helper(n-1,arr,W,dp);
       }else if(W < arr[n-1]){
           return dp[n][W]=helper(n-1,arr,W,dp);
       }
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));//fog(
        //ROW_COUNT,
        //std::vector<int>(COLUMN_COUNT,4));
        return helper(n,arr,sum,dp);
    }

Bottom-up approch:-
      bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1)); //here we can also initialize as false
        for(int i=0 ; i<=n ; i++){
            for(int j=0 ; j<=sum ; j++){
                if(j==0)dp[i][j]=true;
            }
        }
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=sum ; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
