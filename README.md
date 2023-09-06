# EmbeddedT6
## C++
 - Class là một mô tả, một bản thiết kế hoặc một khung cho việc tạo ra các "đối tượng" (objects) cụ thể. Class định nghĩa các thuộc tính (properties) và hành vi (method) mà các đối tượng (object) của class đó sẽ có; class đóng vai trò như 1 kiểu dữ liệu do người dùng từ định nghĩa (gần giống như struct, khác struct có chia ra các cấp độ truy cập để bảo vệ dữ liệu).
 - Đối tượng(object) là thưc thể hữu hình, thể hiện cụ thể của class.
   Ví dụ 1: bản thiết kế là class, ngôi nhà là object, từ 1 bản thiết kế có thể sinh ra nhiều ngôi nhà
 - Thuộc tính(properties) là đặc điểm, đặc trưng, tính chất của class. Thuộc tính là tính từ.
 - Phương thức (method) hành động hành vi của class. Phương thức là động từ.
   Ví dụ 2: class là động vật, object là sư tử thuộc tính (properties) là cân nặng, giới tính, chiều cao
Ba mức độ truy cập dữ liệu trong class:
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
  của đối tượng (object).


Ví dụ 

#include<iostream>
#include<string>
using namespace std;

// Khai báo class nhân viên sửa ống nước
class NhanVienSuaOngNuoc
{
private: 
    string hoten;
    int tuoi;
    string gioi_tinh;
    string dia_chi;
    string sdt;
    float chieu_cao;
    float can_nang;
    float so_h_sua;

public:
    // Phương thức nhập thông tin nhân viên sửa ống nước trong class
    void Nhap()
    {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhap tuoi:  ";
        cin >> tuoi;
        cout << "Nhap gioi tinh: ";
        cin.ignore();
        getline(cin, gioi_tinh);
        cout << "Nhap dia chi:    ";
        cin.ignore();
        getline(cin, dia_chi);
        cout << "Nhap so dien thoai:  ";
        cin.ignore();
        getline(cin, sdt);
        cout << "Nhap chieu cao:  ";
        cin >> chieu_cao;
        cout << "Nhap can nang:   ";
        cin >> can_nang;
    }

    // Phương thức xuất thông tin nhân viên sửa ống nước trong class
    void Xuat()
    {
        cout << "Ho ten: " << hoten << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Gioi tinh: " << gioi_tinh << endl;
        cout << "Dia chi: " << dia_chi << endl;
        cout << "So dien thoai: " << sdt << endl;
        cout << "Chieu cao: " << chieu_cao << endl;
        cout << "Can nang: " << can_nang << endl;
    }

    // Phương thức tính tiền lương nhân viên sửa ống nước
    float Tinh_Tien_Luong()
    {
        return so_h_sua * 50000;
    }

    // Constructor: Khai báo constructor
    NhanVienSuaOngNuoc() {}

    // Destructor: Khai báo destructor
    ~NhanVienSuaOngNuoc() {}
};

// Khai báo class nhân viên giao hàng
class NhanVienGiaoHang
{
private:
    string hoten;
    int tuoi;
    string gioi_tinh;
    string dia_chi;
    string sdt;
    float chieu_cao;
    float can_nang;
    int so_hang_giao;

public:
    // Phương thức nhập thông tin nhân viên giao hàng trong class
    void Nhap()
    {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhap tuoi:  ";
        cin >> tuoi;
        cout << "Nhap gioi tinh: ";
        cin.ignore();
        getline(cin, gioi_tinh);
        cout << "Nhap dia chi:    ";
        cin.ignore();
        getline(cin, dia_chi);
        cout << "Nhap so dien thoai:  ";
        cin.ignore();
        getline(cin, sdt);
        cout << "Nhap chieu cao:  ";
        cin >> chieu_cao;
        cout << "Nhap can nang:   ";
        cin >> can_nang;
    }

    // Phương thức xuất thông tin nhân viên giao hàng trong class
    void Xuat()
    {
        cout << "Ho ten: " << hoten << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Gioi tinh: " << gioi_tinh << endl;
        cout << "Dia chi: " << dia_chi << endl;
        cout << "So dien thoai: " << sdt << endl;
        cout << "Chieu cao: " << chieu_cao << endl;
        cout << "Can nang: " << can_nang << endl;
    }

    // Phương thức tính tiền lương nhân viên giao hàng
    float Tinh_Tien_Luong()
    {
        return so_hang_giao * 50000;
    }

    // Constructor: Khai báo constructor
    NhanVienGiaoHang() {}

    // Destructor: Khai báo destructor
    ~NhanVienGiaoHang() {}
};

// Khai báo class nhân viên xe ôm công nghệ
class NhanVienXeOmCongNghe
{
private:
    string hoten;
    int tuoi;
    string gioi_tinh;
    string dia_chi;
    string sdt;
    float chieu_cao;
    float can_nang;
    float so_km;

public:
    // Phương thức nhập thông tin nhân viên xe ôm công nghệ trong class
    void Nhap()
    {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhap tuoi:  ";
        cin >> tuoi;
        cout << "Nhap gioi tinh: ";
        cin.ignore();
        getline(cin, gioi_tinh);
        cout << "Nhap dia chi:    ";
        cin.ignore();
        getline(cin, dia_chi);
        cout << "Nhap so dien thoai:  ";
        cin.ignore();
        getline(cin, sdt);
        cout << "Nhap chieu cao:  ";
        cin >> chieu_cao;
        cout << "Nhap can nang:   ";
        cin >> can_nang;
    }

    // Phương thức xuất thông tin nhân viên xe ôm công nghệ trong class
    void Xuat()
    {
        cout << "Ho ten: " << hoten << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Gioi tinh: " << gioi_tinh << endl;
        cout << "Dia chi: " << dia_chi << endl;
        cout << "So dien thoai: " << sdt << endl;
        cout << "Chieu cao: " << chieu_cao << endl;
        cout << "Can nang: " << can_nang << endl;
    }

    // Phương thức tính tiền lương nhân viên xe ôm công nghệ
    float Tinh_Tien_Luong()
    {
        return so_km * 34000;
    }

    // Constructor: Khai báo constructor
    NhanVienXeOmCongNghe() {}

    // Destructor: Khai báo destructor
    ~NhanVienXeOmCongNghe() {}
};

int main()
{
    NhanVienGiaoHang nv_giaohang;
    NhanVienSuaOngNuoc nv_suaongnuoc;
    NhanVienXeOmCongNghe nv_xeomcn;

    cout << "\n\n\t\t Nhap thong tin nhan vien sua ong nuoc\n";
    nv_suaongnuoc.Nhap();
    cout << "\n\n\t\t Nhap thong tin nhan vien giao hàng\n";
    nv_giaohang.Nhap();
    cout << "\n\n\t\t Nhap thong tin nhan vien xe om cong nghe\n";
    nv_xeomcn.Nhap();

    cout << "\n\n\t\t Xuat thong tin nhan vien sua ong nuoc\n";
    nv_suaongnuoc.Xuat();
    cout << "\n\n\t\t Luong nhan vien sua ong nuoc\n " << nv_suaongnuoc.Tinh_Tien_Luong();

    cout << "\n\n\t\t Xuat thong tin nhan vien giao hàng\n";
    nv_giaohang.Xuat();

    cout << "\n\n\t\t Luong nhan vien giao hàng\n " << nv_giaohang.Tinh_Tien_Luong();

    cout << "\n\n\t\t Xuat thong tin nhan vien xe om cong nghe\n";
    nv_xeomcn.Xuat();
    cout << "\n\n\t\t Luong xe om cong nghe\n " << nv_xeomcn.Tinh_Tien_Luong();

    return 0;
}

 - Tính trừu tượng (Abstraction): trong code này thể hiện ở việc tạo các lớp NhanVienSuaOngNuoc, NhanVienGiaoHang, và NhanVienXeOmCongNghe đại diện cho các loại nhân viên khác nhau, và chúng đều có các phương thức chung như Nhap(), Xuat(), và Tinh_Tien_Luong() có thể sử dụng chúng để thực hiện các nhiệm vụ riêng biệt.
 - Tính đóng gói (Encapsulation) trong code nay thể hiện ở việc sử dụng các phạm vi truy cập (private, public) cho các thành phần của một lớp (đặc trưng quan trọng nhất của OOP), các thuộc tính properties hoten, tuoi, gioi_tinh, là private.
   + Cụ thể:
private:
string hoten;
int tuoi;
string gioi_tinh;
string dia_chi;
string sdt;
float chieu_cao;
float can_nang;
trong các lớp NhanVienSuaOngNuoc, NhanVienGiaoHang, và NhanVienXeOmCongNghe. Điều này đảm bảo rằng các thuộc tính này chỉ có thể truy cập từ bên trong lớp. 
Ngoài ra, các phương thức method đặt ở phạm vi public (tương tự struct)
  + Cụ thể
public:
void Nhap();
void Xuat();
float Tinh_Tien_Luong();


  
