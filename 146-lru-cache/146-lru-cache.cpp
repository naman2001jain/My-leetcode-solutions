class LRUCache {
public:
    int size;
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator >> lru;
    list<int> order;
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        if(lru.find(key) == lru.end()){
            return -1;
        }
        //erase from the list
        order.erase(lru[key].second);
        //add the new element in the list
        order.push_front(key);
        //update the address in lru
        lru[key].second = order.begin();
        return lru[key].first;
    }
    
    void put(int key, int value) {
        if(lru.find(key) == lru.end()){
            //element is not present in lru we have to insert it
            if(this->size == this->capacity){
                //lru is full
                //remove from lru
                lru.erase(order.back());
                //remove the order
                order.pop_back();
                //adding the new element to order
                order.push_front(key);
                //adding the record of new element in lru
                lru[key] = {value, order.begin()};
            }else{
                order.push_front(key);
                lru[key] = {value, order.begin()};
                this->size++;
            }
            
        }else{
            //update the lru
            lru[key].first = value;
            order.erase(lru[key].second);
            order.push_front(key);
            lru[key].second = order.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */