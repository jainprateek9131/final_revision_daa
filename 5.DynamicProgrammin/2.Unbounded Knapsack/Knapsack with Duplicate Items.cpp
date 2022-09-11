Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

 Example 1:

Input: N = 2, W = 3
val[] = {1, 1}
wt[] = {2, 1}
Output: 3
Explanation: 
1.Pick the 2nd element thrice.
2.Total profit = 1 + 1 + 1 = 3. Also the total 
  weight = 1 + 1 + 1  = 3 which is <= W.
  
 Example 2:

Input: N = 4, W = 8
val[] = {1, 4, 5, 7}
wt[] = {1, 3, 4, 5}
Output: 11
Explanation: The optimal choice is to 
pick the 2nd and 4th element.
  
 Input : W = 100
       val[]  = {1, 30}
       wt[] = {1, 50}
Output : 100
There are many ways to fill knapsack.
1) 2 instances of 50 unit weight item.
2) 100 instances of 1 unit weight item.
3) 1 instance of 50 unit weight item and 50
   instances of 1 unit weight items.
We get maximum value with option 2.

Input : W = 8
       val[] = {10, 40, 50, 70}
       wt[]  = {1, 3, 4, 5}       
Output : 110 
We get maximum value with one unit of
weight 5 and one unit of weight 3.
  
 //recursion Top-down approch:-
  class Solution{
public:
    int helper(int val[],int wt[],vector<vector<int>>&dp,int W,int n){
        if(n==0 || W==0) return 0;
        if(dp[n][W]!=-1)return dp[n][W];
        if(wt[n-1] <= W){
            return dp[n][W] = max(val[n-1]+helper(val,wt,dp,W-wt[n-1],n),helper(val,wt,dp,W,n-1));
        }else{
            return dp[n][W] = helper(val,wt,dp,W,n-1);
        }
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
        return helper(val , wt , dp , W, N);
    }
};

//Bottom up approch


class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N+1,vector<int>(W+1));
        for(int i=0;i<=N;i++){
            for(int j=0;j<=W;j++){
                if(i==0 || j==0)dp[i][j]=0;
                else if(wt[i-1]<=j){
                    dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][W];
    }
};
  
