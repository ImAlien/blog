#### [718. 最长重复子数组](https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/)

给两个整数数组 `A` 和 `B` ，返回两个数组中公共的、长度最长的子数组的长度。

#### 代码：

```cpp
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        int dp[m+1][n+1];
        int res = 0;
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= m; i++) // 遍历 A
            for(int j = 1; j <= n; j++) //遍历 B
            {
                if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = 0;
                res = max(res, dp[i][j]);
            }
        return res;
    }
};
```

#### [1143. 最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/)

给定两个字符串 `text1` 和 `text2`，返回这两个字符串的最长公共子序列的长度。

#### 代码：

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        int dp[m+1][n+1];
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= m ;i++) // 遍历text1
            for(int j = 1; j <= n; j++){  //遍历text2
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = max(dp[i-1][j-1]+1,dp[i][j]);
            }
        return dp[m][n];
    }
};
```

