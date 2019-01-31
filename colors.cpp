#include <iostream>

const int RMASK = 0xFF0000; //0000000011111110000000000000000
const int GMASK = 0x00FF00; //0000000000000001111111100000000
const int BMASK = 0x0000FF; //0000000000000000000000011111111

using namespace std;

int inputSelectedColor(){
    int a = 0;
    cout << "Select color number to convert: ";
    cin >> a;
    cout << endl;

    if(a > 16777215 || a < 0){
        cout << "Color out of #FFFFFF range" << endl;
        return 0;
    }
    else
        return a;
}

void showHex(int a){
    cout << hex << a;
}

void showDec(int a){
    cout << dec << a;
}


int main(){
    int a = inputSelectedColor();

    cout << "Input:" << endl;
    cout << "r=";
    int r = (RMASK & a) >> 16;
    showDec(r);
    cout << endl;
    cout << "g=";
    int g = (GMASK & a) >> 8;
    showDec(g);
    cout << endl;
    cout << "b=";
    int b = (BMASK & a);
    showDec(b);
    cout << endl;
    cout << endl;
    cout << "#";
    showHex(r);
    showHex(g);
    showHex(b);
    cout << endl;
    cout << endl;
    cout << "Output:" << endl;
    cout << "g=";
    showDec(g);
    cout << endl;
    cout << "r=";
    showDec(r);
    cout << endl;
    cout << "b=";
    showDec(b);
    cout << endl;
    cout << endl;
    cout << "#";
    showHex(g);
    showHex(r);
    showHex(b);
    cout << endl;
    cout << endl;
    cout << dec << (g << 16)+(r << 8)+b;
    cout << endl;
    cout << endl;
}
