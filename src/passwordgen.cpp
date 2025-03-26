#include "passwordgen.h"

static std::string PasswordGenerator::generate_password(int length, bool use_digits, bool use_special_chars, bool random_case) {
    const std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string digits = "0123456789";
    const std::string special = "!@#$%^&*()-_=+[]{}|;:,.<>?/";
    
    std::string char_pool = lowercase;
    
    // Добавляем символы в зависимости от флагов
    if (random_case) {
        char_pool += uppercase;
    }
    if (use_digits) {
        char_pool += digits;
    }
    if (use_special_chars) {
        char_pool += special;
    }
    
    // Инициализация генератора случайных чисел
    std::mt19937 rng(std::time(nullptr));
    std::uniform_int_distribution<size_t> dist(0, char_pool.size() - 1);
    
    std::string password;
    for (int i = 0; i < length; ++i) {
        // Если не случайный регистр и есть цифры/спецсимволы, выбираем из всей pool
        if (!random_case && (use_digits || use_special_chars)) {
            password += char_pool[dist(rng)];
        }
        // Если случайный регистр, но нет цифр и спецсимволов
        else if (random_case && !use_digits && !use_special_chars) {
            // Выбираем между верхним и нижним регистром
            std::uniform_int_distribution<int> case_dist(0, 1);
            password += case_dist(rng) ? uppercase[dist(rng) % 26] : lowercase[dist(rng) % 26];
        }
        // Во всех остальных случаях выбираем из всей pool
        else {
            password += char_pool[dist(rng)];
        }
    }
    
    return password;
}