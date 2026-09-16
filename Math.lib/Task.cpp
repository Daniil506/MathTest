#include "Task.h"
#include <cstdlib>
#include <stdexcept>
#include <utility>

static int rand_range(int min, int max) {
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

Task::Task() {
    num_1 = rand_range(1, 20);
    num_2 = rand_range(1, 20);
    operation = rand_operation();
    if (operation == '/' && num_2 == 0) num_2 = 1;
    answer = compute(num_1, num_2, operation);
}

Task::Task(int min, int max, char operation) {
    if (min > max) std::swap(min, max);

    num_1 = rand_range(min, max);
    num_2 = rand_range(min, max);
    this->operation = (operation == '\0') ? rand_operation() : operation;
    if (this->operation == '/' && num_2 == 0) num_2 = 1;
    answer = compute(num_1, num_2, this->operation);
}

std::string Task::to_string() const {
    return std::to_string(num_1) + " " + operation + " " + std::to_string(num_2);
}