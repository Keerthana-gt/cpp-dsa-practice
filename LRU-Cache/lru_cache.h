#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity;
    std::list<std::pair<int,int>> cacheList; // {key, value}
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> cacheMap;

public:
    LRUCache(int cap);
    int get(int key);
    void put(int key, int value);
};

#endif
