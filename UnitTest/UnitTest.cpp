#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include "CppUnitTest.h"
#include <math.h>
#include <cmath>

#define PI 3.14159

double degToRad(double degrees) {
    return degrees * (PI / 180.0);
}

double calculateCos(double angleInRadians) {
    return cos(angleInRadians);
}

int checkInequality(double cosA, double cosB, double cosC) {
    double sum = cosA + cosB + cosC;
    return sum <= 1.5; // Повертає 1 (true), якщо нерівність виконується
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Тест для функції переведення градусів в радіани
        TEST_METHOD(Test_degToRad)
        {
            // Перевірка точності переведення
            Assert::AreEqual(degToRad(0), 0.0, 0.0001);
            Assert::AreEqual(degToRad(90), PI / 2, 0.0001);
            Assert::AreEqual(degToRad(180), PI, 0.0001);
            Assert::AreEqual(degToRad(360), 2 * PI, 0.0001);
        }

        // Тест для функції обчислення косинуса
        TEST_METHOD(Test_calculateCos)
        {
            // Перевірка косинусів для стандартних кутів
            Assert::AreEqual(calculateCos(degToRad(0)), 1.0, 0.0001);
            Assert::AreEqual(calculateCos(degToRad(90)), 0.0, 0.0001);
            Assert::AreEqual(calculateCos(degToRad(180)), -1.0, 0.0001);
            Assert::AreEqual(calculateCos(degToRad(270)), 0.0, 0.0001);
        }

        // Тест для функції перевірки нерівності
        TEST_METHOD(Test_checkInequality)
        {
            // Косинуси для кута 60° (cos(60) = 0.5)
            Assert::IsTrue(checkInequality(0.5, 0.5, 0.5)); // 0.5 + 0.5 + 0.5 = 1.5, повинно бути <= 1.5

            // Косинуси для кута 90° (cos(90) = 0)
            Assert::IsTrue(checkInequality(0, 0, 0)); // 0 + 0 + 0 = 0, повинно бути <= 1.5

            // Косинуси для кута 0° (cos(0) = 1)
            Assert::IsFalse(checkInequality(1, 1, 1)); // 1 + 1 + 1 = 3, повинно бути > 1.5
        }

    };
}
