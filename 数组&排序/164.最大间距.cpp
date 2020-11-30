/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

// @lc code=start
class Solution {
private:
    int digits_num(int val){
        int digits_num = 0;
        for(; val > 0; val /= 10){
            digits_num++;
        }
        return digits_num;
    }
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return 0;
        }
        int sort_time = digits_num(*max_element(nums.begin(), nums.end()));//位数即排序次数

        for(int i = 0, radix = 1; i < sort_time; i++, radix *= 10){//从低位到高位基数排序
            vector<int> bucket(10);  //桶
            for(int& num: nums){
                int digit = (num / radix) % 10;
                bucket[digit]++;
            }
            for(int j = 1; j < 10; j++){//分布函数
                bucket[j] += bucket[j - 1];
            }

            vector<int> temp(n);//每趟结果
            for(int j = n - 1; j >= 0; j--){//倒序必要
                int digit = (nums[j] / radix) % 10;
                temp[bucket[digit] - 1] = nums[j];
                bucket[digit]--;
            }
            copy(temp.begin(), temp.end(), nums.begin());
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};
// @lc code=end

