/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
    //线段树
private:
    struct Status{
        // 以l为左端点的最大子段和
        // 以r为右端点的最大子段和
        // 最大子段和
        // 区间和
        int lSum, rSum, mSum, iSum;
    };
    Status pushUp(Status l, Status r){
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        int iSum = l.iSum + r.iSum;
        return (Status) {lSum, rSum, mSum, iSum};
    }
    Status get(vector<int>& a, int l, int r){
        if (l == r) {
            return (Status) {a[l], a[l], a[l], a[l]};
        }
        int m = l + (r - l) / 2;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }
public:
    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //以其结尾的最大值
        int ans = nums[0], end_max = nums[0];
        for(int i = 1; i < nums.size(); i++){
            end_max = max(end_max + nums[i], nums[i]);
            ans = max(ans, end_max);
        }
        return ans;
    }
};
// @lc code=end

