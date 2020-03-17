#include <stdio.h>

void apresenta_array (int v[],int n) {
    for(int i = 0; i < n ; i++){
        printf(" %d",v[i]);
    }
	printf("\n");
}	

void insere (int v[], int N, int x) {
	
	int i, j;

	for (i = 0; i < N && x >= v[i] ; i++);

	for(j = N  ; j > i  ; j-- ) v[j] = v[j-1];

	v[i] = x;
}

void insertion_sort (int v[], int N) {
	
	int i;
	for(i = 1; i < N; i++) insere(v,i,v[i]);
	
}

void insertion_sort2(int v[], int N) {
	int i, j, x;

	for(i = 1; i < N ; i++) {
		if(v[i] < v[i-1]) {
			x = v[i];
			for(j = i ; j > 0 && x <  v[j - 1]; j--) v[j] = v[j-1];
			v[j] = x;
		}
	}
}

int maxInd (int v[], int N) {

	int maior = v[0], i, indice = 0 ;
	for(i = 0; i < N ; i ++) {

		if(v[i] > maior){
		    maior = v[i];
			indice = i;
		}
	}
	return indice;
}

void heap_sort (int v[], int N) {
	
	int i ,j,max, indice ;
   
	for(i = 0; i < N  ; i++) {

        indice =  maxInd(v, N - i);
		max = v[indice];
		
		for( j = indice  ;  j < N - 1 && v[j + 1] <= max ; j++) v[j] = v[j+1];	
	
		if (v[j + 1] > max) v[j] = max;
		if (j == (N  -  1)) v[N - 1] = max;
	}	
}

void heap_sort2 (int v[], int N) {

	int i, j, k,max , indice = 0;

	for(i = 0; i < N  ; i ++) {

		max = v[0];
		indice = 0;
		for(k = 0; k < N - i; k++) {
			if(v[k] > max) {
				 max = v[k];
				 indice = k;
			}
		}
		for( j = indice  ;  j < N - 1 && v[j + 1] <= max ; j++) v[j] = v[j+1];	
		if (v[j + 1] > max) v[j] = max;
		if (j == (N  -  1)) v[N - 1] = max;
	}
} 

void swap(int v[], int i, int j) {
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


void bubble (int v[], int N) {
	int i;	
	for (i = 1; i < N; i++){
		if (v[i-1] > v[i])
			swap (v,i-1, i);
	}
}	

int bubble2(int v[], int N) {
	int i,j = 0;	
	for (i = 1; i < N; i++){
		if (v[i-1] > v[i]) {
			swap (v,i-1, i);
			j++;
		}
	}
	return j;
}

void bubbleSort (int v[], int N) {
	int i;
	for(i = 0; i < N ; i++) bubble(v,N);
}	

void bubbleSort2(int v[], int N) {
	while(bubble2(v,N));
}

int main () {
	int v [] =  {2,1,3,6,-1,-2,80,20,10,500};
	insertion_sort(v,10);
    apresenta_array(v,10);
	
}	

