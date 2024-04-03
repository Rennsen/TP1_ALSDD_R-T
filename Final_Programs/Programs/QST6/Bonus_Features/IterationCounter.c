/*
DISCLAIMER: PLEASE NOTE THAT THIS PROGRAM SERVES A SIMPLIFIED DEMONSTRATION PURPOSE ONLY
AND MAY NOT ACCURATELY IDENTIFY ALL LOOP CONSTRUCTS. USE PROFESSIONAL TOOLS AND TECHNIQUES
FOR PRECISE ANALYSIS IN REAL-WORLD APPLICATIONS.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countIterations(FILE *file)
{
    int iterations = 0;
    char line[1000]; // Assuming no line exceeds 1000 characters

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (strstr(line, "for") != NULL || strstr(line, "while") != NULL)
            iterations++;
    }

    return iterations;
}

int main(int argc, char *argv[])
{
    printf("\nDISCLAIMER: PLEASE NOTE THAT THIS PROGRAM SERVES A SIMPLIFIED DEMONSTRATION PURPOSE ONLY AND MAY NOT ACCURATELY IDENTIFY ALL LOOP CONSTRUCTS. USE PROFESSIONAL TOOLS AND TECHNIQUES FOR PRECISE ANALYSIS IN REAL-WORLD APPLICATIONS.\n\n");

    if (argc != 2)
    {
        printf("Usage (include path): %s <file_name>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int iterations = countIterations(file);
    printf("Number of iterations in %s: %d\n", argv[1], iterations);

    fclose(file);
    return 0;
}
