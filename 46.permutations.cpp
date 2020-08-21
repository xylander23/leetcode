/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0, nums.size());
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int>& output, int index, int length){
        if(index == length){
            res.push_back(output);
            return ;
        }
        for(int i = index; i < length; i++){
            swap(output[i], output[index]);
            backtrack(res, output, index+1, length);
            swap(output[index], output[i]);
        }
    }
};
// @lc code=end

