#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Phuong trinh bac may!?!??!\n";
    cin >> n;
    
    int *heso = new int[n];

    // Nhap cac he so
    for (unsigned int i = 0; i < n; i++) {
        cout << "Nhap he so " << i+1 << "!!?!?!: ";
        cin >> heso[i];
    }

    return 0;
}