#include<bits/stdc++.h>

using namespace std;

struct articulos{
	string cod;
	string desc;
	float prec;
	float cant;
	float mont;
};

void ordenart(int n, articulos arti[]);

int main(){
	articulos art[100];
	int n;
	cout<<"ingrese la cantidad de articulos: "; cin>>n;
	for(int i=0; i<n; i++){
		cout<<"ingrese el codigo del articulo nro: "<<i+1<<endl; cin>>art[i].cod;
		cout<<"ingrese la descripcion del articulo nro: "<<i+1<<endl; cin>>art[i].desc;
		cout<<"ingrese el precio del articulo nro: "<<i+1<<endl; cin>>art[i].prec;
		cout<<"ingrese la cantidad del articulo nro: "<<i+1<<endl; cin>>art[i].cant;
		art[i].mont=art[i].cant*art[i].prec;
		cout<<endl;
	}
	ordenart(n, art);
	for(int i=0; i<n; i++){
		cout<<"el codigo del articulo nro "<<i+1<<" es: "<<art[i].cod<<endl;
		cout<<"la descripcion del articulo nro: "<<i+1<<" es: "<<art[i].desc<<endl;
		cout<<"el precio del articulo nro "<<i+1<<" es: "<<art[i].prec<<endl;
		cout<<"la cantidad del articulo nro "<<i+1<<" es: "<<art[i].cant<<endl;
		cout<<"el monto del articulo nro "<<i+1<<" es: "<<art[i].mont<<endl;
		cout<<endl;
	}
}

void ordenart(int n, articulos art[]){
	articulos aux;
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1-i; j++){
			if(art[j].mont<art[j+1].mont){
				aux=art[j];
				art[j]=art[j+1];
				art[j+1]=aux;
			}
		}
	}
}
