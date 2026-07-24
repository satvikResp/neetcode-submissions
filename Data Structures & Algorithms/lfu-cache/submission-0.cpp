class Node {
public:
    int data;
    int freq;
    int timer;

    Node(int d = 0, int f = 1, int t = 0) {
        data = d;
        freq = f;
        timer = t;
    }
};

class LFUCache {
public:
    unordered_map<int, Node> cache;
    int capacity;
    int globaltimer;

    LFUCache(int capacity) {
        this->capacity = capacity;
        globaltimer = 0;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        cache[key].freq++;
        cache[key].timer = ++globaltimer;

        return cache[key].data;
    }

    void put(int key, int value) {
        if (capacity <= 0)
            return;

        if (cache.find(key) != cache.end()) {
            cache[key].data = value;
            cache[key].freq++;
            cache[key].timer = ++globaltimer;
            return;
        }

        if (cache.size() >= capacity) {
            int minFreq = INT_MAX;
            int minTimer = INT_MAX;
            int delKey = -1;

            for (auto &it : cache) {
                if (it.second.freq < minFreq ||
                   (it.second.freq == minFreq &&
                    it.second.timer < minTimer)) {

                    minFreq = it.second.freq;
                    minTimer = it.second.timer;
                    delKey = it.first;
                }
            }

            cache.erase(delKey);
        }

        cache.emplace(key, Node(value, 1, ++globaltimer));
    }
};