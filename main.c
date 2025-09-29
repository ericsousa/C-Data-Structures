#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 40
#define NUM_GRADES 4

typedef struct {
    int id;
    char name[50];
    char course[50];
    float grades[NUM_GRADES];
    int enrollmentYear;
    int age;
} Student;

/**
 * @brief Clears the terminal/console screen in a cross-platform manner
 */
void clear();

int main() {
    int opcao;
    
    do {
        printf("\n\n\n------------------------------\n");
        printf("Sistema de controle de alunos:\n");
        printf("1 - Cadastrar novo aluno\n");
        printf("2 - Listar todos alunos\n");
        printf("3 - Buscar aluno pelo RA\n");
        printf("4 - Exibir o aluno com a maior media\n");
        printf("5 - Exibir a media das medias\n");
        printf("6 - Excluir um aluno pelo RA\n");
        printf("7 - Sair\n:");
        scanf("%d", &opcao);
        clear();
        switch(opcao) {
            case 1:
                printf("\n #Cadastro de novo aluno");
                break;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            default:
                printf("Opcao invalida.");
                break;
        }

    } while (opcao <= 8); 


    printf("C-Data-Structures");
    return 0;
}


void clear() {
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}