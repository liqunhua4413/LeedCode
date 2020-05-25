/**
 * Your LRUdList object will be instantiated and called as such:
 * LRUdList* obj = new LRUdList(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
/*
参照labuladong代码。
思路：哈希链表
1.
    哈希表：查找快，O(1)时间复杂度，实现查找get函数。
    链表：插入快，删除快，有顺序之分，O(1)时间复杂度，实现插入删除put函数。
    两者结合，形成一种新的数据结构：哈希链表。
2.
    双链表list：list<pair<int, int>> dList;
    （1）装着 (key, value) 元组。
    （2） 双链表比单链表的好处：O(1)时间复杂度就可以删除一个节点。
    （3）双向链表里面没有只存储value，而是同时需要存储key和value：因为同一个value可能是由多个不同的key值对应，当缓存容量已满，删除节点时，如果节点只有value，容易把其他key对应的value误删掉。同时要记得把 um 中映射到该节点的 key 同时删除，否则um部分会出错。
    哈希表unordered_um：unordered_um<int, list<pair<int, int>>::iterator> um。
    （1）key 映射到 (key, value) 在 dList 中的位置
*/
 class LRUCache {
private:
    int cap;
    // 双链表：装着 (key, value) 元组
    list<pair<int, int>> dList;
    // 哈希表：key 映射到 (key, value) 在 dList 中的位置
    unordered_map<int, list<pair<int, int>>::iterator> um;
public:
    LRUCache(int capacity) {
        this->cap = capacity; 
    }
    
    int get(int key) {
        auto it = um.find(key);
        // 访问的 key 不存在
        if (it == um.end()) return -1;
        // key 存在，把 (k, v) 换到队头
        pair<int, int> kv = *um[key];
        dList.erase(um[key]);
        dList.push_front(kv);
        // 更新 (key, value) 在 dList 中的位置
        um[key] = dList.begin();
        return kv.second; // value
    }
    
    void put(int key, int value) {
        /* 要先判断 key 是否已经存在 */ 
        auto it = um.find(key);
        if (it == um.end()) {
            /* key 不存在，判断 dList 是否已满 */ 
            if (dList.size() == cap) {
                // dList 已满，删除尾部的键值对位置
                // dList 和 um 中的数据都要删除
                auto lastPair = dList.back();
                int lastKey = lastPair.first;
                um.erase(lastKey);
                dList.pop_back();
            }
            // dList 没满，可以直接添加
            dList.push_front(make_pair(key, value));
            um[key] = dList.begin();
        } else {
            /* key 存在，更改 value 并换到队头 */
            dList.erase(um[key]);
            dList.push_front(make_pair(key, value));
            um[key] = dList.begin();
        }
    }
};
