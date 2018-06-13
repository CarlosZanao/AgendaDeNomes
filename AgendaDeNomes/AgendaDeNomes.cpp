// AgendaDeNomes.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

struct lista {
	string nome;
	struct lista* ant;
	struct lista* prox;
};

typedef struct lista Lista;

/* inserção no início */
Lista* insere(Lista* l, string nome)
{
	Lista* novo = new Lista;
	novo->nome = nome;
	novo->prox = l;
	novo->ant = NULL;
	/* verifica se lista não está vazia */
	if (l != NULL)
		l->ant = novo;
	return novo;
}

/* função imprime: imprime valores dos elementos */
void imprime(Lista* l)
{
	Lista* p;
	for (p = l; p != NULL; p = p->prox)
		cout << "Registro = " << p->nome << endl;

}


/* função retira: retira elemento da lista */
Lista* retira(Lista* l, string nome) {
	//IMPLEMENTAR
	return l;
}
/*função menu: escreve o menu inicial na tela*/
void menu() {

	cout << endl << "               .:: AGENDA DE NOMES ::." << endl;
	cout << endl << "1) Cadastrar 2) Buscar 3) Excluir 4) Mostrar 5) Sair" << endl;

}

int main()
{	
	int menuopc = 0;

	/*apresenta o menu*/
	menu();
	

	cin >> menuopc;

	switch (menuopc)
	{
		case 1:
			
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		default:
			cout << "Opcao invalida!!!" << endl;
			break;
	}

	/*Lista*  l = NULL;
	l = insere(l, "NOME2");
	l = insere(l, "NOME1");
	l = insere(l, "NOME3");
	imprime(l);
	retira(l, "NOME2");
	imprime(l);*/
	system("pause");
	return 0;
}

