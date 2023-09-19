// macro
// #include <stdio.h>
// #define N 10

// int nhap(int arr[]) {
//     int i;
//     for (i = 0; i < N; i++) {
//         scanf("%d", &arr[i]);
//     }
// }

// void hienThi(const int arr[]) {
//     int i;
//     for (i = 0; i < N; i++) {
//         printf("%5d", arr[i]);
//     }
// }

// void sort(int arr[]) {
//     int i, j;
//     for (i = 0; i < N - 1; i++) {
//         for (j = N - 1; j > i; j--) {
//             if (arr[j] < arr[j - 1]) {
//                 int tmp = arr[j];
//                 arr[j] = arr[j - 1];
//                 arr[j - 1] = tmp;
//             }
//         }
//     }
// }

// int binarySearch(int arr[], int x, int *position) {
//     int left = 0, right = N - 1;
//     while (left <= right) {
//         int mid = (left + right) / 2;
//         if (arr[mid] == x) {
//             *position = mid;
//             return 1; // tim thay
//         } else if (arr[mid] < x) {
//             left = mid + 1;
//         } else {
//             right = mid - 1;
//         }
//     }
//     return 0;
// }

// int main() {
//     int arr[N];
//     printf("Nhap %d so nguyen:\n", N);
//     nhap(arr);
//     sort(arr);
//     printf("Mang sau khi sap xep:\n");
//     hienThi(arr);
//     int x;

//     while (1) {
//         printf("\nNhap x= ");
//         scanf("%d", &x);
//         if (x == -1)
//             break;
//         int position = -1;
//         if (binarySearch(arr, x, &position)) {
//             printf("\nTim thay x tai vi tri %d.", position);
//         } else {
//             printf("\nKhong tim thay x.");
//         }
//     }

//     return 0;
// }