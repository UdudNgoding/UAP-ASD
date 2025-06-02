// LinkedList.hpp
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Tambah node di akhir
    void addBack(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Hapus node di awal
    void removeFront() {
        if (head == nullptr) {
            cout << "List kosong!\n";
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    // Hapus node di akhir
    void removeBack() {
        if (head == nullptr) {
            cout << "List kosong!\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Print semua isi list
    void print() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Cek apakah list kosong
    bool isEmpty() {
        return head == nullptr;
    }

    // Ambil nilai head
    T front() {
        if (head == nullptr) {
            throw runtime_error("List kosong!");
        }
        return head->data;
    }

    // Hapus semua node (optional, berguna untuk stack/queue destructor)
    void clear() {
        while (!isEmpty()) {
            removeFront();
        }
    }

    // Destructor
    ~LinkedList() {
        clear();
    }
};

#endif
