#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
using namespace std;

struct Producto{
    char nombreProducto[48];
    float precio;
    int stock;
    float valorTotal;
};

struct Nodo{
    struct Producto dato;
    Nodo *sig;
}*ultimo=NULL,*cola=NULL,*primero=NULL;

void registrar();
void listar();

int main(){
    char opc;
    int op;
    do{
        cout<<"FARMACIA SALUD TOTAL"<<endl;
        cout<<"1.Registrar producto"<<endl;
        cout<<"2.Listar productos"<<endl;
        cout<<"3.Salir"<<endl;

        cout<<"Elija una opcion"<<endl;
        cin>>op;
        switch(op){
            case 1:{
                registrar();
                break;
            }
            case 2:{
                listar();
                break;
            }
        }
        system("cls");
    }while(op!=3);
    getch();
    return 0;
}

void registrar(){
    char nombreProducto[48];
    float valorTotal;

    cola = new Nodo();
    cout<<"Ingrese el nombre del producto"<<endl;
    fflush(stdin);
    cin.getline(nombreProducto,48,'\n');
    strcpy(cola->dato.nombreProducto, nombreProducto);
    cout<<"Ingrese el precio: "<<endl;
    cin>>cola->dato.precio;
    cout<<"Ingrese el stock: "<<endl;
    cin>>cola->dato.stock;
    cola->dato.valorTotal = cola->dato.precio * cola->dato.stock;

    if(ultimo!=NULL){
        ultimo->sig=cola;
        cola->sig=NULL;
        ultimo = cola;
        cout<<"Producto registrado correctamente"<<endl;
    }
    else{
        primero=ultimo=cola;
        cout<<"Producto registrado correctamente"<<endl;
    }
}

void listar(){
    if(ultimo==NULL){
        cout<<"Cola vacia...."<<endl;
    }
    cola = primero;
    cout<<"Los productos registrados son: "<<endl;

    while(cola!=NULL){
        if(primero == ultimo){
            cout<<"Producto: "<<cola->dato.nombreProducto<<endl;
            cout<<"Precio  : S/ "<<cola->dato.precio<<endl;
            cout<<"Stock   : "<<cola->dato.stock<<" unidades"<<endl;
            cout<<"Valor Total: S/ "<<cola->dato.valorTotal<<endl;
            if(cola->dato.stock<10){
                cout<<"!! Stock bajo - Reabastecer pronto !!"<<endl;
            }
            else{
                cout<<"Stock en buen nivel"<<endl;
            }
            cout<<"********************************"<<endl;
            cola = NULL;
            getch();
        }
        else{
            cout<<"Producto: "<<cola->dato.nombreProducto<<endl;
            cout<<"Precio  : S/ "<<cola->dato.precio<<endl;
            cout<<"Stock   : "<<cola->dato.stock<<" unidades"<<endl;
            cout<<"Valor Total: S/ "<<cola->dato.valorTotal<<endl;
            if(cola->dato.stock<10){
                cout<<"!! Stock bajo - Reabastecer pronto !!"<<endl;
            }
            else{
                cout<<"Stock en buen nivel"<<endl;
            }
            cout<<"********************************"<<endl;

            cola = cola->sig;
            getch();
        }
    }
}
