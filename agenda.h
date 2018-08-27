/**
 * @Author: Matheus de Souza Sereno <matheus>
 * @Date:   2018-08-07T19:24:37-03:00
 * @Email:  matheus.sereno@usp.br
 * @Filename: agenda.h
 * @Last modified by:   matheus
 * @Last modified time: 2018-08-11T20:46:49-03:00
 */
typedef struct Pessoa p;
typedef struct Agenda a;
extern int size_agenda;
void mostrar_agenda(a* agenda);
p* esta_na_agenda(a* agenda, char* nome );
int insere_na_agenda(a* agenda, char* nome, char* endereco);
char tira_da_agenda(a* agenda, char* nome);
p* busca_endereco(a* agenda, char* nome);
int busca_posicao(a* agenda, char*nome);
void desalocar_memoria(a* agenda);
