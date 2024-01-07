#include <iostream>
#include <fstream>

using namespace std;

struct warzywo
{
    char rodzaj [30];
    int jakosc;
    float masa;
};


//Zadanie 2
warzywo** tablicadyn(int x, int y)
{
    warzywo **tab = new warzywo*[x];
    for(int i=0; i<y; i++)
    {
        tab[i] = new warzywo[x];
    }
    return tab;
}

//Zadanie 3
void pobieranie(warzywo& w)
{
    char rodzaj[30] = "";
    int jakosc = 0;
    float masa = 0.0;

    cout << "Podaj rodzaj: ";
    cin >> w.rodzaj;
    cout << "\nPodaj jakosc: ";
    cin >> jakosc;
    cout << "\nPodaj mase: ";
    cin >> masa;

    w.jakosc = jakosc;
    w.masa = masa;
}

//Zadanie 4
bool zapis(warzywo w[], int rozmiar, string nazwa)
{
    ofstream plik(nazwa);
    if(!plik){return false;}
    for(int i=0;i<rozmiar;i++)
    {
        plik << w[i].rodzaj << " " << w[i].jakosc << " " << w[i].masa << " " << endl;
    }
    return true;
}

//Zadanie 5 (sprawdź parzystość bitów w int)
bool parzyste(int x)
{
    int parzysta = 0;
    while(x > 0)
    {
        //parzysta + AND z pierwszego bitu z jedynką (robimy licznik jedynek)
        parzysta = parzysta + (x & 1);
        //Bit shift o jedną w prawo (np. 0110 -> 0011)
        x >>= 1;
    }
    //DEBUG
    //cout << "Parzysta: " << parzysta << "\n";

    //Reszta dzielenia z sumy jedynek przez 2
    parzysta = parzysta % 2;

    //DEBUG
    //cout << "Parzysta po mod: " << parzysta << "\n";

    //Zwracamy odwróconą wartość (bo reszta jest 1 jak liczba jest nieparzysta, a my chcemy na odwrót)
    return parzysta;
}

int main()
{
//Zad 5
cout << parzyste(3);

//Zad 1

    warzywo w;
pobieranie(w);
cout << "\nRodzaj to: " << w.rodzaj;
cout << "\nJakosc to: " << w.jakosc;
cout << "\nMasa to: " << w.masa;

//Dane do zadania 4
string nazwa;
int rozmiar = 3;
warzywo warzywa[3];

for(int i=0;i<rozmiar;i++)
{
    cout << "Podaj rodzaj: ";
    cin >> warzywa[i].rodzaj;
    cout << "\nPodaj jakosc: ";
    cin >> warzywa[i].jakosc;
    cout << "\nPodaj mase: ";
    cin >> warzywa[i].masa;
};

cout << "\nPodaj nazwe pliku: ";
cin >> nazwa;
cout << "\nPodaj rozmiar tablicy warzyw: ";
zapis(warzywa, rozmiar, nazwa);
system("pause");
}
