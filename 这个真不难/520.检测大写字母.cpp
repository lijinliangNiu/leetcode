/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
class Solution {
private:
    bool isBig(char& ch){
        return ch >= 'A' && ch <= 'Z';
    }
public:
    bool detectCapitalUse(string word) {
        if(word.size() < 2){
            return true;
        }
        if(isBig(word[0])){
            if(isBig(word[1])){
                for(int i = 2; i < word.size(); i++){
                    if(!isBig(word[i])){
                        return false;
                    }
                }
            }
            else{
                for(int i = 2; i < word.size(); i++){
                    if(isBig(word[i])){
                        return false;
                    }
                }
            }
        }
        else{
            for(int i = 1; i < word.size(); i++){
                if(isBig(word[i])){
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

