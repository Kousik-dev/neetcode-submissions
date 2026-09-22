class MyHashSet {
   private:
    struct ListNode {
        int key;
        ListNode* next;

        ListNode(int k) : key(k), next(nullptr) {}
    };

    vector<ListNode*>set;

    int hash(int key) { return key % set.size(); }

   public:
    MyHashSet() {
        set.resize(10000);

        for (auto& s : set) {
            s = new ListNode(0);
        }
    }

    void add(int key) {
        ListNode* current = set[hash(key)];

        while (current->next) {
            if (current->next->key == key) return;

            current = current->next;
        }

        current->next = new ListNode(key);
    }

    void remove(int key) {
        ListNode* current = set[hash(key)];

        while (current->next) {
            if (current->next->key == key) {
                ListNode* temp = current->next;
                current->next = temp->next;

                delete temp;
                return;
            }
            current = current->next;
        }
    }

    bool contains(int key) {
        ListNode* current = set[hash(key)];
        while (current->next) {
            if (current->next->key == key) return true;

            current = current->next;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */