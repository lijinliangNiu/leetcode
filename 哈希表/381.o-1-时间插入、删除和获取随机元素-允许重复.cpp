/*
 * @lc app=leetcode.cn id=381 lang=cpp
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 */

// @lc code=start
class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> index;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.emplace_back(val);
        index[val].insert(nums.size() - 1);
        return index[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(index.count(val) == 0){
            return false;
        }
        int removed_index = *(index[val].begin());
        nums[removed_index] = nums.back();//用末尾顶掉它
        index[val].erase(removed_index);
        index[nums.back()].erase(nums.size() - 1);
        
        if(removed_index < nums.size() - 1){
            index[nums.back()].insert(removed_index);
        }

        if(index[val].size() == 0){//删除要小心，放后
            index.erase(val);
        }
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % (nums.size())];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

