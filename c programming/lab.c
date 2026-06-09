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
    char inputFile[] = "IMDb_400_Movies1.csv";
    char outputFile[] = "sorted_movies.csv";
    
    int count = countMovies(inputFile);
    if(count == 0) return 1;

    Movie *movies = allocateMemory(count);
    if(movies == NULL) return 1;
    
    readMovies(inputFile, movies, count);
    
    int n;
    printf("Enter how many movie records to display: ");
    scanf("%d", &n);
    
    if(n > count)
    {
        n = count;
    }
    
    printf("\nBefore Sorting:\n\n");
    displayMoviesFromFile(inputFile, n);
  
    sortMovies(movies, count);
    writeMovies(outputFile, movies, count);
  
    printf("\nAfter Sorting:\n\n");
    displayMoviesFromFile(outputFile, n);

    printf("\nSorted movie data stored successfully.\n");
    
    freeMemory(&movies);

    return 0;
}

/* Function Definitions */

int countMovies(char filename[])
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("File cannot be opened\n");
        return 0;
    }
    
    int count = 0;
    char buffer[256];
    
    // Skip the header
    fgets(buffer, sizeof(buffer), fp);
    
    // Count the remaining lines
    while(fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        count++;
    }
    
    fclose(fp);
    return count;
}

Movie* allocateMemory(int count)
{
    Movie movies = (Movie)malloc(count * sizeof(Movie));
    if(movies == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return movies;
}

void readMovies(char filename[], Movie *movies, int count)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("File cannot be opened\n");
        return;
    }
    
    char buffer[256];
    fgets(buffer, sizeof(buffer), fp); // Skip header row
    
    for(int i = 0; i < count; i++)
    {
        if(fgets(buffer, sizeof(buffer), fp) != NULL)
        {
            // Parse the CSV line formatting
            sscanf(buffer, "%[^,],%[^,],%d,%f", movies[i].name, movies[i].language, &movies[i].year, &movies[i].rating);
        }
    }
    
    fclose(fp);
}

void displayMoviesFromFile(char filename[], int n)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("File cannot be opened\n");
        return;
    }

    char buffer[256];
    char name[100];
    char language[50];
    int year;
    float rating;
    
    fgets(buffer, sizeof(buffer), fp); // Skip header row
    
    for(int i = 0; i < n; i++)
    {
        if(fgets(buffer, sizeof(buffer), fp) != NULL)
        {
            sscanf(buffer, "%[^,],%[^,],%d,%f", name, language, &year, &rating);
            printf("%s | %s | %d | %.1f\n", name, language, year, rating);
        }
    }
    
    fclose(fp);
}

void sortMovies(Movie *movies, int count)
{
    Movie temp;
    for(int i = 0; i < count - 1; i++)
    {
        for(int j = 0; j < count - i - 1; j++)
        {
            if(strcmp(movies[j].name, movies[j+1].name) > 0)
            {
                temp = movies[j];
                movies[j] = movies[j+1];
                movies[j+1] = temp;
            }
        }
    }
}

void writeMovies(char filename[], Movie *movies, int count)
{
    FILE *fp = fopen(filename, "w");
    if(fp == NULL)
    {
        printf("Cannot create output file\n");
        return;
    }
    
    fprintf(fp, "Movie Name,Language,Year,Rating\n");
    
    for(int i = 0; i < count; i++)
    {
        fprintf(fp, "%s,%s,%d,%.1f\n", movies[i].name, movies[i].language, movies[i].year, movies[i].rating);
    }
    
    fclose(fp);
}

void freeMemory(Movie **movies)
{
    if(movies != NULL && *movies != NULL)
    {
        free(*movies);
        *movies = NULL;
    }
}