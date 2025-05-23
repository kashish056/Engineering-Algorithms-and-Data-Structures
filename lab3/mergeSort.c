#include "mySort.h"

void merge(int array[], int first, int middle, int last)
    {
		int tmp[MAX_SIZE_N_TO_SORT];// the array will be used for merging 
		int a,b,c,d,tmp_value;
		a = first;
		b = middle;
		c= middle+1;
		d= last;
		tmp_value = 0;
		
		while(a < b+1 && c < d+1)// elements in the both list 
		{
			if(myCompare(array[a],array[c]) < 0)
			tmp[tmp_value++] = array[a++];
		else
			tmp[tmp_value++] = array[c++];	
	}
	
	while(a < b+1) {// copying remaining element from the first line
		myCopy(&array[a++],&tmp[tmp_value++]);
	}
	while(c < d+1) {// copying remaining element from the second line
		myCopy(&array[c++],&tmp[tmp_value++]);
	}
	int i;
	for (i=0, a=first; a <=d; i++, a++) {// swaping the elements
		mySwap(&array[a],&tmp[i]);
	}
}

void mySort(int array[], unsigned int first, unsigned int last)
{
	int middle;
	if (first < last)
	{
		middle = (first+last)/2;
		mySort(array, first, middle);
		mySort(array, middle+1, last);
		merge(array, first, middle, last);
	}
	
}

		
    
