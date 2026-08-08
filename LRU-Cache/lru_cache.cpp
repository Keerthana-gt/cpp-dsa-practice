#include "lru_cache.h"

LRUCache::LRUCache(int cap) : capacity(cap) {}

int LRUCache::get(int key) {
    if (cacheMap.find(key) == cacheMap.end()) return -1;

    auto it = cacheMap[key];
    int value = it->second;

    // Move accessed item to front
    cacheList.erase(it);
    cacheList.push_front({key, value});
    cacheMap[key] = cacheList.begin();

    return value;
}

void LRUCache::put(int key, int value) {
    if (cacheMap.find(key) != cacheMap.end()) {
        cacheList.erase(cacheMap[key]);
    } else if (cacheList.size() == capacity) {
        auto last = cacheList.back();
        cacheMap.erase(last.first);
        cacheList.pop_back();
    }
    cacheList.push_front({key, value});
    cacheMap[key] = cacheList.begin();
}
