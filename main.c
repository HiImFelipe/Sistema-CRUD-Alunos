#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
  char *nome;
  int idade;
  int matricula;
  char *curso;
} Aluno;

typedef struct AlunoList {
  Aluno aluno;
  struct AlunoList *next;
} AlunoList;

AlunoList *alunos = NULL;

bool CreateAluno(char nome[100], int idade, int matricula, char curso[50]) {
  Aluno createdAluno = {nome, idade, matricula, curso};

  AlunoList *newAluno = malloc(sizeof(*newAluno));

  if (newAluno == NULL) {
    return false;
  }

  newAluno->aluno = createdAluno;
  newAluno->next = alunos;
  alunos = newAluno;

  printf("Aluno %s criado com sucesso \n", alunos->aluno.nome);

  return true;
}

bool UpdateAluno(int matricula, char nome[100], int idade, char curso[50]) {
  AlunoList *tmp = alunos;

  while (tmp != NULL) {
    if (tmp->aluno.matricula == matricula) {

      if (strcmp(tmp->aluno.nome, nome) == 0 && tmp->aluno.idade == idade &&
          strcmp(tmp->aluno.curso, curso) == 0) {
        printf("Nenhuma alteração foi feita \n");
        return true;
      }

      if (nome != "" || nome != NULL) {
        free(tmp->aluno.nome);
        tmp->aluno.nome = nome;
      }

      if (curso != "" || curso != NULL) {
        free(tmp->aluno.curso);
        tmp->aluno.curso = curso;
      }

      tmp->aluno.idade = idade;

      printf("Aluno %s atualizado com sucesso \n", tmp->aluno.nome);

      return true;
    }

    tmp = tmp->next;
  }

  tmp = NULL;

  printf("Aluno não encontrado");
  return false;
}

void ListAlunos() {
  if (alunos == NULL) {
    printf("Nenhum aluno cadastrado \n");
    return;
  }

  AlunoList *tmp = alunos;

  while (tmp != NULL) {
    printf("%s %d %d %s \n", tmp->aluno.nome, tmp->aluno.idade,
           tmp->aluno.matricula, tmp->aluno.curso);

    tmp = tmp->next;
  }

  tmp = NULL;

  return;
}

bool GetAlunoByMatricula(int matricula) {
  AlunoList *tmp = alunos;

  while (tmp != NULL) {
    if (tmp->aluno.matricula == matricula) {
      printf("%s %d %d %s \n", tmp->aluno.nome, tmp->aluno.idade,
             tmp->aluno.matricula, tmp->aluno.curso);

      return true;
    }

    tmp = tmp->next;
  }

  tmp = NULL;

  printf("Aluno não encontrado");
  return false;
}

bool DeleteAlunoByMatricula(int matricula) {
  AlunoList *tmp = alunos;
  AlunoList *prev = NULL;

  while (tmp != NULL) {
    if (tmp->aluno.matricula == matricula) {

      if (prev == NULL) {
        alunos = tmp->next;
      } else {
        prev->next = tmp->next;
      }

      free(tmp->aluno.nome);
      free(tmp->aluno.curso);
      free(tmp);

      printf("Aluno com matricula %d foi deletado \n", matricula);

      return true;
    }

    prev = tmp;
    tmp = tmp->next;
  }

  tmp = NULL;
  prev = NULL;

  return false;
}

void CreateAlunoController() {
  char *nome = malloc(100);
  char *curso = malloc(50);
  int idade;
  int matricula;

  printf("Digite o nome do aluno: ");
  scanf("%99s", nome);

  printf("Digite a idade do aluno: ");
  scanf("%d", &idade);

  printf("Digite a matricula do aluno: ");
  scanf("%d", &matricula);

  printf("Digite o curso do aluno: ");
  scanf("%49s", curso);

  CreateAluno(nome, idade, matricula, curso);
}

void UpdateAlunoController() {
  char *nome = malloc(100);
  char *curso = malloc(50);
  int idade;
  int matricula;

  printf("Digite a matricula do aluno: ");
  scanf("%d", &matricula);

  if (!GetAlunoByMatricula(matricula)) {
    return;
  }

  printf("Digite o novo nome do aluno: ");
  scanf("%99s", nome);

  printf("Digite a nova idade do aluno: ");
  scanf("%d", &idade);

  printf("Digite o novo curso do aluno: ");
  scanf("%49s", curso);

  UpdateAluno(matricula, nome, idade, curso);
}

void GetAlunoByMatriculaController() {
  int matricula;

  printf("Digite a matricula do aluno: ");
  scanf("%d", &matricula);

  GetAlunoByMatricula(matricula);
}

void ListAlunosController() { ListAlunos(); }

void DeleteAlunoByMatriculaController() {
  int matricula;

  printf("Digite a matricula do aluno: ");
  scanf("%d", &matricula);

  DeleteAlunoByMatricula(matricula);
}

void ClearAlunos() {
  AlunoList *tmp = alunos;

  while (tmp != NULL) {
    AlunoList *next = tmp->next;

    free(tmp->aluno.nome);
    free(tmp->aluno.curso);
    free(tmp);

    tmp = next;
  }

  alunos = NULL;
}

void ClearScreen() {
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
  system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
  system("cls");
#endif
}

int main() {
  void (*options[])(void) = {
      CreateAlunoController,
      UpdateAlunoController,
      ListAlunosController,
      GetAlunoByMatriculaController,
      DeleteAlunoByMatriculaController,
  };

  for (;;) {
    ClearScreen();

    int option;

    printf("1 - Criar Aluno \n");
    printf("2 - Atualizar Aluno \n");
    printf("3 - Listar Alunos \n");
    printf("4 - Buscar Aluno pela Matrícula \n");
    printf("5 - Apagar Aluno \n");
    printf("6 - Sair \n");

    scanf("%d", &option);

    if (getchar() != '\n') {
      printf("Opção inválida \n");
      continue;
    }

    if (option > 6 || option < 1) {
      printf("Opção inválida \n");
      continue;
    }

    if (option == 6) {
      ClearAlunos();

      break;
    }

    options[option - 1]();
  }

  return 0;
}
