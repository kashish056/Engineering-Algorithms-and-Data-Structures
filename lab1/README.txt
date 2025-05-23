KASHISH PATEL
COE 428 SECTION 05
501050150.






1. mySort:- A user-generated library implementing the insertion sort algorithm.

2. SortMain:
   - A program that tests the mySort library by generating six random numbers and sorting them using mySort.
   - If an error occurs during the sorting process, the program checks for the error, throws an error message, and exits.
   - If the sorting is successful, the sorted array is printed.

3. CmdLineDemo
   - A program demonstrating how command-line arguments work.
   - If any number of arguments is passed, it prints them out in varying formats.

4. SortMain2
   - Similar to SortMain.
   - Accepts any integer value less than 10000 as a command-line argument.



> For sorting, lecture notes have been used to complete my lab, and another platform to understand the concept from YouTube and many more.



QUESTION 1) The betterSort function can be called in the mySort function used in this lab. 


void mySort(int data[], int first, int last) {
    betterSort(data, first, last);
}
