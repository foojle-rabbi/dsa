#include<stdio.h> 
#include<stdlib.h>

void countSort(int *arr, int n){
    int i, j;
    int max = arr[0];

    //find the maximum number of the array
    for(i = 0; i < n; i++){
        if(max < arr[i])
        max = arr[i];
    }

    //create a maximum size of array
    int *count = (int *) malloc((max + 1)*sizeof(int));

    //initialize all the count arrays value to '0'
    for(i = 0; i <= max; i++){
        count[i] = 0;
    }

    //insert the value of the main array to the count array by traveling the main array
    for(i = 0; i < n; i++){
        count[arr[i]]++;
    }

    //initialized j = 0; for indexing arr[j] and putting the values to main array
    j = 0;
    for(i = 0; i <= max; i++){
        while(count[i] != 0){
            arr[j] = i;
            j++; 
            count[i]--;
        }
    }

}

//display function for arrys
void display(int *arr, int n){
    printf("Elements of array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 2, 9, 19, 2234, 234, 67, 35};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    display(arr, size);
    countSort(arr, size);
    display(arr, size);
    return 0;
}