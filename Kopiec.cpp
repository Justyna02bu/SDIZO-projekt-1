#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Kopiec.h"

//Imię i nazwisko: Justyna Bułach 262902
//Grupa projektowa: K03-37p – wtorek 15: 15 P
//Prowadzący: mgr inż. Antoni Sterna

using namespace std;



// Poprawia struktrurę aby był zachowany warunek kopca
void Kopiec::popraw(int indeks) {
    int lewy = indeks * 2 + 1;
    int prawy = indeks * 2 + 2;
    int najwiekszy = indeks;

    if (lewy < kopiec.size() && kopiec[lewy] > kopiec[najwiekszy]) {
        najwiekszy = lewy;
    }

    if (prawy < kopiec.size() && kopiec[prawy] > kopiec[najwiekszy]) {
        najwiekszy = prawy;
    }

    if (najwiekszy != indeks) {
        swap(kopiec[indeks], kopiec[najwiekszy]);
        popraw(najwiekszy);
    }
}



void Kopiec::dodaj(int value) {
    kopiec.push_back(value);

    int index = kopiec.size() - 1;
    int rodzic = (index - 1) / 2;

    while (index > 0 && kopiec[rodzic] < kopiec[index]) {
        swap(kopiec[rodzic], kopiec[index]);
        index = rodzic;
        rodzic = (index - 1) / 2;
    }
    rozmiar_kopca++;
}

int Kopiec::usun_ze_szczytu() {
    if (kopiec.empty()) {
        cerr << "Kopiec jest pusty" << endl;
        return -1;
    }

    int szczyt = kopiec[0];
    kopiec[0] = kopiec.back();
    kopiec.pop_back();
    popraw(0);

    rozmiar_kopca--;
    return szczyt;
}

void Kopiec::wypisz_kopiec() {
    for (int i : kopiec) {
        cout << i << " ";
    }
    cout << endl;
}

void Kopiec::wypisz_kopiec2() {
    int n = 0;
    for (int i = 0; i < kopiec.size(); ++i) {
        if(i+1 == pow(2,n)){
            cout << "\n";
            n++;
        }
        for (int j = 1; j < 15/(n+1); ++j){
            cout <<  " ";
        }
        cout << kopiec[i] << " ";
    }
    cout << endl;
}


void Kopiec::czy_istnieje(int wartosc) {
    for (int i = 0; i < kopiec.size(); ++i) {
        if (kopiec[i] == wartosc) {
            cout << "wartosc jest na pozycji: " << i << endl;
            return;
        }
    }
    cout << "Nie ma takiej wartości w kopcu" << endl;
}

void Kopiec::zapisz() {
    string daneWyjsciowe;
    ofstream plikWyjsciowy;
    daneWyjsciowe = "kopiec.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    plikWyjsciowy << rozmiar_kopca << endl;
    for (int i = 0; i < rozmiar_kopca; i++) {
        plikWyjsciowy << kopiec[i] << endl;
    }
    plikWyjsciowy.close();
}
