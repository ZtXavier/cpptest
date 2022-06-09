#ifndef _HASH_MAP_HPP_
#define _HASH_MAP_HPP_
#include<iostream>

template<class Key,class Value>
class Hash_Node
{
    public:
        Key key;
        Value value;
        Hash_Node *next; // 这里使用链式探测在散列的方式
        Hash_Node(Key k,Value v)
        {
            key = k;
            value = v;
            next = NULL;
        }

        ~Hash_Node() {}

        Hash_Node &operator = (Hash_Node& p)
        {
            key = p.key;
            value = p.value;
            next = p.next;
            return *this;
        }
};

template<class Key,class Value,class HashFunc,class EqualKey>
class _Hash_Map
{
    public:
        _Hash_Map(unsigned int  size);
        ~_Hash_Map();
        bool insert(const Key& k,const Value& v);
        bool del_(const Key& k);
        Value& find(const Key& k);
        Value& operator[] (const Key&k);

    private:
        Value null_value;
        HashFunc hash;
        EqualKey equal;
        Hash_Node<Key,Value> **_Table;
        unsigned int _size;
};

template<class Key,class Value,class HashFunc,class EqualKey>
_Hash_Map<Key,Value,HashFunc,EqualKey>::_Hash_Map(unsigned int size):_size(size)
{
    _Table = new Hash_Node<Key,Value> *[size];
    for(unsigned int i = 0;i < size;i++)
    {
        _Table[i] = NULL;
    }
}

template<class Key,class Value,class HashFunc,class EqualKey>
_Hash_Map<Key,Value,HashFunc,EqualKey>::~_Hash_Map()
{
    for(unsigned int i = 0;i < _size;++i)
    {
        Hash_Node<Key,Value> * curr_node = _Table[i];
        while(curr_node != NULL)
        {
            Hash_Node<Key,Value> *temp = curr_node;
            curr_node = curr_node->next;
            delete temp;
        }
    }
    delete _Table;
}














#endif
