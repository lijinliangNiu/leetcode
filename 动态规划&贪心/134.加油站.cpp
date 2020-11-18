/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
//假设 i 最远能到 j ，如果 i + 1 能到 j + 1，那么 i 一定也能到 j + 1，所以
//可以直接从 j 开始
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n; i++){
            int j = i;
            int remain = gas[i];
            while(remain - cost[j] >= 0){
                remain = remain - cost[j] + gas[(j + 1) % n];//试一试能不能前进
                j = (j + 1) % n;
                if(j == i){
                    return i;
                }
            }
            if(j < i){　//如果到了在它前的地方，说明它之后的地方都不能周游了
                break;
            }
            i = j;
        }
        return -1;
    }
};
// @lc code=end

