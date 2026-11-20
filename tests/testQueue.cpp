/*
 * Phase: 2 - Data Structures
 *
 * Queue independent tests
 * =======================
 *
 * Required cases:
 * - Empty queue: isEmpty, getSize, dequeue, peekFront, and peekRear.
 * - Enqueue the first element.
 * - Enqueue multiple elements and verify FIFO order.
 * - Dequeue normally.
 * - Dequeue the only element and verify front/rear are both empty.
 * - Peek front and rear without removing.
 * - Display front to rear.
 * - Verify node cleanup through repeated use.
 */

#include "Queue.h"

 int main() {
    Queue<int> q;
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.getSize();
    // q.display();
    
    cout << q.peekFront();
    cout << q.peekRear();

    return 0;
 }