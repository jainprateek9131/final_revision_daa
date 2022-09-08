Given an array of integers A[] of length N and an integer target.
You want to build an expression out of A by adding one of the symbols '+' and '-' before each integer in A and then concatenate all the integers.

For example, if arr = {2, 1}, you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that can be built, which evaluates to target.
  Example 1:

Input:
N = 5
A[] = {1, 1, 1, 1, 1}
target = 3
Output:
5
Explanation:
There are 5 ways to assign symbols to 
make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:

Input:
N = 1
A[] = {1}
target = 1
Output:
1
  //For below if condition, 
	//sum<abs(target), consider test case - nums: [100], target: -200
	//(target+sum) % 2 != 0, consider test case - nums: [7,9,3,8,0,2,4,8,3,9], its sum = 53 and target: 0, there could not be any 26.5 in integer array.
	
	if(sum < abs(target) || (target+sum) %2 != 0) return 0;
	
	//S1 is newTarget
	int newTarget = (sum - target)/2;
  int findTargetSumWays(vector<int>&nums ,int S) {
        int n = nums.size();

        int arrSum = 0;

        for(int i=0;i<n;i++){
            arrSum += nums[i];
        }
        if(S > arrSum) return 0;
        if((S+arrSum)%2!=0) return 0;
        int sum = (arrSum + S)/2;
        int dp[n+1][sum+1];
        //init
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int j=1;j<=sum;j++){
            dp[0][j] = 0;
        }
        //loop
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return (dp[n][sum]);
    }
