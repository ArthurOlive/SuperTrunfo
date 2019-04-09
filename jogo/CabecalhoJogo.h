#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include <stack>
using namespace std;

constexpr int TAMMAXBARALHO = 32;

struct Carta
{
	//atributos de cartas
	char nome[30];
	int velocidadeMaxima;
	int cilindradas;
	int potencia;
	float comprimento;
	int peso;
};

struct Baralho
{
	char cabecalho[8] = {'\0'}; //cria uma string vazia onde seus 7 primeiros bytes serão utilizados e formara uma string
	unsigned short tamanhoBaralho = 0; //parametro default é 0, pois entende-se que incialmente o baralho não tem cartas
	Carta * Cartas; //mudar para vetor dinamico
};

struct Jogador
{
	char nome[20];
	stack <Carta *> mao; //pilha de ponteiros para cartas
	int pontuacao = 0;
};

void getCartas(Jogador * jogador, Baralho * baralho);			//popula as pilhas de cartas do jogador.
int getAtributos(Jogador * jogador);							//recebe a escolha do usuario.
void logic(Jogador * jogadorA, Jogador * jogadorB, int opc);	//logica do jogo.
void LeitorBaralho(Baralho * baralho);							//ler o arquivo binario e armazena no tipo baralho.
char Menu();