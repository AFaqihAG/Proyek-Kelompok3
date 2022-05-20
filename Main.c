#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void answer_check(char kunci_jawaban[], int nomor_soal, int *nilai);
void list_pertanyaan(int i);

int main( int argc, char *argv[] )
{    
    FILE *fpr, *fpw; 
    int nilai = 0; //Nilai benar menjawab soal
    char login[20] = "Kelompok3@1234abcd"; //Username/password
    char akun[20], kunci_jawaban[6] = "CBBAD"; //Kunci jawaban no 1-5
	
    if (argc != 3) {
        printf("Input: 'File eksekusi' 'Username' 'Password'");
        return EXIT_FAILURE;
    }

	//Menuliskan username/password ke dalam file bin
    fpw = fopen("database/login.bin", "wb");
    fwrite(login, sizeof(char), sizeof(login)/sizeof(char), fpw);
    fclose(fpw);
    
	//Cek ada/tidaknya file
    if((fpr = fopen("database/Login.bin", "rb")) == NULL){
        printf("Gagal membuka file!");
        return EXIT_FAILURE;
    }
  	
	//Membaca username dan password pada file bin
    fread(akun, sizeof(char), sizeof(akun)/sizeof(char), fpr);

    fclose(fpr);
    
    char *string[3];
    char username[20], password[20], username_input[20], password_input[20];
    int ctrl = 0;
    
    string[0] = strtok(akun, "@");
	
	//Memisahkan username dan password pada file bin
    while(string[ctrl++] != NULL){
        string[ctrl] = strtok(NULL, "@");
    }

    //Mendapatkan username dan password dari file bin dan user
    strcpy(username, string[0]);
    strcpy(password, string[1]);
    strcpy(username_input, argv[1]);
    strcpy(password_input, argv[2]);	

    //Cek username dan password
    if( (strcmp(username, username_input) == 0) && (strcmp(password, password_input) == 0)) {
	    printf("\nSelamat anda berhasil login\n\n");
	} 
    else {
	    printf("Username/password anda tidak sesuai!\n");
        printf("Input: 'File eksekusi' 'Username' 'Password'");
        return EXIT_FAILURE;
	}

    //Pertanyaan
    for (int i = 1; i <= 5; i++) {
        list_pertanyaan(i);
        answer_check(kunci_jawaban, i, &nilai);  
    }

    printf("Anda menjawab %d dari 5 pertanyaan dengan benar!", nilai);
    return EXIT_SUCCESS;
}

void answer_check(char kunci_jawaban[], int nomor_soal, int *nilai) {
    char jawaban_input[3];
    char backup[3];
    printf("Jawaban anda [A/B/C/D] : ");
    gets(jawaban_input);

    //User mengetik lebih dari satu karakter (meminta ulang jawaban)
    if (strlen(jawaban_input) > 1) {
        printf("Masukkan tepat satu huruf untuk menjawab!\n");
        printf("Jawaban anda [A/B/C/D] : ");
        gets(backup);
        strcpy(jawaban_input, backup);
    }

    //Cek jawaban user dengan kunci jawaban
    if (*jawaban_input == kunci_jawaban[nomor_soal - 1] || *jawaban_input == tolower(kunci_jawaban[nomor_soal - 1])) {
        printf("Jawaban anda benar\n\n");
        (*nilai)++;
    } 
    else {
        printf("Jawaban anda salah\n\n");
    } 
}

//Self explanatory
void list_pertanyaan(int i) {
    switch (i)
    {
    case 1:
        printf("|+---------------------------------------+|\n");
        printf("|  1. Apakah ibukota negara indonesia?    |\n");
        printf("|+---------------------------------------+|\n");
        printf("|  a.Bangkok         |b.Manila            |\n");
        printf("|+---------------------------------------+|\n");
        printf("|  c.Jakarta         |d.Singapura         |\n");
        printf("|+---------------------------------------+|\n");
        break;
    case 2:
        printf("|+---------------------------------------+|\n");
        printf("|  2. Apakah lambang negara indonesia?    |\n");
        printf("|+---------------------------------------+|\n");
        printf("|  a.Elang           |b.Garuda            |\n");
        printf("|+---------------------------------------+|\n");
        printf("|  c.Kepala banteng  |d.Pohon beringin    |\n");
        printf("|+---------------------------------------+|\n");
        break;
    case 3:
        printf("|+-----------------------------------------+|\n");
        printf("| 3. Apakah warna bendera negara indonesia? |\n");
        printf("|+-----------------------------------------+|\n");
        printf("|  a.Putih biru        |b.Merah putih       |\n");
        printf("|+-----------------------------------------+|\n");
        printf("|  c.Putih merah       |d.Merah biru        |\n");
        printf("|+-----------------------------------------+|\n");
        break;
    case 4:
        printf("|+---------------------------------------+|\n");
        printf("| 4.Siapa presiden ke-7 negara indonesia? |\n");
        printf("|+---------------------------------------+|\n");
        printf("|  a.Jokowi dodo      |b.SBY              |\n");
        printf("|+---------------------------------------+|\n");
        printf("|  c.Soekarno         |d.Megawati         |\n");
        printf("|+---------------------------------------+|\n");
        break;
    case 5:   
        printf("|+-------------------------------------------+|\n");
        printf("| 5.Tahun berapakah negara indonesia merdeka? |\n");
        printf("|+-------------------------------------------+|\n");
        printf("|  a.1954              |b.1944                |\n");
        printf("|+-------------------------------------------+|\n");
        printf("|  c.1955              |d.1945                |\n");
        printf("|+-------------------------------------------+|\n");
        break; 
    }
}
