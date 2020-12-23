#pragma once
#include <iostream>
#include <QString>
template <class T>
struct Node {
    T data;
    Node<T>* previous;
    Node<T>* next;
    int number;
};

template <class T>
class List {
protected:
    Node<T> *head;
    Node<T> *tail;
    int amount;
public:
    List() { head = nullptr; tail = nullptr; amount = 0; }
    List(List<T>* tmp) { head = tmp->head; tail = tmp->tail; amount = tmp->amount; }
    ~List();

    //Длина списка
    int size() { return this->amount; }
    void pushHead(T obj);
    void pushTail(T input_object);
    T popHead();
    T popTail();
    T& operator[](int num);
};

//Добавление с головы
template<class T>
void List<T>::pushHead(T obj) {
    if (head == nullptr) {
        head = new Node<T>;
        head->data = obj;
        head->next = nullptr;
        head->previous = nullptr;
        head->number = (amount++);
        tail = head;
    } else {
        auto *node = new Node<T>;
        node->data = obj;
        node->next = head;
        node->previous = nullptr;
        head->previous = node;
        head = node;
        for (int i = 0;node;node = node->next, i++) {
            node->number = i;
        }
        amount++;
    }
}

//Добавление в хвост
template<class T>
void List<T>::pushTail(T input_object) {
    if (head == nullptr) {
        head = new Node<T>;
        head->data = input_object;
        head->next = nullptr;
        head->previous = nullptr;
        head->number = (amount++);
        tail = head;
        return;
    }
    auto *node = new Node<T>;
    node->data = input_object;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;
    node->number = (amount++);
}

//Удаление от головы
template<class T>
T List<T>::popHead() {
    if (!(head)) return T();
    T data = head->data;
    Node<T>* node = head;
    if (head != tail) {
        head = head->next;
        head->previous = nullptr;
        Node<T>* tmp = head;
        for (int i = 0;tmp;tmp = tmp->next, i++) {
            tmp->number = i;
        }
    } else {
        head = tail = nullptr;
    }
    delete node;
    amount--;
    return data;
}

//Удаление из хвоста
template<class T>
T List<T>::popTail() {
    if (!(head)) return T();
    T data = tail->data;
    Node<T> *node = tail;
    if (tail != head) {
        tail = tail->previous;
        tail->next = nullptr;
    } else {
        head = tail = nullptr;
    }
    delete node;
    amount--;
    return data;
}

// Доступ к объектам с помощью индексации
template<class T>
T& List<T>::operator[](int num) {
    Node<T> *curr = head;
    if (num < 0 || num >= amount) return curr->data;
    for (int i = 0; i < num; i++)
        curr = curr->next;
    return curr->data;
}

template<class T>
List<T>::~List() { while (this->head) { this->popHead(); } }

