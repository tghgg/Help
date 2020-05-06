#include <iostream>
#include <cmath>
#define PI 3.14159
using namespace std;

double *giaiDaThuc(unsigned int *size, double heso[])
{
    double *nghiem;

    // cout << "He so la " << heso << endl;

    switch (*size)
    {
    case 0:
    {
        nghiem = new double[1];
        *size = 1;
        nghiem[0] = heso[0];
        break;
    }
    case 1:
    {
        nghiem = new double[1];
        nghiem[0] = (-heso[*size]) / heso[0];
        break;
    }
    case 2:
    {
        const double a = heso[0];
        if (a == 0)
        {
            nghiem = nullptr;
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
            cout << "Phuong trinh co nghiem kep\n";
            nghiem = new double[2];
            nghiem[0] = (-b) / (2.0 * a);
            nghiem[1] = nghiem[0];
            break;
        }
        else
        {
            cout << "Phuong trinh co 2 nghiem\n";
            nghiem = new double[2];
            delta = sqrt(delta);
            nghiem[0] = (-b + delta) / (2 * a);
            nghiem[1] = (-b - delta) / (2 * a);
            break;
        }
    }
    case 3:
    {
        const double a = heso[0];
        const double b = heso[1];
        const double c = heso[2];
        const double d = heso[3];

        double delta = pow(b, 2.0) - 3 * a * c;
        double k = (9.0 * a * b * c - 2.0 * pow(b, 3.0) - 27.0 * pow(a, 2.0) * d) / (2 * sqrt(fabs(pow(delta, 3.0))));

        if (delta > 0.0)
        {
            if (fabs(k) <= 1.0)
            {
                cout << "Phuong trinh co 3 nghiem\n";
                nghiem = new double[3];
                nghiem[0] = (2.0 * sqrt(delta) * cos((acos(k) / 3.0)) - b) / (3.0 * a);
                nghiem[1] = (2.0 * sqrt(delta) * cos((acos(k) / 3.0 - (2.0 * PI / 3))) - b) / (3.0 * a);
                nghiem[2] = (2.0 * sqrt(delta) * cos((acos(k) / 3.0 + (2.0 * PI / 3))) - b) / (3.0 * a);
            }
            else
            {
                cout << "Phuong trinh co nghiem duy nhat\n";
                nghiem = new double[1];
                *size = 1;
                nghiem[0] = ((sqrt(delta) * fabs(k)) / (3.0 * a * k)) * (pow(fabs(k) + sqrt(pow(k, 2.0) - 1), 1.0 / 3) + pow(fabs(k) - sqrt(pow(k, 2.0) - 1), 1.0 / 3)) - (b / (3 * a));
            }
        }
        else if (delta == 0.0)
        {
            cout << "Phuong trinh co nghiem kep\n[";
            nghiem = new double[2];
            *size = 2;
            nghiem[0] = (-b * pow(pow(b, 3.0) - 27.0 * pow(a, 2.0) * d, 1.0 / 3)) / (3.0 * a);
            nghiem[1] = nghiem[0];
        }
        else if (delta < 0.0)
        {
            cout << "Phuong trinh co 1 nghiem\n";
            nghiem = new double[1];
            *size = 1;
            nghiem[0] = (sqrt(fabs(delta)) / (3.0 * a)) * (pow(k + sqrt(pow(k, 2.0) + 1), 1.0 / 3) + pow(k - sqrt(pow(k, 2.0) + 1), 1.0 / 3)) - (b / (3 * a));
        }
        break;
    }
    default:
        cout << "Phuong trinh khong hop le\n";
    }

    return nghiem;
}

double *nhapDaThuc(unsigned int *bac)
{
    double *heso = new double[*bac + 1];

    for (unsigned int i = 0; i <= *bac; i++)
    {
        cout << "Nhap he so bac " << *bac - i << ": ";
        cin >> heso[i];
    }

    return heso;
}

int main()
{
    unsigned int *size = new unsigned int;

    cout << "Nhap so bac cua phuong trinh: ";
    cin >> *size;
    cout << endl;

    if (*size > 4) {
        cout << "Phuong trinh co bac lon hon 4. Khong hop le.\n";
        return 0;
    }

    double *heso = nhapDaThuc(size);

    const double *nghiem = giaiDaThuc(size, heso);

    // Xuat nghiem
    if (nghiem == nullptr)
        cout << "Phuong trinh vo nghiem";
    else
    {
        for (unsigned int i = 0; i < *size; i++)
        {
            cout << "x" << i + 1 << " = " << nghiem[i] << endl;
        }
    }

    delete[] heso;
    delete nghiem;
    nghiem = nullptr;
    heso = nullptr;

    return 0;
}
