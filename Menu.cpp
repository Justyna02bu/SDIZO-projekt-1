#include <iostream>
#include <Windows.h>
#include "Opcje.h"
#include "Testy.h"
#include "Lista.h"
#include "Kopiec.h"

//Imię i nazwisko: Justyna Bułach 262902
//Grupa projektowa: K03-37p – wtorek 15: 15 P
//Prowadzący: mgr inż. Antoni Sterna

using namespace std;


int main() {
    SetConsoleOutputCP(CP_UTF8); // Konsola ustwiona na utf-8 aby by�y Polskie litery
    cout << "Autor: Jutyna Bułach" << endl;


    Testy testy;
    Opcje opcja;
    int opcja_poczatkowa;
    int wilkosc;
    int nr;
    ifstream plikWejsciowy;
    string daneWejsciowe = " ";


    while (true) {
        cout << "Opcje:" << endl;
        cout << "1 - Tablica Dynamiczna" << endl;
        cout << "2 - Lista Dwukierunkowa" << endl;
        cout << "3 - Kopiec Binarny" << endl;
        cout << "4 - Drzewo Czerwono Czarne" << endl;
        cout << "5 - Testy" << endl;
        cout << "6 - Załaduj" << endl;
        cout << "7 - Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> opcja_poczatkowa;



        switch (opcja_poczatkowa) {
            default:
                //system("CLS");
                cout << "Błędna opcja 1" << endl << endl;
                break;
            case 1:
                cout << "Tablica dynamiczna" << endl;
                opcja.opcja_tablica(0, "");
                break;

            case 2:
                cout << "Lista dwukierunkowa" << endl;
                opcja.opcje_listy(0, "");
                break;

            case 3:
                cout << "Kopiec binarny" << endl;
                opcja.opcje_kopca(0, "");
                break;

            case 4:
                cout << "Drzewo Czerwono Czarne" << endl;
                opcja.opcje_drzewa(0, "");
                break;

            case 5:
                int opcja_testu;
                cout << "Testy do pliku" << endl;
                cout << "1 - Tablica Dynamiczna" << endl;
                cout << "2 - Lista Dwukierunkowa" << endl;
                cout << "3 - Kopiec Binarny" << endl;
                cout << "4 - Drzewo Czerwono Czarne" << endl;
                cin >> opcja_testu;
                switch (opcja_testu) {
                    case 1:
                        nr = 1;
                        wilkosc = 0;
                        for (int j = 0; j < 10; j++) {
                            switch (j) {
                                case 0:
                                    wilkosc = 200;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 1:
                                    wilkosc = 400;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 2:
                                    wilkosc = 600;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 3:
                                    wilkosc = 800;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 4:
                                    wilkosc = 1000;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 5:
                                    wilkosc = 1200;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 6:
                                    wilkosc = 1400;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 7:
                                    wilkosc = 1600;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 8:
                                    wilkosc = 1800;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 9:
                                    wilkosc = 2000;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                            }
                            for (int i = 20; i > 0; i--) {
                                testy.start(wilkosc);
                                testy.testTablicy();

                            }
                        }
                        continue;
                    case 2:
                        wilkosc = 0;
                        nr = 2;
                        for (int j = 0; j < 10; j++) {
                            switch (j) {
                                case 0:
                                    wilkosc = 200;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 1:
                                    wilkosc = 400;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 2:
                                    wilkosc = 600;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 3:
                                    wilkosc = 800;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 4:
                                    wilkosc = 1000;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 5:
                                    wilkosc = 1200;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 6:
                                    wilkosc = 1400;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 7:
                                    wilkosc = 1600;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 8:
                                    wilkosc = 1800;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 9:
                                    wilkosc = 2000;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                            }
                            for (int i = 20; i > 0; i--) {
                                testy.start(wilkosc);
                                testy.testListy();

                            }
                        }
                        continue;
                    case 3:
                        wilkosc = 0;
                        nr = 3;
                        for (int j = 0; j < 10; j++) {
                            switch (j) {
                                case 0:
                                    wilkosc = 200;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 1:
                                    wilkosc = 400;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 2:
                                    wilkosc = 600;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 3:
                                    wilkosc = 800;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 4:
                                    wilkosc = 1000;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 5:
                                    wilkosc = 1200;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 6:
                                    wilkosc = 1400;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 7:
                                    wilkosc = 1600;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 8:
                                    wilkosc = 1800;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 9:
                                    wilkosc = 2000;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                            }
                            for (int i = 20; i > 0; i--) {
                                testy.start(wilkosc);
                                testy.testKopca();

                            }
                        }
                        continue;
                    case 4:
                        wilkosc = 0;
                        nr = 4;
                        for (int j = 0; j < 10; j++) {
                            switch (j) {
                                case 0:
                                    wilkosc = 200;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 1:
                                    wilkosc = 400;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 2:
                                    wilkosc = 600;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 3:
                                    wilkosc = 800;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 4:
                                    wilkosc = 1000;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 5:
                                    wilkosc = 1200;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 6:
                                    wilkosc = 1400;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 7:
                                    wilkosc = 1600;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 8:
                                    wilkosc = 1800;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                                case 9:
                                    wilkosc = 2000;
                                    testy.przedziel(wilkosc,nr);
                                    break;
                            }
                            for (int i = 20; i > 0; i--) {
                                testy.start(wilkosc);
                                testy.testDrzewa();

                            }
                        }
                        continue;
                    default:

                        cout << "Błędna opcja 2 " << endl << endl;
                }
            case 6:
                cout << "podaj nazwę pliku z końcówką .txt" << endl;
                cin >> daneWejsciowe;
                plikWejsciowy.open(daneWejsciowe);
                if (plikWejsciowy.is_open()) {
                    cout << "Otwarto plik " << daneWejsciowe << endl;
                    cout << "Jaka to ma byc struktura?" << endl;
                    cout << "1 - tablica" << endl;
                    cout << "2 - lista" << endl;
                    cout << "3 - kopiec" << endl;
                    cout << "2 - drzewo" << endl;
                    cout << "Wybrano: ";
                    cin >> nr;

                    plikWejsciowy.close();
                    switch (nr) {
                        case 0:
                            cout << "błąd wczytania"  << endl;
                            break;
                        case 1:
                            opcja.opcja_tablica(1, daneWejsciowe);
                            break;
                        case 2:
                            opcja.opcje_listy(1, daneWejsciowe);
                            break;
                        case 3:
                            opcja.opcje_kopca(1, daneWejsciowe);
                            break;
                        case 4:
                            opcja.opcje_drzewa(1, daneWejsciowe);
                            break;
                    }
                }
                break;
            case 7:
                return 0;

        }
    }
}