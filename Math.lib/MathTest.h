#pragma once
#include "Task.h"

class MathTest {
private:
    Task* tasks;          
    int count;            
    int* user_answers;    
    int correct_count;    

    void generate_tasks(int count, int min, int max, char operation);

public:
    MathTest(int count);
    MathTest(int count, int min, int max);
    MathTest(int count, int min, int max, char operation);

    ~MathTest();

    void submit_answer(int index, int answer);
    bool is_correct(int index) const;
    int  get_correct_count() const;
    int  get_count() const;
    const Task& get_task(int index) const;

    void run();
    void show_statistics() const;
};