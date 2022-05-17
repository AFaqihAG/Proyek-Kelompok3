#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{    
    FILE *fpr;
    
    if((fpr = fopen("database/login.bin", "rb"))== NULL){
        printf("gagal membuka file !");
        return EXIT_FAILURE;
    }

    char akun[20];
    fread(akun, sizeof(char), sizeof(akun)/sizeof(char), fpr);

    fclose(fpr);

    char *string[3];
    char username[20], password[20];
    int ctrl = 0;

    string[0] = strtok(akun, "@");
    while(string[ctrl++] != NULL){
        string[ctrl] = strtok(NULL, "@");
    }

    strcpy(username, string[0]);
    strcpy(password, string[1]);

    printf("Username : %s\nPassword : %s", username, password);

    return 0;
}
