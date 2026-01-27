# Generic Singly Linked List in C (Path A)

## Overview

This project implements a generic, production-quality singly linked list in C.
The linked list stores data as `void *`, making it data-type agnostic.

The library focuses on correct API design, memory safety, and ownership clarity.
It manages only the linked list structure and node lifetimes.
All user data handling is explicitly the responsibility of the caller.

This design closely follows how real C libraries and kernel data structures work.

---

## Project Structure



01-linked-list-core/
├── include/
│   └── linked_list.h
├── src/
│   └── linked_list.c
├── test.c
├── README.md
└── .gitignore

`

---

## Design Goals

- No global variables
- Generic storage using `void *`
- Clean separation of library and client code
- No hidden memory allocation for user data
- No assumptions about stored data types
- Predictable behavior and extensible design

---

## Data Structures


struct node {
    void *data;
    struct node *next;
};

struct LinkedList {
    struct node *head;
    int size;
};

---

## Ownership Rules (IMPORTANT)

* The linked list allocates and frees nodes only
* The linked list does NOT allocate, copy, compare, print, or free user data
* The user is responsible for:

  * allocating stored data
  * casting `void *` back to the correct type
  * freeing stored data when required

This design mirrors standard C APIs such as `qsort`, `pthread`, and kernel linked lists.

---

## Public API


void ll_init(struct LinkedList *list);
void ll_clear(struct LinkedList *list);

int ll_push_back(struct LinkedList *list, void *data);
int ll_push_front(struct LinkedList *list, void *data);
int ll_insert_at(struct LinkedList *list, void *data, int pos);

int ll_delete_at(struct LinkedList *list, int pos);

void ll_reverse(struct LinkedList *list);
int  ll_has_cycle(struct LinkedList *list);


---

## Supported Data Types

The linked list can store any data type, including:

* Integers (`int *`)
* Characters (`char *`)
* Strings (`char *`)
* Structures (`struct *`)
* Any user-defined data type

The list stores pointers only, never values.

---

## Example: Storing Integers


struct LinkedList list;
ll_init(&list);

int *a = malloc(sizeof(int));
int *b = malloc(sizeof(int));

*a = 10;
*b = 20;

ll_push_back(&list, a);
ll_push_back(&list, b);


Printing values:


struct node *curr = list.head;
while (curr) {
    printf("%d ", *(int *)curr->data);
    curr = curr->next;
}


Cleanup:


ll_clear(&list);
free(a);
free(b);


---

## Example: Storing Strings


ll_push_back(&list, strdup("hello"));
ll_push_back(&list, strdup("world"));


Printing:


printf("%s\n", (char *)curr->data);


Cleanup:


free(curr->data);


---

## IMPORTANT: Mixed Data Types Limitation

Although the list can store any data type, it cannot safely access multiple data types simultaneously without additional user-managed metadata.

### Why this limitation exists

* The list stores only `void *`
* `void *` contains no type information
* The list cannot determine how to:

  * print data
  * compare data
  * interpret memory

### Example of unsafe usage


ll_push_back(&list, int_ptr);
ll_push_back(&list, char_ptr);


At traversal time, the list cannot know which node contains which type.

### Correct user-side solutions

* Use one data type per list
* Use a wrapper struct with a type tag
* Use separate lists for separate data types

This limitation is intentional and standard for generic C containers.

---

## What This Library Does NOT Do (By Design)

* No delete-by-value (no comparison logic)
* No print function inside the library
* No automatic freeing of user data
* No runtime type inference

These exclusions keep the library:

* simple
* safe
* predictable
* easy to extend

---

## Build and Test

Compile with:

bash
gcc test.c src/linked_list.c -Iinclude -o test


Run:

bash
./test


---

## Development Roadmap

* Path A: Generic singly linked list (Completed)
* Path B: Comparison, print, destructor callbacks
* Path C: Iterators and advanced traversal
* Future: Doubly and circular linked lists

---

## Final Notes

This project emphasizes correct memory ownership, clean APIs, and extensible design.
It serves as a solid foundation for learning systems programming and building reusable C libraries.

