class TimeMap {
public:
    unordered_map<string, unordered_map<int, vector<string>>> keyStore;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        keyStore[key][timestamp].push_back(value);
    }

    string get(string key, int timestamp) {
        int latest = 0;

        for (auto &it : keyStore[key]) {
            if (it.first <= timestamp)
                latest = max(latest, it.first);
        }

        if (latest == 0)
            return "";

        return keyStore[key][latest].back();
    }
};