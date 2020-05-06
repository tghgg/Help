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
            if (heso[0] == 0)
                cout << "He so a = 0\nPhuong trinh khong hop le.\n";
            break;
            double delta = pow(heso[1], 2.0) - 4 * heso[0] * heso[2];
            if (delta < 0.0)
            {
                cout << "Phuong trinh vo nghiem\n";
                break;
            }
            else if (delta == 0.0)
            {
                cout << "Phuong trinh co nghiem kep\n";

                break;
            }
            else
            {
                cout << "Phuong trinh co 2 nghiem phan biet\n";
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

    cout << "Phuong trinh bac may!?!??!\n";
    cin >> bac;

    double *heso = new double[bac+1];

    // Nhap he so
    for (unsigned int i = 0; i <= bac; i++)
    {
        cout << "Nhap he so bac " << bac - i << "!!?!?!: ";
        cin >> heso[i];
    }

    const double *nghiem = giaiDaThuc(bac, heso);

    // Xuat nghiem
    for (unsigned int i = 0; i < bac; i++) {
        cout << "x" << i+1 << " = " << nghiem[i] << endl;
    }

    delete [] heso;
    heso = nullptr;

    return 0;
}
