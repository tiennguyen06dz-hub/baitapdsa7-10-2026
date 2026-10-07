#include <iostream>
#include <string>
using namespace std;

struct NhanVien {
    int manv;
    string hoten;
    string ngaysinh;
    float luong;
};

void nhap(NhanVien *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nNhan vien thu " << i + 1 << ":\n";

        cout << "Ma nhan vien: ";
        cin >> a[i].manv;
        cin.ignore();

        cout << "Ho ten: ";
        getline(cin, a[i].hoten);

        cout << "Ngay sinh: ";
        getline(cin, a[i].ngaysinh);

        cout << "Luong: ";
        cin >> a[i].luong;
    }
}

void xuat(NhanVien *a, int n) {
    cout << "\nDANH SACH NHAN VIEN\n";

    for (int i = 0; i < n; i++) {
        cout << "\nMa NV: " << a[i].manv;
        cout << "\nHo ten: " << a[i].hoten;
        cout << "\nNgay sinh: " << a[i].ngaysinh;
        cout << "\nLuong: " << a[i].luong << " trieu dong";
        cout << "\n--------------------";
    }
}

void bubbleSort(NhanVien *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].luong > a[j + 1].luong) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void timkiem(NhanVien *a, int n, float X) {
    int left = 0;
    int right = n - 1;
    bool timthay = false;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid].luong == X) {
            cout << "\nNHAN VIEN CO LUONG BANG " << X << ":\n";

            int i = mid;

            while (i >= 0 && a[i].luong == X) {
                i--;
            }

            i++;

            while (i < n && a[i].luong == X) {
                cout << "\nMa NV: " << a[i].manv;
                cout << "\nHo ten: " << a[i].hoten;
                cout << "\nNgay sinh: " << a[i].ngaysinh;
                cout << "\nLuong: " << a[i].luong << " trieu dong";
                cout << "\n--------------------";
                i++;
            }

            timthay = true;
            break;
        }
        else if (a[mid].luong < X) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (!timthay) {
        cout << "\nKhong tim thay nhan vien co luong bang " << X;
    }
}

int main() {
    int n;
    float X;

    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    NhanVien *a = new NhanVien[n];

    nhap(a, n);

    cout << "\n\n=== DANH SACH VUA NHAP ===";
    xuat(a, n);

    bubbleSort(a, n);

    cout << "\n\n=== DANH SACH SAU KHI SAP XEP ===";
    xuat(a, n);

    cout << "\n\nNhap X: ";
    cin >> X;

    timkiem(a, n, X);

    delete[] a;

    return 0;
}
