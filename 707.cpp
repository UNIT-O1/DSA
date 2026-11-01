class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int val) {
            this->val = val;
            this->next = nullptr;
        }
    };
    Node* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    // Clean up allocated memory when object is destroyed
    ~MyLinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;

        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* newnode = new Node(val);
        newnode->next = head;
        head = newnode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* curr = head;
        if (curr == nullptr) {
            addAtHead(val);
            return;
        }
        Node* newnode = new Node(val);
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newnode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        // Fix 1: Allow index == size (inserts at tail)
        if (index < 0 || index > size)
            return;

        // Fix 2: Handle head insertion explicitly
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* newnode = new Node(val);
        Node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode; 
        size++; // Fix 3: Update size
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;

        if (index == 0) {
            Node* curr = head;
            head = head->next;
            delete curr;
            size--;
            return;
        }

        Node* curr = head;
        for (int i = 0; i < index - 1; ++i) {
            curr = curr->next;
        }
        Node* toDelete = curr->next;
        curr->next = toDelete->next;
        delete toDelete;
        size--;
    }
};N
