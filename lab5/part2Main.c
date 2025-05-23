#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

int heap[MAX_HEAP_SIZE];
int heap_size = 0;

void bubble_up(int index) {
    if (index == 0) {
        return;
    }
    int parent_index = (index - 1) / 2;
    if (heap[index] > heap[parent_index]) {
        // Swap child and parent
        int temp = heap[index];
        heap[index] = heap[parent_index];
        heap[parent_index] = temp;
        bubble_up(parent_index);
    }
}

void bubble_down(int index) {
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;
    int largest_index = index;
    if (left_child_index < heap_size && heap[left_child_index] > heap[largest_index]) {
        largest_index = left_child_index;
    }
    if (right_child_index < heap_size && heap[right_child_index] > heap[largest_index]) {
        largest_index = right_child_index;
    }
    if (largest_index != index) {
        // Swap parent and largest child
        int temp = heap[index];
        heap[index] = heap[largest_index];
        heap[largest_index] = temp;
        bubble_down(largest_index);
    }
}

void insert(int value) {
    if (heap_size >= MAX_HEAP_SIZE) {
        // Heap is full
        return;
    }
    heap[heap_size] = value;
    bubble_up(heap_size);
    heap_size++;
}

int delete_root() {
    if (heap_size == 0) {
        // Heap is empty
        return -1;
    }
    int root_value = heap[0];
    heap_size--;
    heap[0] = heap[heap_size];
    bubble_down(0);
    return root_value;
}

void print_heap_xml(int index) {
    if (index >= heap_size) {
        return;
    }
    printf("<node id=\"%d\">", heap[index]);
    print_heap_xml(2*index+1);
    print_heap_xml(2*index+2);
    printf("</node>");
}

void print_sorted() {
    int stack[MAX_HEAP_SIZE];
    int stack_size = 0;
    while (heap_size > 0) {
        int value = delete_root();
        printf("%d\n", value);
        stack[stack_size] = value;
        stack_size++;
    }
    printf("\n");
    for (int i = stack_size-1; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    // Read input numbers
    int num;
    while (scanf("%d", &num) == 1) {
        insert(num);
    }

    // Print heap as XML
    print_heap_xml(0);
    printf("\n");

    // Perform delete operation
    printf("Enter to delete : ");
    int index;
    scanf("%d", &index);
    if (index >= 0 && index < heap_size) {
        printf("Deleted value from heap at index %d: %d\n", index, heap[index]);
        heap[index] = heap[heap_size - 1];
        heap_size--;
        bubble_down(index);
    } else if (index != -1) {
        printf("Invalid index\n");
    }

    // Print sorted numbers
    print_sorted();

    return 0;
}
