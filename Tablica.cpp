#include <iostream>
#include "Tablica.h"

//Imię i nazwisko: Justyna Bułach 262902
//Grupa projektowa: K03-37p – wtorek 15: 15 P
//Prowadzący: mgr inż. Antoni Sterna

using namespace std;


//Konstruktor
Tablica::Tablica() {

    Tablica::wskaznik = nullptr;
    Tablica::rozmiar = 0;

}

//Destruktor
Tablica::~Tablica() {
        delete[]wskaznik;
}

void Tablica::dodaj_na_poczatek(int wartosc) {

    //Alokowanie pamięci na tablicę o jeden większą
    int* nowy_wskaznik = new int[rozmiar + 1];

    //Przypisanie nowego pierwszego elementu
    nowy_wskaznik[0] = wartosc;

    //Przepisanie danych ze starej tablicy do nowej
    for (int i = 0; i < rozmiar; i++) {
        nowy_wskaznik[i + 1] = wskaznik[i];
    }

    //Zwalnianie pamięci po starej tablicy
    delete wskaznik;

    wskaznik = nowy_wskaznik;

    rozmiar++;

}

void Tablica::dodaj_na_koniec(int wartosc) {

    //Alokowanie pamięci na tablicę o jeden większą
    int* nowy_wskaznik = new int[rozmiar + 1];

    //Przypisanie nowego ostatniego elementu
    nowy_wskaznik[rozmiar] = wartosc;

    //Przepisanie danych ze starej tablicy do nowej
    for (int i = 0; i < rozmiar; i++) {
        nowy_wskaznik[i] = wskaznik[i];
    }

    //Zwolnienie pamięci po starej tablicy
    delete wskaznik;


    wskaznik = nowy_wskaznik;


    rozmiar++;

}

void Tablica::dodaj_na_pozycje(int wartosc, int pozycja) {
    //Sprawdzanie czy taka pozycja jest w tablicy
    if (pozycja < 0 || pozycja > rozmiar) {
        cout << "W tablicy nie istnieje pozycja [" << pozycja << "]!" << endl;
    }
    else {

        //Alokowanie pamięci na tablicę o jeden większą
        int* nowy_wskaznik = new int[rozmiar + 1];

        //Przepisanie wartości jako elementy_listy tablicy na wybranej pozycji
        nowy_wskaznik[pozycja] = wartosc;

        //Przepisanie danych przed pozycją ze starej do nowej tablicy
        for (int i = 0; i < pozycja; i++) {
            nowy_wskaznik[i] = wskaznik[i];
        }

        //Przepisanie danych po pozycji ze starej do nowej tablicy
        for (int i = pozycja; i < rozmiar; i++) {
            nowy_wskaznik[i + 1] = wskaznik[i];
        }


        delete wskaznik;


        wskaznik = nowy_wskaznik;


        rozmiar++;

    }

}

void Tablica::usun_ostatni() {
    //Sprawdzanie, czy tablica nie jest pusta
    if (rozmiar > 0) {
        //Alokowanie pamięci na tablicę o jeden mniejszą
        int* nowy_wskaznik = new int[rozmiar - 1];

        //Przepisanie elementów starej tablicy bez ostatniego
        for (int i = 0; i < rozmiar - 1; i++) {
            nowy_wskaznik[i] = wskaznik[i];
        }

        //Zwalnianie pamięci po starej tablicy
        delete[] wskaznik;


        wskaznik = nowy_wskaznik;
        rozmiar--;
    }
    else {
        cout << "tablica jest pusta" << endl;
    }

}

void Tablica::usun_pierwszy() {

    //Sprawdzam, czy tablica nie jest pusta
    if (rozmiar > 0) {
        //Alokowanie pamięci na tablicę o jeden mniejszą
        int* nowy_wskaznik = new int[rozmiar - 1];

        //Przepisanie elementów starej tablicy bez pierwszego
        for (int i = 0; i < rozmiar - 1; i++) {
            nowy_wskaznik[i] = wskaznik[i + 1];
        }

        //Zwalnianie pamięci po starej tablicy
        delete[] wskaznik;


        wskaznik = nowy_wskaznik;


        rozmiar--;
    }
    else {
        cout << "W tablicy nie ma żadnego elementu!" << endl;
    }

}

void Tablica::usun_na_pozycji(int pozycja) {
    //Sprawdzanie, czy tablica nie jest pusta i czy pozycja jest prawidłowa
    if (rozmiar > 0 || pozycja > 0 || pozycja < rozmiar) {
        //Alokowanie pamięci na tablicę o jeden mniejszą
        int* nowy_wskaznik = new int[rozmiar - 1];

        //Przepisanie danych do pozycji ze starej do nowej tablicy
        for (int i = 0; i < pozycja; i++) {
            nowy_wskaznik[i] = wskaznik[i];
        }

        //Przepisanie danych po pozycji ze starej do nowej tablicy
        for (int i = pozycja; i < rozmiar - 1; i++) {
            nowy_wskaznik[i] = wskaznik[i + 1];
        }

        //Zwalnianie pamięci po starej tablicy
        delete[] wskaznik;


        wskaznik = nowy_wskaznik;
        rozmiar--;
    }
    else {
        cout << "Nie ma takiej pozycji" << endl;
    }
}

bool Tablica::znajdz_element(int wartosc) {

    //Szukanie elementu
    for (int i = 0; i < rozmiar; i++) {
        if (wskaznik[i] == wartosc) {
            cout << "wartosc jest na pozcyji: " << i << endl;
            return true;
        }
    }

    cout << "Nie ma takiej wartości w tablicy" << endl;
    return false;
}

void Tablica::wypisz_tablice() {
    cout << "Tablica:" << endl;

    //Sprawdzanie czy wskaznik nie jest null i wypisanie tablicy
    if (wskaznik != nullptr) {
        for (int i = 0; i < rozmiar; i++) {
            cout << "    [" << i << "] " << wskaznik[i] << endl;
        }
    }
    else {
        cout << "Tablica nie ma żadnych elementów" << endl;
    }
}

void Tablica::zapisz() {
    string daneWyjsciowe;
    ofstream plikWyjsciowy;
    daneWyjsciowe = "tablica.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    plikWyjsciowy << rozmiar << endl;
    for (int i = 0; i < rozmiar; i++) {
        plikWyjsciowy << wskaznik[i] << endl;
    }
    plikWyjsciowy.clear();
    plikWyjsciowy.close();
}

