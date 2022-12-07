#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    const unsigned MAX_LENGTH = 32;
    char buffer[MAX_LENGTH];
    FILE *fp = fopen(argv[1], "r");

    if(argv[1] <= 0){
        printf("No file argument\n");
        return 1;
    }

    int sum = 0;
    int total = 0;
    char opponent = ' ', condition = ' ';

    while(fgets(buffer, MAX_LENGTH, fp) != NULL){
        sscanf(buffer, "%s %s", &opponent, &condition);

        switch (condition){
            // Lose
            case 'X':
                if(opponent == 'A')
                    sum += 3;
                if(opponent == 'B')
                    sum += 1;
                if(opponent == 'C')
                    sum += 2;
            break;
            //Draw
            case 'Y':
                sum += 3;
                if(opponent == 'A')
                    sum += 1;
                if(opponent == 'B')
                    sum += 2;
                if(opponent == 'C')
                    sum += 3;
            break;
            // Win
            case 'Z':
                sum += 6;
                if(opponent == 'A')
                    sum += 2;
                if(opponent == 'B')
                    sum += 3;
                if(opponent == 'C')
                    sum += 1;
            break;
        }
        printf("Round outcome is %d\n", sum);
        total += sum;
    }
    printf("Total sum is %d\n", total);
    return 0;
}