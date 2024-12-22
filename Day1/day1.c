#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

//Comparator for quicksort
int comp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int main(){

    FILE *list_file;
    list_file = fopen("day1.txt", "r");
    char buffer[25];
    
    if (list_file == NULL){
        printf("Unable to open file.");
        return 1;
    }

    int count = 0;
    char *left_column;
    char *right_column;
    int left_vals[1000];
    int right_vals[1000];

    //storing column values
    while (fgets(buffer, sizeof(buffer), list_file) != NULL){
        left_column = strtok(buffer, " \t");
        right_column = strtok(NULL, " \t");

        left_vals[count] = atoi(left_column);
        right_vals[count] = atoi(right_column);
        ++count;
    }

    printf("Part 1: %d\n", part1(left_vals, right_vals, sizeof(left_vals)/sizeof(int)));
    printf("Part 2: %d", part2(left_vals, right_vals, sizeof(left_vals)/sizeof(int)));
    fclose(list_file);
    return 0;
}

int part1(int left_vals[], int right_vals[], int arr_size){
    int total_distance = 0;
    //Quicksorted value arrays
    qsort(left_vals, arr_size, sizeof(int), comp);
    qsort(right_vals, arr_size, sizeof(int), comp);

    for (int i=0; i<arr_size; ++i) {
        total_distance += abs(left_vals[i] - right_vals[i]);
    }
    return total_distance;
}

int part2(int left_vals[], int right_vals[], int arr_size){
    int similarity_score = 0;
    int term_count = 0;
    for (int i=0; i<arr_size; ++i) {
        for (int j=0; j<arr_size; ++j) {
            if (left_vals[i] == right_vals[j]){
                term_count += 1;
            }
        }
        similarity_score += (left_vals[i] * term_count);
        term_count = 0;
    }
    return similarity_score;
}
