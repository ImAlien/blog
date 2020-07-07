# [32. Longest Valid Parentheses](https://leetcode-cn.com/problems/longest-valid-parentheses/) 最长有效括号

## 题目描述

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

给定一个只包含 `'('` 和 `')'` 的字符串，找出最长的包含有效括号的子串的长度。

## 思路

遇到左右括号问题，考虑使用动态规划或者栈来解决

## 易错点

1. 用贪心思路来解决：每遇到一个（ 则记录， 每遇到 ）则减去一个（，有效数目加2；无（时清零；

   错误样例：**"()(()"** 

   输出：4

   预期：2

   原因：当中间有多余的（时，无法判断；

   解决方法：用栈来记录括号的索引，每次匹配时弹出

## 解法

* 解法一：栈加动态规划

  ```c++
  class Solution {
  public:
      int longestValidParentheses(string s) {
          int n = s.size();
          stack<int> sta;
          // dp[i] 表示 以s[i-1]结尾的最大有效长度
          int dp[n+1] = {0};
          int res = 0;
          for(int i = 0 ; i < n; i++){
              if(s[i] == '('){
                  sta.push(i);
                  dp[i+1] = 0;//因为有效括号不可能以(结尾
              }              
              else{
                  if(sta.empty()){
                      dp[i+1] = 0;
                  }   
                  else{
                      int index = sta.top();//匹配的左括号索引
                      sta.pop();
                      //以s[i]结尾的有效括号 = 两部分之和再加上匹配的部分
                      dp[i+1] = dp[index]+dp[i] + 2;
                  }
              }
              res = max(res,dp[i+1]);
          }
          return res;
      }
  };
  ```

* 解法二：动态规划，通过观察，index可以直接用当前的索引计算得出

  ```c++
  class Solution {
  public:
      int longestValidParentheses(string s) {
          int n = s.size();
          // dp[i] 表示 s[i]之前的最大有效长度
          vector<int> dp(n+1);
          int res = 0;
          for(int i = 0 ; i < n; i++){      
              if(s[i] == ')'){ 
                  int index = i - dp[i] - 1;//可能匹配的左括号索引
                  if(index >= 0 && s[index] == '(')
                      dp[i+1] = dp[index]+dp[i] + 2;
              }
              res = max(res,dp[i+1]);
          }
          return res;
      }
  };
  ```

* 方法三：栈，同样是方法一的改进，也是最针对易错点的，因为只需要针对中间冗余的左括号即可

  ```c++
  class Solution {
  public:
      int longestValidParentheses(string s) {
          int n = s.size();
          stack<int> sta;
          sta.push(-1);//第一个括号之前的括号
          int res = 0;
          for(int i = 0 ; i < n; i++){
              if(s[i] == '('){
                  sta.push(i);
              }              
              else{
                  sta.pop();
                  if(sta.empty()){
                      sta.push(i);
                  }
                  else{
                      res = max(res, i - sta.top());
                  }
              }
          }
          return res;
      }
  };
  ```

* 方法四：利用括号的特性：

  **1，括号组合中左括号的数量等于右括号的数量**

  **2，括号组合中任何位置左括号的数量都是大于等于右括号的数量**

  ![image-20200704100121499](https://raw.githubusercontent.com/ImAlien/pictures/master/img/image-20200704100121499.png)

  ```c++
  class Solution {
  public:
      int longestValidParentheses(string s) {
          int left = 0, right = 0, res = 0;
          for (int i = 0; i < s.length(); i++) {
              if (s[i] == '(') {
                  left++;
              } else {
                  right++;
              }
              if (left == right) {
                  res = max(maxlength, 2 * right);
              } else if (right > left) {
                  left = right = 0;
              }
          }
          left = right = 0;
          for (int i = (int)s.length() - 1; i >= 0; i--) {
              if (s[i] == '(') {
                  left++;
              } else {
                  right++;
              }
              if (left == right) {
                  res = max(maxlength, 2 * left);
              } else if (left > right) {
                  left = right = 0;
              }
          }
          return res;
      }
  };
  ```

  

