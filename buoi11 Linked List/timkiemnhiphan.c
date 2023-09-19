
// // macro
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



// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node *next;
// };

// typedef struct node node;

// node *makeNode(int x) {
//     node *newNode = (node *)malloc(sizeof(node));
//     newNode->data = x;
//     newNode->next = NULL;
//     return newNode;
// }

// void pushFront(node **head, int x) {
//     node *newNode = makeNode(x);
//     newNode->next = *head;
//     *head = newNode;
// }

// node *binarySearch(node *head, int x) {
//     node *left = head;
//     node *right = NULL;

//     while (right != left) {
//         node *mid = left;

//         int count = 0;
//         while (mid->next != right) {
//             mid = mid->next;
//             count++;
//         }

//         for (int i = 0; i < count / 2; i++) {
//             head = head->next;
//         }

//         if (head->data == x) {
//             return head;
//         } else if (head->data < x) {
//             left = head->next;
//         } else {
//             right = mid;
//         }
//     }

//     return NULL;
// }


// int main() {
//     node *head = NULL;

//     for (int i = 0; i < 5; i++) {
//         pushFront(&head, i);
//     }

//     for (int i = 10; i < 20; i++) {
//         pushFront(&head, i);
//     }

//     pushFront(&head, 100);

//     int x;
//     printf("Nhap x: ");
//     scanf("%d", &x);

//     node *result = binarySearch(head, x);

//     if (result != NULL) {
//         printf("Tim thay x tai dia chi %p, vi tri %d.\n", (void *)result, result->data);
//     } else {
//         printf("Khong tim thay x.\n");
//     }

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node *next;
// };

// typedef struct node node;

// node *makeNode(int x) {
//     node *newNode = (node *)malloc(sizeof(node));
//     newNode->data = x;
//     newNode->next = NULL;
//     return newNode;
// }

// void pushFront(node **head, int x) {
//     node *newNode = makeNode(x);
//     newNode->next = *head;
//     *head = newNode;
// }

// node *binarySearch(node *head, int x) {
//     node *left = head;
//     node *right = NULL;

//     while (left != right) {
//         node *mid = left;
//         int count = 0;

//         // Count the number of elements between left and right
//         while (mid != right) {
//             mid = mid->next;
//             count++;
//         }

//         // Move mid to the middle element
//         for (int i = 0; i < count / 2; i++) {
//             mid = mid->next;
//         }

//         if (mid->data == x) {
//             return mid;
//         } else if (mid->data < x) {
//             left = mid->next;
//         } else {
//             right = mid;
//         }
//     }

//     return NULL;
// }

// int main() {
//     node *head = NULL;

//     for (int i = 0; i < 5; i++) {
//         pushFront(&head, i);
//     }

//     for (int i = 10; i < 20; i++) {
//         pushFront(&head, i);
//     }

//     pushFront(&head, 100);

//     int x;
//     printf("Enter x: ");
//     scanf("%d", &x);

//     node *result = binarySearch(head, x);

//     if (result != NULL) {
//         printf("x found at address %p, with data %d.\n", (void *)result, result->data);
//     } else {
//         printf("x not found.\n");
//     }

//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc nút trong danh sách liên kết
struct Node {
    int data;
    struct Node* next;
};

// Hàm để thêm một nút mới vào danh sách liên kết
void insert(struct Node** head_ref, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Hàm để hiển thị danh sách liên kết
void display(struct Node* node) {
    while (node != NULL) {
        printf("%5d", node->data);
        node = node->next;
    }
}

// Hàm để sắp xếp danh sách liên kết
void sort(struct Node** head_ref) {
    int swapped, i;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    if (*head_ref == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *head_ref;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Hàm để thực hiện tìm kiếm nhị phân trên danh sách liên kết
int binarySearch(struct Node* head, int x, int* position) {
    int left = 0, right = 0;

    // Đếm số lượng nút trong danh sách liên kết
    struct Node* current = head;
    while (current != NULL) {
        right++;
        current = current->next;
    }

    while (left <= right) {
        int mid = (left + right) / 2;

        // Duyệt đến vị trí 'mid' trong danh sách liên kết
        struct Node* current = head;
        for (int i = 0; i < mid; i++) {
            current = current->next;
        }

        if (current->data == x) {
            *position = mid;
            return 1; // tìm thấy
        } else if (current->data < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0; // không tìm thấy
}

int main() {
    struct Node* head = NULL;

    printf("Nhap cac so nguyen (nhap -1 de ket thuc nhap):\n");
    while (1) {
        int num;
        scanf("%d", &num);
        if (num == -1)
            break;
        insert(&head, num);
    }

    sort(&head);

    printf("Danh sach sau khi sap xep:\n");
    display(head);

    int x;

    while (1) {
        printf("\nNhap x= ");
        scanf("%d", &x);
        if (x == -1)
            break;
        int position = -1;
        if (binarySearch(head, x, &position)) {
            printf("\nTim thay x tai vi tri %d.", position);
        } else {
            printf("\nKhong tim thay x.");
        }
    }

    return 0;
}
