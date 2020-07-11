#### [146. LRU缓存机制](https://leetcode-cn.com/problems/lru-cache/)

#### 题目：

运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字/值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

#### 思路：

get 和 put的O(1)操作要考虑hash表，因为使用时要调整顺序，考虑用链表，因此数据结构为value为链表指针的hash表

#### 代码：

```cpp
class LRUCache {
public:
    int cap;
    map<int, list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> l;
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        if(mp.count(key) == 0) return -1;
        //移动到头部
        auto t = *mp[key];
        l.erase(mp[key]);
        l.push_front(t);
        mp[key] = l.begin();
        return t.first;
    }
    void put(int key, int value) {
        //因为更新时肯定不会超出容量，所以可以先删后插
        if(mp.count(key)){
            l.erase(mp[key]);
        }
        pair<int,int> t = {value,key};
        l.push_front(t);
        mp[key] = l.begin();
        if(l.size() > cap){//删除多余的
            auto temp = l.back();
            l.pop_back();
            mp.erase(temp.second);
        }        
    }
};
```

#### [460. LFU缓存](https://leetcode-cn.com/problems/lfu-cache/)

#### 题目：

请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。它应该支持以下操作：get 和 put。

get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
put(key, value) - 如果键已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量时，则应该在插入新项之前，使最不经常使用的项无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除最久未使用的键。
「项的使用次数」就是自插入该项以来对其调用 get 和 put 函数的次数之和。使用次数会在对应项被移除后置为 0 。

#### 思路：

比起上题，多了一个使用次数这个数据，因此，数据中还需加入使用次数这个值。链表本身不好根据使用次数排序，因为使用次数是线性增加的，所以可以增加一个维度来排序链表。因为使用次数不知道大小，所以这个维度也用hash表来排序；

#### 注意：

```cpp
auto it = l.begin();
l.erase(it);
这样之后，it指针指向的数据已被清除。
```

#### 代码：

```cpp
class LFUCache {
public:
    struct node{
        int value, key, fre;
        node(int k, int v, int f):value(v), key(k), fre(f){};
    };
    unordered_map<int,list<node>::iterator> mp;
    unordered_map<int,list<node> > fre;
    int minfre = INT_MAX, cap;
    LFUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        if(mp.count(key)){
            //更改在fre表中的位置
            auto it = mp[key];
            node t = *it;
            fre[it->fre].erase(it);
            if(fre[minfre].size() == 0) minfre++;
            t.fre++;
            fre[t.fre].push_front(t);
            mp[key] = fre[t.fre].begin();
            return t.value;
        }
        return -1;
    }
    void put(int key, int value) {
        if (cap <= 0) return;
        int tempf = 1;
        if(mp.count(key)){//删了再插
            auto it = mp[key];
            node t = *it;
            fre[it->fre].erase(it);
            if(fre[minfre].size() == 0) minfre++;
            mp.erase(key);
            tempf = t.fre + 1;
        }
        node t(key,value, tempf);
        if(mp.size() == cap){
        //因为最新插入的可能会是次数最少的,所以不能先插后删
        node t = fre[minfre].back();
        fre[minfre].pop_back();
        if(fre[minfre].size() == 0) minfre++;
        mp.erase(t.key);
        }
        //插入
        fre[t.fre].push_front(t);
        mp[t.key] = fre[t.fre].begin();
        if(tempf < minfre) minfre = tempf;
    }
};
```

