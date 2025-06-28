#pragma once
#include "../include/IStorage.h"
#include "../include/cacheEntry.h"
#include <unordered_map>
#include <mutex>
using namespace std;

class InMemoryStorage : public IStorage
{
    private:
    unordered_map<string, CacheEntry> map;
    mutex mtx;

    public:
    void set(const string& key, const string& value, int ttl) override
    {
        lock_guard<mutex> lock(mtx);
        map[key] = CacheEntry(value, ttl);
    };

    optional<string> get(const string& key) override
    {
        lock_guard<mutex> lock(mtx);

        auto it = map.find(key);
        if (it != map.end())
        {
            if(it->second.isExpired())
            {
                map.erase(it);
                return nullopt;
            }

            it->second.accessCount++;
            return it->second.value;
        }
        return nullopt;
    }

    void remove(const string& key) override
    {
        lock_guard<mutex> lock(mtx);
        map.erase(key);
    }


};