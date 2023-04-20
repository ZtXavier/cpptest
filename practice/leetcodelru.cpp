#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;


//  LRUCache 我们的实现是使用哈希表和双向链表来实现


class LRUCache {
    struct ListNode {
        ListNode *prev;
        ListNode *next;
        int key;
        int value;
        ListNode():prev(nullptr),next(nullptr),key(0),value(0) {}
        ListNode(int k, int v):prev(nullptr),next(nullptr),key(k),value(v) {}
    };

    public:
        LRUCache(int capacity_):_capacity(capacity_),_size(0) {
            // 上面是需要自己创建头和尾的两个伪节点
            head = new ListNode();
            tail = new ListNode();
            head->next = tail;
            tail->prev = head;
            tail->next = NULL;
        }

        int get(int key) {
            if(!mp.count(key)) {
                return -1;
            } 
            ListNode *node = mp[key];
            MoveToTail(node);
            return node->value;
        }

        void put(int key, int value) {
            // 在向lru中添加节点时需要在哈希表中判断
            // 是否存在相同的key,如果存在则需要解决哈希冲突
            if(!mp.count(key)) {
                ListNode *node = new ListNode(key, value);
                mp[key] = node;
                AddNode(node); // 尾插法
                ++_size;
                if(_size > _capacity) {
                    node = DeleteFromhead();
                    mp.erase(node->key);
                    delete node;
                    --_size;
                }
            } else {
                ListNode *node = mp[key];
                node->value = value;
                MoveToTail(node);
            }
        }





    // 这里需要注意的是我们需要自己定义三个函数来完成
    // 链表的添加和删除
    // 这里将最新的节点插入到后面
        void AddNode(ListNode *node) {
            node->prev = tail->prev;
            node->prev->next = node;
            node->next = tail;
            tail->prev = node;
        }

        void MoveToTail(ListNode *node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->prev = tail->prev;
            node->prev->next = node;
            node->next = tail;
            tail->prev = node;
        }

        ListNode *DeleteFromhead() {
            ListNode *node = head->next;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->prev = nullptr;
            node->next= nullptr;
            return node;
        }

    private:
        int _capacity;
        int _size;
        unordered_map<int,ListNode*> mp;
        ListNode *head;
        ListNode *tail;
};