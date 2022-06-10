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
        while(curr_node)
        {
            Hash_Node<Key,Value> *temp = curr_node;
            curr_node = curr_node->next;
            delete temp;
        }
    }
    delete _Table;
}

template<class Key,class Value,class HashFunc,class EqualKey>
bool _Hash_Map<Key,Value,HashFunc,EqualKey>::insert(const Key& k,const Value& v)
{
    int index = hash(k) %_size;
    Hash_Node<Key, Value> *tmp_node = new Hash_Node<Key,Value>(k,v);
    tmp_node->next = _Table[index];
    _Table[index] = tmp_node;
    return true;
}

template<class Key,class Value,class HashFunc,class EqualKey>
bool _Hash_Map<Key,Value,HashFunc,EqualKey>::del_(const Key &k)
{
    unsigned index = hash(k) % _size;
    Hash_Node<Key,Value> *tmp_node = _Table[index];
    Hash_Node<Key,Value> *pre = NULL;
    while(tmp_node)
    {
        if(equal(tmp_node->key,k))
        {
            if(pre == NULL)
            {
                _Table[index] = tmp_node->next;
            }
            else
            {
                pre->next = tmp_node->next;
            }
            delete tmp_node;
            return true;
        }
        pre = tmp_node;
        tmp_node = tmp_node->next;
    }
    return false;
}

template<class Key,class Value,class HashFunc,class EqualKey>
Value& _Hash_Map<Key,Value,HashFunc,EqualKey>::find(const Key& k)
{
    unsigned index = hash(k) % _size;
    if(!_Table[index])
    {
        return null_value;
    }
    else
    {
        Hash_Node<Key,Value> * tmp_node = _Table[index];
        while(tmp_node != NULL)
        {
            if(equal(tmp_node->key,k))
            {
                return tmp_node->value;
            }
            tmp_node = tmp_node->next;
        }
    }
}

template<class Key,class Value,class HashFunc,class EqualKey>
Value& _Hash_Map<Key,Value,HashFunc,EqualKey>::operator[](const Key& k)
{
    return find(k);
}

#endif
