/**
 * @Author: Matheus de Souza Sereno <matheus>
 * @Date:   2018-08-07T19:36:30-03:00
 * @Email:  matheus.sereno@usp.br
 * @Filename: agenda.c
 * @Last modified by:   matheus
 * @Last modified time: 2018-08-11T20:51:40-03:00
 */

 //(*(contato+i))
#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa{
  char nome[30];
  char endereco[50];
};

struct Agenda{
  p* contato;
};

int size_agenda = 0;

p* esta_na_agenda(a* agenda, char* nome ){
  if(size_agenda == 0)
    return NULL;
  for(int i = 0; i<size_agenda; i++){
    if( !strcmp(nome,agenda->contato[i].nome) )
      return &agenda->contato[i];
  }
  return NULL;
}

int busca_posicao(a* agenda, char* nome){
  for(int i = 0; i<size_agenda; i++){
    if(!strcmp(nome,agenda->contato[i].nome))
      return i;
  }
  return -10;
}

void mostrar_agenda(a* agenda){
  for(int i = 0; i<size_agenda; i++){
    printf("%dº Contato: Nome: %s, Endereço: %s\n",i+1,agenda->contato[i].nome,agenda->contato[i].endereco);
  }
}

int insere_na_agenda(a* agenda, char* nome, char* endereco){
  if(size_agenda == 0){
    size_agenda++;
  }else
    agenda->contato = (p*)realloc(agenda->contato,++size_agenda);
  if (agenda->contato != NULL) {
    strcpy(agenda->contato[size_agenda-1].nome, nome);
    strcpy(agenda->contato[size_agenda-1].endereco, endereco);
    return 1;
  }else
    return 0;
}

char tira_da_agenda(a* agenda, char* nome){
  if(size_agenda == 0)
    return '!';
  int test = busca_posicao(agenda,nome);
  if(test!= -10){
    p* contatos_aux;
    contatos_aux = (p*)malloc( (--size_agenda) * sizeof(p));
    if (contatos_aux != NULL) {
      for(int i = 0; i<size_agenda+1; i++){
        if(i >= test){
          contatos_aux[i] = agenda->contato[i+1];
          if(i == size_agenda )
          break;
        }else
          contatos_aux[i] = agenda->contato[i];
      }
      free(agenda->contato);
      agenda->contato = contatos_aux;
      return '1';
    }else
      return '0';
  }else
    return '1';
}

p* busca_endereco(a* agenda, char* nome){
  if(size_agenda == 0)
    return NULL;
  for(int i = 0; i<size_agenda; i++){
    if(!strcmp(nome,agenda->contato[i].endereco) )
        return &agenda->contato[i];
  }
  return NULL;
}

void desalocar_memoria(a* agenda){
  free(agenda->contato);
  free(agenda);
}
