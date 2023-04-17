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

    printf("A program verziószáma: 1.0\n");
    printf("A program létrejöttének az ideje: %s",ctime(&T1));
    printf("A program keszitoje: Machaty Matyas\n");
}

void help(void)
{
    printf("Lehetséges parancssori argumentumok:\n");
    printf("--version: kiírja a program verziószámát, elkészültének dátumát és a fejlesztő nevét\n");
    printf("-send: küldő üzemmód\n");
    printf("-receive: fogadó üzemmód\n");
    printf("-file: fájl kommunikációs mód\n");
    printf("-socket: socket kommunikációs mód\n");
}

int main(int argc, char* argv[])
{
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
                    send_mode = 1;
                    printf("send mode: %d\n", send_mode);    
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