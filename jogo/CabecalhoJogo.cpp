#include "CabecalhoJogo.h"

int getAtributos(Jogador * jogador)
{
	int opcao;
	do
	{
		cout << "[" << jogador->nome << "]" << endl;
		cout << "Carta " << jogador->mao.top()->nome << endl;
		cout << "1 - velocidadeMaxima" << endl;
		cout << "2 - cilindradas" << endl;
		cout << "3 - potencia" << endl;
		cout << "4 - comprimento" << endl;
		cout << "5 - peso" << endl;
		cout << "Escolha atributo [ ]\b\b";
		cin >> opcao;
	} while (opcao > 5 || opcao < 1);
	return opcao;
}

void logic(Jogador * jogadorA, Jogador * jogadorB, int opc)
{
	switch (opc)
	{
	case 1:
		//teste se a velocidade da carta do jogador A é maior, menor ou igual a velociadade da carta do jogador B
		if (jogadorA->mao.top()->velocidadeMaxima > jogadorB->mao.top()->velocidadeMaxima)
		{
			jogadorA->pontuacao += 2; //incrementa os pontos para o jogadorA
		}
		else if (jogadorA->mao.top()->velocidadeMaxima < jogadorB->mao.top()->velocidadeMaxima)
		{
			jogadorB->pontuacao += 2; //incrementa os pontos para o jogadorB
		}
		else
		{
			//incrementa os pontos para ambos os jogadores pois deu empate
			jogadorA->pontuacao += 1;
			jogadorB->pontuacao += 1;
		}
		//exibe na tela a carta e o atributo
		cout << "[" << jogadorA->nome << "]" << jogadorA->mao.top()->nome << " | " << jogadorA->mao.top()->velocidadeMaxima << endl;
		cout << "[" << jogadorB->nome << "]" << jogadorB->mao.top()->nome << " | " << jogadorB->mao.top()->velocidadeMaxima << endl;
		break;
	case 2:
		//testa se as cilidradas da carta do jogador A é maior, menor ou igual as cilidradas da carta do jogador B
		if (jogadorA->mao.top()->cilindradas > jogadorB->mao.top()->cilindradas)
		{
			jogadorA->pontuacao += 2; //incrementa os pontos para o jogadorA
		}
		else if (jogadorA->mao.top()->cilindradas < jogadorB->mao.top()->cilindradas)
		{
			jogadorB->pontuacao += 2; //incrementa os pontos para o jogadorB
		}
		else
		{
			//incrementa os pontos para ambos os jogadores pois deu empate
			jogadorA->pontuacao += 1;
			jogadorB->pontuacao += 1;
		}
		//exibe na tela a carta e o atributo
		cout << "[" << jogadorA->nome << "]" << jogadorA->mao.top()->nome << " | " << jogadorA->mao.top()->cilindradas << endl;
		cout << "[" << jogadorB->nome << "]" << jogadorB->mao.top()->nome << " | " << jogadorB->mao.top()->cilindradas << endl;
		break;
	case 3:
		//testa se a potencia da carta do jogador A é maior, menos ou igual a potencia da carta do jogador B
		if (jogadorA->mao.top()->potencia > jogadorB->mao.top()->potencia)
		{
			jogadorA->pontuacao += 2; //incrementa os pontos para o jogadorA
		}
		else if (jogadorA->mao.top()->potencia < jogadorB->mao.top()->potencia)
		{
			jogadorB->pontuacao += 2; //incrementa os pontos para o jogadorB
		}
		else
		{
			//incrementa os pontos para ambos os jogadores pois deu empate
			jogadorA->pontuacao += 1;
			jogadorB->pontuacao += 1;
		}
		//exibe na tela a carta e o atributo
		cout << "[" << jogadorA->nome << "]" << jogadorA->mao.top()->nome << " | " << jogadorA->mao.top()->potencia << endl;
		cout << "[" << jogadorB->nome << "]" << jogadorB->mao.top()->nome << " | " << jogadorB->mao.top()->potencia << endl;
		break;
	case 4:
		//testa se o comprimento da carta do jogador A é maior, menor ou igual o comprimento da carta do jogador B
		if (jogadorA->mao.top()->comprimento > jogadorB->mao.top()->comprimento)
		{
			jogadorA->pontuacao += 2; //incrementa os pontos para o jogadorA
		}
		else if (jogadorA->mao.top()->comprimento < jogadorB->mao.top()->comprimento)
		{ 
			jogadorB->pontuacao += 2; //incrementa os pontos para o jogadorB
		}
		else
		{
			//incrementa os pontos para ambos os jogadores pois deu empate
			jogadorA->pontuacao += 1;
			jogadorB->pontuacao += 1;
		}
		//exibe na tela a carta e o atributo
		cout << "[" << jogadorA->nome << "]" << jogadorA->mao.top()->nome << " | " << jogadorA->mao.top()->comprimento << endl;
		cout << "[" << jogadorB->nome << "]" << jogadorB->mao.top()->nome << " | " << jogadorB->mao.top()->comprimento << endl;
		break;
	case 5:
		//testa se o peso da carta do jogador A é maior, menor ou igual o peso da carta do jogador B
		if (jogadorA->mao.top()->peso > jogadorB->mao.top()->peso)
		{
			jogadorA->pontuacao += 2; //incrementa os pontos para o jogadorA
		}
		else if (jogadorA->mao.top()->peso < jogadorB->mao.top()->peso)
		{
			jogadorB->pontuacao += 2; //incrementa os pontos para o jogadorB
		}
		else
		{
			//incrementa os pontos para ambos os jogadores pois deu empate
			jogadorA->pontuacao += 1;
			jogadorB->pontuacao += 1;
		}
		//exibe na tela a carta e o atributo
		cout << "[" << jogadorA->nome << "]" << jogadorA->mao.top()->nome << " | " << jogadorA->mao.top()->peso << endl;
		cout << "[" << jogadorB->nome << "]" << jogadorB->mao.top()->nome << " | " << jogadorB->mao.top()->peso << endl;
		break;
	default:
		break;
	}
}

void getCartas(Jogador * jogador, Baralho * baralho)
{
	//coloca 4 endereços no stack do jogador.
	for (int i = 0; i < 4; i++)
	{
		jogador->mao.push(&baralho->Cartas[rand() % baralho->tamanhoBaralho]); //coloca o endereço da carta na pilha
	}

}

void LeitorBaralho(Baralho * baralho)
{
	ifstream leitor;
	//ler o arquivo binario.
	cout << "leitura binaria" << endl;
	leitor.open("..\\baralho.bin", ios_base::binary);
	//exerção lançada quando o arquivo nao foi aberto
	if (!leitor.is_open())
	{
		cout << "Arquivo nao existe" << endl;
		cout << "Crie um baralho apra jogar!!!" << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	else
	{
		leitor.read((char *)baralho->cabecalho, 7); //ler o cabecalho do arquivo binario
		if (!strcmp(baralho->cabecalho, "BARALHO")) //compara se o cabeçalho é igual a string BARALHO
		{
			leitor.read((char *)& baralho->tamanhoBaralho, 2); //ler o numero de cartas em 16 bits ou 2 bytes
			if (baralho->tamanhoBaralho == 0)
			{
				cout << "Baralho Vazio!!! Para jogar crie um baralho" << endl;
				system("pause");
				exit(EXIT_FAILURE);
			}
			baralho->Cartas = new Carta[baralho->tamanhoBaralho]; //cria o vetor dinamico
			for (int i = 0; i < baralho->tamanhoBaralho; ++i)
			{
				//ler todas as cartas armazenadas no arquivo binario.
				leitor.read((char *)& baralho->Cartas[i], sizeof(Carta));
			}
			cout << "Leitura realizada com sucesso." << endl;
		}
		else
		{
			cout << "Arquivo nao pertece ao programa";
		}
	}
	leitor.close();
}

char Menu()
{
	cout << "Super Trunfo Carros" << endl;
	cout << "--------------------" << endl;
	cout << "Iniciar nova partida ? [S / N]";
	return cin.get();
}