/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

// @lc code=start
class Solution {
    static const int m = 20;
    int row[m], col[m], pie[m], na[m];
    vector<vector <string>> result;
    vector<string> tmp;
public:
    vector<vector<string>> solveNQueens(int n) {
        tmp.resize(n, string(n,'.'));
        dfs(0, n);
        return result;
    }
    void dfs(int r, int n){
        if(r == n){
            result.push_back(tmp);
        }
        for(int i=0; i<n; i++){
            if(!row[r] && !col[i] && !pie[r-i+n] && !na[r+i]){
                row[r] = col[i] = pie[r-i+n] = na[r+i] = 1;
                tmp[r][i] = 'Q';
                dfs(r+1, n);
                row[r] = col[i] = pie[r-i+n] = na[r+i] = 0;
                tmp[r][i] = '.';
            }
        }
    }
};
// @lc code=end

