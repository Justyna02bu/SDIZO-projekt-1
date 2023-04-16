#include <iostream>
#include <fstream>
#include "Opcje.h"
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include "Drzewo.h"

//Imię i nazwisko: Justyna Bułach 262902
//Grupa projektowa: K03-37p – wtorek 15: 15 P
//Prowadzący: mgr inż. Antoni Sterna

using namespace std;


void Opcje::opcja_tablica(int zal, string nazwa) {
    Czaso czas;
    Tablica tablica;
    int wybor;
    int wartosc;
    int pozycja;

    if (zal == 1){
        ifstream plikWejsciowy;
        string daneWejsciowe = nazwa;
        plikWejsciowy.open(daneWejsciowe);

        plikWejsciowy.seekg(0, std::ios::beg);

        if (plikWejsciowy.is_open()) {
            cout << "Otwarto plik " << daneWejsciowe << endl;
            int rozmiar;
            plikWejsciowy >> rozmiar;
            while (rozmiar > 0){
                plikWejsciowy >> wartosc;
                tablica.dodaj_na_koniec(wartosc);
                rozmiar --;
            }
            plikWejsciowy.clear();
            plikWejsciowy.close();
        } else{
            cout << "Nie udało się wczytać pliku" << daneWejsciowe << endl;
        }
    }

    while (true) {
        cout << "Opcje tablicy:" << endl;
        cout << "1 - Dodaj element na początek" << endl;
        cout << "2 - Dodaj element na koniec" << endl;
        cout << "3 - Dodaj element na wybranej pozycji" << endl;
        cout << "4 - Usuń element na początku" << endl;
        cout << "5 - Usuń element na końcu" << endl;
        cout << "6 - Usuń element na wybranej pozycji" << endl;
        cout << "7 - Wyszukaj element" << endl;
        cout << "8 - Wypisz tablicę" << endl;
        cout << "9 - Zapisz" << endl;
        cout << "10 - Wyjście" << endl;

        cout << endl;
        cout << "Wybór: ";
        cin >> wybor;
        cout << "Wybrano: " << wybor << endl;
        switch (wybor) {
        case 1:

            cout << "Podaj wartosc: ";
            cin >> wartosc;
            czas.Start();
            tablica.dodaj_na_poczatek(wartosc);
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 2:
            cout << "Podaj wartosc: ";
            cin >> wartosc;
            czas.Start();
            tablica.dodaj_na_koniec(wartosc);
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 3:
            cout << "Podaj wartosc: ";
            cin >> wartosc;
            cout << "Podaj pozycję: ";
            cin >> pozycja;
            czas.Start();
            tablica.dodaj_na_pozycje(wartosc, pozycja);
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 4:
            czas.Start();
            tablica.usun_pierwszy();
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 5:
            czas.Start();
            tablica.usun_ostatni();
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 6:
            cout << "Podaj pozycję: ";
            cin >> pozycja;
            czas.Start();
            tablica.usun_na_pozycji(pozycja);
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 7:
            cout << "Podaj wartosc: ";
            cin >> wartosc;
            czas.Start();
            tablica.znajdz_element(wartosc);
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 8:
            czas.Start();
            tablica.wypisz_tablice();
            czas.Stop();
            czas.Zmierzony_czas();
            break;

            case 9:
                tablica.zapisz();
                break;

            case 10:
                return;

        default:
            cout << "Błędna opcja" << endl;
            break;
        }
    }
}

void Opcje::opcje_listy(int zal, string nazwa) {
    Czaso czas;
    Lista lista;
    int wybor;
    int wartosc;
    int pozycja;

    if (zal == 1){
        ifstream plikWejsciowy;
        string daneWejsciowe = nazwa;
        plikWejsciowy.open(daneWejsciowe);

        plikWejsciowy.seekg(0, std::ios::beg);

        if (plikWejsciowy.is_open()) {
            cout << "Otwarto plik " << daneWejsciowe << endl;
            int rozmiar;
            plikWejsciowy >> rozmiar;
            while (rozmiar > 0){
                plikWejsciowy >> wartosc;
                lista.dodaj_na_koniec(wartosc);
                rozmiar --;
            }
            plikWejsciowy.clear();
            plikWejsciowy.close();
        } else{
            cout << "Nie udało się wczytać pliku" << daneWejsciowe << endl;
        }
    }

    while (true) {
        cout << "Opcje listy:" << endl;
        cout << "1 - Dodaj element na początek" << endl;
        cout << "2 - Dodaj element na koniec" << endl;
        cout << "3 - Dodaj element na na wybranej pozycji" << endl;
        cout << "4 - Usuń pierwszy element" << endl;
        cout << "5 - Usuń ostatni element" << endl;
        cout << "6 - Usuń element na wybranej pozycji" << endl;
        cout << "7 - Wyszukaj element" << endl;
        cout << "8 - Wydrukuj listę" << endl;
        cout << "9 - Zapisz" << endl;
        cout << "10 - Wyjście" << endl;
        cout << "Wybrano: ";
        cin >> wybor;


        switch (wybor) {

        case 1:
            cout << "Podaj wartosc: ";
            cin >> wartosc;
            czas.Start();
            lista.dodaj_na_poczatek(wartosc);
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 2:
            cout << "Podaj wartosc: ";
            cin >> wartosc;
            czas.Start();
            lista.dodaj_na_koniec(wartosc);
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 3:
            cout << "Podaj wartosc: ";
            cin >> wartosc;
            cout << "Podaj pozycję: ";
            cin >> pozycja;
            czas.Start();
            lista.dodaj_na_pozycje(wartosc, pozycja);
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 4:
            czas.Start();
            lista.usun_pierwszy();
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 5:
            czas.Start();
            lista.usun_ostatni();
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 6:

            cout << "Podaj pozycję: ";
            cin >> pozycja;
            czas.Start();
            lista.usun_na_pozycji(pozycja);
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 7:
            cout << "Podaj wartosc: ";
            cin >> wartosc;
            czas.Start();
            lista.znajdz_element(wartosc);
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 8:
            czas.Start();
            lista.wypisz_liste();
            czas.Stop();
            czas.Zmierzony_czas();
            break;

            case 9:
                lista.zapisz();
                break;

            case 10:
                return;

        default:
            cout << "Błędna opcja" << endl;
            break;
        }
    }
}

void Opcje::opcje_kopca(int zal, string nazwa) {
    Czaso czas;
    Kopiec kopiec;
    int wybor;
    int wartosc;

    if (zal == 1){
        ifstream plikWejsciowy;
        string daneWejsciowe = nazwa;
        plikWejsciowy.open(daneWejsciowe);

        plikWejsciowy.seekg(0, std::ios::beg);

        if (plikWejsciowy.is_open()) {
            cout << "Otwarto plik " << daneWejsciowe << endl;
            int rozmiar;
            plikWejsciowy >> rozmiar;
            while (rozmiar > 0){
                plikWejsciowy >> wartosc;
                kopiec.dodaj(wartosc);
                rozmiar --;
            }
            plikWejsciowy.clear();
            plikWejsciowy.close();
        } else{
            cout << "Nie udało się wczytać pliku" << daneWejsciowe << endl;
        }
    }


    while (true) {
        cout << "Opcje Kopca:" << endl;
        cout << "1 - Dodaj" << endl;
        cout << "2 - Usuń" << endl;
        cout << "3 - Wyszukaj" << endl;
        cout << "4 - Wypisz kopiec" << endl;
        cout << "5 - Zapisz" << endl;
        cout << "6 - Wyjście" << endl;
        cout << "Wybrano: ";
        cin >> wybor;


        switch (wybor) {
        case 1:
            cout << "Podaj wartosc: ";
            cin >> wartosc;
            czas.Start();
            kopiec.dodaj(wartosc);
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 2:
            cout << "Podaj wartosc: ";
            cin >> wartosc;
            czas.Start();
            kopiec.usun_ze_szczytu();
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 3:
            cout << "Podaj wartosc: ";
            cin >> wartosc;
            czas.Start();
            kopiec.czy_istnieje(wartosc);
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 4:
            czas.Start();
            kopiec.wypisz_kopiec();
            kopiec.wypisz_kopiec2();
            czas.Stop();
            czas.Zmierzony_czas();
            break;

        case 5:
            kopiec.zapisz();
            break;

        case 6:
            return;

        default:
            cout << "Błędna opcja" << endl;
            break;
        }
    }
}

void Opcje::opcje_drzewa(int zal, string nazwa) {
    Czaso czas;
    Drzewo drzewo;
    int wybor;
    int wartosc;

    if (zal == 1){
        ifstream plikWejsciowy;
        string daneWejsciowe = nazwa;
        plikWejsciowy.open(daneWejsciowe);

        plikWejsciowy.seekg(0, std::ios::beg);

        if (plikWejsciowy.is_open()) {
            cout << "Otwarto plik " << daneWejsciowe << endl;
            int rozmiar;
            plikWejsciowy >> rozmiar;
            while (rozmiar > 0){
                plikWejsciowy >> wartosc;
                drzewo.dodaj(wartosc);
                rozmiar --;
            }
            plikWejsciowy.clear();
            plikWejsciowy.close();
        } else{
            cout << "Nie udało się wczytać pliku" << daneWejsciowe << endl;
        }
    }


    while (true) {
        cout << "Opcje Drzewa Czerwon Czarnego:" << endl;
        cout << "1 - Dodaj" << endl;
        cout << "2 - Usuń" << endl;
        cout << "3 - Wyszukaj" << endl;
        cout << "4 - Wypisz drzewo" << endl;
        cout << "5 - Zapisz" << endl;
        cout << "6 - Wyjście" << endl;
        cout << "Wybrano: ";
        cin >> wybor;


        switch (wybor) {
            case 1:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                czas.Start();
                drzewo.dodaj(wartosc);
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 2:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                czas.Start();
                drzewo.usun(wartosc);
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 3:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                czas.Start();
                drzewo.przeszukaj(wartosc);
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 4:
                czas.Start();
                drzewo.wypisz();
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 5:
                drzewo.zapisz();
                break;

            case 6:
                return;
            default:
                cout << "Błędna opcja" << endl;
                break;
        }
    }
}