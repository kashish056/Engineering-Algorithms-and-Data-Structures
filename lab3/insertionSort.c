#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last)
    {
		int x,y,tmp;
		for ( x = first; x <= last; x++){
			tmp = array[x];
			y = x-1;
			while( y>=0 && (myCompare(array[y],tmp)>0))
			{
				mySwap(&array[y+1], &array[y]);
				y = y-1;
			}
			myCopy(&tmp,&array[y+1]);
		}
    }
