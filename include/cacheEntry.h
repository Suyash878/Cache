#pragma once
#include <chrono>
#include <string>
using namespace std;

class CacheEntry 
{
public:
    string value;
    chrono::steady_clock::time_point creationTime;
    int ttl;
    int accessCount;

    CacheEntry(const std::string& val, int ttlSeconds = -1)
    : value(val),                 
      creationTime(std::chrono::steady_clock::now()),  
      ttl(ttlSeconds),            
      accessCount(0)              
    {}

    CacheEntry() : value(""), creationTime(chrono::steady_clock::now()), ttl(-1), accessCount(0) {}

    bool isExpired() const {
        if(ttl < 0) return false;

        auto now = chrono::steady_clock::now();
        return chrono::duration_cast<chrono::seconds>(now - creationTime).count() > ttl;
    }
};