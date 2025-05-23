void mySort(int d[], unsigned int n) // using insertion short from lecture notes.
{
    int i;
    int j;
    int key;
    for (i = 0 ; i < n ; i++)    //for j ← 2 to n do  
    {
        for( i = 0; i < n; i++){
		key = d[i]; // key ← A[ j]
		j = i -1; //i ← j – 1
		 
		 while( j >= 0 && d[j] > key){ //while i > 0 and A[i] > key (&& and operator).
				d[j +1] = d[j] ;  //do A[i+1] ← A[i]
				j = j - 1;	} //i ← i – 1

		d[j + 1] = key;  //A[i+1] = key
    }
}
} 

