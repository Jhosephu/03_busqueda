#include<bits/stdc++.h>

using namespace std;

struct monomio{
	float coef;
	float exp;
};

int buscapol(monomio t[], int n, monomio dato);

int main(){
	int n;
	monomio ter[100], dato;
	cout<<"ingrese la cantidad de monomios: "; cin>>n;
	for(int i=0; i<n; i++){
		cout<<"ingrese el coeficiente del termino "<<i+1<<": ";cin>>ter[i].coef;
		cout<<"ingrese el exponente del termino "<<i+1<<": ";cin>>ter[i].exp;
	}
	cout<<"ingrese el coeficiente del polinoimio que busca: "; cin>>dato.coef;
	cout<<"ingrese el coeficiente del polinoimio que busca: "; cin>>dato.exp;
	cout<<"el monomio se encuentra en la posicion: "<<buscapol(ter, n, dato);
}
int buscapol(monomio t[], int n, monomio dato){
	int pos, i;
	pos=0;
	i=0;
	while(i<n and t[i].coef!=dato.coef and t[i].exp!=dato.exp){
		i=i+1;
	}
	if(i<n){
		pos=i+1;
	}
	return pos;
}