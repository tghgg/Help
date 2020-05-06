#include <iostream>
using namespace std;

int main() {
    
    int m;
    int n;
    
    int int_count = 0;
    
    cout << "Nhap so hang: ";
    cin >> m;
    cout << "\nNhap so cot: ";
    cin >> n;
    
    int** mang = new int*[m];
    
    for(int i = 0; i < m; i++) {
        mang[i] = new int[n];
    }
    
    // Nhap hang cua mang
    for ( int j = 0; j < m; j++) {
        // Nhap cot cua hang hien tai
        for ( int k = 0; k < n; k++) {
            cout << "Nhap cot " << k+1 << " cua hang " << j+1 << endl;
            cin >> mang[j][k];
            if (cin) {
                int_count += 1;
            } else {
                cin.clear();
            }
        }
    }
    
    cout << "\nMang 2 chieu co " << int_count << " so nguyen to." << endl;
   
    for ( int k = 0; k < m; k++) {
        delete mang[k];
        mang[k] = nullptr;
    }
    
    delete mang;
    mang = nullptr;
    system("pause");
    return 0;
}  
