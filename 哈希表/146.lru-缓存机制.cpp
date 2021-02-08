/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
class Node {
public:
    int key, value;
    Node* pre;
    Node* next;
    Node(): key(0), value(0), pre(nullptr), next(nullptr) {}
    Node(int key, int value): key(key), value(value), pre(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    int capacity;
    int size;

    void add_to_head(Node* node){
        node->pre = head;
        node->next = head->next;
        head->next = node;
        node->next->pre = node;
    }

    void move_to_head(Node* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
        add_to_head(node);
    }

    Node* remove_tail(){
        Node* node = tail->pre;
        tail->pre = node->pre;
        node->pre->next = tail;
        return node;
    }

public:
    LRUCache(int capacity): capacity(capacity), size(0) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        Node* node = cache[key];
        move_to_head(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            Node* node = new Node(key, value);
            cache[key] = node;
            add_to_head(node);
            size++;
            if(size > capacity){
                Node* removed = remove_tail();
                cache.erase(removed->key);
                delete removed;
                size--;
            }
        }
        else{
            Node* node = cache[key];
            node->value = value;
            move_to_head(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

