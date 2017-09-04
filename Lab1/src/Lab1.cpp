#include "stdafx.h"

int n;

namespace space { int n = 1; }

int main() {
    setlocale(LC_CTYPE, ".1251");
    setlocale(LC_MONETARY, ".1251");
    cout << "global variables example " << n << " " << space::n << endl;
    char c = 'A';
    c = 0x42;
    cout << "66th letter " << c << endl;
    c = -1;
    cout << "-1 equals " << c << endl;
    //c = CHAR_BIT;
    //cout << "CHAR_BIT size = " << c << endl;

    wchar_t cw = L'Ф';
    size_t ns = sizeof(cw);
    cout << "cw equals " << cw << " size of wchar is " << ns << endl;
    //Думал, будет 2 байта. Оказалось, 4.

    unsigned char uc = 0x41;
    cout << "unsigned char: " << uc << " ";
    uc = 'B';
    cout << uc << endl;
    
    int i = 1;
    cout << "int: " << i << " ";
    i = -1;
    cout << i << endl;

    unsigned int ui = 1;
    cout << "unsigned int: " << ui << " ";
    ui = -1;
    cout << ui << endl;
 
    short s = 0xffff;
    cout << "short: " << s << " ";
    s = short(0xffff);
    cout << s << " ";
    s = 1;
    cout << s << endl;
    //Здесь обещали warning. Не нашел.

    unsigned short us = 0xffff;
    cout << "unsigned short: " << us << " ";
    us = 5;
    cout << us  << endl;

    long l = 0xffffffff;
    cout << "long: " << l << " ";
    l = -128;
    cout << l << endl;

    l = FLT_MAX_EXP;
    cout << "FLT_MAX_EXP = " << l << endl;

    

    return 0;
}
