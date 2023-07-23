#include <stdio.h>

void display(int *a, int n){
    printf("Elements of array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *a, int n){
    int i, j, min_index;
    for(i=0; i< n; i++){
        min_index = i;
        for(j = i; j< n; j++){
            if(a[min_index] > a[j]){
                min_index = j;
            }          
        }
        if(min_index != i){
                swap(&a[i], &a[min_index]);
        }
    }
}

int main(){

    int a[] = {5, 7, 1, 8, 5, -5};
    int size = sizeof(a) / sizeof(a[0]);

    display(a,size);
    selectionSort(a, size);
    display(a,size);
    return 0;
}