#include<bits/stdc++.h>

using namespace std;

int binaria(int a[], int n, int dato); 
void bublesort(int x[], int n);

int main(){
	int n, a[100], dato, pos;
	cout<<"ingrese la cantidad de elementos: "; cin>>n;
	cout<<"ingrese los datos del arreglo: ";
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<"ingrese el dato que quiere buscar: "; cin>>dato;
	bublesort(a, n);
	pos=binaria(a, n, dato);
	cout<<"el numero esta en la posicion: "<<pos;
	return 0;
}
void bublesort(int x[], int n){
	int aux;
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i; j++){
			if(x[j]>x[j+1]){
				aux=x[j];
				x[j]=x[j+1];
				x[j+1]=aux;
			}
		}
	}
	for(int i=0; i<n; i++){
		cout<< x[i];
	}
}
int binaria(int a[], int n, int dato){
	int izq=0, der=n-1, cen=0, m, pos;
	while(izq<=der and cen==0){
		m=(izq+der)/2;
		if(a[m]==dato){
			cen=1;
		}
		else{
			if(dato>a[m]){
				izq=m+1;
			}
			else{
				der=m-1;
			}
		}
	}
	if(cen==1){
		pos=m+1;
	}
	else{
		pos=-izq-1;
	}
	return pos;
}
