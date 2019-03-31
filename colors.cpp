#include <iostream>

const int RMASK = 0xFF0000; //0000000011111110000000000000000
const int GMASK = 0x00FF00; //0000000000000001111111100000000
const int BMASK = 0x0000FF; //0000000000000000000000011111111
const int RPOS = 16;
const int GPOS = 8;
const int BPOS = 0;

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

void showRGB(int r, int g, int b) {
    cout << "r=";
    showDec(r);
    cout << endl;
    cout << "g=";
    showDec(g);
    cout << endl;
    cout << "b=";
    showDec(b);
    cout << endl << endl;
}

void showHexColorFormat(int r, int g, int b){
    cout << "#";
    showHex(r);
    showHex(g);
    showHex(b);
    cout << endl << endl;
}

int sumColorValues(int r, int g, int b){
    return (r << 16)+(g << 8)+b;
}

int main(){
    int a = inputSelectedColor();

    int r = (RMASK & a) >> RPOS;
    int g = (GMASK & a) >> GPOS;
    int b = (BMASK & a) >> BPOS;

    cout << "Input:" << endl;
    showRGB(r, g, b);
    showHexColorFormat(r, g, b);

    cout << "Output:" << endl;
    showRGB(g, r, b);
    showHexColorFormat(g, r, b);

    cout << dec << sumColorValues(g, r, b);
    cout << endl;  
}