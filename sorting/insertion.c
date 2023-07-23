#include<stdio.h>

void display(int a[], int n){
    printf("Element of array: ");
    for(int i = 0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertionSort(int *a, int n){
    int i,j,key;
    for(i = 1; i< n; i++){
        key = a[i];
        j = i -1;
        while(j >= 0 && key < a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main(){

    int a[] = {2, 5, 8, 1, 35, 7, 90, 3};
    int size = sizeof(a) / sizeof(a[0]);

    display(a, size);
    insertionSort(a, size);
    display(a, size);
    return 0;
}