#include "MathTest.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

MathTest::MathTest(int count)
    : count(count), correct_count(0) {
    generate_tasks(count, 1, 20, '\0');
}

MathTest::MathTest(int count, int min, int max)
    : count(count), correct_count(0) {
    generate_tasks(count, min, max, '\0');
}

MathTest::MathTest(int count, int min, int max, char operation)
    : count(count), correct_count(0) {
    generate_tasks(count, min, max, operation);
}

void MathTest::generate_tasks(int count, int min, int max, char operation) {
    tasks = new Task[count];
    user_answers = new int[count];
    for (int i = 0; i < count; ++i) {
        tasks[i] = Task(min, max, operation);
        user_answers[i] = 0;
    }
}

MathTest::~MathTest() {
    delete[] tasks;
    delete[] user_answers;
}