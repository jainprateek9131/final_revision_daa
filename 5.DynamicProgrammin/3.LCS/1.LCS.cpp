//recursion
class Solution {
public:
    int lcs(string s1, string s2,int m,int n){
        if(m==0 || n==0){
            return 0;
        }
        if(s1[m-1] == s2[n-1]){
            return 1 + lcs(s1,s2,m-1,n-1);
        }else{
            return max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
       return lcs(text1 , text2 , text1.size(), text2.size());
    }
};
//top-down
class Solution {
public:
    int dp[1001][1001];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int lcs(string& s1, string& s2,int m,int n){
        if(m==0 || n==0){
            return 0;
        }
        if(dp[m][n]!=-1)return dp[m][n];
        if(s1[m-1] == s2[n-1]){
            return dp[m][n] = 1 + lcs(s1,s2,m-1,n-1);
        }else{
            return dp[m][n] = max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        return lcs(text1 , text2 , m, n);
    }
};
//Bottom-up
class Solution {
public:    
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0 ; j<=n ; j++){
                dp[i][j]=0;
            }
        }
        for(int i=1; i<=m; i++){
            for(int j=1 ; j<=n ; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
