#include <stdio.h>

void display(int *a, int n){
    printf("Array: ");
    for(int i = 0; i< n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int *a, int low, int mid, int high){
    int i,j,k;
    int b[10];
    i=k=low;
    j = mid + 1;

    while(i<=mid && j<= high){
        if(a[i] < a[j]){
            b[k] = a[i];
            i++;
            k++;
        }else{
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        b[k] = a[i];
            i++;
            k++;
    }
    while(j<=high){
        b[k] = a[j];
            j++;
            k++;
    }
    for(i = low; i<=high; i++){
        a[i] = b[i];
    }

}

void mergeSort(int *a, int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        
        mergeSort(a,low, mid);
        mergeSort(a, mid +1,high);
        merge(a, low, mid, high);
    }
}

int main(){

    int a[] = {2,4,1,6,5,9,7};
    int size = sizeof(a) / sizeof(a[0]);

    display(a, size);
    mergeSort(a, 0, size-1);
    display(a, size);
    return 0;
}