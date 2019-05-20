#include <iostream>

using namespace std;

class MyLinkedList {
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int x) : val( x ), next( NULL ) {}
    };
    ListNode* head;
    int size;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() : head( NULL ), size( 0 ) {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        
        ListNode* node = head;
        for (int i = 0; i < index; ++i) {
            node = node->next;
        }
        return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (head == NULL) {
            head = new ListNode(val);
        }
        else {
            ListNode* node = head;
            while (node->next != NULL) {
                node = node->next;
            }
            node->next = new ListNode(val);
        }
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        else if (index == size) {
            addAtTail( val );
            return;
        }
        else if (index == 0) {
            addAtHead( val );
            return;
        }
        
        ListNode* prev;
        ListNode* curr = head;
        for (int i = 0; i < index; ++i) {
            prev = curr;
            curr = curr->next;
        }
        
        ListNode* node = new ListNode(val);
        prev->next = node;
        node->next = curr;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        else if (index == 0) {
            ListNode* node = head->next;
            delete head;
            head = node;
            return;
        }
        
        ListNode* prev;
        ListNode* curr = head;
        for (int i = 0; i < index; ++i) {
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = curr->next;
        delete curr;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */