#include <cstring>
#include <iostream>
#include "Kernel.h"

int main()
{
    initOS();
    Kernel krnl;

    krnl.runtime();
}