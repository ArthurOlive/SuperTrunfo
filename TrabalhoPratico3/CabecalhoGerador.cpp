#include "CabecalhoGerador.h"

void ListarCartas(const Baralho * baralho)
{
	cout << "Atual baralho:" << endl;
	//se o tamanho do baralho for maior do que 0. nao faz sentido listar um baralho vazio
	if (baralho->tamanhoBaralho != 0)
	{
		//lista todos os atributos
		for (int i = 0; i < baralho->tamanhoBaralho; i++)
		{
			cout << "#" << i + 1 << " ";
			cout << baralho->Cartas[i].nome << " ";
			cout << baralho->Cartas[i].velocidadeMaxima << " ";
			cout << baralho->Cartas[i].cilindradas << " ";
			cout << baralho->Cartas[i].potencia << " ";
			cout << baralho->Cartas[i].comprimento << " ";
			cout << baralho->Cartas[i].peso << " " << endl;
		}
	}
	else
	{
		cout << "Baralho vazio" << endl;
	}
}

void LeitorBaralho(Baralho * baralho)
{
	ifstream leitor;	//Leitor do arquivo binario

	cout << "leitura binaria" << endl;
	leitor.open("..\\baralho.bin", ios_base::binary);
	if (!leitor.is_open()) //se o arquivo nao foi aberto
	{
		cout << "Arquivo nao existe" << endl;

		//criando o arquivo
		ofstream escritor;	//Escitor do arquivo binario

		cout << "Criando arquivo." << endl;
		escritor.open("..\\baralho.bin", ios_base::binary, ios_base::trunc); //escreve um arquivo binario novo com o nome de baralho.bin
		if (!escritor.is_open()) //se o arquivo nao pode ser criado 
		{
			cout << "Arquivo nao pode ser criado";
		}
		else
		{
			escritor.write((char *) "BARALHO", 7); //coloca o nome BARALHO nos 7 primeiros byts
			escritor.write((char *)& baralho->tamanhoBaralho, 2); //cria o numero de cartas em 16 bits ou 2 bytes
			cout << "Arquivo criado com suecesso. " << endl;
		}
		escritor.close();
	}
	else
	{
		leitor.read((char *)baralho->cabecalho, 7); //ler o cabecalho do arquivo binario.
		if (!strcmp(baralho->cabecalho, "BARALHO")) //compara se o cabeçalho é igual a string BARALHO
		{
			leitor.read((char *)& baralho->tamanhoBaralho, 2); //ler o numero de cartas em 16 bits ou 2 bytes
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

void SalvarBaralho(const Baralho * baralho)
{
	ofstream escritor;	//Leitor do arquivo binario
	ifstream leitor;	//Escitor do arquivo binario
	//salva o vetor no arquivo binario
	escritor.open("..\\baralho.bin", ios_base::binary, ios_base::trunc);
	if (!escritor.is_open())//se o arquivo nao foi aberto
	{
		cout << "Erro ao abrir o arquivo";
	}
	else
	{
		escritor.write((char *) "BARALHO", 7); //salva o nome baralho no cabecalho do arquivo em 7 bytes
		escritor.write((char *)& baralho->tamanhoBaralho, 2); //salva o numero de cartas em 16 bits ou 2 bytes
		for (int i = 0; i < baralho->tamanhoBaralho; i++)
		{
			escritor.write((char *)& baralho->Cartas[i], sizeof(Carta));
		}
		cout << "Baralho atualizado com sucesso." << endl;
	}
	escritor.close();
	//==================================
}

void ExcluirCarta(Baralho * baralho)
{
	int escolha;
	//caso o baralho esteja vazio nao se pode excluir nenhuma carta.
	if (baralho->tamanhoBaralho != 0)
	{
		cout << "Excluir Cartas" << endl;
		cout << "----------------" << endl;
		for (int i = 0; i < baralho->tamanhoBaralho; i++)
		{
			cout << i + 1 << ") " << baralho->Cartas[i].nome << endl;
		}
		cout << "Digite o número da carta : [ ]\b\b";
		cin >> escolha;
		//O usuario poderia escolher um numero invalido gerando um erro de execursão, por isso a carta so sera excluida se escolha for menor que o numero de cartas do baralho e maior do que 0
		if (escolha <= baralho->tamanhoBaralho && escolha > 0)
		{
			escolha--; //se subtrai 1 para se utilizar no local do indice do vetor cartas.

			cout << baralho->Cartas[escolha].nome << " foi excluida" << endl;

			//substitui a carta que esta sendo excluida, pela ultima carata do vetor de cartas
			//O programa do visual studio nao me deixou utilizar o strcpy. mesmo atribuindo #define _CRT_SECURE_NO_WARNINGS
			strcpy_s(baralho->Cartas[escolha].nome, baralho->Cartas[baralho->tamanhoBaralho - 1].nome);
			baralho->Cartas[escolha].velocidadeMaxima = baralho->Cartas[baralho->tamanhoBaralho - 1].velocidadeMaxima;
			baralho->Cartas[escolha].cilindradas = baralho->Cartas[baralho->tamanhoBaralho - 1].cilindradas;
			baralho->Cartas[escolha].potencia = baralho->Cartas[baralho->tamanhoBaralho - 1].potencia;
			baralho->Cartas[escolha].comprimento = baralho->Cartas[baralho->tamanhoBaralho - 1].comprimento;
			baralho->Cartas[escolha].peso = baralho->Cartas[baralho->tamanhoBaralho - 1].peso;

			//se coloca parametros vazios no local da ultima carta.
			/*OBS: essa atribuição de valores 0 e " " é de certa forma inutil. pois com o decremento do tamanho do baralho
			  essa carta nao aparecerar mais, e portanto nao sera salva no arquivo binario.
			*/
			//O programa do visual studio nao me deixou utilizar o strcpy. mesmo atribuindo #define _CRT_SECURE_NO_WARNINGS
			strcpy_s(baralho->Cartas[baralho->tamanhoBaralho - 1].nome, " "); 
			baralho->Cartas[baralho->tamanhoBaralho - 1].velocidadeMaxima = 0;
			baralho->Cartas[baralho->tamanhoBaralho - 1].cilindradas = 0;
			baralho->Cartas[baralho->tamanhoBaralho - 1].potencia = 0;
			baralho->Cartas[baralho->tamanhoBaralho - 1].comprimento = 0;
			baralho->Cartas[baralho->tamanhoBaralho - 1].peso = 0;

			baralho->tamanhoBaralho--; //diminui o tamanho do baralho
		}
		else
		{
			cout << "Carta invalida!!!" << endl; //quando o numero digitado é invalido
		}
	}
	else
	{
		cout << "Baralho sem cartas" << endl;
	}
}
void AlterarCarta(Baralho * baralho)
{
	int escolha;
	//não se poder alterar cartas de um baralho vazio
	if (baralho->tamanhoBaralho != 0)
	{
		cout << "Atualizar Cartas" << endl;
		cout << "----------------" << endl;
		
		//lista o nome das cartas
		for (int i = 0; i < baralho->tamanhoBaralho; i++)
		{
			cout << i + 1 << ") " << baralho->Cartas[i].nome << endl;
		}

		cout << "Digite o número da carta : [  ]\b\b\b";
		cin >> escolha;
		//O usuario poderia escolher um numero invalido gerando um erro de execursão, por isso a carta so sera excluida se escolha for menor que o numero de cartas do baralho e maior do que 0
		if (escolha <= baralho->tamanhoBaralho && escolha > 0)
		{
			escolha--;//se subtrai 1 para se utilizar no local do indice do vetor cartas.

			cout << "Alterando Carta " << baralho->Cartas[escolha].nome << endl;
			//altera o vetor de cartas no indice passado.
			cout << "Nome:              ";
			cin.ignore();
			cin.getline(baralho->Cartas[escolha].nome, 50);
			cout << "Velocidade Maxima: ";
			cin >> baralho->Cartas[escolha].velocidadeMaxima;
			cout << "Cilindradas:       ";
			cin >> baralho->Cartas[escolha].cilindradas;
			cout << "Potencia:          ";
			cin >> baralho->Cartas[escolha].potencia;
			cout << "Comprimento:       ";
			cin >> baralho->Cartas[escolha].comprimento;
			cout << "Peso:              ";
			cin >> baralho->Cartas[escolha].peso;
			cout << "\nCarta alterada com sucesso" << endl;
		}
		else 
		{
			cout << "Carta invalida!!!" << endl;
		}
	}
	else
	{
		cout << "Baralho sem cartas para alterar" << endl;
	}
}

void ImportandoArquivos(Baralho * baralho)
{
	ifstream leitorTXT;	//leitor do arquivo txt
	char arquivo[25];	//nome do arquivo

	//importa um arquivo txt e armazena na memoria
	cout << "Importando txt na memoria." << endl;
	cout << "Importar Cartas" << endl;
	cout << "---------------" << endl;
	cout << "Arquivo: ";
	cin >> arquivo; //ler o vakor digitado pelo usuario
	cout << "\nImportando:\n\n";
	leitorTXT.open(arquivo, ios_base::in);

	//se o arquivo existe e abriu
	if (leitorTXT.is_open())
	{
		//se a leitura foi bem executada e se o tamanho do baralho nao superou o tamanho maximo que é 32
		while (leitorTXT.good() && baralho->tamanhoBaralho < TAMMAXBARALHO)
		{
			leitorTXT.getline(baralho->Cartas[baralho->tamanhoBaralho].nome, 50); //o nome pode ter espaço por isso se pega uma linha inteira
			leitorTXT >> baralho->Cartas[baralho->tamanhoBaralho].velocidadeMaxima;
			leitorTXT >> baralho->Cartas[baralho->tamanhoBaralho].cilindradas;
			leitorTXT >> baralho->Cartas[baralho->tamanhoBaralho].potencia;
			leitorTXT >> baralho->Cartas[baralho->tamanhoBaralho].comprimento;
			leitorTXT >> baralho->Cartas[baralho->tamanhoBaralho].peso;

			cout << baralho->Cartas[baralho->tamanhoBaralho].nome << " ";
			cout << baralho->Cartas[baralho->tamanhoBaralho].velocidadeMaxima << " ";
			cout << baralho->Cartas[baralho->tamanhoBaralho].cilindradas << " ";
			cout << baralho->Cartas[baralho->tamanhoBaralho].potencia << " ";
			cout << baralho->Cartas[baralho->tamanhoBaralho].comprimento << " ";
			cout << baralho->Cartas[baralho->tamanhoBaralho].peso << " " << endl;

			leitorTXT.ignore();
			baralho->tamanhoBaralho++; //aumenta o numero das cartas do baralho. 
		}
		if (baralho->tamanhoBaralho == TAMMAXBARALHO)
			cout << "Baralho cheio." << endl;
	} 
	else {
		cout << "Arquivo invalido!!!" << endl;
	}
	

	leitorTXT.close();
}

void CadastrarCarta(Baralho * baralho)
{
	//se o tamanho do baralho ainda n for 32.
	if (baralho->tamanhoBaralho < TAMMAXBARALHO)
	{
		cout << "Cadastrar Carta" << endl;
		cout << "----------------" << endl;
		cout << "Nome:              ";
		cin.ignore();
		cin.getline(baralho->Cartas[baralho->tamanhoBaralho].nome, 50);
		cout << "Velocidade Maxima: ";
		cin >> baralho->Cartas[baralho->tamanhoBaralho].velocidadeMaxima;
		cout << "Cilindradas:       ";
		cin >> baralho->Cartas[baralho->tamanhoBaralho].cilindradas;
		cout << "Potencia:          ";
		cin >> baralho->Cartas[baralho->tamanhoBaralho].potencia;
		cout << "Comprimento:       ";
		cin >> baralho->Cartas[baralho->tamanhoBaralho].comprimento;
		cout << "Peso:              ";
		cin >> baralho->Cartas[baralho->tamanhoBaralho].peso;
		cout << "Cadastrado." << endl;
		baralho->tamanhoBaralho++; //aumenta o tamanho do baralho
	}
	else
	{
		cout << "Baralho cheio, nao e possivel cadastrar mais cartas." << endl;
	}
}
void MenuInicial(char * escolha)
{
	//mensagem inicial
	cout << "Gerador de Cartas"
		"\n------------------"
		"\n(C)adastrar"
		"\n(I)mportar"
		"\n(A)lterar"
		"\n(E)xcluir"
		"\n(L)istar"
		"\n(S)air"
		"\nEscolha uma opcao[ ]\b\b";
	cin >> *escolha;
}