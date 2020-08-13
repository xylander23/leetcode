/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? pow(x, n) : 1.0 / pow(x, -N);
    }
    double pow(double x, long long n) {
    long double result;
    if(n == 0)
        return 1;
    if(n & 1){
        result = pow(x, (n-1)/2);
        return result * result * x;
    }
    else{
    result = pow(x, n/2);
    return result * result;
    }
    }
    };
// @lc code=end

