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

void Informacje(const char* plik)
{
    FILE* test = fopen("test.bmp", "rb");

    if (test == nullptr)
    {
        cout << endl << "Nie udalo sie otworzyc pliku!" << endl;
    }
    else
    {
        cout << endl << "Plik otwarty!" << endl;

        fread(&Plik.Type, sizeof(Plik.Type), 1, test);
        fread(&Plik.Size, sizeof(Plik.Size), 1, test);
        fread(&Plik.Reserved1, sizeof(Plik.Reserved1), 1, test);
        fread(&Plik.Reserved2, sizeof(Plik.Reserved2), 1, test);
        fread(&Plik.OffBits, sizeof(Plik.OffBits), 1, test);

        fseek(test, 14, SEEK_SET);
        fread(&Obraz.headerSize, sizeof(Obraz.headerSize), 1, test);
        fread(&Obraz.width, sizeof(Obraz.width), 1, test);
        fread(&Obraz.height, sizeof(Obraz.height), 1, test);
        fread(&Obraz.planes, sizeof(Obraz.planes), 1, test);
        fread(&Obraz.bitPerPixel, sizeof(Obraz.bitPerPixel), 1, test);
        fread(&Obraz.compresion, sizeof(Obraz.compresion), 1, test);
        fread(&Obraz.imageSize, sizeof(Obraz.imageSize), 1, test);
        fread(&Obraz.xPelsPerMeter, sizeof(Obraz.xPelsPerMeter), 1, test);
        fread(&Obraz.yPelsPerMeter, sizeof(Obraz.yPelsPerMeter), 1, test);
        fread(&Obraz.colorUsed, sizeof(Obraz.colorUsed), 1, test);
        fread(&Obraz.colorImportant, sizeof(Obraz.colorImportant), 1, test);

        cout << endl << "INFORMACJE:" << endl << endl;

        cout << "Typ pliku: " << Plik.Type << endl
            << "Rozmiar pliku: " << Plik.Size << " bajtow" << endl
            << "Zarezerwowane 1: " << Plik.Reserved1 << endl
            << "Zarezerwowane 2: " << Plik.Reserved2 << endl
            << "Offset (poczatkowy adres bitow w tablicy pikseli): " << Plik.OffBits << endl << endl;

        cout << "Wielkosc naglowka informacyjnego: " << Obraz.headerSize << endl
            << "Szerokosc obrazu: " << Obraz.width << " pikseli" << endl
            << "Wysokosc obrazu: " << Obraz.height << " pikseli" << endl
            << "Liczba warstw kolorow: " << Obraz.planes << endl
            << "Liczba bitow na piksel: " << Obraz.bitPerPixel << endl
            << "Algorytm kompresji: " << Obraz.compresion << endl
            << "Rozmiar samego rysunku: " << Obraz.imageSize << endl
            << "Rozdzielczosc pozioma: " << Obraz.xPelsPerMeter << endl
            << "Rozdzielczosc pionowa: " << Obraz.yPelsPerMeter << endl
            << "Liczba kolorow w palecie: " << Obraz.colorUsed << endl
            << "Liczba waznych kolorow w palecie: " << Obraz.colorImportant << endl;

        fclose(test);
    }
}

void Negatyw(const char* plik)
{

}

int main(int arc, char* argv[]) 
{
 
    return 0;
}