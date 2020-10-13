/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m);
        for(int i = 0; i < m; i++){
            dp[i].resize(n);
            for(int j = 0; j < n; j++){
                dp[i][j] = 0;
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                } 
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

