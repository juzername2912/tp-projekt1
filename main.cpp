#include <iostream>
#include <vector>
using namespace std;

struct wezel {
	int value;
	wezel* right;
	wezel* left;
};

void BST_insert(wezel*& r, int x);//dołącza do drzewa węzeł o wartości x w odpowiednim miejscu
wezel* BST_search(wezel*&r, int x);// znajduje węzeł o wartości x w drzewie binarny
void BT_preorder(wezel* r);//wyszukiuje i wypisuje wartosci w drzewie od położenia?
void rysowanie(wezel* r, int depth);
void usuwanie(wezel*& r,int x);

int main(void)
{
	
	int wstawiany;
	wezel* root =NULL;
	int i = 1;
	cout << "w" << i++ << ": ";
	cin >> wstawiany;
	while (wstawiany != 0) {
		BST_insert(root, wstawiany);
		cout << "w" << i++ << ": ";
		cin >> wstawiany;
	}
	while(true)
	{ 
		int depth = 0;
	char opcja;
	cout << "p-preorder" << endl;
	cout << "r-rysowanie" << endl;
	cout << "u-usuwanie" << endl;
	cout << "w-wyjscie" << endl;
	cout << "wybierz opcje:";
	cin >> opcja;
	switch (opcja)
	{
	case 'p':
		system("cls");
		BT_preorder(root);
		break;
	case 'r':
		system("cls");
		
		rysowanie(root, depth);
		break;
	case 'u':
		system("cls");
		cout << "podaj wartosc do usuniecia:" << endl;
		int x;
		cin >> x;
		usuwanie(root,x);
			break;
	case'w':
		return 0;
		break;
	}
	system("pause");
	system("cls");
	}
	return 0;
}


void BST_insert(wezel*& r, int x)
{
	if (r == NULL)
	{
		wezel* nowy = new wezel;
		nowy->value = x;
		nowy->right = NULL;
		nowy->left = NULL;
		r = nowy; // dowiązanie nowego węzła
		// do węzła "wyższego poziomu"
	}
	else if (x >= r->value) BST_insert(r->right, x);// tworzy nowy węzeł do węzła prawego
	else BST_insert(r->left, x);// tworzy nowy węzeł do węzła lewego
}

wezel* BST_search(wezel*& r, int x)
{
	if ((r == NULL) or (r->value == x))
		return r;
	else
		if (x < r->value)
			return BST_search(r->left, x);
		else
			return BST_search(r->right, x);
}

void BT_preorder(wezel * r)
{
		if (r != NULL) {
			cout << r->value;
			BT_preorder(r->left);
			BT_preorder(r->right);
		}
	}


void rysowanie(wezel* r, int depth)
{	// to jest zainspirowane BT_preorder
	depth++;
	if (r != NULL) {
		if (depth > 1)
		{
			cout << " - - - - - - - ";// jesli jestesmy na wezle innym niz root to dodajemy to przed liczbą
		}
		cout << r->value;
		rysowanie(r->right, depth);
		if (r->left != NULL) { cout << endl; cout << endl; }//tu sie staram zrobic odstępy między gałęziami
		
		for (int j = 1; j < depth; j++)
		{
			cout << "               ";//a tu sie staram zrobic wcięcia poprzedzające gałęzię
			if (j == depth - 1 and r->left!=NULL) cout << "|";
		}
		rysowanie(r->left, depth);
	}
	
	

}

void usuwanie(wezel*& r, int x) {
	// to jest tak naprawde zmodyfikowany BST_search (działa)
	if ((r == NULL) or (r->value == x))
		r = NULL;
	else
		if (x < r->value)
			return usuwanie(r->left, x);
		else
			return usuwanie(r->right, x);
	
}
