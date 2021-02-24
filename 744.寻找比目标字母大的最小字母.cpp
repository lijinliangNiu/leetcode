/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(letters[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return (l < letters.size()) ? letters[l] : letters[0];
    }
};
// @lc code=end

