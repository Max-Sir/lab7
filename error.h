#pragma once
#include "imports.h"
class Exception {
private:
    string warning;
public:
    Exception() {
        warning = "";
    }
    Exception(string ex) {
        warning = ex;
    }
    void what() const
    {
            cerr << warning;
    }
};