#include <stdio.h>

void sortArr(int *arr, int size) {
    int temp;

    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (*(arr + i) > *(arr + j)) {
                temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
}

int main (int argc, char **argv)
{
    int n, num;

    printf("Enter a number that will set the array size:\n");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter a number to populate the array with: ");
        scanf("%d", &num);
        *(arr + i) = num;
    }

    for (int i = 0; i < n; i++) {
        printf("Element %d: %d\n", i, *(arr + i));
    }

    printf("\nArray sorted:\n");

    sortArr(arr, n);

    for (int i = 0; i < n; i++) {
        printf("Element %d: %d\n", i, *(arr + i));
    }

    return 0;
}