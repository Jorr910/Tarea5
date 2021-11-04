#include <iostream>
#include <string>
using namespace std;


struct Pets{
    int id, edad, peso;
    string nombre, raza;
};
struct nodo{
    Pets dato;
    nodo *next;
    nodo *back;
    
}*cabeza, *Cola;


int identificador;


void agregarnodo(void){
 
   nodo *nuevo = new nodo();
   Pets mascota;
   identificador++;
   mascota.id = identificador;

   cout <<"El ID de su mascota es: "<< mascota.id<< endl;

   cout <<"Nombre del dueno: ";
   getline(cin,mascota.nombre);

   cout <<"Ingrese que raza es: ";
   getline(cin,mascota.raza);

   cout <<"Ingrese peso de la mascota: ";
   cin>> mascota.peso; cin.ignore();

   cout <<"Ingrese cuantos anos tiene: ";
   cin>> mascota.edad; cin.ignore();

   cout <<"¡Datos registrados!"<<endl;
 
   nuevo->dato = mascota;
   
   if (cabeza == NULL){

     cabeza = nuevo;
     Cola= nuevo;
     cabeza->next = cabeza;
     cabeza->back = Cola;

   }else{

    Cola->next = nuevo;
    nuevo->back = Cola;
    nuevo->next =cabeza;
    Cola= nuevo;
    cabeza->back = Cola;
   
   }


}

void mostrar(void){
        nodo *saltarin= new nodo();
        saltarin = cabeza;
        bool Hallado = false;
        int Nodo_Buscado = 0;

        cout <<"Ingrese el ID a buscar: ";

        cin >>  Nodo_Buscado;
        cout << endl;
        cin.ignore();

        if (cabeza != NULL){

        do
        {  if (saltarin->dato.id ==Nodo_Buscado){
            cout <<"ID ["<<saltarin->dato.id<<"]"<<endl;
            cout <<"Nombre del dueno: "<<saltarin->dato.nombre<<endl;
            cout <<"Raza: "<<saltarin->dato.raza<<endl;
            cout <<"Peso: "<<saltarin->dato.peso<<" kilos" <<endl;
            cout <<"Edad: " <<saltarin->dato.edad <<" anos"<<endl;

            Hallado = true;
            }

            saltarin = saltarin->next;

        } while (saltarin != cabeza && Hallado!= true);
        

        if(!Hallado){
            cout <<"ID no encontrado."<<endl;
            }

        }else{
            cout <<"La lista esta vacia."<<endl;
        }

       
   } 

void eliminarPersona(void)
{
	int id = 0;
	nodo *p = cabeza;
	nodo *q = NULL;

    
	cout<<"Ingrese el ID: ";
    cin>>id;

    while ((p != NULL) && (p->dato.id != id))
	{
		q = p;
		p = p->next;
	}
	if (p == NULL)
	{
		cout << "No existe ID en el registro" << endl;
		return;
	}

	if (cabeza->dato.id == id)
	{
		cabeza = cabeza->next;

		delete (p);
		cout<<"PERSONA ELIMINADA\n";
		return;
	}

	if (q == NULL)
		p = p->next;
	else
		q->next = p->next;
	delete (p);
	cout<<"LA PERSONA HA SIDO ELIMINADA\n";
}

void eliminar_nodo(){

 nodo* actual = new nodo();
	actual = cabeza;
	nodo* anterior = new nodo();
	anterior = NULL;
	bool Hallado = false;
	int nodoBuscado = 0;
	cout << "Ingrese ID para ELIMINAR: ";
	cin >> nodoBuscado;
	if(cabeza!=NULL){
		do{
			
			if(actual->dato.id == nodoBuscado){
				cout <<"ID:" << nodoBuscado << "Encontrado"<<endl;
				
				if(actual==cabeza){
					cabeza = cabeza->next;
					Cola->next = cabeza;
                    delete actual;

				}else if(actual==Cola){
					anterior->next = cabeza;
					Cola = anterior;
                    delete actual;
				}else{
					anterior->next = actual->next;
                    delete actual;
				}
				
				cout << "USUARIO ELIMINADO";
				Hallado = true;
			}
			anterior = actual;
			actual = actual->next;
		}while(actual!=cabeza && Hallado != true);
		if(!Hallado){
			cout << "ID NO HALLADO";
		}
	}else{
		cout << "LA LISTA ESTA VACIA";
	}
}



int main(){

    int opcion = 0;

    do
    {
        cout <<endl;
		cout << "1. Agregar." << endl;
		cout << "2. Buscar por ID." << endl; 
		cout << "3. Borrar" << endl;
	    cout << "4. Salir" << endl;
		cout << "INGRESE LA OPCION QUE DESEE:";
        cin>> opcion; cin.ignore();

        switch (opcion)
        {
        case 1:
            cout <<"\nDatos a ingresar:"<<endl;
            agregarnodo();
            break;
        case 2:
            cout <<"\nLos datos a mostrar:"<<endl;
            mostrar();
            break;
        case 3:
            cout <<"\n Datos a Eliminar."<<endl;
            eliminarPersona();
            break;
        case 4:
            opcion = 4;
            cout <<"\nLo esperamos ver proximamente." <<endl;
            break;
        default:
            cout <<"\nOPCION NO VALIDA, INTENTE NUEVAMENTE."<<endl;
            break;
        }
    } while (opcion !=4);


    return 0;
}