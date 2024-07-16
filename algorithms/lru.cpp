#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << "" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << " " ; dbg_out(T...); }
#ifdef SAGAR
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename K, typename V> 
class LRUCache{
private:
    list<K> items;
    unordered_map<K, pair<V, typename list<K>::iterator>> kvMap;
    int max_cache_size;

public:
    LRUCache(int max_size): max_cache_size(max_size){}

    void set(const K& key, const V& value){
        //check if key exists
        auto itr = kvMap.find(key);

        dbg(key, value);

        if(itr != kvMap.end()){
            itr->second.first = value;
            items.splice(items.begin(), items, itr->second.second);
        }
        else{
            if(items.size() == max_cache_size){
                kvMap.erase(items.back());
                items.pop_back();
            }

            //insert the key at start
            items.push_front(key);
            kvMap[key] = {value, items.begin()};
        }

        dbg("Success Set");
    }

    bool get(const K& key, V& value){
        auto itr = kvMap.find(key);

        if(itr == kvMap.end()){
            dbg("Unsuccess Get");

            return false;
        }
        
        //put it to front
        items.splice(items.begin(), items, itr->second.second);

        value = itr->second.first;

        dbg("Success get");

        return true;
    }
};

template<typename K, typename V>
class LFUCache{

    struct Node
    {
        K key;
        V value;
        int count;
        typename std::list<K>::iterator keyPtr;

        Node(K k, V v, int cnt, typename std::list<K>::iterator keyPtr): key(k), value(v), count(cnt), keyPtr(keyPtr){}
    };

    std::map<int, typename std::list<K>> freq_map;

    std::map<K, Node> kvCache;

    int max_size;

    int curr_size;

    void increment_count(const K& key){
        auto itr = kvCache.find(key);

        int prev_cnt = itr->second.count;

        //move the key node from prev_cnt to new_cnt
        auto& new_list = freq_map[prev_cnt+1];

        auto& old_list = freq_map[prev_cnt];
        
        new_list.splice(new_list.begin(), old_list, itr->second.keyPtr);

        itr->second.count = prev_cnt+1;

        if(old_list.size() == 0){
            //remove the entry of old map key
            freq_map.erase(prev_cnt);
        }
    }

public:

    LFUCache(int max_size): max_size(max_size), curr_size(0){}

    void set(const K k, const V v){
        //finf if key exists
        auto itr = kvCache.find(k);

        if(itr != kvCache.end()){
            //update the value of key
            itr->second.value = v;

            increment_count(k);
        }
        else{
            //remove the key if
            if(curr_size == max_size){
                //need to remove the least frequently used one
                auto itr = freq_map.begin();

                //list
                auto& list = itr->second;

                //remove the last element of the list
                kvCache.erase(list.back());
                list.pop_back();

                if(list.size() == 0){
                    freq_map.erase(itr->first);
                }

                curr_size--;
            }

            auto& list = freq_map[1];

            list.push_front(k);

            kvCache.emplace(std::piecewise_construct,
                    std::forward_as_tuple(k),
                    std::forward_as_tuple(k, v, 1, list.begin()));
            
            curr_size++;
        }

        // dbg("Set Success");
    }

    bool get(const K& k, V& v){

        // dbg("In get");

        auto itr = kvCache.find(k);

        if(itr == kvCache.end()){

            // dbg("get false");

            return false;
        }

        v = itr->second.value;

        //update the counter for k
        increment_count(k);

        // dbg("get success");

        // dbg(freq_map);

        return true;
    }
};

