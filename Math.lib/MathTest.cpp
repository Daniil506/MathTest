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
void MathTest::submit_answer(int index, int answer) {
    if (index < 0 || index >= count) return;   
    user_answers[index] = answer;
    if (answer == tasks[index].answer) {
        ++correct_count;
    }
}

bool MathTest::is_correct(int index) const {
    return user_answers[index] == tasks[index].answer;
}

int MathTest::get_correct_count() const { return correct_count; }
int MathTest::get_count() const { return count; }
const Task& MathTest::get_task(int index) const { return tasks[index]; }