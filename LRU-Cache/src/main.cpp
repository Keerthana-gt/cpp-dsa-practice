#include <iostream>
#include "lru_cache.h"   
int main() {
    // Create an LRU Cache with capacity 2
    LRUCache cache(2);

    // Add some key-value pairs
    cache.put(1, 100);
    cache.put(2, 200);

    // Retrieve values
    std::cout << "Get 1: " << cache.get(1) << std::endl; // Should return 100

    // Add another key, this will evict the least recently used (key 2)
    cache.put(3, 300);

    // Try to get evicted key
    std::cout << "Get 2: " << cache.get(2) << std::endl; // Should return -1

    // Access key 1 again
    std::cout << "Get 1: " << cache.get(1) << std::endl; // Should return 100

    return 0;
}
