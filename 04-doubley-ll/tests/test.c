#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "../../04-doubley-ll/include/doubley-ll.h"

/* ===============================
   VALIDATOR
================================ */

int dll_validate(List *list)
{
    if (!list)
        return 0;

    if (list->size == 0)
        return (list->head == NULL && list->tail == NULL);

    int count = 0;
    Node *prev = NULL;
    Node *cur = list->head;

    while (cur)
    {
        if (cur->pre != prev)
            return 0;

        prev = cur;
        cur = cur->nex;
        count++;
    }

    if (prev != list->tail)
        return 0;

    if (count != list->size)
        return 0;

    return 1;
}

/* ===============================
   MAIN STRESS TEST
================================ */

int main()
{
    srand((unsigned)time(NULL));

    List list;
    assert(dll_init(&list) == 1);

    printf("Starting stress test...\n");

    /* ---------------------------
       1. Sequential push_back
    --------------------------- */
    for (int i = 0; i < 10000; i++)
    {
        assert(dll_push_back(&list, (void*)(long)i) == 1);
        assert(dll_validate(&list));
    }

    /* ---------------------------
       2. Sequential delete front
    --------------------------- */
    while (list.size > 0)
    {
        assert(dll_delete_at(&list, 1) == 1);
        assert(dll_validate(&list));
    }

    /* ---------------------------
       3. Sequential push_front
    --------------------------- */
    for (int i = 0; i < 10000; i++)
    {
        assert(dll_push_front(&list, (void*)(long)i) == 1);
        assert(dll_validate(&list));
    }

    /* ---------------------------
       4. Delete from back
    --------------------------- */
    while (list.size > 0)
    {
        assert(dll_delete_at(&list, list.size) == 1);
        assert(dll_validate(&list));
    }

    /* ---------------------------
       5. Random operations
    --------------------------- */
    for (int i = 0; i < 50000; i++)
    {
        int op = rand() % 5;

        switch (op)
        {
            case 0:
                dll_push_front(&list, (void*)(long)rand());
                break;

            case 1:
                dll_push_back(&list, (void*)(long)rand());
                break;

            case 2:
                if (list.size > 0)
                {
                    int pos = rand() % list.size + 1;
                    dll_insert_at(&list, pos, (void*)(long)rand());
                }
                break;

            case 3:
                if (list.size > 0)
                {
                    int pos = rand() % list.size + 1;
                    dll_delete_at(&list, pos);
                }
                break;

            case 4:
                dll_reverse(&list);
                break;
        }

        assert(dll_validate(&list));
    }

    /* ---------------------------
       6. Reverse stress
    --------------------------- */
    for (int i = 0; i < 10000; i++)
    {
        dll_reverse(&list);
        assert(dll_validate(&list));
    }

    /* ---------------------------
       7. Clear test
    --------------------------- */
    assert(dll_clr(&list) == 1);
    assert(dll_validate(&list));

    printf("All tests passed successfully!\n");

    return 0;
}