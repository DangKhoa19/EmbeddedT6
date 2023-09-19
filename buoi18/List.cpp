#include<iostream>
#include<list>

using namespace std;

int main()
{
    list<int> arr; // Khai báo một danh sách các số nguyên
    list<int>::iterator it;
    
    // Chèn một số phần tử vào danh sách
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    int i = 0;
    for (it = arr.begin(); it != arr.end(); it++)
    {
        if (i == 1)
        {
            // Chèn giá trị 27 sau vị trí hiện tại của vòng lặp
            arr.insert(it, 27);
        }
        i++;
    }

    // In ra các phần tử trong danh sách
    for (it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << endl; // Sử dụng *it để truy cập giá trị, không phải là it chính nó
    }

    // Không cần thiết phải sử dụng system("pause"); trong C++ hiện đại
    return 0;
}


#include<iostream>
#include<list>

using namespace std;

int main()
{
    list<int> arr; // Khai báo một danh sách các số nguyên list<int> myList
    list<int>::iterator it; //khai báo một biến kiểu iterator cho danh sách (list) chứa các số nguyên
    // list: double-linked list
    //::iterator truy cập vào kiểu iterator
    // iterator: công cụ duyệt qua các phần tử trong các cấu trúc dữ liệu như danh sách liên kết, vector, mảng 


    // Chèn một số phần tử vào danh sách
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    int i = 0;
    for (it = arr.begin(); it != arr.end(); it++)
    {
        if (i == 2)
        {
            // Chèn giá trị 27 sau vị trí hiện tại của vòng lặp
            arr.insert(it, 27);
        }
        i++;
    }

    // In ra các phần tử trong danh sách
    for (it = arr.begin(); it != arr.end(); it++)
    // vị trí đầu arr.begin()

    {
        cout << *it << endl; // Sử dụng *it để truy cập giá trị, không phải là it chính nó

         //*it được sử dụng để truy cập giá trị của phần tử mà con trỏ iterator (it) đang trỏ tới trong danh 
         //sách liên kết (list) arr. Iterator (it) là một con trỏ đặc biệt được sử dụng để duyệt qua các phần 
         //tử trong danh sách.

    }

    // Không cần thiết phải sử dụng system("pause"); trong C++ hiện đại
    return 0;
}
