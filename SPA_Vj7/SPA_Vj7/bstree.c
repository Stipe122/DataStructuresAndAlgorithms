#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	// Novo prazno stablo

	//BSTree root = (BSTree)malloc(sizeof(Node));
	//root->word = "";
	//root->left = NULL;
	//root->right = NULL;

	//return root;
	
	return NULL;
}

void AddNode(BSTree *bst, char *word)
{
	// Rekurzivno se traži mjesto za novi cvor u stablu. Ako rijec postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokazivac.

	if (*bst == NULL)
	{
		BSTree novi = (BSTree)malloc(sizeof(Node));
		novi->word = word;
		novi->left = NULL;
		novi->right = NULL;
		*bst = novi;
		return;
	}
	if (strcmp((*bst)->word, word) == 0)
	{
		free(word);
		return 0;
	}
	if (strcmp((*bst)->word, word) < 0)
		AddNode(&((*bst)->left), word);
	else
		AddNode(&((*bst)->right), word);

}

int BSTHeight(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se pronašla najduža grana (visina stabla).
	
	if (bst == NULL)
		return 0;
	else
	{
		int lMax = BSTHeight(bst->left);
		int rMax = BSTHeight(bst->right);
		if (lMax > rMax)
			return (lMax + 1);
		else
			return (rMax + 1);
	}
	return 0;
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rijeci u stablu na ekran po abecednom redu.
	// In-order šetnja po stablu (lijevo dijete, cvor, desno dijete)

	if (bst == NULL)
		return;
	PrintBSTree(bst->left);
	printf("%s ", bst->word);
	PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE *fd)
{
	// Snima rijec po rijec iz stabla u tekstualnu datoteku. Rijeci su odvojene razmakom.
	// Pre-order šetnja po stablu (trenutni cvor pa djeca)

	if (bst == NULL)
		return;
	fprintf(fd, "%s ", bst->word);
	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);
}

void DeleteBSTree(BSTree bst)
{
	// Briše stablo (string word i sam cvor) iz memorije.
	// Post-order šetnja po stablu (prvo djeca pa trenutni cvor)

	if (bst == NULL) {
		return;
	}
	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
	free(bst->word);
	free(bst);
}

BSTree LoadBSTree(FILE *fd)
{
	// Ucitava rijec po rijec iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rijec duplicirati sa strdup().

	BSTree novi = NewBSTree();
	char buffer[1024];
	while (fscanf(fd, "%s", buffer) > 0)
		AddNode(&novi, _strdup(buffer));
	return novi;

}
