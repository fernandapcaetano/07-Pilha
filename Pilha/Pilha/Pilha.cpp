#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* inicio = NULL;
NO* fim = NULL;

// headers
void menu();
void inicializar();
void insere();
void exibirElemento();
void remove();
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
		cout << "Menu Fila";
		cout << endl << endl;
		cout << "1 - Inicializar Fila \n";
		cout << "2 - Inserir elemento \n";
		cout << "3 - Remover elemento  \n";
		cout << "4 - Exibir elementos  \n";
		cout << "5 - Sair \n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:insere();
			break;
		case 3: remove();
			break;
		case 4: exibirElemento();
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
	NO* aux = inicio;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	inicio = NULL;
	fim = NULL;
	cout << "Fila inicializada \n";

}


void insere()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	// Se a fila estiver vazia, o novo elemento será o inicio e o fim
	if (inicio == NULL) {
		inicio = novo;
		fim = novo;
	}
	// Se a fila não estiver vazia, adiciona o novo elemento no final da fila
	else {
		fim->prox = novo;
		fim = novo;
	}

	cout << "Elemento inserido com sucesso! \n";




}

void remove()
{

	int valorRemovido = inicio->valor;

	// Se a fila tiver somente 1 elemento, atualiza o inicio e o fim para NULL
	if (inicio == fim) {
		NO* paraExcluir = inicio;
		inicio = NULL;
		fim = NULL;
		free(paraExcluir);
	}
	// Se a fila tiver mais de 1 elemento, atualiza o inicio
	else {
		NO* paraExcluir = inicio;
		inicio = inicio->prox;
		free(paraExcluir);
	}

	cout << "Elemento " << valorRemovido << " removido com sucesso! \n";

}

void exibirElemento() {

	if (fim == NULL) {
		cout << "Fila vazia" <<endl;
	}
	else
	{
		NO* aux = inicio;

		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}
