/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> rank;
        for(int i = 0; i < arr2.size(); i++){
            rank[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](int x, int y) {
            if(rank.count(x) && rank.count(y)){
                return rank[x] < rank[y];
            }
            else if(rank.count(x) && !rank.count(y)){
                return true;
            }
            else if(!rank.count(x) && rank.count(y)){
                return false;
            }
            else{
                return x < y;
            }
        });
        return arr1;
    }
};


class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int upper = *max_element(arr1.begin(), arr1.end());
        vector<int> frequency(upper + 1);
        for(int x : arr1){
            frequency[x]++;
        }
        arr1.clear();
        for(int x : arr2){
            for(int i = 0; i < frequency[x]; i++){
                arr1.emplace_back(x);
            }
            frequency[x] = 0;
        }
        for(int x = 0; x <= upper; x++){
            for(int i = 0; i < frequency[x]; i++){
                arr1.emplace_back(x);
            }
        }
        return arr1;
    }
};

// @lc code=end

