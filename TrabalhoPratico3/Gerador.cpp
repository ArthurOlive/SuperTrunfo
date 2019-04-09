#include "CabecalhoGerador.h"

int main()
{
	char escolha;
	Baralho baralho;

	LeitorBaralho(&baralho); //ler o arquivo binario e armazena em baralho 

	//recebe a escolha do usuario e testa antes de entrar no laço.
	while (MenuInicial(&escolha), toupper(escolha) != 'S'){
		switch (toupper(escolha)) // transforma a escolha em maiuscula para usar 
		{
		case 'C':
			CadastrarCarta(&baralho);
			system("pause");
			system("cls");
			break;
		case 'I':
			ImportandoArquivos(&baralho);
			system("pause");
			system("cls");
			break;
		case 'A':
			AlterarCarta(&baralho);
			system("pause");
			system("cls");
			break;
		case 'E':
			ExcluirCarta(&baralho);
			system("pause");
			system("cls");
			break;
		case 'L':
			ListarCartas(&baralho);
			system("pause");
			system("cls");
			break;
		default:
			cout << "Opcao invalida.\n";
			system("pause");
			system("cls");
			break;
		}
	} 

	cout << "Atualizando arquivo binario" << endl;
	SalvarBaralho(&baralho);
	cout << "tenha um bom jogo.\n";

	system("pause");
	return 0;
}
