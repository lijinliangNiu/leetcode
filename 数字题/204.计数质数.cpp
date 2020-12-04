/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for(int i = 2; i < n; i++){
            if(isPrime[i]){
                ans++;
            }
            //从i * i开始标记，因为2x,3x在之前就被其他数的倍数标记过了
            if((long long)i * i < n){
                for(int j = i * i; j < n; j += i){
                    isPrime[j] = 0;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

