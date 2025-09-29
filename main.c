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

/**
 * @brief Creates a new student record by prompting the user for input and storing it in the students array.
 * 
 * @param students Pointer to the array of Student structures where the new student will be stored
 * @param v_position Pointer to the current position/index in the students array, incremented after insertion
 * 
 * @return The newly created Student structure
 * 
 * @note This function reads user input for student ID, name, course, grades, enrollment year, and age.
 *       The v_position is incremented to point to the next available position in the array.
 */
Student createStudent(Student *students, int *v_position);

/**
 * @brief Displays all information about a student including personal details and academic data.
 * Calculates and shows the average of all grades.
 * 
 * @param student The Student structure containing all student information to display
 */
void displayStudent(Student student);


/**
 * @brief Displays all students in the array up to the specified position.
 * 
 * @param students Array of Student structures
 * @param v_position Number of students to display (valid positions)
 */
void listAllStudents(Student *students, int v_position);

int main() {
    int option; 
    int v_position = 0; // control students vector position
    Student students[MAX_STUDENTS];

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
        scanf("%d", &option);
        clear();
        switch(option) {
            case 1:
                if (v_position < MAX_STUDENTS) {
                    printf("\n#Cadastro de novo aluno\n");
                    Student new_student = createStudent(&students, &v_position);
                    displayStudent(new_student);
                } else printf("\nNao a espaco para cadastrar novos alunos");
                break;
            case 2:
                printf("\n#Lista todos alunos\n");
                listAllStudents(students, v_position);
                break;
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

    } while (option <= 8); 


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

Student createStudent(Student *students, int *v_position) {

    printf("RA: ");
    scanf(" %d", &students[*v_position].id);
    printf("Nome: ");
    scanf(" %[^\n]%*c", students[*v_position].name);
    printf("Curso: ");
    scanf(" %[^\n]%*c", students[*v_position].course);

    for (int i = 0; i < NUM_GRADES; i++) {
        printf("Nota %d: ", i+1);
        scanf("%f", &students[*v_position].grades[i]);
    }

    printf("Ano de inicio: ");
    scanf("%d", &students[*v_position].enrollmentYear);
    printf("Idade: ");
    scanf("%d", &students[*v_position].age);

    (*v_position)++; // increment the value of v_position variable

    printf("\nAluno cadastrado com sucesso\n");
    return students[*v_position-1]; 
}

void displayStudent(Student student) {
    printf("\nRA: %d", student.id);
    printf("\nNome: %s", student.name);
    printf("\nCurso: %s", student.course);
    float media = 0;
    for (int i = 0; i < NUM_GRADES; i++) {
        media += student.grades[i];
        printf("\nNota %d: %.1f", i+1, student.grades[i]);
    }
    printf("\nMedia das  notas: %.1f", media/NUM_GRADES);
    printf("\nAno de inicio: %d", student.enrollmentYear);
    printf("\nIdade: %d", student.age);
}

void listAllStudents(Student *students, int v_position) {
    for (int i = 0; i < v_position; i++) {
        displayStudent(students[i]);
    }
}

