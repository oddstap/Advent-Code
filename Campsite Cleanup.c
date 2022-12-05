#include <stdlib.h>
#include <stdio.h>

int main()
{
    const unsigned MAX_LENGTH = 32;
    char buffer[MAX_LENGTH];
    char *filename = "input.txt";
    FILE *fp = fopen(filename, "r");
    int answer_1 = 0, answer_2 = 0;

    while(fgets(buffer, MAX_LENGTH, fp)){

        int a, b, c, d;

        sscanf(buffer, "%d-%d, %d-%d", &a, &b, &c, &d );
        
        if (a >= c && b <= d || c >= a && d <= b){
            answer_1 += 1;
        }
        
        if (a <= d && b >= c){
            answer_2 += 1;
        }
        
    }

    printf("Anwser for part 1: %d\n", answer_1);
    printf("Anwser for part 2: %d\n", answer_2);
    fclose(fp);

    return 0;
}
