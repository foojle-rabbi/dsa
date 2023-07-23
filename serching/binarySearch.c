#include <stdio.h>

int binarySearch(int a[], int size, int key)
{
    int low = 0;
    int high = size;
    
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{

    int a[] = {1, 2, 4, 7, 9, 9, 12, 15};
    int size = sizeof(a) / sizeof(a[0]);

    int key = 15;

    printf("%d iteam found at index number %d\n", key, binarySearch(a, size, key));
    return 0;
}
