/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.empty() || num.size() == k){
            return "0";
        }
        //递增的序列，删低位。递减的序列，删高位。
        //所以，如果当前数比栈顶大，就是递增态，入栈。如果比栈顶小，删栈顶的数
        deque<char> q;
        for(char& digit: num){
            while(k > 0 && !q.empty() && digit < q.back()){//删够k个就停
                q.pop_back();
                k--;
            }
            if(digit != '0' || !q.empty()){ //不要前导0
                q.push_back(digit);
            }
        }
        for(; k > 0; k--){
            q.pop_back();
        }
        string ans = "";
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop_front();
        }
        return (ans == "")? "0" : ans;
    }
};
// @lc code=end

