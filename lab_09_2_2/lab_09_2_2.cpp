#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define PI 3.14159

double degToRad(double degrees) {
    return degrees * (PI / 180.0);
}

double calculateCos(double angleInRadians) {
    return cos(angleInRadians);
}

// Функція для перевірки нерівності cosA + cosB + cosC <= 3/2
int checkInequality(double cosA, double cosB, double cosC) {
    double sum = cosA + cosB + cosC;
    return sum <= 1.5; // Повертає 1 (true), якщо нерівність виконується
}

// Функція для введення кута трикутника
void inputAngles(double* A, double* B, double* C) {
    printf("Enter angle A (in degrees): ");
    scanf("%lf", A);
    printf("Enter angle B (in degrees): ");
    scanf("%lf", B);
    printf("Enter angle C (in degrees): ");
    scanf("%lf", C);
}

// Головна функція
int main() {
    double A, B, C;

    // Введення кутів трикутника
    inputAngles(&A, &B, &C);

    // Перевірка умови: сума кутів повинна дорівнювати 180 градусів
    if (A + B + C != 180.0) {
        printf("The sum of the angles must be 180 degrees.\n");
        return 1;
    }

    // Переведення кутів в радіани
    double radA = degToRad(A);
    double radB = degToRad(B);
    double radC = degToRad(C);

    // Обчислення косинусів кутів
    double cosA = calculateCos(radA);
    double cosB = calculateCos(radB);
    double cosC = calculateCos(radC);

    // Перевірка нерівності cosA + cosB + cosC <= 3/2
    if (checkInequality(cosA, cosB, cosC)) {
        printf("The inequality cosA + cosB + cosC <= 3/2 holds.\n");
    }
    else {
        printf("The inequality does not hold.\n");
    }

    return 0;
}
