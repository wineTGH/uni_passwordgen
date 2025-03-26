#ifndef PASSWORDGEN_H
#define PASSWORDGEN_H

#include <string>
#include <random>
#include <ctime>
#include <climits>

namespace PasswordGenerator {
    std::string generate_password(int length, bool use_digits, bool use_special_chars, bool random_case);
}

#endif