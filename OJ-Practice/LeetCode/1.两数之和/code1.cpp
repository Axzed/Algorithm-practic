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
