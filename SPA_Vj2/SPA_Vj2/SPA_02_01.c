#include <stdio.h>
#include <stdlib.h>


void print_niz(int* niz2, int len) {
	int i = 0;
	for (i; i < len; i++)
		printf("%d\n", niz2[i]);

}

int* podniz(int* niz, int start, int stop){

	int i = 0;
	int k = stop - start ;
	int* rez = (int*)malloc(k * sizeof(int));
	if (rez == NULL)
		return 0;

	for (i = 0; i < k; i++) {

		rez[i] = niz[i+start];
	}

	return rez;
}

int* filtriraj(int* niz, int n, int th, int* nth) {
	int k = 0, cnt = 0;

	int* novi_niz = (int*)malloc(n * sizeof(int));
	if (novi_niz == NULL)
		return NULL;

	for (k; k < n; k++) {
		if (niz[k] < th) {
			novi_niz[cnt] = niz[k];
			cnt++;
		}
	}

	int* temp = (int*)realloc(novi_niz, cnt * sizeof(int));
	if (temp == NULL) {
		free(novi_niz);
		return NULL;
	}

	novi_niz = temp;

	*nth = cnt;

	return novi_niz;

}



int** podijeli(int* niz, int n) {
	int pola = n / 2;
	int i = 0, j = 0;

	int** niz_uk = (int**)malloc(2 * sizeof(int*));

	int* prvih_pola = (int*)malloc(pola * sizeof(int));
	if (prvih_pola == NULL)
		return 0;

	for (i=0; i < pola; i++) {
		prvih_pola[i] = niz[i];
	}


	int* drugih_pola = (int*)malloc(pola * sizeof(int));
	if (drugih_pola == NULL)
		return 0;

	for (j; j < pola; j++) {
		drugih_pola[j] = niz[j+pola];
	}

	niz_uk[0] = prvih_pola;
	niz_uk[1] = drugih_pola;

	return niz_uk;

}

int main() {

	int* niz_rez;

	//Zdk1

	/*
	int start = 3;
	int stop = 6;
	int niz[7] = { 1, 2, 3, 4, 5, 6, 7 };
	
	
	int k = stop - start;
	

	int* niz_rez = podniz(niz, start, stop);

	print_niz(niz_rez, k);
	*/

	//Zdk2

	/*
	int niz2[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = sizeof(niz2)/sizeof(int);
	int th = 4;
	int nth ;

	niz_rez = filtriraj(niz2, n, th, &nth);


	print_niz(niz_rez, nth);

	
	free(niz_rez);
	*/
	

	//Zdk3

	
	int niz3[6] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(niz3) / sizeof(int);
	int** niz_rez2;

	niz_rez2 = podijeli(niz3, n);

	print_niz(niz_rez2[0], n/2);
	printf("\n");
	print_niz(niz_rez2[1], n / 2);



	return 0;
}













