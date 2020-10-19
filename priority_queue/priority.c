#include "priority.h"

void insert(MaxHeap* heap, int item){
    if(heap->size == heap->capacity){
        printf("Heap is full\n");
        exit(EXIT_FAILURE);
    }

    heap->size++; //indexing starts at 1;
    heap->element[heap->size] = item;

    sift_up(heap, heap->size);
}

void sift_down(MaxHeap* heap, int index){
    int swap_index;

    while(index * 2 <= heap->size){
        int left_child_index = index * 2;
        int right_child_index = index * 2 + 1;
        bool has_right = index*2 + 1 < heap->size;
        bool has_left = index*2 < heap->size;

        if (has_left && has_right){
            if (heap->element[left_child_index] > heap->element[right_child_index])
                swap_index = left_child_index;
            else
                swap_index = right_child_index;
        } else if (has_left){
            swap_index = left_child_index;
        } else if (has_right){
            swap_index = right_child_index;
        } else {
            break;
        }

        if (heap->element[swap_index] > heap->element[index]){
            int temp = heap->element[swap_index];
            heap->element[swap_index] = heap->element[index];
            heap->element[index] = temp;

            index = swap_index;
        } else {
            break;
        }
    }
}

void sift_up(MaxHeap* heap, int index){
    int parent, temp;
    while (index > 1){
        int parent = index / 2;
        if (heap->element[parent] < heap->element[index]){
            temp = heap->element[index];
            heap->element[index] = heap->element[parent];
            heap->element[parent] = temp;
        }
        index = parent;
    }
}

int get_max(MaxHeap* heap){
    if (heap->size < 1){
        printf("Heap is empty\n");
        exit(EXIT_FAILURE);
    }
    return heap->element[1];
}

int extract_max(MaxHeap* heap){
    int max = get_max(heap);

    heap->element[1] = heap->element[heap->size];
    heap->size--;

    sift_down(heap, 1);

    return max;
}

int get_size(MaxHeap* heap){
    return heap->size;
}

void remove_node(MaxHeap* heap, int index){
    heap->element[index] = heap->element[heap->size];
    heap->size--;

    sift_down(heap, index);
}

bool is_empty(MaxHeap* heap){
    return heap->size == 0;
}

void max_heapify(int* numbers, int index ,int count){
    int i = index;
    int swap_index;

    // no children - nothing to do
    // one child - swap if needed
    // 2 children - swap with larger if needed

    while ((i * 2) + 1 < count) {
      int left_child_index = 2 * i + 1;
      int right_child_index = 2 * i + 2;
      bool has_left = (left_child_index < count);
      bool has_right = (right_child_index < count);

      if (has_left && has_right) {
        int left_child_value = numbers[left_child_index];
        int right_child_value = numbers[right_child_index];

        if (left_child_value > right_child_value) {
          swap_index = left_child_index;
        } else { // right is greater or same
          swap_index = right_child_index;
        }
      } else if (has_left) {
        swap_index = left_child_index;
      } else if (has_right) {
        swap_index = right_child_index;
      } else {
        break;
      }

      if (numbers[swap_index] > numbers[i]) {
        int temp = numbers[i];
        numbers[i] = numbers[swap_index];
        numbers[swap_index] = temp;

        i = swap_index;
      } else {
        break;
      }
    }
}

void build_max_heap(int* numbers, int count){
    for (int i = count / 2 - 1; i >= 0; i--){
        max_heapify(numbers, i, count);
    }
}

void heap_sort(int* numbers, int count){

    build_max_heap(numbers, count);

    for (int i = count - 1; i > 0; i--){
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;

        max_heapify(numbers, 0, i);
    }
}
