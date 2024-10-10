#include<bits/stdc++.h>

using namespace std;

struct per{
	int DNI;
	string nombre;
};
struct fec{
	int dia;
	int mes;
	int year;
};

void ordenp(int n, fec f[], per p[]);
bool compararf(fec f1, fec f2);

int main(){
	fec fech[100];
	per pers[100];
	int n;
	cout<<"ingrese la cantidad de personas: "; cin>>n;
	for(int i=0; i<n; i++){
		cout<<"ingrese el nombre de la persona nro: "<<i+1<<endl; cin>>pers[i].nombre;
		cout<<"ingrese el DNI de la persona nro: "<<i+1<<endl; cin>>pers[i].DNI;
		cout<<"ingrese el dia de nacimiento de la persona nro: "<<i+1<<endl; cin>>fech[i].dia;
		cout<<"ingrese el mes de nacimiento de la persona nro: "<<i+1<<endl; cin>>fech[i].mes;
		cout<<"ingrese el año de nacimiento de la persona nro: "<<i+1<<endl; cin>>fech[i].year;
		cout<<endl;
	}
	ordenp(n, fech, pers);
	cout<<"las personas ordenadas por fecha de nacimiento: "<<endl;
	for(int i=0; i<n; i++){
		cout<<"nombre "<<i+1<<" es: "<<pers[i].nombre<<endl;
		cout<<"DNI "<<i+1<<" es: "<<pers[i].DNI<<endl;
		cout<<"fecha de nacimiento "<<i+1<<" es: "<<fech[i].dia<<"/"<<fech[i].mes<<"/"<<fech[i].year<<endl;
		cout<<endl;
	}
}

void ordenp(int n, fec f[], per p[]){
	fec menorf;
	per menorp;
	int k;
	for(int i=0; i<n-1; i++){
		menorf=f[i];
		menorp=p[i];
		k=i-1;
		for(int j=i+1; j<n; j++){
			if(compararf(menorf, f[j])){
				menorf=f[j];
				menorp=p[j];
				k=j;
			}
		}
		p[k]=p[i];
		f[k]=f[i];
		p[i]=menorp;
		f[i]=menorf;  
	}
}
bool compararf(fec f1, fec f2){
	if(f1.year!=f2.year){
		return f1.year<f2.year;
	}
	if(f1.mes<f2.mes){
		return f1.mes<f2.mes;
	}
	return f1.dia<f2.dia;
}
