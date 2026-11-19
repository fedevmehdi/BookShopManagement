/*
 * Phase: 2 - Data Structures
 *
 * Stack ADT
 * =========
 *
 * Purpose:
 * - Store transaction history with the newest transaction available first.
 *
 * Implementation:
 * - Linked-list-based stack.
 *
 * State:
 * - top: pointer to the newest element; nullptr when empty.
 * - size: number of elements.
 *
 * Operations:
 * - push(data): add an element at the top.
 * - pop(): remove and return the top element/status.
 * - peek(): return/view the top element without removing it.
 * - isEmpty(): return true when there are no elements.
 * - getSize(): return the element count.
 * - display(): display elements from top to bottom.
 *
 * Required behaviour:
 * - Push must add the new element above the existing top.
 * - Pop must remove the most recently pushed element.
 * - Peek must not change the stack.
 * - Pop and peek must handle an empty stack safely.
 * - Display must handle an empty stack clearly.
 * - The destructor must release allocated nodes.
 *
 * Integrated-history rule:
 * - History search must not permanently change stack order.
 * - If temporary popping is used, restore every element before returning.
 *
 * Return convention:
 * - Prefer status plus a reference/output parameter for pop and peek,
 *   or another convention agreed consistently across the project.
 *
 * STL restriction:
 * - Do not use std::stack or std::list.
 */