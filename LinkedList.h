//
// Created by Ariana Astorga Vega on 9/17/26.
//

#pragma once
#include <iostream>

#include "Node.h" #include "List.h"

template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr) {}
    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
    }
    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_->next;
        delete doomed->data;
        delete doomed;
    }
    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) return true;
            current = current->next;
        }
        return false;
    }
    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }
    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }
private:
    Node<T>* head_;
};



// old code + notes with old code

// class LinkedList {
// public:
//     Node<T> *head;
//     // Node<T> *tail;
//     int size;
//
//     LinkedList(T *value) {
//         Node<T> *temp = new Node<T>(value);
//         head = temp; // constructor so very first node gets called forcing list to have at least one node inside of it
//         size = 1; // at least one item via beginning list
//         // must create a list with something at least one element bc must be intentional
//         // although can be empty trees and graphs must be nonempty data structures (at least 1 node in order to be called graphs + tree)
//     }
//     void print() {
//         Node<T> *temp1 = head;
//         while (temp1 != nullptr) {
//             temp1->print(); // if want the address you would point to value but if want to access the actual value you would use print() since node has a print function
//             temp1 = temp1->next; // never move the head pointer bc then you lose track of the front of the list and loose everythign basically
//         }
//
//     }
//
//     void append(T *value) {
//         Node<T> *newnode = new Node<T>(value);
//         if (head == nullptr) { // edge case for list to be empty
//             head = newnode;
//             size++;
//             return;
//         }
//         Node<T> *temp = head;
//         while (temp->next != nullptr) { // one before aka last one
//             temp = temp->next;
//         }
//         temp->next = newnode;
//         size++;
//     } // able to turn into o(1) instead of o(n) if using tail because it would automatically go to the end of the list and not have to go one through one
//     // delete at the end
//     // 4 methods on array.h no linked list no main no anythign jsut h
// };
