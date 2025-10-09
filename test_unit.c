#include <assert.h>
#include <stdio.h>
#include "main.c"

void test_isLeapYear() {
    assert(isLeapYear(2000) == 1);
    assert(isLeapYear(1900) == 0);
    assert(isLeapYear(2024) == 1);
    assert(isLeapYear(2023) == 0);
}

void test_isValidDate() {
    assert(isValidDate(29, 2, 2024) == 1);
    assert(isValidDate(29, 2, 2023) == 0);
    assert(isValidDate(31, 4, 2024) == 0);
    assert(isValidDate(1, 1, 1899) == 0);
    assert(isValidDate(1, 13, 2024) == 0);
    assert(isValidDate(31, 12, 2100) == 1);
}

void test_compareDates() {
    assert(compareDates(1, 1, 2020, 2, 1, 2020) == 1);
    assert(compareDates(2, 1, 2020, 1, 1, 2020) == -1);
    assert(compareDates(1, 2, 2020, 1, 1, 2020) == -1);
    assert(compareDates(1, 1, 2020, 1, 2, 2020) == 1);
    assert(compareDates(1, 1, 2020, 1, 1, 2020) == 0);
}

int main() {
    printf("Running unit tests...\n");
    test_isLeapYear();
    test_isValidDate();
    test_compareDates();
    printf("All unit tests passed!\n");
    return 0;
}
