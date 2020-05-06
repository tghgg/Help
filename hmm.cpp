#include <iostream>
using namespace std;

int main() {
    unsigned int temp = 0;
    unsigned int *pointer = &temp;
    
    unsigned int i = 0;
    unsigned int mang[20] = {};
    cout << "Nhap mang.\nNhap '0' de dung nhap so.\n";
    
    // Nhap mang
    do {
        cin >> *pointer;
        mang[i] = *pointer;
        i += 1;
    } while (temp != 0 && i < 20);
    
   
    
    // Xuat mang
    cout << endl;
    for ( unsigned int index = 0; index < i-1; index++) {
        cout << mang[index] << " ";
    }
    
    unsigned int size = i-1;
    unsigned int foo;
    
    // Dao nguoc mang
    unsigned int j = i - 2;
    i = 0;
    while (i < j) {
        foo = mang[i];
        mang[i] = mang[j];
        mang[j] = foo;
        i += 1;
        j -= 1;
    }
    
    cout << endl;
    cout << "Xuat mang nguoc\n";
    for ( unsigned int index2 = 0; index2 < size; index2++) {
        cout << mang[index2] << " ";
    }
    
    pointer = nullptr;
    system("pause");
    return 0;
}  
