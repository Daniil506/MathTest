#include "Task.h"
#include <cstdlib>
#include <stdexcept>
#include <utility>
#include <algorithm>

static int rand_range(int min, int max) {
    if (min > max) std::swap(min, max);
    return min + std::rand() % (max - min + 1);
}

static char rand_operation() {
    const char ops[] = { '+', '-', '*', '/' };
    return ops[std::rand() % 4];
}

static int compute(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return b != 0 ? a / b : 0;
    default:  throw std::invalid_argument("Unknown operation");
    }
}

static void generate_division(int min, int max, int& num_1, int& num_2) {
    if (min < 1) min = 1;
    if (max < min) max = min;

    num_2 = rand_range(min, max);
    if (num_2 == 0) num_2 = 1;

    int k_min = (min + num_2 - 1) / num_2;
    int k_max = max / num_2;
    if (k_min > k_max) {
        k_min = (min + num_2 - 1) / num_2;
        k_max = k_min;
    }
    int k = rand_range(k_min, k_max);
    num_1 = num_2 * k;

    if (num_2 > num_1) std::swap(num_1, num_2);
}

Task::Task() {
    operation = rand_operation();

    if (operation == '/') {
        generate_division(1, 20, num_1, num_2);
    }
    else {
        num_1 = rand_range(1, 20);
        num_2 = rand_range(1, 20);
    }

    answer = compute(num_1, num_2, operation);
}

Task::Task(int min, int max, char operation) {
    if (min > max) std::swap(min, max);
    this->operation = (operation == '\0') ? rand_operation() : operation;

    if (this->operation == '/') {
        generate_division(min, max, num_1, num_2);
    }
    else {
        num_1 = rand_range(min, max);
        num_2 = rand_range(min, max);
    }

    answer = compute(num_1, num_2, this->operation);
}

std::string Task::to_string() const {
    return std::to_string(num_1) + " " + operation + " " + std::to_string(num_2);
}