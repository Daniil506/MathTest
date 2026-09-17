#include "pch.h"
#include "MathTest.h"

TEST(MathTestTest, ConstructorCount) {
    MathTest mt(5);
    EXPECT_EQ(mt.get_count(), 5);
    EXPECT_EQ(mt.get_correct_count(), 0);
}

TEST(MathTestTest, ConstructorWithRange) {
    MathTest mt(3, 5, 10);
    EXPECT_EQ(mt.get_count(), 3);
    for (int i = 0; i < 3; ++i) {
        const Task& t = mt.get_task(i);
        EXPECT_GE(t.num_1, 5);
        EXPECT_LE(t.num_1, 10);
        EXPECT_GE(t.num_2, 5);
        EXPECT_LE(t.num_2, 10);
    }
}

TEST(MathTestTest, ConstructorWithOperation) {
    MathTest mt(4, 1, 10, '+');
    for (int i = 0; i < 4; ++i) {
        const Task& t = mt.get_task(i);
        EXPECT_EQ(t.operation, '+');
        EXPECT_EQ(t.answer, t.num_1 + t.num_2);
    }
}

TEST(MathTestTest, SubmitCorrectAnswer) {
    MathTest mt(3, 1, 5, '+');
    mt.submit_answer(0, mt.get_task(0).answer);
    EXPECT_TRUE(mt.is_correct(0));
    EXPECT_EQ(mt.get_correct_count(), 1);
}

TEST(MathTestTest, SubmitWrongAnswer) {
    MathTest mt(3, 1, 5, '+');
    mt.submit_answer(0, mt.get_task(0).answer + 999);
    EXPECT_FALSE(mt.is_correct(0));
    EXPECT_EQ(mt.get_correct_count(), 0);
}

TEST(MathTestTest, MultipleAnswers) {
    MathTest mt(5, 1, 10, '*');
    for (int i = 0; i < 5; ++i)
        mt.submit_answer(i, mt.get_task(i).answer);
    EXPECT_EQ(mt.get_correct_count(), 5);
}

TEST(MathTestTest, OutOfRangeIndexIgnored) {
    MathTest mt(3, 1, 5, '+');
    mt.submit_answer(-1, 999);
    mt.submit_answer(100, 999);
    EXPECT_EQ(mt.get_correct_count(), 0);
}