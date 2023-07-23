#include <stdio.h>

int linearSearch(int *a, int n, int key){
    for(int i = 0; i < n; i++){
        if(a[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int a[] = {3, 5, 9, 3, 2, 4, 78};
    int size = sizeof(a) / sizeof(a[0]);

    int key = 9;
    printf("%d found at index %d\n", key , linearSearch(a,size, key));
    return 0;
}