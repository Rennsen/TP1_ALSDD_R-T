#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <windows.h>


void Textecolor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        // Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
// Texte couleur et fond:
void Color(int couleurdutexte, int couleurdufond)
{

    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurdufond * 16 + couleurdutexte);
}

// manipuler les cordonn�s de la console gotoxy :
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


void Presentation ()
{
        system("mode 66,30");
        printf("\n\n");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
        printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
        printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
        printf("%c%c%c%c      %c%c%c%c%c%c   %c%c%c%c%c%c   %c%c%c%c%c%c       %c%c%c%c%c%c   %c%c%c%c%c%c     %c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
        printf("%c%c%c%c      %c%c       %c%c         %c%c           %c%c     %c%c  %c%c     %c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
        printf("%c%c%c%c      %c%c%c%c%c%c   %c%c%c%c%c%c     %c%c           %c%c     %c%c%c%c%c%c     %c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
        printf("%c%c%c%c      %c%c           %c%c     %c%c           %c%c     %c%c         %c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
        printf("%c%c%c%c      %c%c%c%c%c%c   %c%c%c%c%c%c   %c%c%c%c%c%c         %c%c    %c%c%c%c        %c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
        printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
        printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
        printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
        printf("%c%c%c%c                ___________________________              %c%c%c%c\n",219,219,219,219,219,219,219,219);
        printf("%c%c%c%c               /                           /             %c%c%c%c\n",219,219,219,219,219,219,219,219);
        printf("%c%c%c%c              /     TAREK AIT AHMED       /              %c%c%c%c\n",219,219,219,219,219,219,219,219);
        printf("%c%c%c%c             /          RAYAN DERRADJI   /               %c%c%c%c\n",219,219,219,219,219,219,219,219);
        printf("%c%c%c%c            /___________________________/                %c%c%c%c\n",219,219,219,219,219,219,219,219);
        printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
        printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
        printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
        printf("\n");
        printf("\n");
        printf("\t\t\t\t\t\t                             PLease                                         \n");
        printf("\t\t\t\t\t\t                    Press any key to continue..                             ");
        getch();
        system("cls");

}

void GoodBye(){
system("cls");
printf("\n\n\n\n\n\n\n");
printf("\t\t\t\t .----------------.  .----------------.  .----------------.  .-----------------. .----------------. \n");
printf("\t\t\t\t| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n");
printf("\t\t\t\t| |  _________   | || |  ____  ____  | || |      __      | || | ____  _____  | || |  ___  ____   | |\n");
printf("\t\t\t\t| | |  _   _  |  | || | |_   ||   _| | || |     /  |     | || ||_   ||_   _| | || | |_  ||_  _|  | |\n");
printf("\t\t\t\t| | |_/ | | |_|  | || |   | |__| |   | || |    / /| |    | || |  |   ( | |   | || |   | |_/ /    | |\n");
printf("\t\t\t\t| |     | |      | || |   |  __  |   | || |   / ____ |   | || |  | |( (| |   | || |   |  __'.    | |\n");
printf("\t\t\t\t| |    _| |_     | || |  _| |  | |_  | || | _/ /    | |_ | || | _| |_(   |_  | || |  _| |  | |_  | |\n");
printf("\t\t\t\t| |   |_____|    | || | |____||____| | || ||____|  |____|| || ||_____|(____| | || | |____||____| | |\n");
printf("\t\t\t\t| |              | || |              | || |              | || |              | || |              | |\n");
printf("\t\t\t\t| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n");
printf("\t\t\t\t '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n\n\n");
printf("\t\t\t\t           .----------------.  .----------------.  .----------------.  .----------------. \n");
printf("\t\t\t\t          | .--------------. || .--------------. || .--------------. || .--------------. |\n");
printf("\t\t\t\t          | |  ____  ____  | || |     ____     | || | _____  _____ | || |              | |\n");
printf("\t\t\t\t          | | |_  _||_  _| | || |   .'    `.   | || ||_   _||_   _|| || |      _       | |\n");
printf("\t\t\t\t          | |   ( |  / /   | || |  /  .--.  |  | || |  | |    | |  | || |     | |      | |\n");
printf("\t\t\t\t          | |    ( |/ /    | || |  | |    | |  | || |  | '    ' |  | || |     | |      | |\n");
printf("\t\t\t\t          | |    _|  |_    | || |  |  `--'  /  | || |   | `--' /   | || |     | |      | |\n");
printf("\t\t\t\t          | |   |______|   | || |   `.____.'   | || |    `.__.'    | || |     |_|      | |\n");
printf("\t\t\t\t          | |              | || |              | || |              | || |     (_)      | |\n");
printf("\t\t\t\t          | '--------------' || '--------------' || '--------------' || '--------------' | \n");
printf("\t\t\t\t           '----------------'  '----------------'  '----------------'  '----------------' \n");
Sleep(2200);
system("cls");
}

void welcome()

{
    int k;
    system("Cls");
    for (k = 0; k < 10; k++)
    {
        if (k % 2 == 0)
            Textecolor(5);
        if (k % 2 == 1)
            Textecolor(3);
        printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t  .----------------.  .----------------.  .----------------.\n");
    printf("\t\t\t\t\t\t | .--------------. || .--------------. || .--------------. |\n");
    printf("\t\t\t\t\t\t | |  _________   | || |    _______   | || |     _____    | |\n");
    printf("\t\t\t\t\t\t | | |_   ___  |  | || |   /  ___  |  | || |    |_   _|   | |\n");
    printf("\t\t\t\t\t\t | |   | |_  \\_|  | || |  |  (__ \\_|  | || |      | |     | |\n");
    printf("\t\t\t\t\t\t | |   |  _|  _   | || |   \'.___`-.   | || |      | |     | |\n");
    printf("\t\t\t\t\t\t | |  _| |___/ |  | || |  |`\\____) |  | || |     _| |_    | |\n");
    printf("\t\t\t\t\t\t | | |_________|  | || |  |_______.\'  | || |    |_____|   | |\n");
    printf("\t\t\t\t\t\t | |              | || |              | || |              | |\n");
    printf("\t\t\t\t\t\t | \'--------------\' || \'--------------\' || \'--------------\' |\n");
    printf("\t\t\t\t\t\t  \'----------------\'  \'----------------\'  \'----------------\'\n");
    Sleep(200);
    system("cls");
    }
    Textecolor(5);
    printf("\t\t\t\t\t\t          R%cpublique Alg%crienne D%cmocratique et Populaire           \n", 130, 130, 130);
    printf("\t\t\t\t\t\tMinist%cre de l'Enseignement Sup%crieur et de la Recherche Scientifique\n\n\n", 130, 130);
    printf("\t\t\t\t\t\t     _______________________________________________________\n");
    printf("\t\t\t\t\t\t    |        _______     _______     _                      |\n");
    printf("\t\t\t\t\t\t    |       |  _____|   |  _____|   | |  %ccole nationale    |\n", 130);
    printf("\t\t\t\t\t\t    |       | |_____    | |_____    | |                     |\n");
    printf("\t\t\t\t\t\t    |       |  _____|   |_____  |   | |  sup%crieure         |\n", 130);
    printf("\t\t\t\t\t\t    |       | |_____     _____| |   | |                     |\n");
    printf("\t\t\t\t\t\t    |       |_______|   |_______|   |_|  d'informatique     |\n");
    printf("\t\t\t\t\t\t    |_______________________________________________________|\n\n\n");
    Textecolor(3);
    printf("\t\t\t\t\t\t ___________________________________________________________________\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t| Done by  :             Tarek Ait Ahmed                            |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|                              &                                    |\n");
    printf("\t\t\t\t\t\t|                        Rayan Derradji                             |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|           SECTION : A           GROUP : 03                        |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|           TP1 :        Linked Lists                               |\n", 130, 130);
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t| Supervised By :Mrs. Artabaz Saliha                                |\n");
    printf("\t\t\t\t\t\t|___________________________________________________________________|\n\n\n");
    Sleep(200);
    Sleep(200);
    Textecolor(5);
    printf("\n");
    printf("\t\t\t\t\t\t                             PLease                                         \n");
    printf("\t\t\t\t\t\t                    Press any key to continue..                             ");
    getch();
}


void MENU (int *ch)
{
            system("mode con: cols=999 lines=999");

            Textecolor(15);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
            printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
            printf("%c%c%c%c                        MENU                             %c%c%c%c\n",219,219,219,219,219,219,219,219);
            printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
            printf( "   \n\n" );
            printf( "     1) The searching algorithm \n\n" );
            printf( "     2) Search for prime numbers using the Dynamic array \n\n" );
            printf( "     3) Search for the prime numbers using Linked Lists\n\n" );
            printf( "     4) Printing prime numbers between two values \n\n" );
            printf( "     5) expressing each number of the initial list as a product of prime numbers  \n\n" );
            printf( "     6) Find the Co-prime numbers\n\n" );
            printf( "     0) Exit the program \n\n");
            printf("\n");
            printf("\n");
            printf("Please enter your chocie : ");
            scanf( " %d", ch );
            printf( "\n" );
}

void SearchingPrimeAlgorithm()
{
                    system("mode con: cols=150 lines=50");

                    system("cls");
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c                  The search algorithm                   %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
                    printf( "   \n\n" );
}


void  PrimeSearchDynamicArray()
{

                    system("mode con: cols=150 lines=50");
                    system("cls");
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c      Search for prime numbers using  Dynamic array      %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
                    printf( "   \n\n" );
}

void PrimeSearchLinkedLists()
{
                    system("mode con: cols=150 lines=50");

                    system("cls");
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c      Search for prime numbers using Linked Lists        %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
                    printf( "   \n\n" );
}
void PrimeListIndexing()
{
                    system("mode con: cols=150 lines=50");


                    system('cls');
                     printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c      displaying prime numbers between two values        %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
                    printf( "   \n\n" );
}
void PrimeProduct()
{

                    system("mode con: cols=150 lines=50");

                    system('cls');
                    clearScreen();
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c  expressing the integers as a product of prime numbers  %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
                    printf( "   \n\n" );
}
void Coprime()
{
                    system("mode con: cols=150 lines=50");

                    system("cls");
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c               Find the Co-prime numbers                 %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
                    printf( "   \n\n" );
}


