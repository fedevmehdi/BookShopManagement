/*
 * Phase: 2 - Data Structures
 *
 * Queue ADT
 * =========
 *
 * Purpose:
 * - Store pending order IDs in FIFO (first-in, first-out) order.
 *
 * Implementation:
 * - Linked-list-based queue.
 *
 * State:
 * - front: pointer to the oldest element.
 * - rear: pointer to the newest element.
 * - size: number of elements.
 * - An empty queue has front == nullptr and rear == nullptr.
 *
 * Operations:
 * - enqueue(data): insert an element at the rear.
 * - dequeue(): remove and return the front element/status.
 * - peekFront(): view the front element without removing it.
 * - peekRear(): view the rear element without removing it.
 * - isEmpty(): return true when the queue is empty.
 * - getSize(): return the element count.
 * - display(): display elements from front to rear.
 *
 * Required behaviour:
 * - Enqueue must add at the rear.
 * - Dequeue must remove from the front.
 * - Removing the only element must set both front and rear to nullptr.
 * - Empty dequeue and peek operations must be safe.
 * - Cancelled orders may be skipped when they reach the front.
 *
 * Pending-order policy proposal:
 * - FIFO processing.
 * - If the front order cannot be fulfilled in full, stop processing later
 *   orders rather than bypassing it.
 *
 * Return convention:
 * - Prefer status plus a reference/output parameter for dequeue and peek,
 *   or another convention agreed consistently across the project.
 *
 * STL restriction:
 * - Do not use std::queue or std::list.
 */

#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Node {
public:
   T data;
   Node* next;
   Node(T data) {
      this->data = data;
      next = nullptr;
   }
};

template <typename T>
class Queue {
public:
   Node<T>* front;
   Node<T>* rear;
   int size;

   Queue(): size(0), front(nullptr), rear(nullptr) {};

   void enqueue(T data){
      Node<T>* newNode = new Node<T>(data);
      if(front == nullptr) {
         front = rear = newNode;
      } else {
         rear->next = newNode;
         rear = newNode;
      }
      size++;
   }

   T dequeue() {
      if(front == nullptr) {
         throw out_of_range("Queue is empty");
      } 

      Node<T>* target = front;
      T value = target->data;
      
      front = front->next;
      if(front == nullptr) {
         rear = nullptr;
      }

      size--;
      delete target;
      return value; 
   }

   T peekFront() {
      if(front == nullptr) {
         throw out_of_range("Queue is empty");
      }
      return front->data;
   }

   T peekRear() {
      if(rear == nullptr) {
         throw out_of_range("Queue is empty");
      }
      return rear->data;
   }

   bool isEmpty() {
      if(rear == nullptr && front == nullptr) {
         return true;
      } else return false;
   }

   int getSize() {
      return size;
   }

   void display() {
      if(front==nullptr) {
         throw out_of_range("Queue is empty");
      }
      Node<T>* iterator = front;
      while(iterator != nullptr) {
         cout << iterator->data;
         if(iterator->next != nullptr) {
            cout << " -> ";
         }
         iterator = iterator->next;
      }
      cout << endl;
   }

};
