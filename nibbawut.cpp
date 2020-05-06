#include <iostream>
#include <cmath>
using namespace std;

double * giaiDaThuc(int bac, double heso[])
{
    double *nghiem = new double[bac];

    // cout << "He so la " << heso << endl;

    switch (bac)
    {
        case 1:
        {   
            nghiem[0] = (-heso[bac]) / heso[0];
            break;
        }
        case 2:
        {
            const double a = heso[0];
            if (a == 0) {
                cout << "He so a = 0\nPhuong trinh khong hop le.\n";
                break;
            }
            const double b = heso[1];
            const double c = heso[2];
    
            double delta = pow(b, 2.0) - 4 * a * c;

            if (delta < 0.0)
            {
                nghiem = nullptr;
                break;
            }
            else if (delta == 0.0)
            {
                nghiem[0] = (-b)/(2.0*a);
                nghiem[1] = nghiem[0];
                break;
            }
            else
            {
                delta = sqrt(delta);
                nghiem[0] = (-b + delta) / (2 * a);
                nghiem[1] = (-b - delta) / (2 * a);
                break;
            }
        }
        default:
            cout << "Phuong trinh khong hop le\n";
    }

    return nghiem;
}

int main()
{
    int bac;

    cout << "Phuong trinh bac may?\n";
    cin >> bac;

    double *heso = new double[bac+1];

    // Nhap he so
    for (unsigned int i = 0; i <= bac; i++)
    {
        cout << "Nhap he so bac " << bac - i << "!!?!?!: ";
        cin >> heso[i];
    }

    const double *nghiem = giaiDaThuc(bac, heso);
    cout << *nghiem << endl;
    // Xuat nghiem

    if (nghiem == nullptr)
        cout << "Phuong trinh vo nghiem";
    else
    {
        for (unsigned int i = 0; i < bac; i++) {
            cout << "x" << i+1 << " = " << nghiem[i] << endl;
        }
        delete nghiem;
        nghiem = nullptr;
    }

    delete [] heso;
    
    heso = nullptr;

    return 0;
}
