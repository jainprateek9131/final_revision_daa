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
	
	
Jist of the logic used in the solution (in the end this is quite different from Aditya’s solution, and also more easy to understand):-


1.	We need to partition the array into two subsets such that the difference of their sum is minimum. For that, what we have done is first we don’t know what 
the sum of these two partitions will be, we don’t have any idea about the candidate sums of the subsets of the array. So, first we need to find all the candidate sums.
2.	To find all the candidate sums, we know that the minimum sum possible is 0, and the maximum sum possible is the sum of the whole array (which he’s calling 
as range), all the candidate sums will lie into this range (0-sum). So, after finding the total sum (range), pass this into subset sum function, which will give you
a 2D matrix.
3.	In this 2D matrix, the last row signifies which number is possible as sum out of all the numbers in the range (0-range), so we’ll only work with the last 
row of the matrix, true value means this number is making a sum, and a false value means this number is not making a sum.
4.	Also notice that in the last row, through the first half of the row, we can retrieve the other half, like range-s1 will give me the value in the other
half, and range -2*s1 will give the difference between these two values. Also you can notice that the possibility of minimum difference is more likely in the 
middle of this last row, because two middle elements are more likely to be close to each other than two elements which are lying at the ends of the row.
	The difference between these two middle elements is more likely to be less than the difference obtained by a pair which are far from each other.
	So, what we can do is we can run a loop starting from the middle of the last row to the 0th index of the last row. And then checking if its making a 
	sum (or if it is having a true value), then doing sum-2*s1, which will give me the desired minimum difference. The moment I’ll get this difference I’ll
	come out of this loop, because if I’ll keep on traversing the backward side, the difference will only increase, because, as I’ll move towards 0th index, 
I’m encountering a pair which are far from each other, and thus they’ll give me a big difference as compare to a pair which is closer or equal to the middle number.

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
//bottom up approch

1
4
1 6 5 11
	
	
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
1 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
1 1 0 0 0 1 1 1 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 
1 1 0 0 0 1 1 1 0 0 0 1 1 0 0 0 1 1 1 0 0 0 1 1 
	ans = 1
	
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for ( int i = 0 ; i < n ; i++ ) {
	        sum += arr[i];
	    }
	    bool dp[n+1][sum+1];
	    for(int i=0 ;i<=n ;i++){
	        dp[i][0]=true;
	    }
	    for(int j=1 ;j<=sum;j++){
	        dp[0][j] = false;
	    }
	    dp[0][0] = true;
	    for(int i=1 ; i<=n ; i++){
	        for(int j=1 ; j<=sum ;j++){
	            if(arr[i-1]<=j){
	                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
	            }else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    for(int i = sum/2 ; i>=0 ; i--){
	        if(dp[n][i]==true)return sum-2*i;
	    }
	    return sum;
	} 
};
 for(int i=sum/2;i>=0;i--)
	   {
	       if(t[n][i]==true)
	       {
	           diff=sum-2*i;
	           break;
	       }
	   }
	   return diff;
also
//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
