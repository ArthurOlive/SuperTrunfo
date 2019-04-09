#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

constexpr int TAMMAXBARALHO = 32;	//constante

//A carta � referente a atributos de carros.
struct Carta
{
	char nome[30];		//os nomes podem ter espa�o
	int velocidadeMaxima;
	int cilindradas;
	int potencia;
	float comprimento;
	int peso;
};

//Um baralho tem varias cartas, e um tamanho que ir� servir para controle.
struct Baralho
{
	unsigned short tamanhoBaralho = 0; //parametro default � 0, pois entende-se que incialmente o baralho n�o tem cartas
	Carta Cartas[TAMMAXBARALHO]; //vetor estatico
	char cabecalho[8] = {'\0'}; //cria uma string vazia onde seus 7 primeiros bytes ser�o utilizados e formara uma string
};

//fun��es utilizadas no programa
void ListarCartas(const Baralho * baralho); //lista todas as cartas
void LeitorBaralho(Baralho * baralho);		//ler o arquivo binario e escreve no tipo baralho
void SalvarBaralho(const Baralho * baralho);//salva o baralho no arquivo binario
void ExcluirCarta(Baralho * baralho);		//exclui uma carta na memoria
void AlterarCarta(Baralho * baralho);		//aletera uma carta na memoria
void ImportandoArquivos(Baralho * baralho);	//importa um arquivo txt e salva na memoria
void CadastrarCarta(Baralho * baralho);		//cadastra uma carta na memoria
void MenuInicial(char * escolha);			//mostra a mensagem inicial e retorna a op��o escolhida pelo usuario