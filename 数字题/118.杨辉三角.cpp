/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++){
            vector<int> row(i + 1);
            if(i == 0){
                row[0] = 1;
            }
            else{
                row[0] = row[i] = 1;
                for(int j = 0; j < i - 1; j++){
                    row[j + 1] = ans[i - 1][j] + ans[i - 1][j + 1];
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};
// @lc code=end

