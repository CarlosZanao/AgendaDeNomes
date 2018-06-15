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
		cout << "Nome: " << p->nome << endl;

}
/* função consulta: retorna busca de uma palavra*/
void consulta(Lista* l, string nome)
{
	int teste = 0;
	Lista* p;
	for (p = l; p != NULL; p = p->prox)
		if (p->nome == nome)
		{
			cout << "O Nome: " << p->nome << " Foi Localizado!!!" << endl;
			teste = 1;
		}
	if (teste != 1)
	{
		cout << "O Contato Nao Pode Ser Localizado!!!" << endl;
	}
	
		
}

/* função retira: retira elemento da lista */
Lista* retira(Lista* l, string nome) {
	return l;
}

Lista* InsereOrdenado(Lista* l, string v)
{
	Lista* novo = new Lista;
	novo->nome = v;
	Lista* ant = NULL; /* Ponteiro para o elemento anterior */
	Lista* p = l; /* Ponteiro para percorrer a lista*/
				  /* procura posição de inserção */
	while (p != NULL && p->nome < v) {
		ant = p;
		p = p->prox;
	}
	/* insere elemento */
	if (ant == NULL) { /* insere elemento no início */
		novo->prox = l;
		l = novo;
	}
	else { /* insere elemento no meio da lista */
		novo->prox = ant->prox;
		ant->prox = novo;
	}
	return l;
}

/*função menu: escreve o menu inicial na tela*/
void menu(int opc) {

	switch (opc)
	{
	case 0:
		cout << endl << "               .:: AGENDA DE NOMES ::." << endl;
		cout << endl << "1) Cadastrar 2) Buscar 3) Excluir 4) Mostrar 5) Sair" << endl;
		break;
	case 1:
		cout << endl << "               .:: AGENDA DE NOMES ::." << endl;
		cout << endl << "------------------ Cadastrar Nome -------------------" << endl;
		cout << "Digite o Nome: ";
		break;
	case 2:
		cout << endl << "               .:: AGENDA DE NOMES ::." << endl;
		cout << endl << "------------------ Consultar Nome -------------------" << endl;
		cout << "Digite o Nome: ";
		break;
	case 4:
		cout << endl << "               .:: AGENDA DE NOMES ::." << endl;
		cout << endl << "----------------- Nomes Cadastrados -----------------" << endl;

		break;
	default:
		break;
	}
}

Lista * executa(Lista* l, int *retorno) {
	
	string nome;
	int menuopc;

	cin >> menuopc;
	system("cls");
	
	switch (menuopc)
	{
	case 1:/*cadastrar*/
		menu(1);
		cin >> nome;
		l = InsereOrdenado(l, nome);
		system("cls");
		*retorno = 0;
		return l;
	case 2:/*consultar*/
		menu(2);
		cin >> nome;
		consulta(l, nome);
		system("pause");
		system("cls");
		*retorno = 0;
		return l;
	case 3:

		*retorno = 0;
		return l;
	case 4:/*Mostra cadastrados*/
		menu(4);
		imprime(l);
		system("pause");
		system("cls");
		*retorno = 0;
		return l;
	case 5:/*Sair*/
		*retorno = 1;
		return l;
	default:
		cout << "Opcao invalida!!!" << endl;
		break;
	}

}

int main()
{
	Lista* l = NULL;
	int result = 0;
	do
	{
		/*apresenta o menu*/
		menu(0);
		/*executa*/
		l = executa(l, &result);
	} while (result == 0);



	/*Lista*  l = NULL;
	l = insere(l, "NOME2");
	l = insere(l, "NOME1");
	l = insere(l, "NOME3");
	imprime(l);
	retira(l, "NOME2");
	imprime(l);*/
	return 0;
}

