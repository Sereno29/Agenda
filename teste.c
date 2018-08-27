/**
 * @Author: Matheus de Souza Sereno <matheus>
 * @Date:   2018-08-07T19:41:12-03:00
 * @Email:  matheus.sereno@usp.br
 * @Filename: teste.c
 * @Last modified by:   matheus
 * @Last modified time: 2018-08-07T21:41:42-03:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

void ler(char* nome, char* endereco, char op){
  if(op == '3'){
    printf("\nVocê escolheu adicionar um contato.\n Insira o nome: ");
    scanf(" %s",nome);
    printf("Agora insira o endereço de %s:\n",nome);
    scanf(" %s",endereco);
  }else{
    if(op == '2'){
      printf("\nVocê escolheu buscar um endereço.\n Insira o endereço: ");
      scanf(" %s",endereco);
    }else{
      printf("Insira o nome: ");
      scanf(" %s",nome);
    }
  }
}

void menu(a* agenda){
  char escolha, nome[30], endereco[50],erro, vazio = '\n';
  struct Pessoa* pessoa_contato = NULL;
  do{
    printf("\n\t\t\tBem-vindo à sua Agenda Eletrônica!!\n");
    printf("Escolha abaixo uma das tarefas a ser executada:\n");
    printf("(0)Mostrar contatos\n(1)Inserir contato\n(2)Excluir contato\n");
    printf("(3)Pesquisar Nome\n(4)Pesquisar Endereço\n(5)Sair\nEscolha:");
    scanf(" %c",&escolha);
    switch(escolha){
      case '0':
      //Mostrar Contatos
        mostrar_agenda(agenda);
        break;
      case '1':
      //Inserir Contato
        ler(nome,endereco,'3');//função a se fazerS
        if( strcmp(nome,&vazio) || strcmp(endereco,&vazio) ){
            printf("É preciso que tanto o nome como o endereço sejam preenchidos\n");
            break;
        }
        insere_na_agenda(agenda,nome,endereco);
        break;
      case '2':
      //Excluir Contato
        printf("\nVocê escolheu excluir um contato.\n");
        ler(nome,endereco,'1');
        if( strcmp(nome,&vazio) ){
            printf("É preciso que o nome seja preenchido\n");
            break;
        }
        erro = tira_da_agenda(agenda,nome);
        if(erro == '!')
          printf("\nA agenda está vazia.\n");
        else{
          if(erro == '0')
            printf("\nFalha ao alocar o novo espaço.\n");
        }
        break;
      case '3':
      //Buscar Contato pelo Nome
        printf("\nVocê escolheu buscar um contato.\n");
        ler(nome,endereco,'1');
        if( strcmp(nome,&vazio) ){
            printf("É preciso que o nome seja preenchido\n");
            break;
        }
        pessoa_contato = esta_na_agenda(agenda,nome);
        if(pessoa_contato == NULL)
          printf("\nA agenda está vazia ou o contato não foi encontrado.\n");
        else{
          printf("\nContato: %s\t%s\n", pessoa_contato->nome, pessoa_contato->endereco);
        }
        break;
      case '4':
      //Buscar Endereço do Contato pelo Nome
        ler(nome,endereco,'1');
        if( strcmp(nome,&vazio) ){
            printf("É preciso que o nome seja preenchido\n");
            break;
        }
        pessoa_contato = busca_endereco(agenda,nome);
        if(pessoa_contato == NULL)
          printf("\nA agenda está vazia ou o contato não foi encontrado.\n");
        else{
            printf("\nContato: %s\t%s\n", pessoa_contato->nome, pessoa_contato->endereco);
        }
        break;
      case '5':
        break;
      default:
        printf("\nOpção inválida!\n");
        escolha = '!';
        break;
    }
  }while(escolha != '5');
}

int main(int argc, char *argv[]){
  a* agenda;
  agenda = (a*)malloc(sizeof(a*));
  if (agenda != NULL) {
    menu(agenda);
  }
  desalocar_memoria(agenda);
  return 0;
  }
