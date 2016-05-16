#include<mcs51/8052.h>

//#include<stdio.h>
unsigned char array[10];
void bubble_sort(unsigned char* list, int n);
void main(){

    int i = 0;
    for(i = 0; i < 10; i++) {
        array[i] = P0;
    }    

    bubble_sort(array, 10);
    for(i = 0; i < 10; i++) {
        P2 = array[i];
    }

    while(1);
}

void bubble_sort(unsigned char* list, int n)
{
  unsigned char c, d, t;
 
  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (list[d] > list[d+1])
      {
        /* Swapping */
 
        t         = list[d];
        list[d]   = list[d+1];
        list[d+1] = t;
      }
    }
  }
}
