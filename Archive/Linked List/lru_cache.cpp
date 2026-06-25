#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: LRU Cache
 * 
 * Description:
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 * Implement the LRUCache class:
 * - LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 * - int get(int key) Return the value of the key if the key exists, otherwise return -1.
 * - void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value 
 *   pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
 * 
 * Approach 1 (LRUCache2):
 * Custom Doubly Linked List (DLL) and Hashing. A Node structure with key, value, prev, and next pointers.
 * Dummy head and tail are used to simplify node insertion and deletion.
 * 
 * Approach 2 (LRUCache):
 * STL std::list (acting as DLL for key history) and std::unordered_map storing the value along with 
 * an iterator pointing to the key's location in the list.
 * 
 * Time Complexity:
 * - get(): O(1) average.
 * - put(): O(1) average.
 * 
 * Space Complexity:
 * - O(Capacity) to store elements.
 */

class Node {
public:
    int key, value;
    Node* prev;
    Node* next;
    Node(int _key, int _value) {
        key = _key;
        value = _value;
        prev = next = nullptr;
    }
};

class LRUCache2 {
private:
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;
    int capacity;

    // Internal helper: Safely removes a node from the linked list links and the map
    void remove(Node* node) {
        map.erase(node->key);
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Internal helper: Inserts a node right after the dummy head (Most Recently Used position)
    void insert(Node* node) {
        map[node->key] = node;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

public:
    LRUCache2(int _capacity) {
        capacity = _capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    // Destructor to free dynamically allocated memory safely
    ~LRUCache2() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    int get(int key) {
        if (map.count(key)) {
            Node* node = map[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (map.count(key)) {
            // Key exists: update its value, bring it to front
            Node* existingNode = map[key];
            remove(existingNode);
            existingNode->value = value; // Update value
            insert(existingNode);       // Re-insert at the head
        } else {
            // Key does not exist: Check capacity
            if (map.size() == capacity) {
                Node* lruNode = tail->prev; // Node right before tail is the LRU item
                remove(lruNode);
                delete lruNode;             // Clean up memory!
            }
            // Create and insert the fresh node
            insert(new Node(key, value));
        }
    }
};

class LRUCache {
private:
    int capacity;
    // Doubly Linked List to store keys. Front = Most Recent, Back = Least Recent
    list<int> key_history; 
    
    // Map stores: key -> pair<value, list iterator to track its position in key_history>
    unordered_map<int, pair<int, list<int>::iterator>> cache;

    // Helper function to bring an existing key to the front (Most Recently Used)
    void make_recently_used(int key) {
        // Erase the old position from the list using the iterator stored in map
        key_history.erase(cache[key].second);
        // Push it to the front
        key_history.push_front(key);
        // Update the map with the new iterator position
        cache[key].second = key_history.begin();
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }
        
        // Refresh its usage status since it was accessed
        make_recently_used(key);
        
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        
        if (it != cache.end()) {
            // Key exists: update its value and move to front
            it->second.first = value;
            make_recently_used(key);
        } else {
            // Key does not exist: check if cache is full
            if (cache.size() >= capacity) {
                // Cache full: get the LRU key (from the back of the list)
                int lru_key = key_history.back();
                
                // Evict it from both map and list
                cache.erase(lru_key);
                key_history.pop_back();
            }
            
            // Insert the new key at the front of the list
            key_history.push_front(key);
            // Insert into the map along with its list position iterator
            cache[key] = {value, key_history.begin()};
        }
    }

    bool contains(int key) {
        auto it = cache.find(key);
        return it != cache.end();
    }
};
