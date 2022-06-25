#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits>

using namespace std;

struct PlikHeader {
    short Type;
    int Size;
    short Reserved1;
    short Reserved2;
    int OffBits;
} Plik;

struct ObrazHeader {
    int headerSize;
    int width;
    int height;
    short int planes;
    short int bitPerPixel;
    int compresion;
    int imageSize;
    int xPelsPerMeter;
    int yPelsPerMeter;
    int colorUsed;
    int colorImportant;
} Obraz;

struct KoloryRGB {
    char R;
    char G;
    char B;
} Rgb;

void Informacje()
{

}

void Negatyw()
{

}

int main(int arc, char* argv[]) 
{




    return 0;
}