#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{    
    FILE *fpr;
    char login[20] = "Kelompok3@1234abcd";
    char akun[20];
    
    //Check existance file
    if((fpr = fopen("database/Login.bin", "rb+")) == NULL){
        printf("Gagal membuka file!");
        return EXIT_FAILURE;
    }
  	
	//Writing & Reading username/password
    fwrite(login, sizeof(char), sizeof(login)/sizeof(char), fpr);
    fread(akun, sizeof(char), sizeof(akun)/sizeof(char), fpr);

    fclose(fpr);
    
    char *string[3];
    char username[20], password[20];
    int ctrl = 0;
    
    string[0] = strtok(akun, "@");
	
	//Getting username/password from bin file
    while(string[ctrl++] != NULL){
        string[ctrl] = strtok(NULL, "@");
    }

    strcpy(username, string[0]);
    strcpy(password, string[1]);

    printf("Username : %s\nPassword : %s", username, password);

    return 0;
}
