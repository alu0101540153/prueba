#include "guess.hpp"

bool is_grater(int num, int secretnum) {
    if (num > secretnum) {
        return 1;
    }
    else if (num < secretnum) {
        return 0;
    }
}