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
void MathTest::run() {
    for (int i = 0; i < count; ++i) {
        std::cout << "§£§à§á§â§à§ã " << (i + 1) << ": "
            << tasks[i].to_string() << " = ? ";
        int ans;
        std::cin >> ans;
        submit_answer(i, ans);
    }
    show_statistics();
}

void MathTest::show_statistics() const {
    std::cout << "|" << std::setw(12) << "No";
    for (int i = 0; i < count; ++i)
        std::cout << "|" << std::setw(8) << (i + 1);
    std::cout << "|\n";

    std::cout << "+";
    for (int i = 0; i <= count; ++i) std::cout << "--------+";
    std::cout << "\n";

    std::cout << "|" << std::setw(12) << "Question";
    for (int i = 0; i < count; ++i)
        std::cout << "|" << std::setw(8) << tasks[i].to_string();
    std::cout << "|\n";

    std::cout << "|" << std::setw(12) << "True Answer";
    for (int i = 0; i < count; ++i)
        std::cout << "|" << std::setw(8) << tasks[i].answer;
    std::cout << "|\n";

    std::cout << "|" << std::setw(12) << "Your Answer";
    for (int i = 0; i < count; ++i)
        std::cout << "|" << std::setw(8) << user_answers[i];
    std::cout << "|\n";

    std::cout << "|" << std::setw(12) << "Result";
    for (int i = 0; i < count; ++i)
        std::cout << "|" << std::setw(8) << (is_correct(i) ? "+" : "-");
    std::cout << "|\n\n";

    int percent = count ? correct_count * 100 / count : 0;
    char mark = percent >= 80 ? 'A' : percent >= 60 ? 'B' : 'C';
    std::cout << "Total Result: " << correct_count << " / " << count
        << " (mark: " << mark << ")\n";
}