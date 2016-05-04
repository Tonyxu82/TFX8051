#include<mcs51/8052.h>

//#include<stdio.h>
unsigned char array[4];
void quickSort(int left, int right);
void main(){

    int i = 0;
    for(i = 0; i < 4; i++) {
        array[i] = P0;
    }    
    quickSort(0, 3);
    for(i = 0; i < 4; i++) {
        P2 = array[i];
    }

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
