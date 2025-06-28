#include "src/inMemoryStorage.h"
#include<iostream>
using namespace std;

int main()
{
    InMemoryStorage storage;     
    // storage.set("Suyash","21",10);

    auto result = storage.get("Suyash");
    if (result) {
        cout << "Value: " << *result << endl;
    } else {
        cout << "Key not found or expired." << endl;
    }
}   