#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

//Comparator for quicksort
int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(){

    FILE *list_file;
    list_file = fopen("day1_list.txt", "r");
    char buffer[25];
    int total_distance = 0;
    
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

    //Quicksorted value arrays
    qsort(left_vals, sizeof(left_vals)/sizeof(left_vals[0]), sizeof(int), comp);
    qsort(right_vals, sizeof(right_vals)/sizeof(right_vals[0]), sizeof(int), comp);

    for (int i=0; i<1000; ++i) {
        total_distance += abs(left_vals[i] - right_vals[i]);
    }

    printf("%d", total_distance);
    fclose(list_file);
    return 0;
}
