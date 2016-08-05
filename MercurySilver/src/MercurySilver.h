#pragma once

class MercurySilver {
public:
    MercurySilver();
    virtual ~MercurySilver();
};

extern "C" {
MercurySilver* getMercurySilver();
}
