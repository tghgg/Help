#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Phuong trinh bac may!?!??!\n";
    cin >> n;
    
    double *heso = new double[n];

    // Nhap cac he so
    for (unsigned int i = 0; i <= n; i++) {
        cout << "Nhap he so bac " << n-i << "!!?!?!: ";
        cin >> heso[i];
    }

    // Giai phuong trinh
    switch (n) {
        case 1:
            {
                double nghiem = (-heso[n])/heso[0];
                cout << "x = " << nghiem << endl;
                break;
            }
        default :
            cout << "Phuong trinh khong hop le\n";
    }

    delete heso;
    heso = nullptr;

    return 0;
}
