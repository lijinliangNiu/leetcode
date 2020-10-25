/*
 * @lc app=leetcode.cn id=845 lang=cpp
 *
 * [845] 数组中的最长山脉
 */

// @lc code=start
//左右指针
class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(A.size() < 3){
            return 0;
        }
        int ans = 0;
        for(int left = 0; left < A.size() - 2;){
            if(A[left] < A[left + 1]){
                int right = left + 1;
                while(right < A.size() - 1 && A[right] < A[right + 1]){//top
                    right++;
                }
                if(right < A.size() - 1 && A[right] > A[right + 1]){
                    while(right < A.size() - 1 && A[right] > A[right + 1]){
                        right++;
                    }
                    ans = max(ans, right - left + 1);
                }
                left = right;
            }
            else{
                left++;
            }
        }
        return ans;
    }
};

//DP
class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(A.size() < 3){
            return 0;
        }
        vector<int> left(A.size());
        for(int i = 1; i < A.size(); i++){
            left[i] = (A[i - 1] < A[i]) ? left[i - 1] + 1 : 0;
        }
        vector<int> right(A.size());
        for(int i = A.size() - 2; i >= 0; i--){
            right[i] = (A[i + 1] < A[i]) ? right[i + 1] + 1 : 0;
        }
        int ans = 0;
        for(int i = 1; i < A.size() - 1; i++){
            if(left[i] > 0 && right[i] > 0){
                ans = max(ans, right[i] + left[i] + 1);
            }
        }
        return ans;
    }
};
// @lc code=end

