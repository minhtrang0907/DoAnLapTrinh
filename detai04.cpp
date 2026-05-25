// ================================================================
//  De tai 04: Quan ly muon tra sach thu vien
//  Yeu cau: Su dung vector<> de quan ly sach
//  Gom 4 class: Sach, SachMuonVe, SachMuonDoc, ThuVien
//  Bien dich: g++ -std=c++11 QuanLyThuVien_Vector_4Class.cpp -o ThuVien
// ================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;
//TRANG
// ================================================================
//  CLASS CO SO: Sach
// ================================================================
class Sach {};

// ===============================================================================================================================
// TRANG
//  CLASS DAN XUAT: SachMuonVe
// ================================================================
class SachMuonVe : public Sach {};

// ===============================================================================================================================
// QUANH
// ================================================================
//  CLASS DAN XUAT: SachMuonDoc
// ================================================================
class SachMuonDoc : public Sach {
private:
    string gioMuon;
    string gioTra;

public:
    SachMuonDoc(string ma = "", string ten = "", string cd = "", string tg = "",
                string nxb = "", string ngayXB = "", int trang = 0, int ban = 0,
                string gioM = "", string gioT = "")
        : Sach(ma, ten, cd, tg, nxb, ngayXB, trang, ban) {
        gioMuon = gioM;
        gioTra = gioT;
    }

    string getLoaiSach() { return "Muon doc"; }
    void nhap();
    void xuat();
    bool quaHan();

    // 2 ham doc/ghi file co trong class SachMuonDoc
    void docFile(string dong);
    string ghiFile();

    string chuyenChuoi() {
        return ghiFile();
    }
};

void SachMuonDoc::nhap() {
    Sach::nhap();
    cout << "Nhap gio muon doc (hh:mm): "; cin >> ws;
    getline(cin, gioMuon);
    cout << "Nhap gio tra (hh:mm): ";
    getline(cin, gioTra);
}

void SachMuonDoc::xuat() {
    Sach::xuat();
    cout << left;
    cout << "| " << setw(10) << "D";
    cout << "| " << setw(12) << "";
    cout << "| " << setw(12) << "";
    cout << "| " << setw(10) << gioMuon;
    cout << "| " << setw(10) << gioTra;
    cout << "| " << endl;
}

// Doc day du thong tin cua SachMuonDoc tu file
void SachMuonDoc::docFile(string dong) {
    Sach::docFile(dong);

    stringstream ss(dong);
    string boQua, trangStr, banStr;

    getline(ss, boQua, '|');      // loai
    getline(ss, boQua, '|');      // ma
    getline(ss, boQua, '|');      // ten
    getline(ss, boQua, '|');      // chu de
    getline(ss, boQua, '|');      // tac gia
    getline(ss, boQua, '|');      // nha xuat ban
    getline(ss, boQua, '|');      // ngay xuat ban
    getline(ss, trangStr, '|');   // so trang
    getline(ss, banStr, '|');     // so ban luu
    getline(ss, gioMuon, '|');
    getline(ss, gioTra, '|');
}

// Ghi day du thong tin cua SachMuonDoc ra file
string SachMuonDoc::ghiFile() {
    stringstream ss;
    ss << "D|" << Sach::ghiFile() << "|" << gioMuon << "|" << gioTra;
    return ss.str();
}

bool SachMuonDoc::quaHan() {
    if (gioMuon.length() < 5 || gioTra.length() < 5) return false;

    int phutMuon = atoi(gioMuon.substr(0, 2).c_str()) * 60
                 + atoi(gioMuon.substr(3, 2).c_str());
    int phutTra = atoi(gioTra.substr(0, 2).c_str()) * 60
                + atoi(gioTra.substr(3, 2).c_str());

    // Gia su muon doc qua 240 phut la qua gio
    return (phutTra - phutMuon) > 240;
}

// ===============================================================================================================================
// THU + HIEN
//  CLASS QUAN LY: ThuVien
// ================================================================
class ThuVien {
private:
    vector<Sach*> dsSach;

public:
    void thongKe() {} // HIEN
    void themSach() {} // HIEN
    void xoaSach() {} // HIEN
    void timKiemMa() {} // THU
    void timKiemTen() {} // THU
    void timKiemNXB() {} // THU
    void Menu() {} // THU
    void dieuHuong() {} // THU
};
// ===================================================================================================================================
//  HIEN
//  CLASS GIAO DIEN (Ve bang)  //
// ================================================================

class GiaoDien {
public:
    static void duongKeVe(ostream& os) { os << "  +----------+-------------------------+---------------+-----+------------------+------------+------------+-------------+\n"; }
    static void duongKeDoc(ostream& os) { os << "  +----------+-------------------------+---------------+-----+----------+----------+----------------------+\n"; 
    }
    
    static void tieuDeVe(ostream& os) {
        os << "\n  +-----------------------------------------------------------------------------------------------------------------------+\n"
           << "  |                                        DANH SACH MUON VE                                                              |\n";
        duongKeVe(os);
        os << left << "  | " << setw(9) << "Ma sach" << "| " << setw(24) << "Ten sach" << "| " << setw(14) << "Nha xuat ban" 
           << "| " << setw(4) << "SL" << "| " << setw(17) << "Nguoi muon" << "| " << setw(11) << "Ngay muon" 
           << "| " << setw(11) << "Ngay tra" << "| " << setw(12) << "Trang thai" << "|\n";
        duongKeVe(os);
    }

    static void tieuDeDoc(ostream& os) {
        os << "\n  +-------------------------------------------------------------------------------------------------------+\n"
           << "  |                                        DANH SACH MUON DOC                                             |\n";
        duongKeDoc(os);
        os << left << "  | " << setw(9) << "Ma sach" << "| " << setw(24) << "Ten sach" << "| " << setw(14) << "Nha xuat ban" 
           << "| " << setw(4) << "SL" << "| " << setw(9) << "Gio muon" << "| " << setw(9) << "Gio tra" 
           << "| " << setw(21) << "Trang thai/Thoi gian" << "|\n";
        duongKeDoc(os);
    }

    static void xuatBang(ostream& os, const vector<Sach*>& ds) {
        tieuDeVe(os); bool coVe = false;
        for (const Sach* s : ds) if (s->getLoai() == 'V') { s->xuatDong(os); duongKeVe(os); coVe = true; }
        if (!coVe) { os << "  | " << left << setw(116) << "Khong co sach muon ve" << "|\n"; duongKeVe(os); }

        tieuDeDoc(os); bool coDoc = false;
        for (const Sach* s : ds) if (s->getLoai() == 'D') { s->xuatDong(os); duongKeDoc(os); coDoc = true; }
        if (!coDoc) { os << "  | " << left << setw(102) << "Khong co sach muon doc" << "|\n"; duongKeDoc(os); }
    }
};


    
// ================================================================
//  HAM MAIN
// ================================================================
int main() {
    
}
