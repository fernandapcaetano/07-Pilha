// Pilha.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* topo = NULL;

// headers
void menu();
void inicializar();
void pop();
void push();
void exibirElementos();
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 5) {
		system("cls"); // somente no windows
		cout << "Menu Pilha";
		cout << endl << endl;
		cout << "1 - Inicializar Pilha \n";
		cout << "2 - Inserir elemento (Push) \n";
		cout << "3 - Remover elementos (Pop) \n";
		cout << "4 - Exibir Elementos \n";
		cout << "5 - Sair \n";


		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:push();
			break;
		case 3: pop();
			break;
		case 4: exibirElementos();
			break;
		case 5: 
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	//variável auxiliar, é possível evitar a perda da referência para o início da lista, o que permite reutilizar a variável "topo" para outras operações na lista.
	//Quando uma lista é liberada da memória, não é possível mais acessá-la, por isso é importante ter cuidado com a manipulação de ponteiros para evitar vazamento de memória.
	NO* aux = topo;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	topo = NULL;
	cout << "Pilha inicializada \n";

}


void push()
{
	// aloca memória dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		cout << "Erro: memoria insuficiente \n";
		return;
	}

	cout << "Digite o valor a ser inserido: ";
	cin >> novo->valor;

	// insere o novo elemento no início da pilha
	novo->prox = topo;
	topo = novo;
	cout << "Elemento inserido com sucesso \n";



}

void pop()
{


	// verifica se a pilha está vazia
	if (topo == NULL)
	{
		cout << "A pilha está vazia." << endl;
		return;
	}

	// cria um ponteiro auxiliar que aponta para o topo da pilha
	NO* aux = topo;

	// atribui o valor do campo valor do topo da pilha a uma variável elementoRemovido
	int elementoRemovido = aux->valor;

	// atribui o valor do campo prox do topo da pilha ao ponteiro topo
	topo = topo->prox;

	// desaloca a memória ocupada pelo elemento removido
	free(aux);

	cout << "Elemento " << elementoRemovido << " removido da pilha." << endl;

}

void exibirElementos() {
	//se o totpo for nulo a lista esta vazia
	if (topo == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";

		//variavel auxiliar referenciando o topo
		NO* aux = topo;
		//enquanto aux (topo) for diferente de nulo, exiba o valor da auxiliar e auxiliar aponta para o próximo
		//vai dando voltas até não tiver mais elemtos (Nulo)
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}
