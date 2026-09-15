class LFUCache {
public:
    struct Node{
        Node* prev;
        Node* next;
        int key;
        int value;
        int cnt;
        Node(int k,int v){
            key=k;
            cnt=1;
            value=v;
            prev=NULL;
            next=NULL;
        }
    };
    struct list{
        int size;
        Node* head;
        Node* tell;
        list(){
            head=new Node(0,0);
            tell=new Node(0,0);
            head->next=tell;
            tell->prev=head;
            size=0;
        } 
        void add_front(Node* node){
            Node* temp=head->next;
            node->next=temp;
            node->prev=head;
            head->next=node;
            temp->prev=node;
            size++;
        }
        void remove_node(Node* delnode){
            Node* delprev=delnode->prev;
            Node* delnext=delnode->next;
            delprev->next=delnext;
            delnext->prev=delprev;
            size--;
        }
    };
    
    map<int,Node*>keynode;
    map<int,list*>freqlistmap;
    int maxsizeCache;
    int minfreq=0;
    int cursize=0;

    LFUCache(int capacity) {
        maxsizeCache=capacity;
        minfreq=0;
        cursize=0;
    }
    void updateNode(Node* node){
        keynode.erase(node->key);
        freqlistmap[node->cnt]->remove_node(node);
        if(node->cnt==minfreq && freqlistmap[node->cnt]->size==0){
            minfreq++;
        }
        list* nextHigherFreqList=new list();
        if(freqlistmap.find(node->cnt+1)!=freqlistmap.end()){
            nextHigherFreqList=freqlistmap[node->cnt+1];
        }
        node->cnt+=1;
        nextHigherFreqList->add_front(node);
        freqlistmap[node->cnt]=nextHigherFreqList;
        keynode[node->key]=node;
    }
    int get(int key) {
        if(keynode.find(key)!=keynode.end()){
            Node* node=keynode[key];
            int val=node->value;
            updateNode(node);
            return val;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(maxsizeCache==0)return ;
        if(keynode.find(key)!=keynode.end()){
            Node* node=keynode[key];
            node->value=value;
            updateNode(node);
        }
        else {
            if(cursize==maxsizeCache){
                list* list1=freqlistmap[minfreq];
                keynode.erase(list1->tell->prev->key);
                freqlistmap[minfreq]->remove_node(list1->tell->prev);
                cursize--;
            }
            cursize++;
            minfreq=1;
            list* listfreq=new list();
            if(freqlistmap.find(minfreq)!=freqlistmap.end()){
                listfreq=freqlistmap[minfreq];
            }
            Node* node=new Node(key,value);
            listfreq->add_front(node);
            keynode[key]=node;
            freqlistmap[minfreq]=listfreq ; 
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */