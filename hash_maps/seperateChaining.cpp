#include<iostream>
#include<string>
using namespace std;
template <typename V>
// for my linked list 
// node properties
class mapNode {
    public:

    string key;
    V value;
    mapNode* next;

    mapNode(string key, V value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~ mapNode() {
        delete next;
    }
};

// map class which contains functions 
// insert remove size
template <typename V>
class ourmap {
    public:

    mapNode<V>** bucketarr;
    int count;
    int numBuckets;

    ourmap() {
        count = 0;
        numBuckets = 5;
        bucketarr = new mapNode<V>*[numBuckets];

        for (int idx=0; idx<numBuckets; idx++) {
            bucketarr[idx] = NULL;
        }
    }

    ~ ourmap() {
        for (int idx=0; idx<numBuckets; idx++) {
            delete bucketarr[idx];
        }
        delete bucketarr;
    }

    // this will generate hash code and compress it 
    int generateHashCode(string key) {
        int hashcode = 0;
        int currentCoeff = 1;

        for (int idx=key.size() - 1; idx>=0; idx--) {
            hashcode += key[idx] * currentCoeff;
            hashcode = hashcode % numBuckets;
            currentCoeff *= 37;
            currentCoeff %= numBuckets;
        }

        return hashcode % numBuckets;
    }
  
    void rehashing() {
        mapNode<V>** temp = bucketarr;
        bucketarr = new mapNode<V>*[2*numBuckets];

        for (int idx=0; idx<2*numBuckets; idx++) {
            bucketarr[idx] = NULL;
        } 

        int oldBucketCount = numBuckets;
        count = 0;
        numBuckets *= 2;
        for (int idx=0; idx<oldBucketCount; idx++) {
            mapNode<V>* head = temp[idx];

            while(head != NULL) {
                string key = head->key;
                V value = head->value;

                insert(key,value);
                head = head->next;
            }
        } 

        for (int idx=0; idx<oldBucketCount; idx++) {
            delete temp[idx];
        }
        delete temp;
    }

    void insert(string key , V value) {
        int bucketIdx = generateHashCode(key);
        mapNode<V>* head = bucketarr[bucketIdx];
        while(head != NULL) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }

        mapNode<V>* node = new mapNode<V>(key,value);
        node->next = head;
        bucketarr[bucketIdx] = node;
        count++;

        double loadFactor = (1.0*count)/numBuckets;

        if (loadFactor > 0.7) {
            rehashing();
        }
    }

    double getLoadFactor() {
        return (1.0*count)/numBuckets;
    }
    int size() {
        return count;
    }

    V getValue(string key) {
        int bucketIdx = generateHashCode(key);
        mapNode<V>* head = bucketarr[bucketIdx];

        while(head != NULL) {

            if (head->key == key) {
                return head->value;
            }
            head = head->next;
        }

        return 0;
    }

    V removekey(string key) {
        int bucketIdx = generateHashCode(key);
        mapNode<V>* head = bucketarr[bucketIdx];
        mapNode<V>* prev = NULL;

        while(head != NULL) {
            
            
            if (head->key == key) {
                
                if (prev == NULL) {
                    bucketarr[bucketIdx] = head->next;
                }
                else {
                    prev->next = head->next; 
                }
                
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }

            prev = head;
            head = head->next;
        }

        return 0;
    }
};