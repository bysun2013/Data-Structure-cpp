/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/
#include <iostream>
#include <map>
#include <list>
#include <utility>

using namespace std;

typedef std::list<std::pair<int, int> > lru_type;

class LRUCache{
private:
	int total; /* 链表的最大容量 */
	int cur;  /* 目前链表的大小 */

	std::map<int, lru_type::iterator> tree;
	lru_type lru;
	lru_type::iterator get_free(int key, int value);
public:
    LRUCache(int capacity):total(capacity), cur(0) { }
    int get(int key);
    void set(int key, int value);
};

lru_type::iterator LRUCache::get_free(int key, int value)
{
	lru_type::iterator it;

	if(cur >= total){
		pair<int, int> last = lru.back();
//		cout<< "delete key " << last.first<< endl;
		tree.erase(last.first);
		lru.pop_back();
		cur--;
	}

	lru.push_front(make_pair(key, value));
	cur++;
	return lru.begin();
}

int LRUCache::get(int key) {
	map<int, lru_type::iterator>::const_iterator it;
	it = tree.find(key);
    if(it == tree.end())
		return -1;
    else{
 	    int value = it->second->second;
	    lru.push_front(make_pair(key, value));
        lru.erase(it->second);
	    tree[key] = lru.begin();
        return value;
    }
}

void LRUCache::set(int key, int value) {
    map<int, lru_type::iterator>::const_iterator it;
	if((it = tree.find(key)) == tree.end()){
//        cout<< "can' find key " << key<< endl;
		tree[key] = get_free(key, value);
	}else{
//	    cout<< "set key: find key " << key<< endl;
	    lru.erase(it->second);
	    lru.push_front(make_pair(key, value));
	    tree[key] = lru.begin();
	}
}

int main()
{

	LRUCache cache(2);
	cout << cache.get(2) << endl;
	cache.set(2,6);
	cout << cache.get(1) << endl;
	cache.set(1,5);
	cache.set(1,2);
	cout << cache.get(1) << endl;
	cout << cache.get(2) << endl;
	return 0;
}