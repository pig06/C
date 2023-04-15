#include <stdio.h>
#include <string.h>

// Standard Library
#include <stdlib.h> // qsort() Function

typedef struct
{
    char name[10];
    int age;
} Student_t; // Aliasing (이름 바꾸기, 이름 축약)

int cmpfunc(const void *a, const void *b)
{
    return strcmp(((Student_t *)a)->name, ((Student_t *)b)->name);
}

int main(void)
{
    int arr_count = 5;
    Student_t student[5] = {{"bb", 15}, {"ab", 11}, {"aa", 12}, {"ba", 19}, {"ca", 13}};

    // Print
    printf("Before sorting the array\n");
    for (int i = 0; i < arr_count; i++)
        printf("%s %d\n", student[i].name, student[i].age);
    printf("\n");

    // Sort
    qsort((Student_t *)student, arr_count, sizeof(Student_t), cmpfunc);

    // Print
    printf("After sorting the array\n");
    for (int i = 0; i < arr_count; i++)
        printf("%s %d\n", student[i].name, student[i].age);
    printf("\n");

    return 0;
}