Given a value sum, if we want to make change for sum cents, and we have an infinite supply of each of coins[] = { coins1, coins2, .. , coinsn} valued coins, 
how many ways can we make the change? The order of coins doesn’t matter.
 Input: sum = 4, coins[] = {1,2,3}, 
Output: 4
Explanation: there are four solutions: {1, 1, 1, 1}, {1, 1, 2}, {2, 2}, {1, 3}. 

Input: sum = 10, coins[] = {2, 5, 3, 6}
Output: 5
Explanation: There are five solutions: 
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
  
  long long int count(int coins[], int N, int sum) {
        long long dp[N+1][sum+1];
        for(int i=0;i<=N;i++){
            dp[i][0]=1;
        }
        for(int j=1;j<=sum;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=sum;j++){
                if(coins[i-1]<=j){
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][sum];
    }
