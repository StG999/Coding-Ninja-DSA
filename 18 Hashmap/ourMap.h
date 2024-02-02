#include <string>
using namespace std;

template <typename V>
class MapNode
{
    public:
        string key;
        V value;
        MapNode *next;

        MapNode(string key, V value)
        {
            this->key = key;
            this->value = value;
            next = nullptr;
        }

        ~MapNode()
        {
            delete next;
        }
};

template <typename V>
class ourMap
{
    MapNode<V> **buckets;
    int count;
    int numBuckets;
    
    public:
        ourMap()
        {
            numBuckets = 5;
            count = 0;
            buckets = new MapNode<V>*[numBuckets];

            for(int i=0; i<numBuckets; i++)
                buckets[i] = nullptr;
        }

        ~ourMap()
        {
            for(int i=0; i<numBuckets; i++)
                delete buckets[i];

            delete [] buckets;
        }

        int size()
        {
            return count;
        }

        V getValue(string key)
        {
            int bucketIndex = hashIndexGenerator(key);

            MapNode<V> *head = buckets[bucketIndex];
            while(head != nullptr)
            {
                if(head->key == key)
                    return head->value;

                head = head->next;
            }

            return 0;
        }

    private:
        int hashIndexGenerator(string key)
        {
            int hashCode = 0;
            int keyLen = key.length();
            int currentCoeff = 1;

            for(int i=keyLen-1; i<=0; i--)
            {
                hashCode += key[i] * currentCoeff;
                currentCoeff *= 37;
                hashCode = hashCode % numBuckets;
                currentCoeff = currentCoeff % numBuckets;
            }

            return hashCode % numBuckets;
        }

        void rehashing()
        {
            MapNode<V> **oldBuckets = buckets;
            int oldCount = numBuckets;
            count = 0;
            numBuckets *= 2;
            buckets = new MapNode<V>*[numBuckets];

            for(int i=0; i<numBuckets; i++)
                buckets[i] = nullptr;

            for(int i=0; i<oldCount; i++)
            {
                MapNode<V> *head = oldBuckets[i];
                while(head != NULL)
                {
                    insert(head->key, head->value);
                    head = head->next;
                }

                delete oldBuckets[i];
            }   

            delete [] oldBuckets;
        }

    public:
        void insert(string key, V value)
        {
            int bucketIndex = hashIndexGenerator(key);
            
            MapNode<V> *head = buckets[bucketIndex];
            while(head != nullptr)
            {
                if(head->key == key)
                {
                    head->value = value;
                    return;
                }
                head = head->next;
            }

            head = buckets[bucketIndex];
            MapNode<V> *newNode = new MapNode<V>(key, value);
            newNode->next = head;
            buckets[bucketIndex] = newNode;
            count++;

            if((1.0*count)/numBuckets > 0.7)
                rehashing();

            return;
        }

        V remove(string key)
        {
            int bucketIndex = hashIndexGenerator(key);
            
            MapNode<V> *head = buckets[bucketIndex];
            MapNode<V> *prev = nullptr;
            while(head != nullptr)
            {
                if(head->key == key)
                {
                    if(prev == NULL)
                        buckets[bucketIndex] = nullptr;
                    else
                        prev->next = head->next;

                    head->next = nullptr;
                    V tmp = head->value;
                    delete head;
                    count--;
                    return tmp;

                }
                prev = head;
                head = head->next;
            }

            return 0;
        }

        double getLoadFactor()
        {
            return (1.0*count)/numBuckets;
        }
};