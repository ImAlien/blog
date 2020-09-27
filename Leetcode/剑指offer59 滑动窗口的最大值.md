#### [剑指 Offer 59 - I. 滑动窗口的最大值](https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/)

给定一个数组 `nums` 和滑动窗口的大小 `k`，请找出所有滑动窗口里的最大值

#### 单调队列模板题：

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for(int i = 0; i < nums.size(); i++){
            //去尾并插入
            while(q.size() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
            //去头 
            if(q.size() && q.front() <= i - k) q.pop_front();                 
            if(i >= k-1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
```

