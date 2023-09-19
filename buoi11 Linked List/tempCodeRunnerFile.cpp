#include <stdio.h>
// #include <stdlib.h> // Thêm thư viện này để sử dụng hàm malloc

// struct node
// {
//     int data;
//     struct node *next;
// }; // Đặt dấu chấm phẩy ở cuối

// typedef struct node node;

// node *makeNode(int x) // Sửa thành makeNode
// {
//     node *newNode = (node *)malloc(sizeof(node));
//     newNode->data = x; // Gán giá trị cho data
//     newNode->next = NULL; // Khởi tạo next là NULL
//     return newNode; // Thêm dòng này để trả về newNode
// }

// void duyet(node *head)
// {
//     while (head != NULL)
//     {
//         printf("Address: %p, Data: %d\n", (void *)head, head->data); // In địa chỉ và giá trị của nút
//         head = head->next;
//     }
// }

// int count(node *head) // Sửa thành count
// {
//     int dem = 0;
//     while (head != NULL)
//     {
//         ++dem;
//         head = head->next;
//     }
//     return dem; // Thêm dòng này để trả về giá trị đếm
// }

// void pushFront(node **head, int x)
// {
//     node *newNode = makeNode(x);
//     newNode->next = *head;
//     *head = newNode;
// }

// void duyetFormatted(node *head)
// {
//     printf("\n");
//     while (head != NULL)
//     {   
//         printf("%d", head->data); // In giá trị của nút

//         if (head->next != NULL)
//         {
//             printf(" -> "); // In dấu "->" nếu nút hiện tại không phải là nút cuối cùng
//         }
//         else
//         {
//             printf(" -> NULL"); // In "-> NULL" cho nút cuối cùng
//         }

//         head = head->next;
//     }
//     printf("\n"); // Xuống dòng sau khi in xong danh sách
// }

// int main()
// {
//     node *head = NULL;
//     for (int i = 0; i < 5; i++)
//     {
//         pushFront(&head, i); // Thêm dấu chấm phẩy ở cuối
//     }

//     for (int i = 10; i < 20; i++)
//     {
//         pushFront(&head, i); // Sửa thành pushFront(&head, i)
//     }
//     duyet(head);

//     duyetFormatted(head); // In danh sách có định dạng
  
//     int numNodes = count(head); // Sửa thành count
//     printf("\nNumber of nodes: %d\n", numNodes);

//     return 0;
// }
