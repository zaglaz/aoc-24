#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *datafile;
    datafile = fopen("day2.txt", "r");
    char buffer[30];
    int safe_count = 0;
    if (datafile == NULL) {
        return 1;
    }
    
    //report traversal by line
    while (fgets(buffer, sizeof(buffer), datafile) != NULL){
        int inc_factor = 0;
        int dec_factor = 0;
        int violations = 0;
        char *report = strtok(buffer, " ");
        char *previous = NULL;
        while (report != NULL){
            if (previous != NULL){
                //adjacent diff
                if (abs(atoi(previous) - atoi(report)) > 3 || abs(atoi(previous) - atoi(report)) == 0){
                    violations++; 
                }
                //abs(previous - report) == 0 catches equals, letting us use this tertiary
                (atoi(previous) > atoi(report)) ? dec_factor++ : inc_factor++;
            }
            previous = report;
            report = strtok(NULL, " ");
        }
        //mutually exclusive, all dec. or all inc.
        if (inc_factor > 0 && dec_factor > 0){
            violations++;
        }
        if (violations == 0){
            safe_count++;
        }
    }

    fclose(datafile);
    printf("Safe Count: %d", safe_count);
    return 0;
}