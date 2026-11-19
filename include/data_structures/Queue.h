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