#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Nhap so luong phan tu can: ";
    cin >> n;
    int *a;
    a = new int[n]; //Nhap mang
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap gia tri cho phan tu thu " << i + 1 << ": ";
        cin >> a[i];
    }

    // Xuat mang
    for (int i = 0; i < n; i++) 
    {
        cout << a[i] << " ";
    }

    cout << endl; 

    delete [] a; 
    a = nullptr;
    return 0;
}
