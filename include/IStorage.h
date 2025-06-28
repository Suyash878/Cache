#pragma once
#include<string>
#include<optional>
using namespace std;

class IStorage{
    public:
    virtual ~IStorage() = default;
    virtual void set(const string& key, const string& value, int ttl = -1) = 0;
    virtual optional<string> get(const string& key) = 0;    
    virtual void remove(const string& key) = 0;
};