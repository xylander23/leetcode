/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        for(int i=0; i<=nums.size(); i++) //长度从0开始，遍历组合数目
            subsets(nums, tmp, 0, i);
        return result;
    }

    void subsets(vector<int> nums, vector<int> tmp, int start, int length){
        if(tmp.size() == length){
            result.push_back(tmp);
            return;
        }
        // nums.size() - (length - tmp.size()为了确保前序数字不会排在后序数字之后（剪枝的过程）
        for(int i=start; i<=nums.size() - (length - tmp.size()) ; i++){ 
            tmp.push_back(nums[i]);
            subsets(nums, tmp, i+1, length);
            tmp.pop_back();
        }
    }
};
// @lc code=end

