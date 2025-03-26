#ifndef PASSWORDGEN_H
#define PASSWORDGEN_H

#include <climits>
#include <ctime>
#include <random>
#include <string>

namespace PasswordGenerator {
std::string generate_password(int length, bool use_digits,
                              bool use_special_chars, bool random_case);
}

#endif