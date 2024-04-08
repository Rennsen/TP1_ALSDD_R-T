/*
DISCLAIMER: THIS PROGRAM MEASURES EXECUTION TIME FOR DEMONSTRATION PURPOSES ONLY.
ACCURATELY CALCULATING EXECUTION TIME MAY INVOLVE COMPLEXITIES SUCH AS I/O OVERHEADS,
SYSTEM LOAD, AND OTHER FACTORS THAT THIS SIMPLE PROGRAM DOES NOT ACCOUNT FOR. USE PROFESSIONAL
TOOLS AND TECHNIQUES FOR PRECISE MEASUREMENTS IN REAL-WORLD APPLICATIONS.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define BILLION 1000000000L

int main()
{
    LARGE_INTEGER start, end, frequency;
    long long unsigned int diff;

    char filename[200]; // Increased buffer size to accommodate path

    // Disclaimer Message
    printf("\nDISCLAIMER: THIS PROGRAM MEASURES EXECUTION TIME FOR DEMONSTRATION PURPOSES ONLY. ACCURATELY CALCULATING EXECUTION TIME MAY INVOLVE COMPLEXITIES SUCH AS I/O OVERHEADS, SYSTEM LOAD, AND OTHER FACTORS THAT THIS SIMPLE PROGRAM DOES NOT ACCOUNT FOR. USE PROFESSIONAL TOOLS AND TECHNIQUES FOR PRECISE MEASUREMENTS IN REAL-WORLD APPLICATIONS.\n\n");

    printf("Enter the filename of the program (including extension and path, e.g., ../../QST4/QST4.c): ");
    scanf("%199s", filename); // Limiting input size to avoid buffer overflow

    // Get the frequency of the performance counter
    QueryPerformanceFrequency(&frequency);

    // Measure execution time
    QueryPerformanceCounter(&start);
    system(filename);
    QueryPerformanceCounter(&end);

    // Calculate execution time in nanoseconds
    diff = (end.QuadPart - start.QuadPart) * BILLION / frequency.QuadPart;

    printf("Execution time for %s: %llu nanoseconds\n", filename, (long long unsigned int)diff);

    //Display execution time in seconds as a bonus
    double seconds = (double)diff / BILLION;
    printf("Execution time for %s: %.6f seconds\n", filename, seconds);

    return 0;
}
