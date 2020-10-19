#ifndef PROJECT_PRIORITY_QUEUE
#define PROJECT_PRIORITY_QUEUE

#define max(x,y) ((x) > (y) ? (x) : (y));


const int heapSize = 1000;

typedef struct priority_queue{
    int size;
    int element[1001];
    int capacity;
} MaxHeap;

void insert(MaxHeap* heap, int value);
// Output the elements of the data in array form
void print_data(MaxHeap* heap);
// Satisfies the max-heap property from given node up to root, if needed.
void sift_up(MaxHeap* heap, int index);
// Returns the maximum element in the heap
int get_max(MaxHeap* heap);
// Removes the maximum element from the heap, returning its key
int extract_max(MaxHeap* heap);
// Satisfies the max-heap property from given node down to leaf, if needed.
void sift_down(MaxHeap* heap, int index);
// Returns the number of elements stored in the heap
int get_size(MaxHeap* heap);
// Removes the node at the given index
void remove_node(MaxHeap* heap, int index);
// Returns true if queue is empty
bool is_empty(MaxHeap* heap);
// Sorts the given array
void heap_sort(int* numbers, int count);
// Required by heap_sort with an in-place 0-indexed array
void build_max_heap(int* numbers, int count);
// This is a sift down that is customized for 0-indexed arrays
void max_heapify(int* numbers, int count, int index);

#endif
