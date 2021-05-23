class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        //每次左右指针停下后判断一下长度是否比之前的要长，若比之前要长则更新ans
        //r - l -1为每次指针停下后回文串的长度
        for(int i = 0; i < s.size(); i ++){
            //判断出来的子串是奇数子串（由i的两边设置指针）
            int l = i - 1, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) l --, r ++;
            if(ans.size() < r - l - 1) ans = s.substr(l + 1, r - l - 1);
            //判断出来的是偶数子串（让左指针为i）
            l = i, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) l --, r ++;
            if(ans.size() < r - l - 1) ans = s.substr(l + 1, r - l - 1);
        }
        return ans;
    }
};
