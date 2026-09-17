class LRUCache {
public:

    int capacity;

    // key -> {value, iterator}
    unordered_map<int, pair<int, list<int>::iterator>> mp;

    // Front = most recently used
    // Back = least recently used
    list<int> lru;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {

        // Key not found
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // Remove key from its current position
        lru.erase(mp[key].second);

        // Put it at front (most recently used)
        lru.push_front(key);

        // Update iterator
        mp[key].second = lru.begin();

        return mp[key].first;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            // Remove old position
            lru.erase(mp[key].second);

            // Put at front
            lru.push_front(key);

            // Update value and iterator
            mp[key] = {value, lru.begin()};

            return;
        }

        // New key
        lru.push_front(key);
        mp[key] = {value, lru.begin()};

        // If capacity exceeded
        if (mp.size() > capacity) {

            // Least recently used key
            int oldKey = lru.back();

            // Remove from list
            lru.pop_back();

            // Remove from map
            mp.erase(oldKey);
        }
    }
};