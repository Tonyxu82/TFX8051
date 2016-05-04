
#include<stdio.h>
// unsigned char array[10]={1, 2, 2, 1, 2, 1, 3, 16, 3, 2};
unsigned char array[10]={1, 1, 1, 8, 1, 1, 1, 1, 3, 1};
void quickSort(int left, int right);
void main(){

    int i = 0;

    quickSort(0, 9);
    for(i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    /* test quickSort
    int array[8] = {2, 5, 3, 7, 4, 1, 6, 8};
    quickSort(array, 0, 7);
    int i = 0;
    printf("sorted array = ");
    for(i = 0; i < 8; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");cd
    */
    while(1);
}

void quickSort(int left, int right){
    int i = left;
    int j = right;
    int tmp;
    int pivot = array[(left + right) / 2];

    while(i <= j) {
        while(array[i] < pivot) {
            i++;
        }
        while(array[j] > pivot) {
            j--;
        }
        if(i <= j) {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    }
    if(left < j) {
        quickSort(left, j);
    }
    if(i < right) {
        quickSort(i, right);
    }
}
