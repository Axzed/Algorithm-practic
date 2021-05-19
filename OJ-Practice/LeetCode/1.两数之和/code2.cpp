/*
  建立hash表ans，映射关系为：【target与当前扫描到的数的差值，该数所对应的下标】
  从头扫描该数组：
  （1）若当前数的差值在hash表中找得到，则返回i的下标和该差值的下表
  （2）找不到当前值的差值，则在hash表中插入当前数的值以及其对应的下表
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ans;
        for(int i = 0; i < nums.size(); i ++){
            int t = target - nums[i];
            if(ans.count(t)) return {ans[t], i};
            ans[nums[i]] = i;
        }
        return {};
    }
};
