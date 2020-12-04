/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

// @lc code=start
class Solution {
private:
    vector<int> max_subsequence(vector<int>& nums, int k){//参见leetcode402
        if(k == 0){
            return {};
        }
        int remove_num = nums.size() - k;
        deque<int> q;
        for(int& num: nums){
            while(remove_num > 0 && !q.empty() && q.back() < num){
                q.pop_back();
                remove_num--;
            }
            if(num != 0 || !q.empty()){
                q.push_back(num);
            }
        }
        for(; remove_num > 0; remove_num--){
            q.pop_back();
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop_front();
        }
        return ans;
    }

    vector<int> merge(vector<int>& sequence1, vector<int>& sequence2){
        if(sequence1.empty()){
            return sequence2;
        }
        if(sequence2.empty()){
            return sequence1;
        }
        vector<int> ans(sequence1.size() + sequence2.size());
        int index1 = 0, index2 = 0;
        for(int i = 0; i < ans.size(); i++){
            if(bigger(sequence1, index1, sequence2, index2)){//合并时相同大小看后续
                ans[i] = sequence1[index1++];
            }
            else{
                ans[i] = sequence2[index2++];
            }
        }
        return ans;
    }

    bool bigger(vector<int>& sequence1, int index1, vector<int>& sequence2, int index2){
        while(index1 < sequence1.size() && index2 < sequence2.size()){
            int difference = sequence1[index1++] - sequence2[index2++];
            if(difference > 0){
                return true;
            } 
            else if(difference < 0){
                return false;
            }
        }
        return (sequence1.size() - index1) > (sequence2.size() - index2);
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans(k);
        int m = nums1.size(), n = nums2.size();
        for(int i = max(0, k - n); i <= min(k, m); i++){
            vector<int> sequence1 = max_subsequence(nums1, i);
            vector<int> sequence2 = max_subsequence(nums2, k - i);
            vector<int> cur = merge(sequence1, sequence2);
            if(bigger(cur, 0, ans, 0)){
                ans = cur;
            }
        }
        return ans;
    }
};
// @lc code=end

