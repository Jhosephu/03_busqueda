#include<bits/stdc++.h>

using namespace std;

struct articulos{
	string codigo;
	string desc;
	float precio;
	float cantidad;
	float monto;
};

void ordenart(int n, articulos arti[]);

int main(){
	articulos arti[100];
	int n;
	cout<<"ingrese la cantidad de articulos: "; cin>>n;
	for(int i=0; i<n; i++){
		cout<<"ingrese el codigo del articulo nro: "<<i+1<<endl; cin>>arti[i].codigo;
		cout<<"ingrese la descripcion del articulo nro: "<<i+1<<endl; cin>>arti[i].desc;
		cout<<"ingrese el precio del articulo nro: "<<i+1<<endl; cin>>arti[i].precio;
		cout<<"ingrese la cantidad del articulo nro: "<<i+1<<endl; cin>>arti[i].cantidad;
		arti[i].monto=arti[i].cantidad*arti[i].precio;
		cout<<endl;
	}
	ordenart(n, arti);
	for(int i=0; i<n; i++){
		cout<<"el codigo del articulo nro "<<i+1<<" es: "<<arti[i].codigo<<endl;
		cout<<"la descripcion del articulo nro: "<<i+1<<" es: "<<arti[i].desc<<endl;
		cout<<"el precio del articulo nro "<<i+1<<" es: "<<arti[i].precio<<endl;
		cout<<"la cantidad del articulo nro "<<i+1<<" es: "<<arti[i].cantidad<<endl;
		cout<<"el monto del articulo nro "<<i+1<<" es: "<<arti[i].monto<<endl;
		cout<<endl;
	}
}

void ordenart(int n, articulos arti[]){
	articulos aux;
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1-i; j++){
			if(arti[j].monto<arti[j+1].monto){
				aux=arti[j];
				arti[j]=arti[j+1];
				arti[j+1]=aux;
			}
		}
	}
}
