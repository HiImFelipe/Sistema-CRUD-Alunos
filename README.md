 
<h1 align="center">🖋️ Sistema de Cadastro de Alunos</h1>

<br/>

<p align="center">
  <img src="https://github.com/user-attachments/assets/582955cd-22a9-4306-83e0-c7733c5097b0"/>
</p>

**Objetivo:** Desenvolver um programa em C que permita o cadastro de alunos utilizando struct. O sistema deve armazenar informações básicas sobre os alunos, como nome, idade, matrícula e curso.

## 📖 Instruções

### Definição da struct

Crie uma struct chamada Aluno que contenha os seguintes campos:

- char nome[100];
- int idade;
- int matricula;
- char curso[50];

### Criação de Funções

**Cadastrar Aluno**

- [x] Implemente uma função para cadastrar um aluno. A função deve receber os dados do aluno e armazená-los em um array de struct Aluno.

**Listar Alunos**

- [x] Crie uma função que liste todos os alunos
      cadastrados.

**Buscar Aluno por Matrícula**

- [x] Desenvolva uma função que receba uma matrícula como parâmetro e retorne as informações do aluno correspondente.

**Atualizar Cadastro**

- [x] Crie uma função para atualizar os dados de um aluno já cadastrado, identificando-o pela matrícula.

**Remover Aluno**

- [x] Implemente uma função que remova um aluno do sistema, também identificando-o **pela matrícula**.

**Menu de Opções**

Crie um menu de opções no main que permita ao usuário:

- [x] Cadastrar um novo aluno.
- [x] Listar todos os alunos.
- [x] Buscar um aluno por matrícula.
- [x] Atualizar informações de um aluno.
- [x] Remover um aluno.

## 💻 Como rodar o projeto

Para gerar o binário do projeto, eu utilizo `gcc` da seguinte maneira

```
gcc -o app main.c
```

Para rodar de fato, utilizamos a sintaxe abaixo

```
./app
```

O nome `app` é genérico e pode ser alterado para o que desejar.

## 📑 Considerações

A matéria, até o presente dia, não nos apresentou ponteiros ou estruturas mais complexas como listas ligadas. A implementação dos mesmos, utilizados neste projeto, são extras e utilizados apenas para treino pessoal.

O projeto não têm nenhum tipo de peso nas notas do semestre.

## ⌚ Desafios Durante o Desenvolvimento

O uso de malloc para salvar as strings (nome, curso) da variável `alunos` foi imprescindível, pois, após a criação, o programa realizava uma liberação de memória ao final da execução da função CreateAlunoController. Isto fazia com que a listagem de Alunos tentasse printar um valor em um espaço de memória que o programa já não reconhecia, fazendo com que o programa mostrasse `trash values` no terminal.

Isto também me trouxe alguns desafios como: utilizar a função `free` corretamente para não causar nenhum tipo de memory leak ao final da execução do programa.
