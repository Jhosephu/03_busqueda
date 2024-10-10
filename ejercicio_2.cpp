#include<bits/stdc++.h>

using namespace std;

struct personas{
	int DNI;
	string nombres;
};
struct fechas{
	int dia;
	int mes;
	int year;
};

void ordenp(int n, fechas f[], personas p[]);
bool compararf(fechas f1, fechas f2);
int binaria(fechas f[], int n, fechas dato);

int main(){
	fechas f[100], dato;
	personas p[100];
	int n;
	cout<<"ingrese la cantidad de personas: "; cin>>n;
	for(int i=0; i<n; i++){
		cout<<"ingrese el nombre de la persona nro: "<<i+1<<endl; cin>>p[i].nombres;
		cout<<"ingrese el DNI de la persona nro: "<<i+1<<endl; cin>>p[i].DNI;
		cout<<"ingrese el dia de nacimiento de la persona nro: "<<i+1<<endl; cin>>f[i].dia;
		cout<<"ingrese el mes de nacimiento de la persona nro: "<<i+1<<endl; cin>>f[i].mes;
		cout<<"ingrese el año de nacimiento de la persona nro: "<<i+1<<endl; cin>>f[i].year;
		ordenp(n, f, p);
		cout<<endl;
	}
	cout<<"ingrese la año que quiere buscar: "; cin>>dato.year;
	cout<<"ingrese el mes que quiere buscar: "; cin>>dato.mes;
	cout<<"ingrese el dia que quiere buscar: "; cin>>dato.dia;
	if(binaria(f, n, dato)<0){
		cout<<"la persona buscada deberia estar en la posicion: "<<-binaria(f, n, dato);
	}
	else{
		cout<<"la persona buscada esta en la posicion: "<<binaria(f, n, dato);
	}
}

void ordenp(int n, fechas f[], personas p[]){
	fechas auxf;
	personas auxp;
	int k;
	for(int i=1; i<n; i++){
		auxf=f[i];
		auxp=p[i];
		k=i-1;
		while(k>=0 and compararf(auxf, f[k])){
			f[k+1]=f[k];
			p[k+1]=p[k];
			k=k-1;
		}
		f[k+1]=auxf;
		p[k+1]=auxp;  
	}
}

bool compararf(fechas f1, fechas f2){
	if(f1.year!=f2.year){
		return f1.year<f2.year;
	}
	if(f1.mes<f2.mes){
		return f1.mes<f2.mes;
	}
	return f1.dia<f2.dia;
}

int binaria(fechas f[], int n, fechas dato){
	int izq=0, der=n-1, cen=0, m, pos;
	while(izq<=der and cen==0){
		m=(izq+der)/2;
		if(f[m].year==dato.year and f[m].mes==dato.mes and f[m].dia==dato.dia){
			cen=1;
		}
		else{
			if(compararf(f[m], dato)){
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
		pos=-izq;
	}
	return pos;
}
