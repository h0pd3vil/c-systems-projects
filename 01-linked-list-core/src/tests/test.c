#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "linked_list.h"

#define STRESS_COUNT 10000

static void test_init()
{
    struct LinkedList list;

    assert(ll_init(&list) == DS_OK);
    assert(list.head == NULL);
    assert(list.size == 0);

    assert(ll_init(NULL) == DS_ERR_NULL);
}

static void test_push_back()
{
    struct LinkedList list;
    ll_init(&list);

    int a = 10, b = 20;

    assert(ll_push_back(&list, &a) == DS_OK);
    assert(ll_push_back(&list, &b) == DS_OK);

    assert(list.size == 2);
}

static void test_push_front()
{
    struct LinkedList list;
    ll_init(&list);

    int a = 1, b = 2;

    ll_push_front(&list, &a);
    ll_push_front(&list, &b);

    assert(list.size == 2);
}

static void test_insert_bounds()
{
    struct LinkedList list;
    ll_init(&list);

    int a = 5;

    assert(ll_insert_at(&list, &a, 0) == DS_ERR_BOUNDS);
    assert(ll_insert_at(&list, &a, 2) == DS_ERR_BOUNDS);
}

static void test_delete()
{
    struct LinkedList list;
    ll_init(&list);

    int a = 1, b = 2, c = 3;

    ll_push_back(&list, &a);
    ll_push_back(&list, &b);
    ll_push_back(&list, &c);

    assert(ll_delete_at(&list, 2) == DS_OK);
    assert(list.size == 2);

    assert(ll_delete_at(&list, 0) == DS_ERR_BOUNDS);
    assert(ll_delete_at(NULL, 1) == DS_ERR_NULL);
}

static void test_reverse()
{
    struct LinkedList list;
    ll_init(&list);

    int a = 1, b = 2, c = 3;

    ll_push_back(&list, &a);
    ll_push_back(&list, &b);
    ll_push_back(&list, &c);

    assert(ll_reverse(&list) == DS_OK);
    assert(list.size == 3);

    struct LinkedList empty;
    ll_init(&empty);
    assert(ll_reverse(&empty) == DS_ERR_EMPTY);
}

static void test_cycle_detection()
{
    struct LinkedList list;
    ll_init(&list);

    int a = 1, b = 2;

    ll_push_back(&list, &a);
    ll_push_back(&list, &b);

    assert(ll_has_cycle(&list) == DS_OK);

    // Manually create cycle
    list.head->next->next = list.head;

    assert(ll_has_cycle(&list) == DS_ERR_STATE);

    // Break cycle to avoid infinite loop in clear
    list.head->next->next = NULL;
}

static void stress_test()
{
    struct LinkedList list;
    ll_init(&list);

    int *values = malloc(sizeof(int) * STRESS_COUNT);

    for (int i = 0; i < STRESS_COUNT; i++)
    {
        values[i] = i;
        assert(ll_push_back(&list, &values[i]) == DS_OK);
    }

    assert(list.size == STRESS_COUNT);

    for (int i = STRESS_COUNT; i > 0; i--)
    {
        assert(ll_delete_at(&list, 1) == DS_OK);
    }

    assert(list.size == 0);

    free(values);
}

static void test_clear()
{
    struct LinkedList list;
    ll_init(&list);

    int a = 10;
    ll_push_back(&list, &a);

    assert(ll_clear(&list) == DS_OK);
    assert(list.size == 0);
    assert(list.head == NULL);
}

int main()
{
    printf("Running LinkedList tests...\n");

    test_init();
    test_push_back();
    test_push_front();
    test_insert_bounds();
    test_delete();
    test_reverse();
    test_cycle_detection();
    test_clear();
    stress_test();

    printf("All LinkedList tests PASSED ✅\n");
    return 0;
}