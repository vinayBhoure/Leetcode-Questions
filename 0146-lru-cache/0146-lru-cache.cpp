class LRUCache {
public:
    class node{
        public: 
        int key;
        int value;
        node* next;
        node* prev;
        
        node(int a, int b){
           key = a;
            value = b;
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int, node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    void addnode(node* newnode)
    {
        node* temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }
    
    void delnode(node* n)
    {
        node* prevnode = n -> prev;
        node* nextnode = n -> next;
        nextnode -> prev = prevnode;
        prevnode -> next = nextnode;
    }
    int get(int key) {
        if(mp.find(key) != mp.end())
        {
          node* node = mp[key];
            int res = node -> value;
            mp.erase(key);
            delnode(node);
            addnode(node);
            mp[key] = head->next;
            return res;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            node* extnode = mp[key];
            mp.erase(key);
            delnode(extnode);
        }
        
        if(mp.size() == cap)
        {
            mp.erase(tail->prev->key);
                delnode(tail->prev);
        }
        
        addnode(new node(key,value));
        mp[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */