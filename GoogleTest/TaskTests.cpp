#include "pch.h"
#include "Task.h"

TEST(TaskTest, DefaultConstructorInRange) {
    for (int i = 0; i < 100; ++i) {
        Task t;
        EXPECT_GE(t.num_1, 1);
        EXPECT_LE(t.num_1, 20);
        EXPECT_GE(t.num_2, 1);
        EXPECT_LE(t.num_2, 20);
    }
}

TEST(TaskTest, InitConstructorRange) {
    for (int i = 0; i < 100; ++i) {
        Task t(5, 10);
        EXPECT_GE(t.num_1, 5);
        EXPECT_LE(t.num_1, 10);
        EXPECT_GE(t.num_2, 5);
        EXPECT_LE(t.num_2, 10);
    }
}

TEST(TaskTest, InitConstructorFixedOperation) {
    for (int i = 0; i < 100; ++i) {
        Task t(1, 10, '+');
        EXPECT_EQ(t.operation, '+');
        EXPECT_EQ(t.answer, t.num_1 + t.num_2);
    }
}

TEST(TaskTest, DivisionNoZeroDivisor) {
    for (int i = 0; i < 200; ++i) {
        Task t(0, 5, '/');
        EXPECT_NE(t.num_2, 0);
    }
}