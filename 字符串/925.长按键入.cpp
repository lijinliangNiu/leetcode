/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        for(int j = 0; j < typed.size();){
            if(i < name.size() && typed[j] == name[i]){
                i++;
                j++;
            }
            else if(j > 0 && typed[j] == typed[j - 1]){
                j++;
            }
            else{
                return false;
            }
        }
        return i == name.size();
    }
};
// @lc code=end

