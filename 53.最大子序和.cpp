/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_num = nums[0];
        for(int i=1; i < nums.size(); i++){
            if(nums[i - 1] > 0){
                nums[i] = nums[i - 1] + nums[i];
            }
            if(max_num < nums[i])
                max_num = nums[i];
        }
        return max_num;
    }
};
// @lc code=end

