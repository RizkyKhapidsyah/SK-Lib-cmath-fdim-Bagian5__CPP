#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
#include <conio.h>

/*
    Source by CPPReference
    Modified For Learn by RK
    I.D.E : VS2019
*/

int main() {
    std::cout << "fdim(4, 1) = " << std::fdim(4, 1)
        << " fdim(1, 4) = " << std::fdim(1, 4) << '\n'
        << "fdim(4,-1) = " << std::fdim(4, -1)
        << " fdim(1,-4) = " << std::fdim(1, -4) << '\n';
    
    // penanganan error / kesalahan
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "fdim(1e308, -1e308) = " << std::fdim(1e308, -1e308) << '\n';
    
    if (errno == ERANGE) {
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    }
        
    if (std::fetestexcept(FE_OVERFLOW)) {
        std::cout << "    FE_OVERFLOW raised\n";
    }
    
    _getch();
    return 0;
}