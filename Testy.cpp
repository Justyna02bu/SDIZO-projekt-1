#include <iostream>
#include <fstream>
#include <cstdlib> // funckje systemowe
#include <direct.h> //mkdir w windows
#include <random>
#include "Czaso.h"
#include "Tablica.h"
#include "Lista.h"
#include "Testy.h"
#include "Kopiec.h"
#include "Drzewo.h"
using namespace std;

//Imię i nazwisko: Justyna Bułach 262902
//Grupa projektowa: K03-37p – wtorek 15: 15 P
//Prowadzący: mgr inż. Antoni Sterna

int losuj(int rozmiar) {
    if (rozmiar == 0) {
        return 0;
    }
    int val, min, max;
    random_device rd; // non-deterministic generator
    mt19937 gen(rd()); // random engine seeded with rd()
    // 1 and 1000000 inclusive
    if(rozmiar == 10000){
        uniform_int_distribution<> dist(-2500000, 2500000); // distribute results between
        max = INT_MAX;
        min = INT_MIN;
        val = dist(gen); // pass the generator to the distribution
        if (val < min)
            val = min;
        if (val > max)
            val = max;
    }
    else
    {
        max = rozmiar - 1;
        min = 0;
        uniform_int_distribution<> dist(0, (rozmiar)); // distribute results between
        val = dist(gen); // pass the generator to the distribution
        if (val < min)
            val = min;
        if (val > max)
            val = max;
    }

    return val;
}

void Testy::start(int wielkosc) {
    string daneWyjsciowe;
    ofstream plikWyjsciowy;
    daneWyjsciowe = "wejscie_100.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
   for (int i = 0; i < wielkosc; i++) {
       plikWyjsciowy << losuj(10000) << endl;
   }

    plikWyjsciowy.close();
}


void Testy::testTablicy() {
    srand(time(NULL));
    Czaso czas;
    Tablica tablica;
    int wartosc;
    // pliki wejściowe i wyjściowe
    string daneWyjsciowe;
    string daneWejsciowe = "wejscie_100.txt";
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;


    plikWejsciowy.open(daneWejsciowe);
    if (plikWejsciowy.is_open()) {
        cout << "Otwarto plik " << daneWejsciowe << endl;
    }
    else {
        cout << "Nie udało się otworzyć pliku wejściowego" << endl;
        return;
    }

    cout << "Uruchomiono Test tablicy " << endl;

    const char* folder = "Wyniki_tablicy";
    _mkdir(folder);
    _chdir(folder);

    cout << "dodaj na początek";
    daneWyjsciowe = "dodaj_na_poczotek_tablica.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    //Wykonanie funkcji z pomiarem
    czas.Start();
    while (plikWejsciowy.good()) {
        //Wczytanie wartośći z pliku
        plikWejsciowy >> wartosc;

        tablica.dodaj_na_poczatek(wartosc);

    }
    czas.Stop();
    plikWyjsciowy.seekp( 0, ios_base::end );
    //Zapisanie do pliku wynik pomiaru
    plikWyjsciowy << czas.czas_do_pliku() << endl;
    plikWyjsciowy.close();
    plikWejsciowy.clear();

    cout << "Dodaj na koniec";
    daneWyjsciowe = "dodaj_na_koniec_tablica.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    plikWejsciowy.seekg(0, std::ios::beg);
    czas.Start();
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        tablica.dodaj_na_koniec(wartosc);

    }
    czas.Stop();
    plikWyjsciowy.seekp( 0, ios_base::end );
    plikWyjsciowy << czas.czas_do_pliku()  << endl;
    plikWyjsciowy.close();
    plikWejsciowy.clear();

    cout << "Dodaj na pozycji";
    daneWyjsciowe = "dodaj_na_pozycje_tablica.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    plikWejsciowy.seekg(0, std::ios::beg);
    czas.Start();
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        tablica.dodaj_na_pozycje(wartosc, losuj(tablica.rozmiar));

    }
    czas.Stop();
    plikWyjsciowy.seekp( 0, ios_base::end );
    plikWyjsciowy << czas.czas_do_pliku() << endl;
    plikWyjsciowy.close();
    plikWejsciowy.clear();

    cout << "Usun pierwsze";
    daneWyjsciowe = "usun_pierwszy_tablica.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        tablica.dodaj_na_poczatek(wartosc);
    }

    plikWejsciowy.clear();
    plikWejsciowy.seekg(0, std::ios::beg);
    czas.Start();
    while (plikWejsciowy.good()) {
        //Wypełnianie tablicy wartościami

        plikWejsciowy >> wartosc;

        tablica.usun_pierwszy();

    }
    czas.Stop();
    plikWyjsciowy.seekp( 0, ios_base::end );
    plikWyjsciowy << czas.czas_do_pliku() << endl;
    plikWyjsciowy.close();
    plikWejsciowy.clear();

    cout << "Usun ostanie";
    daneWyjsciowe = "usun_ostatni_tablica.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        tablica.dodaj_na_poczatek(wartosc);
    }
    plikWejsciowy.clear();
    plikWejsciowy.seekg(0, std::ios::beg);
    czas.Start();
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        tablica.usun_ostatni();
        czas.Stop();

    }
    czas.Stop();
    plikWyjsciowy.seekp( 0, ios_base::end );
    plikWyjsciowy << czas.czas_do_pliku() << endl;
    plikWyjsciowy.close();
    plikWejsciowy.clear();

    cout << "Usun na pozycji";
    daneWyjsciowe = "usun_na_pozycji_tablica.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        tablica.dodaj_na_poczatek(wartosc);
    }
    plikWejsciowy.clear();
    plikWejsciowy.seekg(0, std::ios::beg);
    czas.Start();
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        tablica.usun_na_pozycji(losuj(tablica.rozmiar));
    }
    czas.Stop();
    plikWyjsciowy.seekp( 0, ios_base::end );
    plikWyjsciowy << czas.czas_do_pliku() << endl;
    plikWyjsciowy.close();

    char sciezka_wyjscia[1024];
    if (getcwd(sciezka_wyjscia, sizeof(sciezka_wyjscia)) != nullptr) {
        cout << "Dane wyjściowe zapisano w: " << sciezka_wyjscia << endl;
    }
    else {
        cerr << "Nie udało się otworzyć ścieżki.\n";
        return;
    }

    plikWejsciowy.close();
    chdir("..");
}

void Testy::testListy() {
    Czaso czas;
    Lista lista;
    int wartosc;
    string daneWyjsciowe;
    string daneWejsciowe = "wejscie_100.txt";
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    plikWejsciowy.open(daneWejsciowe);
    if (plikWejsciowy.is_open()) {
        cout << "Otwarto plik " << daneWejsciowe << endl;
    }
    else {
        cout << "Nie udało się otworzyć pliku wejściowego" << endl;
        return;
    }

    cout << "Uruchomiono Test listy " << endl;

    const char* folder = "Wyniki_listy";
    _mkdir(folder);
    _chdir(folder);

    cout << "Dodaj na poczatek";
    daneWyjsciowe = "dodaj_na_poczatek_lista.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    //Wykonanie funkcję z pomiarem
    czas.Start();
    while (plikWejsciowy.good()) {
        //Wczytannie wartosc z pliku
        plikWejsciowy >> wartosc;

        lista.dodaj_na_poczatek(wartosc);

    }
    czas.Stop();
    //Zapisaie do pliku wynik pomiaru
    plikWyjsciowy.seekp( 0, ios_base::end );
    plikWyjsciowy << czas.czas_do_pliku() << endl;
    plikWyjsciowy.close();
    plikWejsciowy.clear();

    cout << "Dodaj na koniec";
    daneWyjsciowe = "dodaj_na_koniec_lista.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    plikWejsciowy.seekg(0, std::ios::beg);
    czas.Start();
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        lista.dodaj_na_koniec(wartosc);

    }
    czas.Stop();
    plikWyjsciowy.seekp( 0, ios_base::end );
    plikWyjsciowy << czas.czas_do_pliku()  << endl;
    plikWyjsciowy.close();
    plikWejsciowy.clear();

    cout << "Dodaj na pozycji";
    daneWyjsciowe = "dodaj_na_pozycje_lista.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    plikWejsciowy.seekg(0, std::ios::beg);
    czas.Start();
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        lista.dodaj_na_pozycje(wartosc, 0);

    }
    czas.Stop();
    plikWyjsciowy.seekp( 0, ios_base::end );
    plikWyjsciowy << czas.czas_do_pliku() << endl;
    plikWyjsciowy.close();
    plikWejsciowy.clear();

    cout << "Usun pierwsze";
    daneWyjsciowe = "usun_pierwszy_lista.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        lista.dodaj_na_poczatek(wartosc);
    }
    plikWejsciowy.clear();
    plikWejsciowy.seekg(0, std::ios::beg);
    czas.Start();
    while (lista.rozmiar > 0) {

        lista.usun_pierwszy();

    }
    czas.Stop();
    plikWyjsciowy.seekp( 0, ios_base::end );
    plikWyjsciowy << czas.czas_do_pliku() << endl;
    plikWyjsciowy.close();
    plikWejsciowy.clear();

    cout << "ostatnie";
    daneWyjsciowe = "usun_ostatni_lista.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        lista.dodaj_na_poczatek(wartosc);
    }
    plikWejsciowy.clear();
    plikWejsciowy.seekg(0, std::ios::beg);
    czas.Start();
    while (lista.rozmiar > 0) {
        plikWejsciowy >> wartosc;

        lista.usun_ostatni();

    }
    czas.Stop();
    plikWyjsciowy.seekp( 0, ios_base::end );
    plikWyjsciowy << czas.czas_do_pliku() << endl;
    plikWyjsciowy.close();
    plikWejsciowy.clear();

    cout << "Usun na pozycji";
    daneWyjsciowe = "usun_na_pozycji_lista.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        lista.dodaj_na_poczatek(wartosc);
    }
    plikWejsciowy.clear();
    plikWejsciowy.seekg(0, std::ios::beg);
    czas.Start();
    int a = lista.rozmiar;
    while (a > 0) {
        int b = losuj(a);
        lista.usun_na_pozycji(b);
        a--;
    }
    czas.Stop();
    plikWyjsciowy.seekp( 0, ios_base::end );
    plikWyjsciowy << czas.czas_do_pliku() << endl;
    plikWyjsciowy.close();
    plikWejsciowy.clear();


    // Wypisanie ścieżki w której zapisano plik
    char sciezka_wyjscia[1024];
    if (getcwd(sciezka_wyjscia, sizeof(sciezka_wyjscia)) != nullptr) {
        cout << "Dane wyjściowe zapisano w: " << sciezka_wyjscia << '\n';
    }
    else {
        cerr << "Nie udało sie otworzyć ścieżki.\n";
        return;
    }

    plikWejsciowy.close();
    plikWejsciowy.clear();

    //Powrót do nadrzędnej lokacji
    chdir("..");
}



void Testy::testKopca() {
    Czaso czas;
    Kopiec kopiec;
    int wartosc;
    string daneWyjsciowe;
    string daneWejsciowe = "wejscie_100.txt";
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    plikWejsciowy.open(daneWejsciowe);
    if (plikWejsciowy.is_open()) {
        cout << "Otwarto plik " << daneWejsciowe << endl;
    }
    else {
        cout << "Nie udało się otworzyć pliku wejściowego" << endl;
        return;
    }

    cout << "Uruchomiono Test Kopca " << endl;

    const char* folder = "Wyniki_kopiec";
    _mkdir(folder);
    _chdir(folder);

    cout << "Dodaje";
    daneWyjsciowe = "dodaj_kopiec.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    czas.Start();
    while (plikWejsciowy.good()) {
        //Wczytanie wartosc z pliku
        plikWejsciowy >> wartosc;
        //Wykonanie funkcję z pomiarem
        kopiec.dodaj(wartosc);

    }
    czas.Stop();
    //Zapisanie do pliku wyniku pomiaru
    plikWyjsciowy.seekp( 0, ios_base::end );
    plikWyjsciowy << czas.czas_do_pliku() << endl;
    plikWyjsciowy.close();
    plikWejsciowy.clear();

    cout << "Usuwanie";
    daneWyjsciowe = "usun_kopiec.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        kopiec.dodaj(wartosc);
    }
    plikWejsciowy.seekg(0, std::ios::beg);
    plikWejsciowy.clear();
    czas.Start();
    while (kopiec.rozmiar_kopca > 0) {

        kopiec.usun_ze_szczytu();

    }
    czas.Stop();
    plikWyjsciowy.seekp( 0, ios_base::end );
    plikWyjsciowy << czas.czas_do_pliku() << endl;
    plikWyjsciowy.close();
    plikWejsciowy.clear();

    cout << "Przeszukuje";
    daneWyjsciowe = "przeszukaj_kopiec.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        kopiec.dodaj(wartosc);
    }
    plikWejsciowy.clear();
    plikWejsciowy.seekg(0, std::ios::beg);
    czas.Start();
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;


        kopiec.czy_istnieje(wartosc);

    }
    czas.Stop();
    plikWyjsciowy.seekp( 0, ios_base::end );
    plikWyjsciowy << czas.czas_do_pliku() << endl;
    plikWyjsciowy.close();
    plikWejsciowy.clear();

    char sciezka_wyjscia[1024];
    if (getcwd(sciezka_wyjscia, sizeof(sciezka_wyjscia)) != nullptr) {
        cout << "Dane wyjściowe zapisano w: " << sciezka_wyjscia << '\n';
    }
    else {
        cerr << "Nie udało sie otworzyć ścieżki.\n";
        return;
    }

    plikWejsciowy.close();
    plikWejsciowy.clear();

    chdir("..");
}

void Testy::testDrzewa() {
    Czaso czas;
    Drzewo drzewo;
    int wartosc;
    string daneWyjsciowe;
    string daneWejsciowe = "wejscie_100.txt";
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    plikWejsciowy.open(daneWejsciowe);
    if (plikWejsciowy.is_open()) {
        cout << "Otwarto plik " << daneWejsciowe << endl;
    }
    else {
        cout << "Nie udało się otworzyć pliku wejściowego" << endl;
        return;
    }

    cout << "Uruchomiono Test Kopca " << endl;

    const char* folder = "Wyniki_drzewo";
    _mkdir(folder);
    _chdir(folder);

    cout << "Dodaje";
    daneWyjsciowe = "dodaj_drzewo.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    //Wykonanie funkcję z pomiarem
    czas.Start();
    while (plikWejsciowy.good()) {
        //Wczytanie wartosc z pliku
        plikWejsciowy >> wartosc;

        drzewo.dodaj(wartosc);

    }
    czas.Stop();
    //Zapisanie do pliku wyniku pomiaru
    plikWyjsciowy.seekp( 0, ios_base::end );
    plikWyjsciowy << czas.czas_do_pliku() << endl;
    plikWyjsciowy.close();
    plikWejsciowy.clear();


    cout << "Usuwanie";
    daneWyjsciowe = "usun_drzewo.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        drzewo.dodaj(wartosc);
    }
    plikWejsciowy.clear();
    plikWejsciowy.seekg(0, std::ios::beg);
    czas.Start();
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        drzewo.usun(wartosc);
    }
    czas.Stop();
    plikWyjsciowy.seekp( 0, ios_base::end );
    plikWyjsciowy << czas.czas_do_pliku() << endl;
    plikWyjsciowy.close();
    plikWejsciowy.clear();

    cout << "Przeszukuje";
    daneWyjsciowe = "przeszukaj_drzewo.txt";
    plikWyjsciowy.open(daneWyjsciowe, ios::app);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        drzewo.dodaj(wartosc);
    }
    plikWejsciowy.clear();
    plikWejsciowy.seekg(0, std::ios::beg);
    czas.Start();
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        drzewo.przeszukaj(wartosc);
    }
    czas.Stop();
    plikWyjsciowy.seekp( 0, ios_base::end );
    plikWyjsciowy << czas.czas_do_pliku() << endl;
    plikWyjsciowy.close();
    plikWejsciowy.clear();

    char sciezka_wyjscia[1024];
    if (getcwd(sciezka_wyjscia, sizeof(sciezka_wyjscia)) != nullptr) {
        cout << "Dane wyjściowe zapisano w: " << sciezka_wyjscia << '\n';
    }
    else {
        cerr << "Nie udało sie otworzyć ścieżki.\n";
        return;
    }

    plikWejsciowy.close();
    plikWejsciowy.clear();

    chdir("..");
}

void Testy::przedziel(int wartosc, int nr){
    string daneWyjsciowe;
    ofstream plikWyjsciowy;
    const char* folder1 = "Wyniki_tablicy";
    const char* folder2 = "Wyniki_listy";
    const char* folder3 = "Wyniki_kopiec";
    const char* folder4 = "Wyniki_drzewo";

    switch (nr) {
        case 1:
            _mkdir(folder1);
            _chdir(folder1);
            daneWyjsciowe = "dodaj_na_poczotek_tablica.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            daneWyjsciowe = "dodaj_na_koniec_tablica.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            daneWyjsciowe = "dodaj_na_pozycje_tablica.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            daneWyjsciowe = "usun_na_pozycji_tablica.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            daneWyjsciowe = "usun_pierwszy_tablica.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            daneWyjsciowe = "usun_ostatni_tablica.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            chdir("..");
            break;
        case 2:
            _mkdir(folder2);
            _chdir(folder2);
            daneWyjsciowe = "dodaj_na_poczatek_lista.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            daneWyjsciowe = "dodaj_na_koniec_lista.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            daneWyjsciowe = "dodaj_na_pozycje_lista.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            daneWyjsciowe = "usun_na_pozycji_lista.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            daneWyjsciowe = "usun_pierwszy_lista.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            daneWyjsciowe = "usun_ostatni_lista.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            chdir("..");
            break;
        case 3:
            _mkdir(folder3);
            _chdir(folder3);
            daneWyjsciowe = "dodaj_kopiec.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            daneWyjsciowe = "przeszukaj_kopiec.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            daneWyjsciowe = "usun_kopiec.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            chdir("..");
            break;
        case 4:
            _mkdir(folder4);
            _chdir(folder4);
            daneWyjsciowe = "dodaj_drzewo.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            daneWyjsciowe = "przeszukaj_drzewo.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            daneWyjsciowe = "usun_drzewo.txt";
            plikWyjsciowy.open(daneWyjsciowe, ios::app);
            plikWyjsciowy.seekp( 0, ios_base::end );
            plikWyjsciowy << "---" << wartosc << "---" << endl;
            plikWyjsciowy.close();
            chdir("..");
            break;
    }
}