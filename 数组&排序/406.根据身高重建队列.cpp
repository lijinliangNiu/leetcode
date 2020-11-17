/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);//排在前边的入队之后，对后边入队时前边不小于他的元素个数无影响
        });
        vector<vector<int>> ans(people.size());
        for(const vector<int>& person: people){//挑第几个空放
            int space = person[1] + 1;
            for(int i = 0; i < people.size(); i++){
                if(ans[i].empty()){
                    space--;
                    if(!space){
                        ans[i] = person;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [&](const vector<int>& u, const vector<int>& v){
            return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
        });
        list<vector<int>> tmp;
        for(int i = 0; i < people.size(); i++){
            auto pos = tmp.begin();
            advance(pos, people[i][1]);
            tmp.insert(pos, people[i]);
        }
        return vector<vector<int>>(tmp.begin(), tmp.end());
    }
};
// @lc code=end

