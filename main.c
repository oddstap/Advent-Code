#include <stdlib.h>
#include <stdio.h>

int main()
{
    const unsigned MAX_LENGTH = 32;
    char buffer[MAX_LENGTH];
    char *filename = "input.txt";
    FILE *fp = fopen(filename, "r");
    int answer = 0;

    while(fgets(buffer, MAX_LENGTH, fp)){

        int a, b, c, d;

        sscanf(buffer, "%d-%d, %d-%d", &a, &b, &c, &d );

        if (a >= c && b <= d || c >= a && d <= b){
            answer += 1;
        }
    }

    printf("%d\n", answer);
    fclose(fp);

    return 0;
}