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

int main() {
  void (*options[])(void) = {
      CreateAlunoController,
      ListAlunosController,
      GetAlunoByMatriculaController,
      DeleteAlunoByMatriculaController,
  };

  for (;;) {
    int option;

    printf("1 - Criar Aluno \n");
    printf("2 - Listar Alunos \n");
    printf("3 - Buscar Aluno pela Matrícula \n");
    printf("4 - Apagar Aluno \n");
    printf("5 - Sair \n");

    scanf("%d", &option);

    if (getchar() != '\n') {
      printf("Opção inválida \n");
      continue;
    }

    if (option > 5 || option < 1) {
      printf("Opção inválida \n");
      continue;
    }

    if (option == 5) {
      ClearAlunos();

      break;
    }

    options[option - 1]();
  }

  return 0;
}
