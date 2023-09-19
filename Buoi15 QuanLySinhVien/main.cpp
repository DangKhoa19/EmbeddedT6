

#include<iostream>
#include<string>

using namespace std;
// Lớp cơ sở DoiTuong với tính chất đóng gói và trừu tượng

class DoiTuong {
protected: // Tính đóng gói: thuộc tính được bảo vệ
    string TEN;
    int NAM_SINH;
    string DIA_CHI;
    int tinhTuoi(int namSinh); // method trừu tượng
public:
    void themThongTin(string ten, int namSinh, string dia_chi); //method gán thông tin cho các properties
    void hienThi();  //method hiển thị thông tin
};

// triển khai,định nghĩa method tinhTuoi(int namSinh) của class Doituong
/// Triển khai phương thức trừu tượng(làm rõ) tinhTuoi của class DoiTuong
int DoiTuong::tinhTuoi(int namSinh){
    return 2023 - namSinh;
};

// triển khai,định nghĩa method themThongTin(string ten, int namSinh, string dia_chi) của class Doituong
void DoiTuong::themThongTin(string ten, int namSinh, string dia_chi){
    TEN=ten;
    NAM_SINH = namSinh;
    DIA_CHI=dia_chi;
};

// triển khai,định nghĩa method hienThi() của class Doituong
void DoiTuong::hienThi() {
    cout << "Ten: " << TEN << endl;
    cout << "Nam sinh: " << NAM_SINH << endl;
    cout << "Diachi: " << DIA_CHI << endl;
    cout << "Tuoi: "<<tinhTuoi(NAM_SINH)<<endl;
}

// class Sinh vien(class con) kế thừa từ class Doi tuong (class cha) (Kế thừa giúp tái sử dụng mã nguồn)
//Class SinhVien là một class kế thừa (derived class) từ class DoiTuong. 
class SinhVien : public DoiTuong {
private:
    int MSSV; // Class này chứa thêm thuộc tính private là MSSV (Mã số sinh viên).
public:
    SinhVien();
};

//Conductor (hàm tạo) của class SinhVien được định nghĩa
SinhVien::SinhVien() {
    static int mssv = 1000;
    MSSV = mssv;
    mssv++; // tạo ra một số MSSV tăng dần mỗi khi một đối tượng SinhVien mới được tạo. 
}

int main() {
    DoiTuong dt;
    dt.themThongTin("Hoang", 1997, "Go Vap");
    dt.hienThi();

    SinhVien sv;
    sv.themThongTin("Tien", 2000, "Tan Binh");
    sv.hienThi();

    return 0;
}


