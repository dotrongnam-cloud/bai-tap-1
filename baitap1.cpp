#include <iostream>
#include <string>
#include <bitset>

using namespace std;

//  nhan 2 da thuc trong truong GF(2^n)
int nhandt(int dtA, int dtB, int bac, int dtToiGian) {
    int ketQua = 0;

    for (int i = 0; i < bac; i++) {
        // Neu bit cuoi cua B bang 1 thi cong (XOR) A vao ket qua
        if ((dtB & 1) == 1) {
            ketQua = ketQua ^ dtA;
        }

        // Kiem tra bit cao nhat cua A (tai vi tri bac - 1)
        int bitmax = dtA & (1 << (bac - 1));

        // Dich trai A 1 bit (tuong duong nhan voi x)
        dtA = dtA << 1;

        // Neu bit cao nhat bang 1 (bi tran bac), rut gon modulo voi da thuc toi gian
        if (bitmax != 0) {
            dtA = dtA ^ dtToiGian;
        }

        // Dich phai B 1 bit de xet he so tiep theo
        dtB = dtB >> 1;
    }

    return ketQua;
}

int main() {
    int luaChon;
    cout << "CHON TRUONG HUU HAN CAN TINH:" << endl;
    cout << "1. GF(2^4) voi m(x) = x^4 + x + 1 (10011)" << endl;
    cout << "2. GF(2^8) voi m(x) = x^8 + x^4 + x^3 + x + 1 (100011011)" << endl;
    cout << "Nhap lua chon (1 hoac 2): ";
    cin >> luaChon;

    string nhapA, nhapB;
    cout << "Nhap da thuc A dang nhi phan : ";
    cin >> nhapA;
    cout << "Nhap da thuc B dang nhi phan : ";
    cin >> nhapB;

    // Chuyen chuoi nhi phan sang so nguyen 
    int daThucA = stoi(nhapA, nullptr, 2);
    int daThucB = stoi(nhapB, nullptr, 2);

    if (luaChon == 1) {
        int m4 = 0b10011; // da thuc toi gian gf 2 mu 4
        int ketQua = nhandt(daThucA, daThucB, 4, m4);
        
        cout << "\n=> Ket qua nhan tren GF(2^4) la " << endl;
        cout << "Dang nhi phan: " << bitset<4>(ketQua) << endl;
    } 
    else if (luaChon == 2) {
        int m8 = 0b100011011; // da thu toi gian gf 2 mu 8
        int ketQua = nhandt(daThucA, daThucB, 8, m8);
        
        cout << "\n=> Ket qua nhan tren GF(2^8):" << endl;
        cout << "Dang nhi phan: " << bitset<8>(ketQua) << endl;
    } 
    else {
        cout << "Lua chon khong hop le!" << endl;
    }

    return 0;
}