#pragma once
#include <string>

struct Task {
    int num_1;
    int num_2;
    char operation;
    int answer;

    Task();
    Task(int min, int max, char operation = '\0');

    std::string to_string() const;
};