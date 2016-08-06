/*
 * main.cpp
 *
 *  Created on: Aug 5, 2016
 *      Author: pavel
 */

#include <dlfcn.h>

#include <memory>
#include <stdexcept>
#include <iostream>

#include <ffi.h>

#include <MercurySilver.h>

using namespace std;

int main(int argc, char **argv) {
    try {
        unique_ptr<void, void (*)(void*)> libHandle(dlopen("./libMercurySilver.so", RTLD_LAZY), [](void* h) {
            dlclose(h);
        });

        void* getMercurySilver = dlsym(libHandle.get(), "getMercurySilver");

        cout << "getMercurySilver " << (getMercurySilver ? "success" : "fail") << endl;

        ffi_cif cif;
        if (ffi_prep_cif(&cif, FFI_DEFAULT_ABI, 0, &ffi_type_pointer, nullptr) != FFI_OK)
            throw runtime_error("can't prepare cif");

        MercurySilver* ms = nullptr;
        ffi_call(&cif, FFI_FN(getMercurySilver), &ms, nullptr);

        cout << "MercurySilver pointer " << hex << ms << endl;

        return 0;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

