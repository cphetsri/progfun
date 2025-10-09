#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.c"

void writeMockCSV() {
    FILE *f = fopen("borrowdata.csv", "w");
    fprintf(f, "Name, Equipment, Borrow Date, Return Date\n");
    fprintf(f, "Alice, Laptop, 2024-01-01, 2024-01-05\n");
    fprintf(f, "Bob, Camera, 2024-02-02, 2024-02-10\n");
    fprintf(f, "Charlie, Mouse, 2024-03-03, 2024-03-15\n");
    fclose(f);
}

char* readFile(const char *path) {
    FILE *f = fopen(path, "r");
    static char buf[10000];
    size_t len = fread(buf, 1, sizeof(buf) - 1, f);
    buf[len] = '\0';
    fclose(f);
    return buf;
}

void test_read_log() {
    writeMockCSV();
    FILE *input = fopen("input.txt", "w");
    fprintf(input, "1\n\n\n0\n");
    fclose(input);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    decideThing();
    fclose(stdin);
    fclose(stdout);

    char *out = readFile("output.txt");
    assert(strstr(out, "Alice") != NULL);
    assert(strstr(out, "Camera") != NULL);
}

void test_add_record() {
    writeMockCSV();
    FILE *input = fopen("input.txt", "w");
    fprintf(input,
        "2\n\nJohn Doe\nKeyboard\n"
        "2024 04 01\n2024 04 10\n\n\n0\n"
    );
    fclose(input);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    decideThing();
    fclose(stdin);
    fclose(stdout);

    char *csv = readFile("borrowdata.csv");
    assert(strstr(csv, "John Doe") != NULL);
    assert(strstr(csv, "Keyboard") != NULL);
}

void test_search() {
    writeMockCSV();
    FILE *input = fopen("input.txt", "w");
    fprintf(input, "3\n\nCamera\n\n\n0\n");
    fclose(input);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    decideThing();
    fclose(stdin);
    fclose(stdout);

    char *out = readFile("output.txt");
    assert(strstr(out, "Bob") != NULL);
    assert(strstr(out, "Camera") != NULL);
}

void test_edit_record() {
    writeMockCSV();
    FILE *input = fopen("input.txt", "w");
    fprintf(input,
        "4\n\nAlice\n"
        "Tablet\n"
        "2024 05 01\n2024 05 10\n\n\n0\n"
    );
    fclose(input);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    decideThing();
    fclose(stdin);
    fclose(stdout);

    char *csv = readFile("borrowdata.csv");
    assert(strstr(csv, "Tablet") != NULL);
    assert(strstr(csv, "Laptop") == NULL); 
}


void test_delete_record() {
    writeMockCSV();
    FILE *input = fopen("input.txt", "w");
    fprintf(input,
        "5\n\nCamera\n1\n\n\n0\n"
    );
    fclose(input);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    decideThing();
    fclose(stdin);
    fclose(stdout);

    char *csv = readFile("borrowdata.csv");
    assert(strstr(csv, "Camera") == NULL);
    assert(strstr(csv, "Alice") != NULL);
}

int main() {
    printf("Running full E2E tests...\n");
    test_read_log();
    test_add_record();
    test_search();
    test_edit_record();
    test_delete_record();
    printf("All End-to-End tests passed successfully!\n");
    return 0;
}
