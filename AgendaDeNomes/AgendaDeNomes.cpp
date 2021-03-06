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
		Lista* ant = NULL;
		Lista* p = l;
		/* Encontrar elemento */ 
		while (p != NULL && p->nome != nome) 
		{
			ant = p;
			p = p->prox; 
		}
		/* verifica se achou elemento */
		if (p == NULL) {
			/* não achou: retorna lista original */
			cout << "Nome nao encontrado!!!" << endl;	
			system("pause");
			return l;
		}
		/* retira elemento */ 
		if (ant == NULL) {
			/* retira elemento do inicio */
			l = p->prox;
		}else {
			/* retira elemento do meio da lista */ 
			ant->prox = p->prox;
		}
		/* Apaga o elemento */
		delete p;
		cout << "Nome excluido!!!" << endl;
		system("pause");
		return l;
}

/*InsereOrdenado: insere os item na lista de forma ordenada*/
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

/*função menu: contem os menus*/
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
	case 3:
		cout << endl << "               .:: AGENDA DE NOMES ::." << endl;
		cout << endl << "-------------------- Deletar Nome --------------------" << endl;
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

/* executa: faz a execução das opções */
Lista * executa(Lista* l, int *retorno) {
	
	char dignome[100];
	string nome=" ";
	int menuopc = 5;
	cin >> menuopc;
	cin.ignore();
	system("cls");


	switch (menuopc)
	{
	case 1:/*cadastrar*/
		menu(1);
		getline(cin, nome);
		l = InsereOrdenado(l, nome);
		system("cls");
		*retorno = 0;
		return l;
	case 2:/*consultar*/
		menu(2);
		getline(cin, nome);
		consulta(l, nome);
		system("pause");
		system("cls");
		*retorno = 0;
		return l;
	case 3:/*deleta*/
		menu(3);
		getline(cin, nome);
		l = retira(l,nome);
		system("cls");
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
		system("pause");
		system("cls");
		*retorno = 0;
		break;
	}

}

int main()
{
	Lista* l = NULL;
	int result = 0, menuopc = 5;
	do
	{
		/*apresenta o menu*/
		menu(0);
		/*executa*/
		l = executa(l, &result);
	} while (result == 0);

	return 0;
}

