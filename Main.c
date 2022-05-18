#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{    
    FILE *fpr, *fpw, nilai = 0;
    char login[20] = "Kelompok3@1234abcd";
    char akun[20];
	
	//writing username/password
    fpw = fopen("database/login.bin", "wb");
    fwrite(login, sizeof(char), sizeof(login)/sizeof(char), fpw);
    fclose(fpw);
    
	//Check existance file
    if((fpr = fopen("database/Login.bin", "rb")) == NULL){
        printf("Gagal membuka file!");
        return EXIT_FAILURE;
    }
  	
	//Reading username/password
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
	
	
	printf("Anda menjawab %d pertanyaan dengan benar", nilai);
    return 0;
}
