#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"

int main(int argc, char *argv[]) {
    int data[10000]; 
    int nDataItems;   
    int i;

  
    if (argc > 1) {    // command line arguments are given, initializing the data array */
        nDataItems = argc - 1;
        for (i = 0; i < nDataItems; i++) {
            data[i] = atoi(argv[i + 1]);
        }
        // Test data
    } else {
        // If no command line arguments, use hardcoded test data 
        nDataItems = 4;
        data[0] = 10;
        data[1] = 20;
        data[2] = 30;
        data[3] = 40;
    }

    mySort(data, nDataItems);   // Check that the data array is sorted.

   
    for (i = 0; i < nDataItems - 1; i++) {  
        if (data[i] > data[i + 1]) {
            fprintf(stderr, "Sort error: data[%d] (= %d)"
                            " should be <= data[%d] (= %d) - aborting\n",
                            i, data[i], i + 1, data[i + 1]);
            exit(1);
        }
    }

    
    for (i = 0; i < nDataItems; i++) {  // Print sorted array to output 
        printf("%d\n", data[i]);
    }

    exit(0);
}
