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

void menu() {
	cout << "aaa";
}

int main()
{	
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

