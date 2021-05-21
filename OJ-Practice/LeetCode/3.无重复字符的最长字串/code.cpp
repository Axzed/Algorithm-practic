class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //建立hash表，维护在当前滑动窗口中每个字符所出现的次数（为了判重）
        unordered_map<char, int> hash;
        //ans为最长的字串的值
        int ans = 0;
        //设置双指针（j前，i后），让i先遍历字符串
        for(int i = 0, j = 0; i < s.size(); i ++){
            //将i指针所指到的字符地出现次数加1，当hash表中每个字符只出现一次地时候，j指针不用动，i继续往后移
            hash[s[i]] ++;
            //当i指向的字符出现次数大于1，i停止后移，j开始后移直到i指向的字符重新只出现一次（因为字串是一定相邻的，故可以一直维护着这个滑动窗口）
            while(hash[s[i]] > 1){
                hash[s[j]] --;
                j ++;
            }
            //没处理一个字符更新一次ans的值
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
