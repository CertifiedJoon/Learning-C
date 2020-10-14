#include <assert.h>
#include <stdio.h>
#include <string.h>

#ifndef PROJECT_TESTS_HASH_H
#define PROJECT_TESTS_HASH_H

void run_all_tests();

void print_debug(hashtable* table);

void test_new();

void test_add();

void destroy_table(hashtable* table);

#endif //PROJECT_TESTS_HASH_H
