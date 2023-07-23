#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *a, int n){
    int i, j;
    for(i = 0; i<n; i++){
        for(j = 0; j< n-1-i; j++){
            if(a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

void display(int *a, int n){
    printf("Elements of array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){

    int a[] = {1,5,9,3,5,10,7,2};
    int size = sizeof(a) / sizeof(a[0]);

    display(a, size);
    bubbleSort(a, size);
    display(a, size);


    return 0;
}