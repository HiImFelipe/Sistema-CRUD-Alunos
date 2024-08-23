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

bool CreateAluno(char *nome, int idade, int matricula, char *curso) {
  Aluno createdAluno = {nome, idade, matricula, curso};

  AlunoList *newAluno = (AlunoList *)malloc(sizeof(AlunoList));

  if (newAluno == NULL) {
    return false;
  }

  newAluno->aluno = createdAluno;
  newAluno->next = alunos;
  alunos = newAluno;

  return true;
}

void ListAlunos() {
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

  printf("%s", "Aluno não encontrado");
  return false;
}

bool DeleteAlunoByMatricula(int matricula) {
  AlunoList *tmp = alunos;
  AlunoList *prev = NULL;

  while (tmp != NULL) {
    if (tmp->aluno.matricula == matricula) {

      printf("Aluno com matricula %d foi deletado \n", matricula);

      if (prev == NULL) {
        alunos = tmp->next;
      } else {
        prev->next = tmp->next;
      }

      free(tmp);
      return true;
    }

    prev = tmp;
    tmp = tmp->next;
  }

  tmp = NULL;
  prev = NULL;

  return false;
}

int main() {
  CreateAluno("João", 20, 123, "Engenharia");
  CreateAluno("Maria", 21, 124, "Medicina");
  CreateAluno("José", 22, 125, "Direito");

  ListAlunos();

  GetAlunoByMatricula(123);

  DeleteAlunoByMatricula(123);

  return 0;
}
