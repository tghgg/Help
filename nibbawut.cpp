#include <iostream>
#include <cmath>
#include <string>
#define PI 3.14159

using namespace std;

double * giaiDaThuc(unsigned int *size, double heso[])
{
    double *nghiem;

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
        const double delta = pow(b, 2.0) - 3.0 * a * c;
        const double k = (9.0 * a * b * c - 2.0 * pow(b, 3.0) - 27.0 * pow(a, 2.0) * d) / (2.0 * sqrt(fabs(pow(delta, 3.0))));

        if (delta > 0.0)
        {
            if (fabs(k) <= 1.0)
            {
                cout << "Phuong trinh co 3 nghiem\n";
                nghiem = new double[3];
                nghiem[0] = (2.0 * sqrt(delta) * cos((acos(k) / 3.0)) - b) / (3.0 * a);
                nghiem[1] = (2.0 * sqrt(delta) * cos((acos(k) / 3.0 - (2.0 * PI / 3.0))) - b) / (3.0 * a);
                nghiem[2] = (2.0 * sqrt(delta) * cos((acos(k) / 3.0 + (2.0 * PI / 3.0))) - b) / (3.0 * a);
            }
            else
            {
                cout << "Phuong trinh co nghiem duy nhat\n";
                nghiem = new double[1];
                *size = 1;
                nghiem[0] = ((sqrt(delta) * fabs(k)) / (3.0 * a * k)) * (pow(fabs(k) + sqrt(pow(k, 2.0) - 1.0), 1.0 / 3) + pow(fabs(k) - sqrt(pow(k, 2.0) - 1.0), 1.0 / 3)) - (b / (3.0 * a));
            }
        }
        else if (delta == 0.0)
        {
            cout << "Phuong trinh co nghiem kep\n";
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
            nghiem[0] = (sqrt(fabs(delta)) / (3.0 * a)) * (pow(k + sqrt(pow(k, 2.0) + 1.0), 1.0 / 3) + pow(k - sqrt(pow(k, 2.0) + 1.0), 1.0 / 3)) - (b / (3.0 * a));
        }
        break;
    }
    default:
        cout << "Phuong trinh khong hop le\n";
    }

    return nghiem;
}

double * nhapDaThuc(unsigned int *bac)
{
    double *heso = new double[*bac + 1];

    for (unsigned int i = 0; i <= *bac; i++)
    {
        cout << "Nhap he so bac " << *bac - i << ": ";
        cin >> heso[i];
    }

    return heso;
}

double * congDaThuc()
{
    unsigned int *size1 = new unsigned int;
    cout << "Nhap so bac cua da thuc 1: ";
    cin >> *size1;
    cout << endl;

    double *daThuc1 = nhapDaThuc(size1);

    unsigned int *size2 = new unsigned int;
    cout << "Nhap so bac cua da thuc 2: ";
    cin >> *size2;
    cout << endl;

    double *daThuc2 = nhapDaThuc(size2);

    double *daThucTong;

    if (*size1 > *size2)
    {
        daThucTong = new double[*size1];

        cout << "Da thuc tong la: ";

        for (int i = *size1; i >= 0; i--)
        {
            if (i < *size2)
            {
                daThucTong[i] = daThuc1[i] + daThuc2[i];
            }
            else
            {
                daThucTong[i] = daThuc1[i];
            }

            cout << daThucTong[i] << " ";
        }
    }
    else
    {
        daThucTong = new double[*size2];

        cout << "Da thuc tong la: ";

        for (unsigned int i = 0; i <= *size2; i++)
        {
            if (i < *size1)
            {
                daThucTong[i] = daThuc1[i] + daThuc2[i];
            }
            else
            {
                daThucTong[i] = daThuc2[i];
            }

            cout << daThucTong[i] << " ";
        }
    }

    delete size1;
    delete size2;
    delete daThuc1;
    delete daThuc2;
    size1 = nullptr;
    size2 = nullptr;
    daThuc1 = nullptr;
    daThuc2 = nullptr;

    return daThucTong;
}

int main()
{
    unsigned int hanhDong;

    // Menu
    do
    {
        cout << "Chon hanh dong de chuong trinh thuc hien:\n";
        cout << "0. Huy chuong trinh\n";
        cout << "1. Nhap da thuc\n";
        cout << "2. Giai da thuc\n";
        cout << "3. Cong 2 da thuc\n";

        cin >> hanhDong;

        switch (hanhDong)
        {
        case 0:
            break;
        case 1:
        {
            unsigned int *size = new unsigned int;

            cout << "Nhap so bac cua phuong trinh: ";
            cin >> *size;
            cout << endl;

            if (*size > 4)
            {
                cout << "Phuong trinh co bac lon hon 4. Khong hop le.\n";
                return 0;
            }

            double *heso = nhapDaThuc(size);

            // Xuat da thuc
            cout << "Da thuc vua nhap: ";
            for (unsigned int i = 0; i <= *size; i++) {
                string dau = "";
                if (heso[i] > 0 && i != 0)
                    dau = "+";

                if (*size-i == 0) {
                    cout << dau << heso[i] << " = 0\n";
                }
                else
                    cout << dau << heso[i] << "x^" << *size-i;
            }

            delete size;
            delete heso;
            size = nullptr;
            heso = nullptr;
            break;
        }
        case 2:
        {
            unsigned int *size = new unsigned int;

            cout << "Nhap so bac cua phuong trinh: ";
            cin >> *size;
            cout << endl;

            if (*size > 4)
            {
                cout << "Phuong trinh co bac lon hon 4. Khong hop le.\n";
                return 0;
            }

            double *heso = nhapDaThuc(size);

            // Xuat da thuc
            cout << "Da thuc vua nhap: ";
            for (unsigned int i = 0; i <= *size; i++) {
                string dau = "";
                if (heso[i] > 0 && i != 0)
                    dau = "+";

                if (*size-i == 0) {
                    cout << dau << heso[i] << " = 0\n";
                }
                else
                    cout << dau << heso[i] << "x^" << *size-i;
            }

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

            delete size;
            delete heso;
            delete nghiem;
            size = nullptr;
            heso = nullptr;
            nghiem = nullptr;
            break;
        }
        case 3:
        {
            congDaThuc();
            break;
        }

        default:
            cout << "Hanh dong khong hop le. Xin hay chon lai.\n";
            break;
        }
        cout << "KET THUC HANH DONG\n";
    } while (hanhDong != 0);

    cout << "KET THUC CHUONG TRINH\n";

    // system("pause");
    return 0;
}
