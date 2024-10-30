#include <stdio.h>
#include <string.h>
#define MAX_POKEMON 100

struct POKE
{
    int number;
    char name[50];
    char type[50];
};
int main()
{
    struct POKE VP[MAX_POKEMON];
    FILE *file;
    char line[150];
    int count = 0;

    file = fopen("Pokemon.csv", "r");
    if (file == NULL)
    {
        printf("Errore nell'apertura del file");
        return 0;
    }

    while (fgets(line, sizeof(line), file) && count < MAX_POKEMON)
    {
        sscanf(line, "%d,%49[^,],%49[^,\n]", &VP[count].number, VP[count].name, VP[count].type);
        count++;
    }

    fclose(file);

    printf("Contenuto VP:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Numero: %d, Nome: %s, Tipo: %s\n", VP[i].number, VP[i].name, VP[i].type);
    }

    struct POKE *longestNamePokemon = &VP[0];

    for (int i = 1; i < count; i++)
    {
        if (strlen(VP[i].name) > strlen(longestNamePokemon->name))
        {
            longestNamePokemon = &VP[i];
        }
    }

    printf("\nIl Pokémon con il nome più lungo è:\n");
    printf("Numero: %d, Nome: %s, Tipo: %s\n", longestNamePokemon->number, longestNamePokemon->name, longestNamePokemon->type);

    return 0;
}