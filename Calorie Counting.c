#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    const unsigned MAX_LENGTH = 32;
    char buffer[MAX_LENGTH];
    FILE *fp = fopen(argv[1], "r");
    int array[1000] = {0};
    int sum = 0, i = 0, anwser_1 = 0, anwser_2 = 0, anwser_3 = 0;

    if(argv[1] <= 0){
        printf("No file argument\n");
        return 1;
    }

    while(fgets(buffer, MAX_LENGTH, fp) != NULL){
        if(strlen(buffer) == 1){
            array[i] = sum;
            sum = 0;
            i++;
        }
        else if(feof(fp)){
            array[i] = atoi(buffer);
        }
        else{
            sum += atoi(buffer);
        }
    }

    for(int j = 0; j < 1000; ++j){
        if(anwser_2 > array[j] && anwser_3 < array[j]){
            anwser_3 = array[j];
        }
        else if(anwser_2 < array[j] && anwser_2 < anwser_1){
            anwser_2 = array[j];
        }
        else if(anwser_1 < array[j]){
            anwser_1 = array[j];
        }
    }

    printf("anwser 1 is %d\n", anwser_1);
    printf("answer 2 is %d\n", anwser_2);
    printf("answer 3 is %d\n", anwser_3);

    printf("Total sum of all three is %d\n", anwser_1 + anwser_2 + anwser_3);
   
    fclose(fp);
    return 0;
}
