#include <stdio.h>

void swap(int *x, int *y);
void bubble_sort(int x[], int size);


int main() {
    int a[10] = {3,2,1,7,6,5,4,8,9, 0};
    bubble_sort(a, 10);
    for (int it = 0; it < 10; it++)
        printf("%d ", a[it]);
    return 0;
}

void bubble_sort(int x[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (x[j] > x[j + 1])
                swap(&x[j], &x[j+1]);
        }
    }
}

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}