# EmbeddedT6
C++
 - Class là một mô tả, một bản thiết kế hoặc một khung cho việc tạo ra các "đối tượng" (objects) cụ thể. Class định nghĩa các thuộc tính (properties) và hành vi (method) mà
   các đối tượng (object) của class đó sẽ có; class đóng vai trò như 1 kiểu dữ liệu do người dùng từ định nghĩa (gần giống như struct, khác struct có chia ra các cấp độ truy
   cập để bảo vệ dữ liệu).
 - Đối tượng(object) là thưc thể hữu hình, thể hiện cụ thể của class.
   Ví dụ 1: bản thiết kế là class, ngôi nhà là object, từ 1 bản thiết kế có thể sinh ra nhiều ngôi nhà
 - Thuộc tính(properties) là đặc điểm, đặc trưng, tính chất của class. Thuộc tính là tính từ.
 - Phương thức (method) hành động hành vi của class. Phương thức là động từ.
   Ví dụ 2: class là động vật, object là sư tử thuộc tính (properties) là cân nặng, giới tính, chiều cao
3 mức độ truy cập dữ liệu trong class:

- Public: những thuộc tính(properties) hay phương thức(method) được khái báo với từ khóa này sẽ có phạm vi hoạt động bên trong bên ngoài class và trên toàn bộ chương trình
- Private: những thuộc tính hay phương thức được khai báo với từ khóa này có phạm vi hoạt động chỉ bên trong class nội tại.
- Protected: những thuộc tính hay phương thức được khai báo với từ khóa này có phạm vi hoạt động chỉ bên trong class nội tại và class kế thừa từ nó.

Các đặc trưng của OOP:
 - Tính đóng gói:
   + Đặc trưng của phương pháp OOP, không cho phép người dùng hay các đối tượng truy xuất trực tiếp dữ liệu của lớp nội tại.
   + Đặc điểm:
     a) Tạo cơ chế ngăn ngừa việc gọi phương thức(method) của class này tác động hay truy xuất dữ liệu của đối tượng thuộc về lớp khác.
     b) Người lập trình có thể dựa vào cơ chế này ngăn ngừa việc gán giá trị không hợp lệ vào thành phần dữ liệu của mỗi đối tượng.
     c) Không cho truy xuất 1 cách tùy tiện dữ liệu của lớp nội tại
     d) Cơ chế đóng gói setter và setter giúp thay đổi dữ liệu và lấy dữ liệu, phá vỡ tính private. Cụ thể Setter là một phương thức
     được sử dụng để thay đổi giá trị của một thuộc tính, Getter là một phương thức được sử dụng để truy xuất giá trị của một thuộc tính. 
   Ví dụ: #include<iostream>
   using namespace std;

   class sinhvien
   {
   //thuộc tính (properties) đặc trưng của 1 thực thể, được bảo vệ ở private
private:
string hoten;
string maso;
float diem_toan;
float diem_ly;
//phương thức (method) hành vi, hành động thể hiện ra ngoài
public:
    void Nhap_Thong_Tin();   //{có thể định nghĩa bên trong class( không khuyến khích)   }
    void Xuat_Thong_Tin();
   // Cơ chế đóng gói setter (trình ghi) và getter(trình đọc)
string Getter_HoTen()
{
return hoten;
}
//setter họ tên
void Setter(string HOTEN)
{
hoten = HOTEN;
}

    };
// hàm tạo và hàm hủy
sinhvien();
~sinhvien();

void sinhvien::Nhap_Thong_Tin()
{
cout<<"\nNhap Ho ten";
getline(cin, hoten); //gọi thuộc tính hoten trong class nội tại sinhvien

cout<<"Nhap ma so sinh vien";
getline(cin, maso); 

cout<<"Nhap diemtoan";
cin>>diem_toan; 

cout<<"Nhap diem ly";
cin>>diem_ly; 
}
void sinhvien::Xuat_Thong_tin()
{
cout <<"Ho ten"<<hoten <<endl;
cout << "\nMa so: " << maso ;
cout <<"Diem toan"<<diem_toan <<endl;
cout <<"Diem ly"<<diem_ly <<endl;
}


int main()
{

sinhvien nguyenvana;
cout<<"Nhap thong tin sinh vien:"<<endl;
nguyenvana.Nhap_Thong_Tin();
//nguyenvana.Setter_HoTen("nguyen van b")

//cout<<nguyenvana.Getter_HoTen();
cout<<"Xuat thong tin sinh vien:"<<endl;
nguyenvana.Xuat_Thong_Tin();
return 0;
}

- Tính trừu tượng  (Abstraction):
  + Trừu tượng hóa là quá trình đơn giản hóa 1 đối tượng object, xác định thuộc
  tính properties và phương thức method cần thiết của đối tượng object đó để đáp
  ứng yêu cầu cần thiết của chương trình tại thời điểm hiện tại.
  + Quá trình trừu tượng hóa giúp sàng lọc ra những tính chất và hành vi cốt lõi
  của đối tượng (object)
  
