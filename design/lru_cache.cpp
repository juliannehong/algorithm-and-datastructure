#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

//LRUCache cache = new LRUCache(2 /* capacity */);
//
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // returns 1
//cache.put(3, 3);    // evicts key 2
//cache.get(2);       // returns -1 (not found)
//cache.put(4, 4);    // evicts key 1
//cache.get(1);       // returns -1 (not found)
//cache.get(3);       // returns 3
//cache.get(4);       // returns 4

class LRUCache {
public:
  LRUCache(int capacity) {
    m_capacity = capacity;
  }

  int get(int key) {
    if (table.find(key) == table.end())
      return -1;
    else
      return *(table[key]);
  }

  void put(int key, int value) {
    if (table.find(key) == table.end()) {
      if (cache.size() == m_capacity) {
        int old_key = cache.back();
        cache.pop_back();
        table.erase(old_key);
      } 
      else {
        cache.push_front(key);
        table[key] = cache.begin();
      }
    }
    else {
      cache.erase(table[key]); // update data
      cache.push_front(key);
      table[key] = cache.begin();
    }
  }

private:
  int m_capacity;
  list<int> cache;
  unordered_map<int, list<int>::iterator> table;

};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache obj = new LRUCache(capacity);
* int param_1 = obj.get(key);
* obj.put(key,value);
*/
int main() {

  LRUCache cache(2);
  
  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl;      // returns 1
  cache.put(3, 3);    // evicts key 2
  cout << cache.get(2) << endl;       // returns -1 (not found)
  cache.put(4, 4);    // evicts key 1
  cout << cache.get(1) << endl;       // returns -1 (not found)
  cout << cache.get(3) << endl;       // returns 3
  cout << cache.get(4) << endl;       // returns 4
  system("pause");
  return 0;
}