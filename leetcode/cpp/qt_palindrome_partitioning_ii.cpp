/**
* @Author: Tian Qiao
* @Date:   2016-08-01T22:21:45+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-01T22:22:14+08:00
*/


/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/



/* Wrong Solution
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int delta = 0; // 子串中'('数目减去')'数目
        int cur = 0;   // 当前子串中最大有效长度
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='(') delta++;
            else if(s[i]==')') {
                delta--;
                if(delta < 0) {
                    ans = max(ans, cur); // start到i-1
                    delta = cur = 0;
                } else if(delta > 0) {
                    cur=2; // "()(()"
                    ans = max(ans, cur);
                } else {
                    cur+=2; // "()()"
                    ans = max(ans, cur);
                }
            }
            else continue;
        }
        return ans;
    }
};*/


/* 解题思路
https://discuss.leetcode.com/topic/2426/my-dp-o-n-solution-without-using-stack
DP Solution:
The main idea is as follows: I construct a array longest[], for any longest[i], it stores the longest length of valid parentheses which is end at i.


if s[i] is '(':
    set longest[i] to 0,because any string end with '(' cannot be a valid one.
else if s[i] is ')':
    if s[i-1] is '(', longest[i] = longest[i-2] + 2
    else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]

For example, input "()(())", at i = 5, longest array is [0,2,0,0,2,0], longest[5] = longest[4] + 2 + longest[1] = 6.
*/


class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int n = s.size();
        if(n<2) return ans;

        vector<int> longest(n, 0);
        for(int i=1; i<n; i++) {
            if(s[i]==')') {
                if(s[i-1]=='(') {
                    longest[i]=(i>1?longest[i-2]:0)+2;
                    ans = max(ans, longest[i]);
                } else {
                    if(i-longest[i-1]-1>=0 && s[i-longest[i-1]-1]=='('){
                        longest[i] = longest[i-1]+2+(i-longest[i]-2>=0?longest[i-2-longest[i-1]]:0);
                        ans = max(ans, longest[i]);
                    }
                }
            }
        }
        return ans;
    }
};
