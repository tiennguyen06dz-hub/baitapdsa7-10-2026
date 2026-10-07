#include <iostream>
#include <string>
using namespace std;

struct KhachHang {
    int makh;
    string tenkh;
    string sdt;
    float tongtien;
};

void nhap(KhachHang *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nKhach hang thu " << i + 1 << ":\n";

        cout << "Ma khach hang: ";
        cin >> a[i].makh;
        cin.ignore();

        cout << "Ten khach hang: ";
        getline(cin, a[i].tenkh);

        cout << "So dien thoai: ";
        getline(cin, a[i].sdt);

        cout << "Tong tien thanh toan: ";
        cin >> a[i].tongtien;
    }
}

void xuat(KhachHang *a, int n) {
    cout << "\nDANH SACH KHACH HANG\n";

    for (int i = 0; i < n; i++) {
        cout << "\nMa KH: " << a[i].makh;
        cout << "\nTen KH: " << a[i].tenkh;
        cout << "\nSDT: " << a[i].sdt;
        cout << "\nTong tien: " << a[i].tongtien;
        cout << "\n--------------------";
    }
}

void insertionSort(KhachHang *a, int n) {
    for (int i = 1; i < n; i++) {
        KhachHang x = a[i];
        int j = i - 1;

        while (j >= 0 && a[j].tongtien > x.tongtien) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = x;
    }
}

void timkiem(KhachHang *a, int n, float X) {
    int left = 0;
    int right = n - 1;
    bool timthay = false;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid].tongtien == X) {
            cout << "\nKhach hang co tong tien bang " << X << ":\n";

            int i = mid;

            while (i >= 0 && a[i].tongtien == X) {
                i--;
            }
            i++;

            while (i < n && a[i].tongtien == X) {
                cout << "\nMa KH: " << a[i].makh;
                cout << "\nTen KH: " << a[i].tenkh;
                cout << "\nSDT: " << a[i].sdt;
                cout << "\nTong tien: " << a[i].tongtien;
                cout << "\n--------------------";
                i++;
            }

            timthay = true;
            break;
        }
        else if (a[mid].tongtien < X) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (!timthay) {
        cout << "\nKhong tim thay khach hang co tong tien bang " << X;
    }
}

int main() {
    int n;
    float X;

    cout << "Nhap so luong khach hang: ";
    cin >> n;

    KhachHang *a = new KhachHang[n];

    nhap(a, n);

    cout << "\n\n=== DANH SACH VUA NHAP ===";
    xuat(a, n);

    insertionSort(a, n);

    cout << "\n\n=== DANH SACH SAU KHI SAP XEP ===";
    xuat(a, n);

    cout << "\n\nNhap X: ";
    cin >> X;

    timkiem(a, n, X);

    delete[] a;

    return 0;
}
