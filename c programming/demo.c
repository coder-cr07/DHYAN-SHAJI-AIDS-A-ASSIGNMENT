#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
    char language[50];
    int year;
    float rating;
} Movie;

/* Function Prototypes */

int countMovies(char filename[]);
Movie* allocateMemory(int count);
void readMovies(char filename[], Movie *movies, int count);
void displayMoviesFromFile(char filename[], int n);
void sortMovies(Movie *movies, int count);
void writeMovies(char filename[], Movie *movies, int count);
void freeMemory(Movie **movies);

/* Main Function */

int main()
{

    printf("Enter how many movie records to display: ");
    
    if(n > count)
    {
        n = count;
    }
    printf("\nBefore Sorting:\n\n");
  
    printf("\nAfter Sorting:\n\n");

    printf("\nSorted movie data stored successfully.\n");

    return 0;
}

/* Function Definitions */

int countMovies(char filename[])
{
   
    if()
    {
        printf("File cannot be opened\n");
    }

}

Movie* allocateMemory(int count)
{

    if()
    {
        printf("Memory allocation failed\n");

    }

}

void readMovies(char filename[], Movie *movies, int count)
{

    if()
    {
        printf("File cannot be opened\n");
    }
    
}

void displayMoviesFromFile(char filename[], int n)
{

    if()
    {
        printf("File cannot be opened\n");

    }

    {
        
        printf("%s | %s | %d | %.1f\n", );
    }

}

void sortMovies(Movie *movies, int count)
{

}

void writeMovies(char filename[], Movie *movies, int count)
{
    if()
    {
        printf("Cannot create output file\n");
    }
    fprintf(fp, "Movie Name,Language,Year,Rating\n");
    
        fprintf( , "%s,%s,%d,%.1f\n", );
    }

}

void freeMemory(Movie **movies)
{

}