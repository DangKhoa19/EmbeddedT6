# EmbeddedT6
## C++
 * Class là một mô tả, một bản thiết kế hoặc một khung cho việc tạo ra các "đối tượng" (objects) cụ thể. Class định nghĩa các thuộc tính (properties) và hành vi (method) mà các đối tượng (object) của class đó sẽ có; class đóng vai trò như 1 kiểu dữ liệu do người dùng từ định nghĩa (gần giống như struct, khác struct có chia ra các cấp độ truy cập để bảo vệ dữ liệu).
 * Đối tượng (object) là thưc thể hữu hình, thể hiện cụ thể của class.
   Ví dụ 1: bản thiết kế là class, ngôi nhà là object, từ 1 bản thiết kế có thể sinh ra nhiều ngôi nhà
 * Thuộc tính (properties) là đặc điểm, đặc trưng, tính chất của class. Thuộc tính là tính từ.
 * Phương thức (method) hành động hành vi của class. Phương thức là động từ.
   Ví dụ 2: class là động vật, object là sư tử thuộc tính (properties) là cân nặng, giới tính, chiều cao
Ba mức độ truy cập dữ liệu trong class:
 * Public: những thuộc tính (properties) hay phương thức(method) được khái báo với từ khóa này sẽ có phạm vi hoạt động bên trong bên ngoài class và trên toàn bộ chương trình
 - Private: những thuộc tính hay phương thức được khai báo với từ khóa này có phạm vi hoạt động chỉ bên trong class nội tại.
 - Protected: những thuộc tính hay phương thức được khai báo với từ khóa này có phạm vi hoạt động chỉ bên trong class nội tại và class kế thừa từ nó.

Các đặc trưng của OOP:
 * Tính đóng gói:
   - Đặc trưng của phương pháp OOP, không cho phép người dùng hay các đối tượng truy xuất trực tiếp dữ liệu của lớp nội tại.
   - Đặc điểm:
     + Tạo cơ chế ngăn ngừa việc gọi phương thức(method) của class này tác động hay truy xuất dữ liệu của đối tượng thuộc về lớp khác.
     + Người lập trình có thể dựa vào cơ chế này ngăn ngừa việc gán giá trị không hợp lệ vào thành phần dữ liệu của mỗi đối tượng.
     + Không cho truy xuất 1 cách tùy tiện dữ liệu của lớp nội tại
     + Cơ chế đóng gói setter và setter giúp thay đổi dữ liệu và lấy dữ liệu, phá vỡ tính private. Cụ thể Setter là một phương thức
     được sử dụng để thay đổi giá trị của một thuộc tính, Getter là một phương thức được sử dụng để truy xuất giá trị của một thuộc tính. 
Ví dụ: 
#include<iostream>
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

* Tính trừu tượng  (Abstraction):
  - Trừu tượng hóa là quá trình đơn giản hóa 1 đối tượng object, xác định thuộc
  tính properties và phương thức method cần thiết của đối tượng object đó để đáp
  ứng yêu cầu cần thiết của chương trình tại thời điểm hiện tại.
  - Quá trình trừu tượng hóa giúp sàng lọc ra những tính chất và hành vi cốt lõi
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



int main ()
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
   + Cụ thể:
public:
void Nhap();
void Xuat();
float Tinh_Tien_Luong();

 - Tính trừu tượng (Inheritance):
  + Kế thừa: Sự trao đổi thông tin từ thế hệ này sang thế hệ khác <=> Sự trao đổi thông tin từ class A sang class. Lớp cha mà có lớp con
kế thừa lại thì các thuộc tính lớp cha sẽ để phạm vi protected.
  + Protected: Khi ta khai báo các thuộc tính hay phương thức với từ khóa này thì nó sẽ có phạm vi hoạt động bên trong lớp đó và ở cácớp con kế thừa nó.
  + Kế thừa là chúng ta đi kiếm những cái "CHUNG" - sau đó đem những cái "CHUNG" đó ra tạo thành 1 class.
  + Khi class con kế thừa từ class cha, class cha có cái gì thì class con cũng có cái đó (trừ khi class cha dùng phạm vi private).
  + Lợi ích: Tránh tình trạng dư thừa dữ liệu

#include <iostream>
#include <string>
using namespace std;

//Đây là khai báo một lớp cơ sở NhanVien, định nghĩa các thuộc tính và phương thức chung cho tất cả các nhân viên.
class NhanVien
{
protected:

    string hoten;
    int tuoi;
    string gioi_tinh;
    string dia_chi;
    string sdt;
    float chieu_cao;
    float can_nang;
//protected: định nghĩa phạm vi truy cập của các thành viên được bảo vệ 
//tức là chúng chỉ có thể truy cập từ các lớp con(dẫn xuất) của NhanVien.

public:

    void Nhap();
    void Xuat();
    //void Nhap(); và void Xuat(); là phương thức để nhập và xuất thông tin nhân viên.
    float Tinh_Tien_Luong();
    //float Tinh_Tien_Luong(); là một phương thức ảo sẽ được cài đặt trong các lớp con để tính lương của từng loại nhân viên.
};

void NhanVien::Nhap()
{

    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, hoten);
    cout << "Nhap tuoi: ";
    cin >> tuoi;
    cout << "Nhap gioi tinh: ";
    cin.ignore();
    getline(cin, gioi_tinh);
    cout << "Nhap dia chi: ";
    cin.ignore();
    getline(cin, dia_chi);
    cout << "Nhap so dien thoai: ";
    cin.ignore();
    getline(cin, sdt);
    cout << "Nhap chieu cao: ";
    cin >> chieu_cao;
    cout << "Nhap can nang: ";
    cin >> can_nang;
}

void NhanVien::Xuat()
{

    cout << "ho ten: " << hoten << endl;
    cout << "tuoi: " << tuoi << endl;
    cout << " gioi tinh: " << gioi_tinh << endl;
    cout << "dia chi: " << dia_chi << endl;
    cout << " so dien thoai: " << sdt << endl;
    cout << " chieu cao: " << chieu_cao << endl;
    cout << " can nang: " << can_nang << endl;
}

float NhanVien::Tinh_Tien_Luong()
{

    return 0; // Không có lương mặc định
}

class NhanVienSuaOngNuoc : public NhanVien
{
private:

    float so_h_sua;
public:

    void Nhap();
    void Xuat();
    float Tinh_Tien_Luong();
};
void NhanVienSuaOngNuoc::Nhap()
{

    NhanVien::Nhap();
    cout << "Nhap so gio sua: ";
    cin >> so_h_sua;
}
void NhanVienSuaOngNuoc::Xuat()
{

    NhanVien::Xuat();
    cout << " so gio sua: " << so_h_sua << endl;
}
float NhanVienSuaOngNuoc::Tinh_Tien_Luong()
{

    return so_h_sua * 50000;
}
class NhanVienGiaoHang : public NhanVien
{
private:

    int so_hang_giao;

public:

    void Nhap();
    void Xuat();
    float Tinh_Tien_Luong();
};

void NhanVienGiaoHang::Nhap()
{

    NhanVien::Nhap();
    cout << "Nhap hang giao: ";
    cin >> so_hang_giao;
}

void NhanVienGiaoHang::Xuat()
{

    NhanVien::Xuat();
    cout << " so hang giao: " << so_hang_giao << endl;
}
float NhanVienGiaoHang::Tinh_Tien_Luong()
{

    return so_hang_giao * 50000;
}
class NhanVienXeOmCongNghe : public NhanVien
{
private:

    float so_km;

public:

    void Nhap();
    void Xuat();
    float Tinh_Tien_Luong();
};

void NhanVienXeOmCongNghe::Nhap()
{

    NhanVien::Nhap();
    cout << "Nhap km: ";
    cin >> so_km;
}

void NhanVienXeOmCongNghe::Xuat()
{

    NhanVien::Xuat();
    cout << " km: " << so_km << endl;
}

float NhanVienXeOmCongNghe::Tinh_Tien_Luong()
{

    return so_km * 34000;
}

void SapXepDanhSachNhanVienSuaOngNuocGiamDanTheoLuong(NhanVienSuaOngNuoc ds[], int n)
{

    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if (ds[j].Tinh_Tien_Luong()<ds[j-1].Tinh_Tien_Luong())
            {
                  NhanVienSuaOngNuoc temp=ds[j];
                  ds[j]=ds[j-1];
                  ds[j-1]=temp;
            }
        }
    }
    // Xuất danh sách sau khi đã sắp xếp
    cout << "\nDanh sach nhan vien sua ong nuoc giam dan theo luong:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Nhan vien " << i + 1 << " - Luong: " << ds[i].Tinh_Tien_Luong() << endl;
        ds[i].Xuat();
    }
}

float TinhTongTienLuongNhanVienSuaOngNuoc(NhanVienSuaOngNuoc ds[], int n)
{

    double sum = 0;
    cout << "Tinh tong tien luong" << endl;
    for (int i = 0; i < n; i++)
    {
        sum += ds[i].Tinh_Tien_Luong();
    }
    return sum;
}

float TinhTongTienLuongNhanVienGiaoHang(NhanVienGiaoHang ds[], int m)
{

    double sum = 0;
    cout << "Tinh tong tien luong" << endl;
    for (int i = 0; i < m; i++)
    {
        sum += ds[i].Tinh_Tien_Luong();
    }
    return sum;
}
float TinhTongTienLuongNhanVienXeOmCongNghe(NhanVienXeOmCongNghe ds[], int l)
{

    double sum = 0;
    cout << "Tinh tong tien luong" << endl;
    for (int i = 0; i < l; i++)
    {
        sum += ds[i].Tinh_Tien_Luong();
    }
    return sum;
}

void Menu(NhanVienSuaOngNuoc ds_nv_suaongnuoc[], NhanVienGiaoHang ds_nv_giaohang[], NhanVienXeOmCongNghe ds_nv_xeomcn[],int n,int m, int l)
{

    int luachon;
    while (true) {
        system("cls");
        cout << "\n\n\t\t ====== CHUONG TRINH QUAN LY";
        cout << "\n1. Nhap thong tin nhan vien sua ong nuoc";
        cout << "\n2. Nhap thong tin nhan vien giao hang";
        cout << "\n3. Nhap thong tin nhan vien xe om cong nghe";
        cout << "\n4. Xuat thong tin nhan vien sua ong nuoc";
        cout << "\n5. Xuat thong tin nhan vien giao hang";
        cout << "\n6. Xuat thong tin nhan vien xe om cong nghe";
        cout << "\n7. Xuat tong luong nhan vien";
        cout << "\n8. Xuat danh sach nhan vien giam dan theo luong";        
        cout << "\n0. KET THUC";
        cout << "\n\n\t\t ====== KET THUC =====";

        cout << "\nNhap lua chon: ";
        cin >> luachon;
        cin.ignore(); 

        if (luachon == 1) {
            NhanVienSuaOngNuoc nv_suaongnuoc;
            cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN SUA ONG NUOC \n";
            nv_suaongnuoc.Nhap();
            ds_nv_suaongnuoc[n] = nv_suaongnuoc;
            n++;
        } else if (luachon == 2) {
            NhanVienGiaoHang nv_giaohang;
            cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN GIAO HANG \n";
            nv_giaohang.Nhap();
            ds_nv_giaohang[m] = nv_giaohang;
            m++;
        } else if (luachon == 3) {
            NhanVienXeOmCongNghe nv_xeomcn;
            cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN XE OM CONG NGHE \n";
            nv_xeomcn.Nhap();
            ds_nv_xeomcn[l] = nv_xeomcn;
            l++;
        } else if (luachon == 4) {
            cout << "\n\n\t\t XUAT THONG TIN NHAN VIEN SUA ONG NUOC \n";
            for (int i = 0; i < n; i++) {
                cout << "\n\n\t\t XUAT THONG TIN NHAN VIEN SUA ONG NUOC THU " << i + 1;
                ds_nv_suaongnuoc[i].Xuat();
            }
            cout << "\n\n\t\t TINH TONG TIEN LUONG NHAN VIEN SUA ONG NUOC " << TinhTongTienLuongNhanVienSuaOngNuoc(ds_nv_suaongnuoc, n);
            system("pause");
        } else if (luachon == 5) {
            cout << "\n\n\t\t XUAT THONG TIN NHAN VIEN GIAO HANG \n";
            for (int i = 0; i < m; i++) {
                cout << "\n\n\t\t XUAT THONG TIN NHAN VIEN GIAO HANG THU " << i + 1;
                ds_nv_giaohang[i].Xuat();
            }
            cout << "\n\n\t\t TINH TONG TIEN LUONG NHAN VIEN GIAO HANG " << TinhTongTienLuongNhanVienGiaoHang(ds_nv_giaohang, m);
            system("pause");
        } else if (luachon == 6) {
            cout << "\n\n\t\t XUAT THONG TIN NHAN VIEN XE OM CONG NGHE \n";
            for (int i = 0; i < l; i++) {
                cout << "\n\n\t\t XUAT THONG TIN NHAN VIEN XE OM CONG NGHE THU " << i + 1;
                ds_nv_xeomcn[i].Xuat();
            }
            cout << "\n\n\t\t TINH TONG TIEN LUONG NHAN VIEN XE OM CONG NGHE " << TinhTongTienLuongNhanVienXeOmCongNghe(ds_nv_xeomcn, l);
            system("pause");

            
        } 
        
        else if(luachon ==7)
        {
            cout<<"\n\n\t\t TONG TIEN PHAI TRA HANG THANG"<<TinhTongTienLuongNhanVienSuaOngNuoc(ds_nv_suaongnuoc, n)+ TinhTongTienLuongNhanVienGiaoHang(ds_nv_giaohang,m)+TinhTongTienLuongNhanVienXeOmCongNghe(ds_nv_xeomcn, l);
        }
         else if (luachon == 8)
        {
        cout << "\n\n\t\t DANH SACH NHAN VIEN SUA ONG NUOC GIAM DAN THEO LUONG\n";
        SapXepDanhSachNhanVienSuaOngNuocGiamDanTheoLuong(ds_nv_suaongnuoc, n);
        system("pause");
        }
        else if (luachon == 0) {
            return; 
        } else {
            cout << "Lua chon khong hop le!";
        }
    }
}

int main ()
{

    NhanVienSuaOngNuoc ds_nv_suaongnuoc[100];//mảng 1 chiều nhân viên sửa ống nước, mỗi phần tử là 1 đối tượng giá trị
    NhanVienGiaoHang ds_nv_giaohang[100];//mảng 1 chiều nhân viên giao hàng, mỗi phần tử là 1 đối tượng giá trị
    NhanVienXeOmCongNghe ds_nv_xeomcn[100];//mảng 1 chiều nhân viên xe ôm công nghệ, mỗi phần tử là 1 đối tượng giá trị
    int n=0;// số lượng nhân viên sửa ống nước
    int m=0;// số lượng nhân viên giao hàng
    int l=0;// số lượng nhân viên xe ôm công nghệ

    Menu(ds_nv_suaongnuoc, ds_nv_giaohang, ds_nv_xeomcn, n, m, l);

    system("pause");
    return 0;
}  

Trong code trên, Tính kế thừa thể hiện ở sử dụng phạm vi protected cho các thuộc tính để lớp con có thể kế thừa. Ở lớp con NhanVienSuaOngNuoc, NhanVienGiaoHang, và NhanVienXeOmCongNghe dùng kế thừa kiểu public từ lớp cha NhanVien, điều này cho phép 
các lớp con kế thừa và cài đặt lại các phương thức khi cần.

 * Tính đa hình (Polymorphism):
  - Phương thức ảo: Những phương thức ở lớp cha được khai báo với từ khóa virtual (ảo) - thì các class con kế thừa từ nó cũng sẽ cài đặt lại các method "trùng tên" của class cha - để cho phép các phương thức của class cha. Nếu như các method của class cha không có từ khóa virtual thì khi chúng ta cấp phát (new) ra đối tượng con bất kì thì nó mặc định chạy về phương thức trùng tên của class cha.
  - Tác dụng của từ khóa virtual: nếu các phương thức của lớp cha có khai báo từ khóa virtual thì khi new ra đối tượng con nào đó bất kì thì khi đó sẽ chạy vào phương thức trùng tên của class con đó, nó cho ta gọi lại phương thức trùng tên của class con
  - Cú pháp: <virtual> <Kiểu Dữ Liệu><Tên phương thức>(Các tham số truyền vào nếu có)
  - Phương thức thuần ảo: Những phương thức sẽ được khai báo ở class cha - còn việc định nghĩa do các class con kế thừa nó đảm nhận
kế thừa lại thì các thuộc tính lớp cha sẽ để phạm vi protected.
  - Nếu ở class cha có khai báo các phương thức thuần ảo, thì quy tắc các lớp con nào kế thừa lại từ lớp cha đó thì các lớp con kế thừa từ lớp cha đó bắt buộc phải đi định nghĩa lại phương thức thuần ảo của class cha đó;  nếu lớp con không định nghĩa => sẽ bị lỗi.
  - Cú pháp: <virtual> <Kiểu Dữ Liệu><Tên phương thức>(Các tham số truyền vào nếu có)=0.
  - Như vậy khi nào dùng ảo, khi nào dùng thuần ảo: Khi ở lớp cha có thông tin để tính toán => dùng ảo; còn khi không có thông tin tính toán ta dùng thuần ảo.

Ví dụ:
Phuong thức ảo:
#include<iostream>
using namespace std;
class A
{

    public:
    void Xuat()
    {
        cout<<"Ai keu toi day co A day !!!";
    }
};

class B: public A
{

    public:
    void Xuat()
    {
        cout<<"Ai keu toi day co B day !!!";
    }
};

int main()
{

    A *x = new B;
    x->Xuat();
    system("pause");
    return 0;
}

* Function Template (khuôn mẫu hàm) là cách để định nghĩa một hàm tổng quát, mà có thể được sử dụng với nhiều kiểu dữ liệu khác nhau. Nó cho phép  viết một lần và sử dụng cho nhiều kiểu dữ liệu mà không cần viết lại mã hàm cho mỗi kiểu đó.




 * Vector: là mảng 1 chiều, cụ thể là mảng động;
   - Vector không cần khai báo trước số lượng phần tử cần dùng, bởi vì nó được hỗ trợ cơ chế tự động thêm vào phần tử cuối (push_back())
   - Tự động giải phóng vùng nhớ khi kết thúc chương trình.
   - Thư viện <Vector> hỗ trợ thao tác thêm, xóa, tìm kiếm, sắp xếp.
   - Khuyết điểm là tốn bộ nhớ hơn mảng tĩnh và động ( do cơ chế buộc tạo ra thêm vùng nhớ để quản lý chặt chẽ hơn)
   - Một số hàm hỗ trợ:
     + resize: 2 dạng
       a) resize(<số lượng>): cấp phát mảng với số lượng phần tử cụ thể cho trước
       b) resize(<số lượng>,<giá trị mặc định>): cấp phát mảng với số lượng phần tử cụ thể cho trước với giá trị các phần tử là giá trị
mặc định.
     + at(<chỉ số index>): truy xuất đến phần tử có chỉ số index trong vector.
     + size(): trả về kích thước hiện tại của vector (số lượng các phần tử đang chứa trong vector).
     + push_back(<phần tử có kdl bất kỳ>): thực hiện đưa phần tử vào cuối vector.
     + pop_back(): xóa phần tử cuối cùng trong vector.
     + front(): trả về phần tử đầu tiên trong mảng.
     + back(): trả về phần tử cuối cùng trong mảng.
     + capacity(): trả về kích thước thực sự vector đang lưu trữ (các phần tử). Nếu muốn xuất kích thước dung lượng thì soạn cũ pháp    capacity() * sizeof(KDL).
     + max.size(): trả về kích thước tối đa có thể chứa các phần tử của các container.
     + swap(<vector x>): hoán đổi các phần tử vector hiện và vector x cho nhau.
Ví dụ:
#include<iostream>
#include<vector>
using namespace std;

void Xuat_mang_vector(vector<int>arr)
//vector<int> arr;: Tạo một vector rỗng có tên arr để lưu trữ các số nguyên.
{

    for(int i=0; i<arr.size();i++)
    {
        cout<<arr.at(i)<<"  ";
        // Xuất phần tử tại vị trí i
    }
}

int main()
{

    vector<int>arr;
    for(int i=0; i<5;i++)//Vòng lặp này thêm 5 phần tử vào vector arr với giá trị từ 0 đến 4.
    {
        arr.push_back(i);
        //Thêm phần tử i vào cuối vector
    }
    cout<<"\n\n\t\t XUAT MANG\n";
    Xuat_mang_vector(arr);//gọi hàm để in ra các phần tử trong vector arr.
    cout << "\nKICH THUOC THUC SU CUA MANG VECTOR HIEN TAI: " << arr.capacity();
    // In ra kích thước thực sự của vector arr bằng cách sử dụng arr.capacity(). (số phần tử)
    cout << "\nKICH THUOC THUC SU CUA MANG VECTOR HIEN TAI (byte): " << arr.capacity() * sizeof(int);
    // In ra kích thước thực sự của vector arr bằng cách sử dụng arr.capacity(). (byte)

    system("pause");
    return 0;
}

Kết quả:XUAT MANG
0  1  2  3  4
KICH THUOC THUC SU CUA MANG VECTOR HIEN TAI: 8
KICH THUOC THUC SU CUA MANG VECTOR HIEN TAI (byte): 32
Press any key to continue . . .

#include<iostream>
#include<vector>
using namespace std;

void Xuat_mang_vector(vector<int>arr)
//vector<int> arr;: Tạo một vector rỗng có tên arr để lưu trữ các số nguyên.
{

    for(int i=0; i<arr.size();i++)
    {
        cout<<arr.at(i)<<"  ";
        // Xuất phần tử tại vị trí i
    }
}

int main()
{

    vector<int>arr;
    for(int i=0; i<5;i++)//Vòng lặp này thêm 5 phần tử vào vector arr với giá trị từ 0 đến 4.
    {
        arr.push_back(i);
        
        //Thêm phần tử i vào cuối vector
    }

    cout<<"\nPHAN TU DAU TIEN CUA MANG:\t"<<arr.front();
    cout<<"\nPHAN TU CUOI CUNG CUA MANG:\t"<<arr.back();

    cout<<"\n\n\t\t XUAT MANG\n";
    Xuat_mang_vector(arr);//gọi hàm để in ra các phần tử trong vector arr.

    arr.pop_back(); //hàm xóa phần tử cuối cùng của mảng vector
    cout<<"\n\n\t\t XUAT MANG\n";
    Xuat_mang_vector(arr);//gọi hàm để in ra các phần tử trong vector arr.

    cout << "\nKICH THUOC THUC SU CUA MANG VECTOR HIEN TAI: " << arr.capacity();
    // In ra kích thước thực sự của vector arr bằng cách sử dụng arr.capacity(). (số phần tử)
    cout << "\nKICH THUOC THUC SU CUA MANG VECTOR HIEN TAI (byte): " << arr.capacity() * sizeof(int);
    // In ra kích thước thực sự của vector arr bằng cách sử dụng arr.capacity(). (byte)
    cout<<"\n SO LUONG PHAN TU CO THE CHUA DUOC TOI DA CUA VECTOR:  "<<arr.max_size();
    system("pause");
    return 0;
}

kẾT QUẢ PHAN TU DAU TIEN CUA MANG:      0
PHAN TU CUOI CUNG CUA MANG:     4
                 XUAT MANG
0  1  2  3  4
                 XUAT MANG
0  1  2  3
KICH THUOC THUC SU CUA MANG VECTOR HIEN TAI: 8
KICH THUOC THUC SU CUA MANG VECTOR HIEN TAI (byte): 32
 SO LUONG PHAN TU CO THE CHUA DUOC TOI DA CUA VECTOR:  1073741823

#include<iostream>
#include<vector>
using namespace std;

void Xuat_mang_vector(vector<int>arr)
//vector<int> arr;: Tạo một vector rỗng có tên arr để lưu trữ các số nguyên.
{

    for(int i=0; i<arr.size();i++)
    {
        cout<<arr.at(i)<<"  ";
        // Xuất phần tử tại vị trí i
    }
}

int main()
{

    vector<int>arr;
    for(int i=0; i<5;i++)//Vòng lặp này thêm 5 phần tử vào vector arr với giá trị từ 0 đến 4.
    {
        arr.push_back(i);
        
        //Thêm phần tử i vào cuối vector
    }

    cout<<"\nPHAN TU DAU TIEN CUA MANG:\t"<<arr.front();
    cout<<"\nPHAN TU CUOI CUNG CUA MANG:\t"<<arr.back();

    cout<<"\n\n\t\t XUAT MANG DA THEM 5 PHAN TU\n";
    Xuat_mang_vector(arr);//gọi hàm để in ra các phần tử trong vector arr.

    arr.pop_back(); //hàm xóa phần tử cuối cùng của mảng vector
    cout<<"\n\n\t\t XUAT MANG DA XOA PHAN TU CUOI\n";
    Xuat_mang_vector(arr);//gọi hàm để in ra các phần tử trong vector arr.

    arr.erase(arr.begin()+2);// xóa phần tử tại vị trí thứ 3
    cout<<"\n\n\t\t XUAT MANG DA XOA PHAN TU THU 3\n";
    Xuat_mang_vector(arr);//gọi hàm để in ra các phần tử trong vector arr.

    arr.insert(arr.begin()+2,69);// thêm phần tử tại vị trí thứ 3
    cout<<"\n\n\t\t XUAT MANG DA THEM PHAN TU O VI TRI THU 3\n";
    Xuat_mang_vector(arr);//gọi hàm để in ra các phần tử trong vector arr.

    cout << "\nKICH THUOC THUC SU CUA MANG VECTOR HIEN TAI: " << arr.capacity();
    // In ra kích thước thực sự của vector arr bằng cách sử dụng arr.capacity(). (số phần tử)
    cout << "\nKICH THUOC THUC SU CUA MANG VECTOR HIEN TAI (byte): " << arr.capacity() * sizeof(int);
    // In ra kích thước thực sự của vector arr bằng cách sử dụng arr.capacity(). (byte)
    cout<<"\n SO LUONG PHAN TU CO THE CHUA DUOC TOI DA CUA VECTOR:  "<<arr.max_size();


    vector<int>x;
    for(int i=10; i<15;i++)//Vòng lặp này thêm 5 phần tử vào vector arr với giá trị từ 0 đến 4.
    {
        x.push_back(i);
        
        //Thêm phần tử i vào cuối vector
    }

    arr.swap(x); //hoán đổi 2 mảng vector cho nhau

    cout<<"\n\n\t\t XUAT MANG arr sau khi hoan doi\n";
    Xuat_mang_vector(arr);//gọi hàm để in ra các phần tử trong vector arr.
    cout<<"\n\n\t\t XUAT MANG x sau khi hoan doi\n";
    Xuat_mang_vector(x);//gọi hàm để in ra các phần tử trong vector arr.
    system("pause");
    return 0;
}



Áp dụng vào bài toán nhân viên:
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Lớp cơ sở NhanVien định nghĩa các thuộc tính và phương thức chung cho tất cả các nhân viên.
class NhanVien {
protected:

    string hoten;
    int tuoi;
    string gioi_tinh;
    string dia_chi;
    string sdt;
    float chieu_cao;
    float can_nang;
public:

    void Nhap();
    void Xuat();
    virtual float Tinh_Tien_Luong() = 0; // Hàm ảo để tính lương (phải được định nghĩa lại trong các lớp con).
};

// Hàm nhập thông tin nhân viên.
void NhanVien::Nhap() {

    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, hoten);
    cout << "Nhap tuoi: ";
    cin >> tuoi;
    cout << "Nhap gioi tinh: ";
    cin.ignore();
    getline(cin, gioi_tinh);
    cout << "Nhap dia chi: ";
    cin.ignore();
    getline(cin, dia_chi);
    cout << "Nhap so dien thoai: ";
    cin.ignore();
    getline(cin, sdt);
    cout << "Nhap chieu cao: ";
    cin >> chieu_cao;
    cout << "Nhap can nang: ";
    cin >> can_nang;
}

// Hàm xuất thông tin nhân viên.
void NhanVien::Xuat() {

    cout << "Ho ten: " << hoten << endl;
    cout << "Tuoi: " << tuoi << endl;
    cout << "Gioi tinh: " << gioi_tinh << endl;
    cout << "Dia chi: " << dia_chi << endl;
    cout << "So dien thoai: " << sdt << endl;
    cout << "Chieu cao: " << chieu_cao << endl;
    cout << "Can nang: " << can_nang << endl;
}

// Lớp con NhanVienSuaOngNuoc kế thừa từ lớp NhanVien.
class NhanVienSuaOngNuoc : public NhanVien {
private:

    float so_h_sua;

public:

    void Nhap();
    void Xuat();
    float Tinh_Tien_Luong();
};

// Hàm nhập thông tin nhân viên sửa ống nước.
void NhanVienSuaOngNuoc::Nhap() {

    NhanVien::Nhap();
    cout << "Nhap so gio sua: ";
    cin >> so_h_sua;
}

// Hàm xuất thông tin nhân viên sửa ống nước.
void NhanVienSuaOngNuoc::Xuat() {

    NhanVien::Xuat();
    cout << "So gio sua: " << so_h_sua << endl;
}

// Hàm tính lương của nhân viên sửa ống nước.
float NhanVienSuaOngNuoc::Tinh_Tien_Luong() {

    return so_h_sua * 50000;
}

// Lớp con NhanVienGiaoHang kế thừa từ lớp NhanVien.
class NhanVienGiaoHang : public NhanVien {
private:

    int so_hang_giao;
public:

    void Nhap();
    void Xuat();
    float Tinh_Tien_Luong();
};

// Hàm nhập thông tin nhân viên giao hàng.
void NhanVienGiaoHang::Nhap() {

    NhanVien::Nhap();
    cout << "Nhap so hang giao: ";
    cin >> so_hang_giao;
}

// Hàm xuất thông tin nhân viên giao hàng.
void NhanVienGiaoHang::Xuat() {

    NhanVien::Xuat();
    cout << "So hang giao: " << so_hang_giao << endl;
}

// Hàm tính lương của nhân viên giao hàng.
float NhanVienGiaoHang::Tinh_Tien_Luong() {

    return so_hang_giao * 50000;
}

// Lớp con NhanVienXeOmCongNghe kế thừa từ lớp NhanVien.
class NhanVienXeOmCongNghe : public NhanVien {
private:

    float so_km;

public:

    void Nhap();
    void Xuat();
    float Tinh_Tien_Luong();
};

// Hàm nhập thông tin nhân viên xe ôm công nghệ.
void NhanVienXeOmCongNghe::Nhap() {

    NhanVien::Nhap();
    cout << "Nhap km: ";
    cin >> so_km;
}

// Hàm xuất thông tin nhân viên xe ôm công nghệ.
void NhanVienXeOmCongNghe::Xuat() {

    NhanVien::Xuat();
    cout << "Km: " << so_km << endl;
}

// Hàm tính lương của nhân viên xe ôm công nghệ.
float NhanVienXeOmCongNghe::Tinh_Tien_Luong() {
    return so_km * 34000;
}

// Hàm tính tổng tiền lương của danh sách nhân viên.
float TinhTongTienLuong(vector<NhanVien*>& ds) {

    double sum = 0;
    for (NhanVien* nv : ds) {
        sum += nv->Tinh_Tien_Luong();
    }
    return sum;
}

// Hàm sắp xếp danh sách nhân viên theo thứ tự giảm dần theo lương.
void SapXepDanhSachNhanVienGiamDanTheoLuong(vector<NhanVien*>& ds) {

    for (size_t i = 0; i < ds.size(); i++) {
        for (size_t j = ds.size() - 1; j > i; j--) {
            if (ds[j]->Tinh_Tien_Luong() < ds[j - 1]->Tinh_Tien_Luong()) {
                swap(ds[j], ds[j - 1]);
            }
        }
    }
}

// Hàm hiển thị menu và quản lý chương trình.
void Menu(vector<NhanVien*>& ds_nv) {

    int luachon;
    while (true) {
        system("cls");
        cout << "\n\n\t\t ====== CHUONG TRINH QUAN LY";
        cout << "\n1. Nhap thong tin nhan vien sua ong nuoc";
        cout << "\n2. Nhap thong tin nhan vien giao hang";
        cout << "\n3. Nhap thong tin nhan vien xe om cong nghe";
        cout << "\n4. Xuat thong tin nhan vien";
        cout << "\n5. Xuat tong luong nhan vien";
        cout << "\n6. Xuat danh sach nhan vien giam dan theo luong";
        cout << "\n0. KET THUC";
        cout << "\n\n\t\t ====== KET THUC =====";

        cout << "\nNhap lua chon: ";
        cin >> luachon;
        cin.ignore();

        if (luachon == 1) {
            NhanVienSuaOngNuoc* nv_suaongnuoc = new NhanVienSuaOngNuoc;
            cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN SUA ONG NUOC \n";
            nv_suaongnuoc->Nhap();
            ds_nv.push_back(nv_suaongnuoc);
        } else if (luachon == 2) {
            NhanVienGiaoHang* nv_giaohang = new NhanVienGiaoHang;
            cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN GIAO HANG \n";
            nv_giaohang->Nhap();
            ds_nv.push_back(nv_giaohang);
        } else if (luachon == 3) {
            NhanVienXeOmCongNghe* nv_xeomcn = new NhanVienXeOmCongNghe;
            cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN XE OM CONG NGHE \n";
            nv_xeomcn->Nhap();
            ds_nv.push_back(nv_xeomcn);
        } else if (luachon == 4) {
            cout << "\n\n\t\t XUAT THONG TIN NHAN VIEN \n";
            for (NhanVien* nv : ds_nv) {
                nv->Xuat();
            }
            system("pause");
        } else if (luachon == 5) {
            cout << "\n\n\t\t TONG TIEN PHAI TRA HANG THANG " << TinhTongTienLuong(ds_nv) << endl;
            system("pause");
        } else if (luachon == 6) {
            cout << "\n\n\t\t DANH SACH NHAN VIEN GIAM DAN THEO LUONG\n";
            SapXepDanhSachNhanVienGiamDanTheoLuong(ds_nv);
            for (NhanVien* nv : ds_nv) {
                cout << "Luong: " << nv->Tinh_Tien_Luong() << endl;
                nv->Xuat();
            }
            system("pause");
        } else if (luachon == 0) {
            return;
        } else {
            cout << "Lua chon khong hop le!";
        }
    }

    // Giải phóng bộ nhớ của các đối tượng nhân viên khi kết thúc chương trình.
    for (NhanVien* nv : ds_nv) {
        delete nv;
    }
}

int main() {

    vector<NhanVien*> ds_nv; // Sử dụng vector để quản lý danh sách nhân viên.
    Menu(ds_nv);

    system("pause");
    return 0;
}

 
  




