#include<bits/stdc++.h>

using namespace std;

struct monomio{
	float coef;
	float exp;
};

void ordenapol(monomio t[], int n);

int main(){
	int n;
	monomio t[100];
	cout<<"ingrese la cantidad de terminos del polinomio: "; cin>>n;
	for(int i=0; i<n; i++){
		cout<<"ingrese el coeficiente del termino "<<i+1<<": "; cin>>t[i].coef;
		cout<<"ingrese el exponente del termino "<<i+1<<": "; cin>>t[i].exp;
	}
	ordenapol(t, n);
	cout<<"el polinomio ordenado es: ";
	for(int i=0; i<n; i++){
		cout<<" + "<<t[i].coef<<"x^"<<t[i].exp;
	}
}

void ordenapol(monomio t[], int n){
	monomio aux;
	for(int i=0; i<n-1; i++){
		for(int j=n-1; j>i; j--){
			if(t[j].exp>t[j-1].exp){
				aux=t[j];
				t[j]=t[j-1];
				t[j-1]=aux;
			}
		}
	}
}
