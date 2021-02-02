/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.empty()){
            return "";
        }
        sort(nums.begin(), nums.end(), [](const int &a, const int &b){
            string s1 = to_string(a) + to_string(b);
            string s2 = to_string(b) + to_string(a);
            return s1 > s2;
        });
        string ans = "";
        for(int& num : nums){
            ans += to_string(num);
        }
        if(ans[0] == '0'){
            return "0";
        }
        return ans;
    }
};
// @lc code=end

