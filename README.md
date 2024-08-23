# Sistema de Cadastro de Alunos

**Objetivo:** Desenvolver um programa em C que permita o cadastro de alunos utilizando struct. O sistema deve armazenar informações básicas sobre os alunos, como nome, idade, matrícula e curso.

## Instruções

#### Definição da struct

Crie uma struct chamada Aluno que contenha os seguintes campos:

- char nome[100];
- int idade;
- int matricula;
- char curso[50];

#### Criação de Funções

**Cadastrar Aluno**

- [x] Implemente uma função para cadastrar um aluno. A função deve receber os dados do aluno e armazená-los em um array de struct Aluno.

**Listar Alunos**

- [x] Crie uma função que liste todos os alunos
      cadastrados.

**Buscar Aluno por Matrícula**

- [x] Desenvolva uma função que receba uma matrícula como parâmetro e retorne as informações do aluno correspondente.

**Atualizar Cadastro**

- [ ] Crie uma função para atualizar os dados de um aluno já cadastrado, identificando-o pela matrícula.

**Remover Aluno**

- [x] Implemente uma função que remova um aluno do sistema, também identificando-o **pela matrícula**.

**Menu de Opções**

Crie um menu de opções no main que permita ao usuário:

- [ ] Cadastrar um novo aluno.
- [ ] Listar todos os alunos.
- [ ] Buscar um aluno por matrícula.
- [ ] Atualizar informações de um aluno.
- [ ] Remover um aluno.

## Considerações do Aluno

A matéria, até o presente dia, não nos apresentou ponteiros ou estruturas mais complexas como listas ligadas. A implementação dos mesmos, utilizados neste projeto, são extras e utilizados apenas para treino pessoal.

O projeto não têm nenhum tipo de peso nas notas do semestre.