#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <fstream>
using namespace std;
#include "InverIndex.h"

int run()
{
	InverIndex<string> Dauvao;
	string s,ss;
	int chon;
	do {
	cout <<"\t\t\t ============MENU================================\n";
    cout <<"\t\t\t |1. Them file va noi dung                      |\n";
    cout <<"\t\t\t |2. Tim kiem And                               |\n";
    cout <<"\t\t\t |3. Tim kiem Or                                |\n";
    cout <<"\t\t\t |4. Ket thuc chuong trinh                      |\n";
    cout <<"\t\t\t ================================================\n";
    cout << "Nhap lua chon: ";
    cin >> chon;
    cin.ignore();
    switch(chon)
    {
        case 1:
            cout << "Nhap ten file: ";
            getline(std::cin,ss);
            cout << "Nhap noi dung file " << ss << ": ";
            getline(std::cin,s);
            Dauvao.Add(s,ss);
            //Dauvao.DisplayAll();
            break;
        case 2:
            cout << "Nhap cum tu tim kiem: ";
            getline(std::cin,ss);
            Dauvao.FindAnd(ss);
            break;
        case 3:
            cout <<"Nhap cac tu can tim kiem: ";
            getline(cin,ss);
            Dauvao.FindOr(ss);
            break;
        case 4:
            cout <<"Bam bat ky de ket thuc chuong trinh" << endl;
            system("pause");
            break;
        default:
                cout <<"Ban chon sai. Moi ban chon lai MENU!\n";
                break;
    }
    system("cls");
	}while(chon!=4);
	return 0;
}

int main()
{
    run();
    return 0;
}
