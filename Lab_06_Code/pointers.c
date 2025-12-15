/*
pointers.c

Example demonstrating the use of pointers

*/

#include <stdio.h>

#define arraysize 8


void print_array(int *, int );  //Prototype of function call


int main() {

int i, a[arraysize], *pa;

for (i=0; i<arraysize; i++)             //Values per cell a[0]=0, a[1]=1, a[2]=4, a[3]=9 ...
    a[i] = i*i;

pa          = &a[0];            //STEP1 
                                //pa points to a[0]

//Array after STEP 1: a[0]=0, a[1]=1, a[2]=4, a[3]=9, a[4]=16, a[5]=25, a[6]=36, a[7]=49, pa=a[0]

a[6]        = *(a+4);           //STEP2: CHANGES a[6]: OK
                                //a[6]=a[4]=16
                                //a[6] equals a[4]. (a+4) goes to base address of a plus 4*sizeof(int)
                                //                  pointing to a[4]

//Array after STEP 2: a[0]=0, a[1]=1, a[2]=4, a[3]=9, a[4]=16, a[5]=25, a[6]=16, a[7]=49, pa=a[0]

*(pa+3)     = a[5];             //STEP3: CHANGES a[3]: OK
                                //a[3]=a[5]=25

//Array after STEP 3: a[0]=0, a[1]=1, a[2]=4, a[3]=25, a[4]=16, a[5]=25, a[6]=16, a[7]=49, pa=a[0]

a[0]        = *((pa++)+2);      //STEP4: CHANGES a[0]: OK
                                //a[0]=a[2]=4
                                //First pa + 2  goes from a[0] to a[2] and so returns value a[2], 
                                //and then pa goes from a[0] to a[1]
-
//Array after STEP 4: a[0]=4, a[1]=1, a[2]=4, a[3]=25, a[4]=16, a[5]=25, a[6]=16, a[7]=49,  pa=a[1]

*((++pa)+5) = a[1];             //STEP5: CHANGES a[7]: OK
                                //a[7]=a[1]=1. See STEP4
                                //First pa changes to a[2], and then so returns a[2]+5*sizeof(int)=a[7]

//Array after STEP 5: a[0]=4, a[1]=1, a[2]=4, a[3]=25, a[4]=16, a[5]=25, a[6]=16, a[7]=1, pa=a[2]

*(&a[5]-1)  = *(--pa);          //STEP6: CHANGES a[4]
                                //a[4]=a[1], as pa was a[2]

//Array after STEP 6: a[0]=4, a[1]=1, a[2]=4, a[3]=25, a[4]=1, a[5]=25, a[6]=16, a[7]=1

print_array(a, 8);
return 0;    

}

void print_array(int *array, int n) {

for (int i=0;i<n;i++)
    printf("The %d th element of the array has value: %d\n", i, array[i]);



}