/*
 * @lc app=leetcode.cn id=842 lang=cpp
 *
 * [842] 将数组拆分成斐波那契序列
 */

// @lc code=start
class Solution {
private:
    vector<int> ans;
    //index当前元素的开头，sum前两个块的和，pre上一个块
    bool backtrack(string S, int index, long long sum, int pre){
        if(index == S.size()){ //遍历完，看看长度
            return ans.size() >= 3;
        }
        long long cur = 0;//当前块的值
        for(int i = index; i < S.size(); i++){
            if(i > index && S[index] == '0'){//长度大于1的块不能以0开头
                break;
            }
            cur = cur * 10 + S[i] - '0';
            if(cur > INT_MAX){
                break;
            }
            if(ans.size() >= 2){//斐波那契剪枝
                if(cur < sum){
                    continue;
                }
                else if(cur > sum){
                    break;
                }
            }
            ans.push_back(cur);            
            if (backtrack(S, i + 1, pre + cur, cur)) {
                return true;
            }
            ans.pop_back();
        }
        return false;
    }
public:
    vector<int> splitIntoFibonacci(string S) {
        backtrack(S, 0, 0, 0);
        return ans;
    }
};
// @lc code=end

