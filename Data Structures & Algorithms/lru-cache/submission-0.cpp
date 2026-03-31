class LRUCache {
public:
    LRUCache(int capacity) {
        maxSize = capacity;
    }
    
    int get(int key) {
        if (lruCache.find(key) != lruCache.end()) {
            erase(lruKey, key);
            lruKey.push_back(key);
            return lruCache[key];
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (lruCache.find(key) == lruCache.end() && lruCache.size() >= maxSize) {
            lruCache.erase(lruKey[0]);
            lruKey.erase(lruKey.begin());
        }

        lruCache[key] = value;
        erase(lruKey, key);
        lruKey.push_back(key);
    }

private:
    unordered_map<int, int> lruCache;
    vector<int> lruKey;
    int maxSize;
};
