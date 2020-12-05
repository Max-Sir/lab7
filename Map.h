#pragma once
#include "imports.h"
#include "error.h"
#include "Wear.h"
template <class T>
class Map {
public:
    static int size;
    class Node {
    public:
        Node* next;
        Node* prev;
        T data;
        Wear key;
        Node(T data) {
            this->data = data;
            next = nullptr;
            prev = nullptr;
        }
        Node() {
            next = nullptr;
            prev = nullptr;

        }
        Node& operator[](int index) {
            Node* tmp = head;
            int count = 0;
            while (count != index) {
                count++;
                tmp = tmp->next;
            }
            return tmp;
        }
        Node& operator=(Node it) {
            next = it.next;
            prev = it.prev;
            data = it.data;
            key.name = it.key.name;
            key.cost = it.key.cost;
            key.id = it.key.id;
            return *this;
        }
    };
    class Map_Iterator
    {
        Node* tmp;

    public:
        Map_Iterator() {
            tmp = nullptr;
        }
        Map_Iterator(Node* node) {
            tmp = node;
        }
        Map_Iterator& operator++() {
            try {
                if (size == 0) {
                    throw "The Map container is empty!\n";
                }
            }
            catch (const char* i) {
                Exception ex(i);
                ex.what();
            }
            tmp = tmp->next;
            return *this;
        }
        Map_Iterator& operator=(Map_Iterator it) {
            tmp = it.tmp;
            return *this;
        }
        bool operator == (const Map_Iterator& it) const
        {
            return (tmp == it.tmp);
        }
        bool operator!=(const Map_Iterator& it) const
        {
            return !(it == *this);
        }
        T& operator*() {
            return tmp->data;
        }

        Node*& operator[](int index) {
            try {
                if (size == 0) {
                    throw "The Map container is empty!\n";
                }
            }
            catch (const char* i) {
                Exception ex(i);
                ex.what();
            }
            Node* tmp = head;
            int count = 0;
            while (count != index) {
                count++;
                tmp = tmp->next;
            }
            return tmp;
        }
    	
        Map_Iterator& operator+(int data) {
            int i = 0;
            while (i < data) {
                tmp = tmp->next;
                i++;
            }
            return *this;
        }
    };
private:
    Node* head;
    Node* tail;
    Map_Iterator* begin;
    Map_Iterator* end;
public:
    Map() {
        head = nullptr;
        tail = nullptr;
        begin = nullptr;
        end = nullptr;
    }
    int Size() {
        return size;
    }
    void push(T data) {
        Node* tmp = new Node(data);
        tmp->next = nullptr;
        if (head == nullptr) {
            tmp->prev = nullptr;
            tail = tmp;
            head = tmp;
            begin = new Map_Iterator(head);
        }
        else {
            tmp->prev = tail;
            tail->next = tmp;
            tail = tmp;
            end = new Map_Iterator(tail);
        }
        size++;
    }
    void print() const
    {
        try {
            if (size == 0) {
                throw "The Map container is empty!\n";
            }
        }
        catch (const char* i) {
            Exception ex(i);
            ex.what();
            return;
        }
        Node* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->key << " " << tmp->data << endl;
            tmp = tmp->next;
        }
    }


    void search(int id) const
    {
        try {
            if (size == 0) {
                throw "Error: Searching in Empty map. The Map container is empty!\n";
            }
        }
        catch (const char* i) {
            Exception ex(i);
            ex.what();
            return;
        }
        Node* tmp = head;
        int fl = 0;
        while (tmp != nullptr) {
            if (tmp->key.id == id) {
                cout << "FIND:\n " << tmp->data << "\nKEY is object: \n" << tmp->key << "\n\n";
                fl = 1;
            }
            tmp = tmp->next;
        }
        if (fl == 0) {
            cout << "There isn't such object in the _array";
        }
    }
    Node*& operator[](int index) {
        try {
            if (size == 0) {
                throw "The Map container is empty!\n";
            }
        }
        catch (const char* i) {
            Exception ex(i);
            ex.what();
        }
        Node* tmp = head;
        int count = 0;
        while (count != index) {
            count++;
            tmp = tmp->next;
        }
        return tmp;
    }
    Map_Iterator& _begin() {
        try {
            if (size == 0) {
                throw "The Map container is empty!\n";
            }
        }
        catch (const char* i) {
            Exception ex(i);
            ex.what();
        }
        return *begin;
    }

    Map_Iterator& _end() {
        try {
            if (size == 0) {
                throw "The Map container is empty!\n";
            }
        }
        catch (const char* i) {
            Exception ex(i);
            ex.what();
            return;
        }
        return *end;
    }
    T pop()
    {

        try {
            if (size == 0) {
                throw "The Map container is empty!\n";
            }
        }
        catch (const char* i) {
            Exception ex(i);
            ex.what();
        }
        Node* Node_to_remove = head;
        T return_val = Node_to_remove->data;
        head = Node_to_remove->next;
        head->prev = nullptr;
        begin = new Map_Iterator(head);

        delete Node_to_remove;
        size--;
        return return_val;

    }
    void Insertion_Sort(Map<T>& _array) {
        try {
            if (size == 0) {
                throw "The Map container is empty!\n";
            }
        }
        catch (const char* i) {
            Exception ex(i);
            ex.what();
            return;
        }
        Node* tmp = new Node();
        for (int counter = 1; counter < _array.Size(); counter++)
        {
            tmp = _array[counter];
            int it = counter - 1;
            while (it >= 0 && _array[it]->key.cost < tmp->key.cost)
            {
                _array[it + 1] = _array[it];
                _array[it] = tmp;
                it--;
            }
        }
    }
	
    void pasteSort() {
        if (!(this->head && this->tail)) return;
        Node* current_node = this->head,
            * spoted_node;
        while (current_node != this->tail)
        {
            spoted_node = current_node->next;
            while (spoted_node->key.cost < spoted_node->prev->key.cost)
            {
                if (spoted_node->next) {
                    spoted_node->next->prev = spoted_node->prev;
                }
                else {
                    this->tail = spoted_node->prev;//вот тута замечательный эксепшн для попытки сорта контэйнера с одним элементом
                }
                spoted_node->prev->next = spoted_node->next;
                spoted_node->prev = spoted_node->prev->prev;
                if (!spoted_node->prev) break;
            }
            if (spoted_node->prev) {
                if (spoted_node->prev != current_node) {
                    spoted_node->next = spoted_node->prev->next;
                    spoted_node->prev->next = spoted_node;
                    spoted_node->next->prev = spoted_node;
                }
            }
            else
            {
                this->head->prev = spoted_node;
                spoted_node->next = this->head;
                this->head = spoted_node;
            }
            if (current_node->next == spoted_node)
                current_node = spoted_node;

        }
    }
};
template<class T>
int Map<T>::size = 0;
