/* CS261- Assignment 1 - Q. 0*/
/* Name: Steven Walter
 * Date: 10/1/16
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int fooB(int* a, int* b, int c) {
	c = (*a)+(*b);
	int l = (*b);
	(*a) = l;
	*b = (*b)+(*b);

	return c;
}


void fooA(int* iptr){
	printf("intger: %d adres: %p adresofadres: %p \n", *iptr, iptr, &iptr);
}

int main(){
    
  /* declare an integer x */
  int x = 10;
  
  /* print the address of x */
  printf("%p \n", &x);
  /* Call fooA() with the address of x */
  fooA(&x);  
  /* print the value of x */
  printf("%d \n", x);
  int o = 7;
  int p = 3;
  int k;
  k = fooB(&o, &p, k);
  printf("A: %d \n", o);
  printf("B: %d \n", p);
  printf("C : %d \n", k);
  return 0;
}
