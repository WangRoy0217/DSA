class LRUCache {
public:
    LRUCache(int capacity)
    {
        capacity_ = capacity;
    }
    
    int get(int key)
    {
        const auto iter = m_.find(key);

        // cend() -> return const iterator
        if(iter == m_.cend())
            return -1;
        cache_.splice(cache_.begin(), cache_, iter->second);
        return iter->second->second;
    }
    
    void put(int key, int value)
    {
        const auto iter = m_.find(key);
        if(iter != m_.cend())
        {
            cache_.splice(cache_.begin(), cache_, iter->second);
            return;
        }
        if(cache_.size() == capacity_ )
        {
            const auto& pop_node = cache_.back();
            m_.erase(pop_node.first);
            cache_.pop_back();
        }
        cache_.emplace_front(key, value);
        m_[key] = cache_.begin();
    }
private:
    int capacity_;
    list<pair<int,int>> cache_;
    unordered_map< int,list<pair<int,int>>::iterator > m_;

};