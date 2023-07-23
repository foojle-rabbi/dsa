#include<stdio.h> 
#include<stdlib.h> 

#define max 10

struct array{
    int *arr;
    int size;
};

void traverseArray(struct array *a){
    printf("Elements of array: ");
    for(int i = 0; i < a->size; i++){
        printf("%d ", a->arr[i]);
    }
    printf("\n");
}

void insertInArray(struct array *a, int data, int index){
    a->size = a->size +1;
    for(int i = a->size; i >= index; i--){
        a->arr[i] = a->arr[i-1];
    }
    a->arr[index] = data;
}

void deleteInArray(struct array *a, int index){
    for(int i = index; i < a->size; i++){
        a->arr[i] = a->arr[i + 1];
    }
    a->size -= 1;
}

int main() {
    struct array a;
    a.size = 2;
    a.arr = (int *) malloc(max * sizeof(int));
    
    a.arr[0] = 5;
    a.arr[1] = 2;

    traverseArray(&a);

    int data = 3;

    insertInArray(&a, data, 2);
    deleteInArray(&a, 1);
    traverseArray(&a);

    return 0;
}