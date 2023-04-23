#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void version(void)
{
    time_t T1;
    int T2;
    T2 = time(&T1);

    printf("A program verzioszama: 1.0\n");
    printf("A program letrejottenek az ideje: %s",ctime(&T1));
    printf("A program keszitoje: Machaty Matyas\n");
}

void help(void)
{
    printf("Lehetseges parancssori argumentumok:\n");
    printf("--version: kiirja a program verzioszamat, elkeszultenek datumat es a fejleszto nevet\n");
    printf("-send: kuldo uzemmod\n");
    printf("-receive: fogado uzemmod\n");
    printf("-file: fajl kommunikacios mod\n");
    printf("-socket: socket kommunikacios mod\n");
}

int Measurement(int **Values) {
    time_t T1;
    int T2;
    T2 = time(&T1);

    srand((unsigned) time(&T1));

    int maxValues = T2 % 900;

    if(maxValues <= 99)
    {
        maxValues = 100;
    }

    // Dinamikus memória foglalása az értékek tárolására
    int *values = (int *)malloc(maxValues * sizeof(int));

    // A bolyongás implementálása
    int x = 0; // Kezdőérték
    values[0] = x;
    for (int i = 1; i < maxValues; i++) {
        int random = rand() % 100; // Véletlenszerű szám generálása 0 és 99 között

        // Az xi+1 = xi + 1 állítás 42,8571% eséllyel való teljesülése
        if (random < 42.8571) {
            x += 1;
        }
        // Az xi+1 = xi - 1 állítás 11/31-ed eséllyel való teljesülése
        else if (random < 42.8571 + (11.0 / 31.0) * 100) {
            x -= 1;
        }
        // Egyébként xi+1 = xi
        // (az xi+1 = xi eset a maradék 45,1429% eséllyel fordul elő)
        // A két szomszédos érték különbsége maximum 1
        // Azonos érték is előfordulhat
        values[i] = x;
    }

    // Az értékek átadása a Values pointernek
    *Values = values;

    // Az előállított értékek számával való visszatérés
    return maxValues;
}

int main(int argc, char* argv[])
{
    int *Values;
    int numValues = Measurement(&Values);
    int send_mode = 1;
    int file_mode = 1;

    if(argc < 2)
    {
            printf("send mode: %d\n", send_mode);
            printf("file mode: %d\n", file_mode);
    }
    else
    {
        if(strcmp(argv[1], "--version") == 0)
        {
            version();
        }
        else if(strcmp(argv[1], "--help") == 0)
        {
            help();
        }
        else
        {
            for (int i = 1; i < argc; i++)
            {
                if(strcmp(argv[i], "-send") == 0)
                {
                    printf("Elert ertekszam: %d\n", numValues);
                    printf("Elert ertekek: ");
                    for (int i = 0; i < numValues; i++)
                    {
                        printf("%d ", Values[i]);
                    }
                    printf("\n");

                    // A dinamikusan foglalt memória felszabadítása
                    free(Values);    
                }
                else if(strcmp(argv[i], "-receive") == 0)
                {
                    send_mode = 0;
                    printf("send mode: %d\n", send_mode);
                }
                else if(strcmp(argv[i], "-file") == 0)
                {
                    file_mode = 1;
                    printf("file mode: %d\n", file_mode);
                }
                else if(strcmp(argv[i], "-socket") == 0)
                {
                    file_mode = 0;
                    printf("file mode: %d\n", file_mode);
                }
                else if(i+1 == argc)
                {
                    help();
                }
            }   
        }
    }
    return 0;
}