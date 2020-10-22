/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max_num = amount + 1;
        vector<int> dp(max_num, max_num);
        dp[0] = 0;
        for(int i=0; i<coins.size(); i++){
            for(int j=1; j<=amount; j++){
                if(j - coins[i]>=0){
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};
// @lc code=end

