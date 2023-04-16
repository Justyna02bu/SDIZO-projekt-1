
#include "Czaso.h"
#include <chrono>

//Imię i nazwisko: Justyna Bułach 262902
//Grupa projektowa: K03-37p – wtorek 15: 15 P
//Prowadzący: mgr inż. Antoni Sterna

using namespace std;

void Czaso::Start() {
    start = chrono::steady_clock::now();
}

void Czaso::Stop() {
    stop = chrono::steady_clock::now();
}


void Czaso::Zmierzony_czas() const {
	long zmierzony_czas = chrono::duration_cast<chrono::nanoseconds>(Czaso::stop - Czaso::start).count();
	cout << "Czasomierz wykonania: " << zmierzony_czas << "ns" << endl;
}

long Czaso::czas_do_pliku() const {
	long zmierzony_czas = chrono::duration_cast<chrono::nanoseconds>(Czaso::stop - Czaso::start).count();
	return zmierzony_czas;
}