#include<bits/stdc++.h>

using namespace std;

int SecuencialDes(int a[], int n, int dato);
int SecuencialOrd(int a[], int n, int dato); 

int main(){
	int n, a[100], dato, pos;
	cout<<"ingrese la cantidad de elementos: "; cin>>n;
	cout<<"ingrese los datos del arreglo: ";
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<"ingrese el dato que quiere buscar: "; cin>>dato;
	pos=SecuencialOrd(a, n, dato);
	cout<<"el numero esta en la posicion: "<<pos;
	return 0;
}

int SecuencialOrd(int a[], int n, int dato){
	int i, pos;
	i=0;
	while(i<n and a[i]<dato){
		i=i+1;
	}
	if(i>n or a[i]>dato){
		pos=-i;
	}
	else{
		pos=i+1;
	}
	return pos;
}

int secuencialDes(int a[], int n, int dato){
	int pos, i;
	pos=0;
	i=0;
	while(i<n and a[i]!=dato){
		i=i+1;
	}
	if(i<n){
		pos=i+1;
	}
	return pos;
}