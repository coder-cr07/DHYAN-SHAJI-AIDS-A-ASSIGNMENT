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
void getSearchMovieName(char searchName[]);
void removeNewLine(char str[]);
int linearSearch(Movie *movies, int count, char searchName[]);
void displayMovie(Movie *movies, int position);
void freeMemory(Movie **movies);

/* Global Variables */
int foundIndex =-1;

/* Main Function */

int main()
{
    char fileName[100]= "sorted_movies.csv";
    char searchName[100];

    int count = countMovies(fileName);
    Movie *movies = allocateMemory(count);
    readMovies(fileName, movies, count);
    getSearchMovieName(searchName);

    foundIndex = linearSearch(movies, count, searchName);
    display(movies, foundIndex);

    freeMemory(&movies);
    
    return 0;
}

/* Function Definitions */

int countMovies(char filename[])
{
    FILE *fp;
    int cont = 0;
    char line[200];

    fp= fopen(filename,"r");
    if(fp == NULL){
    
        printf("File cannot be opened\n");
        return 0;

    }
    while(fgets(line, sizeof(line), fp) != NULL){
        cont++;
    }
    fclose(fp);
    return cont;
}

Movie* allocateMemory(int count)
{
    Movie *movies;
    movies = (Movie*)mallo(count* sizeof(Movie));
    if(movies == NULL){
    
        printf("Memory allocation failed\n");
        return NULL;
    }
    return movies;
    
  
}

void readMovies(char filename[], Movie *movies, int count)
{
    FILE *fp;
    char line[200];
    int i=0;

    fp=fopen(filename,"r");
    if(fp == NULL){

    

        printf("File cannot be opened\n");
        return;
    }
    fgets(line, sizeof(line),fp);
    while(i<count-1 && fscanf(fp,"%99[^,],%49[^,],%d,%f",
    movies[i].name, movies[i].language, &movies[i].year, &movies[i].rating) == 4){
        i++;

    }
    fclose(fp);

    
}

void getSearchMovieName(char searchName[])
{

    printf("Enter movie name to search: ");
    fgets(  searchName, sizeof(searchName), stdin);
    removeNewLine(searchName);

}

void removeNewLine(char str[])
{
    int len;
    len = strlen(str);
    if(str[len-1] == "\n"){
        str[len -1] = "\0";
    }

}

int linearSearch(Movie *movies, int count, char searchName[])
{
    for(int i=0; i<count; i++){
        if(strcmp(movies[i].name, searchName) == 0){
            return i;
        }
    }
    return -1;

}

void displayMovie(Movie *movies, int position)
{
    if(position == -1){
 
        printf("\nMovie not found\n");


    }
    else{

        printf("\nMovie found at index %d in array and row %d in the file\n\n",position, position +2 );
        printf("Movie Name : %s\n",movies[position].name );
        printf("Language   : %s\n",movies[position].language );
        printf("Year       : %d\n",movies[position].year );
        printf("Rating     : %.1f\n",movies[position].rating );
    }

}

void freeMemory(Movie **movies)
{
    free(*movies);
    *movies = NULL;
    
}