
#include <iostream>
#include "MercurySilver.h"

using namespace std;

MercurySilver::MercurySilver() {
}

MercurySilver::~MercurySilver() {
}

MercurySilver* mercurySilver = nullptr;

MercurySilver* getMercurySilver() {
    cout << __PRETTY_FUNCTION__ << endl;
    if (mercurySilver)
        mercurySilver = new MercurySilver;
    return mercurySilver;
}
