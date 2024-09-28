#include<bits/stdc++.h>

using namespace std;

struct personas{
	int DNI;
	string nombres;
};
struct fecha{
	int dia;
	int mes;
	int year;
};

void ordenp(int n, fecha f[], personas p[]);
bool compararf(fecha f1, fecha f2);
int binaria(fecha a[], int n, fecha dato);

int main(){
	fecha f[100], dato;
	personas p[100];
	int n;
	cout<<"ingrese la cantidad de personas: "; cin>>n;
	for(int i=0; i<n; i++){
		cout<<"ingrese el nombre de la persona nro: "<<i+1<<endl; cin>>p[i].nombres;
		cout<<"ingrese el DNI de la persona nro: "<<i+1<<endl; cin>>p[i].DNI;
		cout<<"ingrese el dia de nacimiento de la persona nro: "<<i+1<<endl; cin>>f[i].dia;
		cout<<"ingrese el mes de nacimiento de la persona nro: "<<i+1<<endl; cin>>f[i].mes;
		cout<<"ingrese el año de nacimiento de la persona nro: "<<i+1<<endl; cin>>f[i].year;
		cout<<endl;
	}
	ordenp(n, f, p);
	cout<<"las personas ordenadas por fecha de nacimiento: "<<endl;
	for(int i=0; i<n; i++){
		cout<<"nombre "<<i+1<<" es: "<<p[i].nombres<<endl;
		cout<<"DNI "<<i+1<<" es: "<<p[i].DNI<<endl;
		cout<<"fecha de nacimiento "<<i+1<<" es: "<<f[i].dia<<"/"<<f[i].mes<<"/"<<f[i].year<<endl;
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

void ordenp(int n, fecha f[], personas p[]){
	fecha aux_fech;
	personas aux_per;
	int k;
	for(int i=1; i<n; i++){
		aux_fech=f[i];
		aux_per=p[i];
		k=i-1;
		while(k>=0 and compararf(aux_fech, f[k])){
			f[k+1]=f[k];
			p[k+1]=p[k];
			k=k-1;
		}
		f[k+1]=aux_fech;
		p[k+1]=aux_per;  
	}
}

bool compararf(fecha f1, fecha f2){
	if(f1.year!=f2.year){
		return f1.year<f2.year;
	}
	if(f1.mes<f2.mes){
		return f1.mes<f1.mes;
	}
	return f1.dia<f2.dia;
}

int binaria(fecha a[], int n, fecha dato){
	int izq=0, der=n-1, cen=0, m, pos;
	while(izq<=der and cen==0){
		m=(izq+der)/2;
		if(a[m].year==dato.year and a[m].mes==dato.mes and a[m].dia==dato.dia){
			cen=1;
		}
		else{
			if(compararf(a[m], dato)){
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
