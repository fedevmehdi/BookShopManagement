# Implementation Phase Tracker

**Purpose:** This file tracks the team's current implementation phase and prevents
work from skipping ahead.

## Instructions

- Update `CURRENT_PHASE` before starting work.
- Mark a phase complete only after its definition-of-done evidence exists.
- Do not begin the next phase while unchecked required work remains.
- Keep phase labels in header and test file comments in sync with this tracker.
- Record test commands or test evidence in the evidence column.

## Current status

**CURRENT_PHASE:** 2 - Data Structures

**Current action:** Implement and independently test the Linked List first.

**Next action after Phase 2:** Implement Phase 3 entity class skeletons and tests.

| Phase | Title | Status | Required output | Evidence |
|---|---|---|---|---|
| 1 | Project Setup | Complete | Structure, documentation, build convention, skeleton | Repository skeleton created |
| 2 | Data Structures | In progress | Linked List, Stack, Queue, BST, Hash Table, sorting/searching + tests | Linked List implementation and tests pending |
| 3 | Entity Classes | Not started | Book, Customer, Supplier, Employee, Order, Transaction | None |
| 4 | Book Management | Not started | Book CRUD, consistency across list/BST/hash table | None |
| 5 | Other CRUD Managers | Not started | Customer, Supplier, and Employee CRUD | None |
| 6 | Orders and Transactions | Not started | Pending queue, sales/restock, transaction stack/history | None |
| 7 | Persistence and Integration | Not started | File manager, startup load, save, index rebuilding | None |
| 8 | Reports, Testing, and Submission | Not started | Menu, reports, full tests, documentation, screenshots | None |

## Phase 1 — Project Setup

- [x] Create project folders.
- [x] Create commented skeleton files.
- [x] Add project context and phase tracker.
- [x] Confirm build command and team naming conventions.
- [x] Commit the initial skeleton.

## Phase 2 — Data Structures

Recommended implementation order:

1. Linked List
2. Stack
3. Queue
4. BST
5. Hash Table
6. Sorting and Searching

Completion checklist:

- [x] Linked List implemented and tested.
- [x] Stack implemented and tested.
- [x] Queue implemented and tested.
- [x] BST implemented and tested.
- [ ] Hash Table implemented and tested.
- [ ] Sorting and Searching implemented and tested.
- [ ] Independent tests pass.
- [ ] Manual structure ownership and cleanup are verified.
- [ ] No prohibited STL container replacements are used.

## Phase 3 — Entity Classes

- [x] Implement `Book` fields, constructor/validation, getters/setters, stock methods, and display contract.
- [x] Implement `Customer` fields and lifecycle contract.
- [ ] Implement `Supplier` fields and lifecycle contract.
- [ ] Implement `Employee` fields and lifecycle contract.
- [ ] Implement `Order` fields and status contract.
- [ ] Implement `Transaction` fields and history contract.
- [ ] Add and pass independent entity tests.

## Phase 4 — Book Management

- [ ] Implement book add/update/delete/search/display.
- [ ] Keep Linked List, BST, and Hash Table indexes consistent.
- [ ] Apply stock and deletion validation rules.
- [ ] Implement title/price sorting through the utility module.
- [ ] Test normal, missing-key, duplicate, and update/remove cases.

## Phase 5 — Customer, Supplier, and Employee Management

- [ ] Implement Customer CRUD and validation.
- [ ] Implement Supplier CRUD and validation.
- [ ] Implement Employee CRUD and validation.
- [ ] Test independent normal and error cases.

## Phase 6 — Orders and Transactions

- [ ] Implement pending order Queue.
- [ ] Validate sales against available stock.
- [ ] Reduce stock and record successful sales.
- [ ] Implement restocking and transaction recording.
- [ ] Process and update pending orders.
- [ ] Add Transaction Stack history and safe history search.
- [ ] Test FIFO, cancellation, insufficient stock, and history behavior.

## Phase 7 — Persistence and Integration

- [ ] Agree and document CSV format and date format.
- [ ] Implement File Manager load/save operations.
- [ ] Load data at startup.
- [ ] Save changes when mutations occur or at defined shutdown points.
- [ ] Rebuild BST and Hash Table indexes after loading.
- [ ] Preserve pending Queue order.
- [ ] Test persistence and restart behavior.

## Phase 8 — Reports, Testing, and Submission

- [ ] Build the menu-driven interface.
- [ ] Implement system summary and required reports.
- [ ] Handle invalid input and edge cases consistently.
- [ ] Run complete system tests.
- [ ] Update README and documentation.
- [ ] Prepare screenshots, diagrams, conclusion, and viva notes.

## Module-to-phase map

| Skeleton area | Phase |
|---|---|
| `include/data_structures/*`, `tests/test*` | 2 |
| `include/entities/*`, `tests/testEntities.cpp` | 3 |
| `include/managers/BookManager.h`, `tests/testBookManager.cpp` | 4 |
| Customer/Supplier/Employee manager files | 5 |
| Order/Transaction manager files | 6 |
| `include/services/FileManager.h`, persistence data files | 7 |
| Menu and report files | 8 |

