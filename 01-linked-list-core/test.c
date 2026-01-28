#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/linked_list.h"

/* test declarations */
void test_init_clear(void);
void test_push_back(void);
void test_push_front(void);
void test_insert_at(void);
void test_delete_at(void);
void test_reverse(void);

int main(void)
{
    test_init_clear();
    test_push_back();
    test_push_front();
    test_insert_at();
    test_delete_at();
    test_reverse();

    printf("All tests passed \n");
    return 0;
}

/* ---------------- TESTS ---------------- */

void test_init_clear(void)
{
    struct LinkedList list;
    ll_init(&list);

    assert(list.head == NULL);
    assert(list.size == 0);

    int *x = malloc(sizeof(int));
    assert(x != NULL);
    *x = 42;

    ll_push_back(&list, x);
    assert(list.head != NULL);
    assert(list.size == 1);

    ll_clear(&list);
    assert(list.head == NULL);
    assert(list.size == 0);

    free(x);
}

void test_push_back(void)
{
    struct LinkedList list;
    ll_init(&list);

    char *s = strdup("hari om purohit");
    assert(s != NULL);

    ll_push_back(&list, s);

    assert(list.head != NULL);
    assert(list.size == 1);
    assert(strcmp((char *)list.head->data, "hari om purohit") == 0);

    ll_clear(&list);
    free(s);
}

void test_push_front(void)
{
    struct LinkedList list;
    ll_init(&list);

    char *s1 = strdup("hari om purohit");
    char *s2 = strdup("is a great guy");
    assert(s1 && s2);

    ll_push_back(&list, s1);
    assert(list.size == 1);

    ll_push_front(&list, s2);
    assert(list.size == 2);

    /* first node */
    assert(strcmp((char *)list.head->data, "is a great guy") == 0);

    /* second node */
    assert(list.head->next != NULL);
    assert(strcmp((char *)list.head->next->data, "hari om purohit") == 0);

    ll_clear(&list);
    free(s1);
    free(s2);
}

void test_insert_at(void)
{
    struct LinkedList list;
    ll_init(&list);

    char *a = strdup("hari om purohit");
    char *b = strdup("is a great guy");
    char *c = strdup("and a great coder");
    assert(a && b && c);

    ll_push_back(&list, a);      // pos 1
    ll_push_back(&list, b);      // pos 2
    ll_insert_at(&list, c, 2);   // pos 3

    assert(list.size == 3);
    assert(strcmp((char *)list.head->next->data,"and a great coder") == 0);

    assert(-1 == ll_insert_at(&list, strdup("text"), 0));
    

    ll_clear(&list);
    free(a);
    free(b);
    free(c);
}

void test_delete_at(void)
{
    struct LinkedList list;
    ll_init(&list);

    char *a = strdup("hari om purohit");
    char *b = strdup("is a great guy");
    char *c = strdup("and a great coder");
    assert(a && b && c);

    ll_push_back(&list, a); // 1
    ll_push_back(&list, b); // 2
    ll_push_back(&list, c); // 3

    ll_delete_at(&list, 2); // remove "is a great guy"

    assert(list.size == 2);
    assert(strcmp((char *)list.head->data, "hari om purohit") == 0);
    assert(strcmp((char *)list.head->next->data, "and a great coder") == 0);
    assert(-1 == ll_delete_at(&list, 0));


    ll_clear(&list);
    free(a);
    free(b);
    free(c);
}

void test_reverse(void)
{
    struct LinkedList list;
    ll_init(&list);

    char *a = strdup("one");
    char *b = strdup("two");
    char *c = strdup("three");
    assert(a && b && c);

    ll_push_back(&list, a);
    ll_push_back(&list, b);
    ll_push_back(&list, c);

    ll_reverse(&list);

    assert(strcmp((char *)list.head->data, "three") == 0);
    assert(strcmp((char *)list.head->next->data, "two") == 0);
    assert(strcmp((char *)list.head->next->next->data, "one") == 0);

    ll_clear(&list);
    free(a);
    free(b);
    free(c);
}
