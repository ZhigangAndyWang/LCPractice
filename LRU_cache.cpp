class LRUCache{
private:
    //define the double linked list
    struct Node{
        Node *prev;
        Node *next;
        int value;
        int key;
        Node(int k, int v):prev(NULL),next(NULL),value(v),key(k){};
        Node(Node *p, Node *n,int v, int k):prev(p),next(n),value(v),key(k){};
    };
    //the head and tail of the double linked list
    Node *head;
    Node *tail;
    //define the hashtable used to find node
    unordered_map<int,Node*> mp;
    int cp;
public:
    LRUCache(int capacity) {
        cp = capacity;
        head = NULL;
        tail = NULL;
        mp.clear();
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        else
        {
            Node *tmp = mp[key];
            moveNode(tmp);
            return tmp->value;
        }    
    }
    
    void set(int key, int value) {
        if(mp.find(key)!=mp.end()){
            moveNode(mp[key]);
            mp[key]->value = value;
            return;
        }
        else{
            if(mp.size()==cp){
                mp.erase(head->key);
                rmNode(head);
            }
            Node *node = new Node(key,value);
            mp[key] = node;
            insertNode(node);
        }
    }
    
    void moveNode(Node *node){
        if(node == tail) return;
        if(node == head){
            tail->next = head;
            head->prev = tail;
            head = head->next;
            head->prev = NULL;
            tail = tail ->next;
            tail->next = NULL;
        }
        else{
            node->prev->next = node->next;
            node->next->prev = node->prev;
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
            tail->next = NULL;
        }
    }
    
    void rmNode(Node *node){
        if(node == head){
            head = head->next;
            if(head) head->prev = NULL;
        }
        else if(node == tail){
            tail = tail->prev;
            if(tail) tail->next = NULL;
        }
        else{
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }
    
    void insertNode(Node *node){
        if(!head){
            head = tail = node;
        }
        else{
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
        }
    }
    
};