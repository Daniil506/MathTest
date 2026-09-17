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

TEST(TaskTest, DefaultConstructorDivisionExact) {
    for (int i = 0; i < 200; ++i) {
        Task t;
        if (t.operation == '/') {
            EXPECT_NE(t.num_2, 0);
            EXPECT_EQ(t.num_1 % t.num_2, 0);
            EXPECT_LE(t.num_2, t.num_1);
        }
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

TEST(TaskTest, InitConstructorSubtraction) {
    for (int i = 0; i < 100; ++i) {
        Task t(1, 10, '-');
        EXPECT_EQ(t.operation, '-');
        EXPECT_EQ(t.answer, t.num_1 - t.num_2);
    }
}

TEST(TaskTest, InitConstructorMultiplication) {
    for (int i = 0; i < 100; ++i) {
        Task t(1, 10, '*');
        EXPECT_EQ(t.operation, '*');
        EXPECT_EQ(t.answer, t.num_1 * t.num_2);
    }
}

TEST(TaskTest, DivisionAlwaysExact) {
    for (int i = 0; i < 200; ++i) {
        Task t(1, 20, '/');
        EXPECT_NE(t.num_2, 0);
        EXPECT_EQ(t.num_1 % t.num_2, 0);
    }
}

TEST(TaskTest, DivisionDivisorLessOrEqualDividend) {
    for (int i = 0; i < 200; ++i) {
        Task t(5, 50, '/');
        EXPECT_NE(t.num_2, 0);
        EXPECT_LE(t.num_2, t.num_1);
    }
}

TEST(TaskTest, DivisionExactAndLess) {
    for (int i = 0; i < 200; ++i) {
        Task t(2, 30, '/');
        EXPECT_NE(t.num_2, 0);
        EXPECT_EQ(t.num_1 % t.num_2, 0);
        EXPECT_LE(t.num_2, t.num_1);
    }
}

TEST(TaskTest, DivisionNoZeroDivisor) {
    for (int i = 0; i < 200; ++i) {
        Task t(0, 5, '/');
        EXPECT_NE(t.num_2, 0);
    }
}

TEST(TaskTest, ToStringFormat) {
    Task t(1, 5, '+');
    std::string s = t.to_string();
    EXPECT_NE(s.find(' '), std::string::npos);
    EXPECT_NE(s.find('+'), std::string::npos);
}