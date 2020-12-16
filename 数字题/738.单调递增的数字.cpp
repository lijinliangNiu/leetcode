/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string n_str = to_string(N);
        int i = 1;
        //找第一个非递增的数字
        while(i < n_str.size() && n_str[i - 1] <= n_str[i]){
            i++;
        }
        if(i < n_str.size()){
            //找真正要-1的那一位
            for(; i > 0 && n_str[i - 1] > n_str[i]; i--){
                n_str[i - 1]--;
            }
            //这一位往后全得改成9
            for(i = i + 1; i < n_str.size(); i++){
                n_str[i] = '9';
            }
        }
        return stoi(n_str);
    }
};
// @lc code=end

