#include "test.h"

void run_all_tests() {
    printf("testing new\n");
    test_new();
    printf("testing add\n");
    test_add();
}

void print_debug(hashtable* table) {
  for (int i = 0; i < table->capacity; ++i) {
    if (table->data[i] == NULL) {
      printf("%d:\n", i);
    } else {
      printf("%s: %s\n", table->data[i]->key, table->data[i]->val);
    }
  }
  printf("===================\n");
}

void test_new() {
    hashtable* table = new_table(90);
    assert(table->capacity == 97);

    destroy_table(table);

    table = new_table(98);
    assert(table->capacity == 197);

    destroy_table(table);
}

void test_add(){
    hashtable* table = new_table(90);

    add(table, "California", "CA");
    assert(strcmp(get(table, "California"), "CA") == 0);

    FILE *fp;
    fp = fopen("fortune500.txt", "r");
    char line[100];

    for (int i = 0; i < 400; i++){
        fgets(line, 100, fp);
        add(table, line, "dafe");
    }
    fclose(fp);

    print_debug(table);
    assert(table->capacity == 197);
    destroy_table(table);
}

void destroy_table(hashtable *table){
    for (int i = 0; i < table->size; i++){
        free(table->data[i]->key);
        free(table->data[i]->val);
    }
    free(table->data);
    free(table);
}
