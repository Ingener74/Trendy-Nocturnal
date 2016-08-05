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
        ffi_status status = ffi_prep_cif(&cif, FFI_DEFAULT_ABI, 0, &ffi_type_pointer, nullptr);
        if (status == FFI_OK) {

            MercurySilver* ms = nullptr;
            ffi_call(&cif, FFI_FN(getMercurySilver), &ms, nullptr);

            cout << "MercurySilver pointer " << hex << ms << endl;

        } else {
            cerr << "can't prepare cif" << endl;
        }

//		ffi_prep_cif(&cif, )

        return 0;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

