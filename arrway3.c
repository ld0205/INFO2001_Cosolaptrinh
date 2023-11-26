#include <stdio.h>

// Hàm t?m ki?m tuy?n tính
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Tr? v? v? trí n?u t?m th?y
        }
    }
    return -1; // Tr? v? -1 n?u không t?m th?y
}

int main() {
    int arr[] = {2, 5, 7, 12, 18, 20, 24};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 18; // Giá tr? c?n t?m

    int result = linearSearch(arr, n, x);

    if (result == -1) {
        printf("Khong tim thay %d trong mang.\n", x);
    } else {
        printf("Tim thay %d tai vi tri %d trong mang.\n", x, result);
    }

    return 0;
}

