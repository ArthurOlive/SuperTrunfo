#include "CabecalhoJogo.h"

int main()
{
	Baralho baralho;		//cria um baralho
	LeitorBaralho(&baralho);//ler o baralho a partir do arquivo binario, aqui tambem é criado um vetor dinamico no ponteiro dentro de baralho.
	Jogador JogadorA , JogadorB; //cria os dois jogadores
	while(toupper(Menu()) == 'S')
	{
			//recebe os dados dos jogadores.
			cout << "Jogador 1: ";
			cin.ignore();
			cin.getline(JogadorA.nome, 20);
			cout << "Jogador 2: ";
			cin.getline(JogadorB.nome, 20);

			getCartas(&JogadorA ,&baralho);
			getCartas(&JogadorB, &baralho);

			for(int i = 0; i < 2; ++i)
			{
				logic(&JogadorA, &JogadorB, getAtributos(&JogadorA)); //vez do jogadorA
				JogadorA.mao.pop(); //para exclui a carta da pilha.
				JogadorB.mao.pop();	//para exclui a carta da pilha.
				cout << "Placar: " << JogadorA.pontuacao << " X " << JogadorB.pontuacao << endl << endl;
				cout << "------------------------\n";
				logic(&JogadorB, &JogadorA, getAtributos(&JogadorB)); //vez do jogadorB
				JogadorA.mao.pop(); //para exclui a carta da pilha.
				JogadorB.mao.pop();	//para exclui a carta da pilha.
				cout << "Placar: " << JogadorA.pontuacao << " X " << JogadorB.pontuacao << endl << endl;
				cout << "------------------------\n";
			}
			//diz quem é o vencendor
			if (JogadorA.pontuacao > JogadorB.pontuacao)
				cout << "O vencedor e " << JogadorA.nome << endl;
			else if (JogadorA.pontuacao < JogadorB.pontuacao)
				cout << "O vencedor e " << JogadorB.nome << endl;
			else
				cout << "O resultado foi um empate." << endl;

			//reseta os pontos, para o caso de mais uma partida.
			JogadorA.pontuacao = 0;
			JogadorB.pontuacao = 0;

			cin.ignore();
			system("pause");
			system("cls");
	}
	
	delete[] baralho.Cartas; //deleta o vetor dinamico 
	system("pause");
	return 0;
}

