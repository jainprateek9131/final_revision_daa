Partition a set into two subsets such that the difference of subset sums is minimum:-
Given an array arr of size N containing non-negative integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their
sums is minimum and find the minimum difference

Example: 
Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11 
  
Input: N = 2, arr[] = {1, 4}
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4
//here we cannot use the memoization approch because it does not cover all blocks of table
  
-10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 
-10 1 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 
-10 -10 -10 -10 -10 -10 -10 1 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 
-10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 1 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 
-10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 -10 1 
23
4
1 6 5 11
  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    bool helper(int n, int arr[], int W ,vector<vector<int>>&dp){
        if(W==0)return 1;
        if( n==0){
            return 0;
        }
        if(dp[n][W]!=-10){
           return dp[n][W];
        }
       if(W >= arr[n-1]){
           return dp[n][W]=helper(n-1,arr,W-arr[n-1],dp)||
                          helper(n-1,arr,W,dp);
       }else if(W < arr[n-1]){
           return dp[n][W]=helper(n-1,arr,W,dp);
       }cout<<dp[n][W]<<" ";
    }
	int minDifference(int arr[], int n)  { 
	    int sum =0;
	    for(int i=0;i<n;i++)
	    sum+=arr[i];
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-10));
	    
	    helper(n,arr,sum,dp);
	    cout<<endl;
	    for(int i=0;i<=n;i++){
	    for(int j=0;j<=sum;j++)
	    cout<<dp[i][j]<<" ";cout<<endl;
	    }
	    
	    for(int i=sum/2 ; i>=0; i--){
	    if(dp[n][i]==1){
	        return sum-2*i;
	     }
	    }
	    return sum;
	} 
	
};
