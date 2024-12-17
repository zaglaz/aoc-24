#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

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
    printf("%d", total_distance);
    fclose(list_file);
    return 0;
}
