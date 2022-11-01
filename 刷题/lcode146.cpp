#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;
struct MoveNode
{
    MoveNode *prev;
    MoveNode *next;
    int key;
    int value;
    MoveNode():prev(nullptr),next(nullptr),key(0),value(0) {}
    MoveNode(int _key,int _value):prev(nullptr),next(nullptr),key(_key),value(_value) {}
};



class LRUCache {
public:
    LRUCache(int capacity) {
        head = new MoveNode();
        tail = new MoveNode();
        _size = 0;
        _capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!nodemap.count(key)) {
            return -1;
        }
        MoveNode *node = nodemap[key];
        MovetoTail(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(!nodemap.count(key)) {
            MoveNode* node = new MoveNode(key,value);
            nodemap[key] = node;
            AddNode(node);
            ++_size;
            if(_size > _capacity) {
                node = Deletefromhead();
                nodemap.erase(node->key);
                delete node;
                --_size;
            } 
        }
        else {
            MoveNode *node = nodemap[key];
            node->value = value;
            MovetoTail(node);
        }

    }
    MoveNode* Deletefromhead();
    void MovetoTail(MoveNode *node);
    void AddNode(MoveNode *node);

private:
    MoveNode *head;
    MoveNode *tail;
    int _size;
    int _capacity;
    unordered_map<int,MoveNode*> nodemap;
};

void LRUCache::MovetoTail(MoveNode *node) {
    // 将node分离出来
    node->prev->next = node->next;
    node->next->prev = node->prev;
    // 插入尾部为最新节点
    node->prev = tail->prev;
    node->next = tail;
    tail->prev = node;
}

MoveNode* LRUCache::Deletefromhead() {
    MoveNode * node = head->next;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    return node;
}

void LRUCache::AddNode(MoveNode *node) {
    node->prev = tail->prev;
    node->prev->next = node;
    node->next = tail;
    tail->prev = node;
}







int main() {
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // 缓存是 {1=1}
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    lRUCache->get(1);    // 返回 1
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lRUCache->get(2);    // 返回 -1 (未找到)
    lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lRUCache->get(1);    // 返回 -1 (未找到)
    lRUCache->get(3);    // 返回 3
    lRUCache->get(4);    // 返回 4
    return 0;
}