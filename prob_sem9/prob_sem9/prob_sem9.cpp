#include <cstdio>

template <typename K, typename V>
class Map 
{
private:
    struct Node 
    {
        K key;
        V value;
        Node* next;
    };

    Node* head;
    int count;

public:
    Map() : head(nullptr), count(0) {}

    bool Get(const K& key, V& value) 
    {
        Node* current = head;
        int index = 0;
        while (current != nullptr) 
        {
            if (current->key == key) 
            {
                value = current->value;
                return true;
            }
            current = current->next;
            index++;
        }
        return false;
    }

    void Set(const K& key, const V& value) 
    {
        Node* newNode = new Node{ key, value, nullptr };
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;
            while (current->next != nullptr) 
            {
                if (current->key == key) 
                {
                    current->value = value;
                    return;
                }
                current = current->next;
            }
            if (current->key == key) 
            {
                current->value = value;
            }
            else 
            {
                current->next = newNode;
            }
        }
        count++;
    }

    int Count() 
    {
        return count;
    }

    void Clear()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        count = 0;
    }

    bool Delete(const K& key) 
    {
        if (head == nullptr) 
        {
            return false;
        }
        if (head->key == key)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            count--;
            return true;
        }
        Node* current = head;
        while (current->next != nullptr)
        {
            if (current->next->key == key)
            {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                count--;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool Includes(const Map<K, V>& map)
    {
        Node* current = map.head;
        while (current != nullptr) 
        {
            V value;
            if (!Get(current->key, value)) 
            {
                return false;
            }
            current = current->next;
        }
        return true;
    }
};

template <typename K, typename V>
void PrintMap(const Map<K, V>& map) 
{
    int index = 0;
    for (auto [key, value, i] : map) {
        printf("Index:%d, Key=%d, Value=%s\n", i, key, value);
    }
}

int main() 
{
    Map<int, const char*> m;
    m.Set(10, "C++");
    m.Set(20, "test");
    m.Set(30, "Poo");
    PrintMap(m);
    m.Set(20, "result");
    PrintMap(m);
    return 0;
}
