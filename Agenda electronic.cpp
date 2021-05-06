//Carne 4090-11-18486  oscar garcia cortez

#include <fstream>
#include <conio>
#include <stdio>

struct persona
{
	char nombre[25];
   char direccion[25];
   char telefono[25];
   char correo[25];
}contacto;

void ingresar();
void mostrar();

void main()
{
	int n;
	int salida=0;
	do
 	{
   	clrscr();
		cout<<"\n\n---M.E.N.U---\n\n";
 		cout<<"\n1. Ingresar Contactos\n";
 		cout<<"\n2. Mostrar Contactos\n";
 		cout<<"\n3. Salir\n";
      cout<<"\n_ ";
 		cin>>n;
 		switch(n)
 		{
    		case 1: ingresar();break;
    		case 2: mostrar();break;
    		case 3: salida=1;break;
         default:
         	clrscr();
            cout<<"\n\n\nPresione Solamente Una De Las Teclas Indicadas";
            cout<<"\n\n\nPresione Una Tecla Para Continuar...!";
            getch();
         break;
   	}
   }while(salida==0);
getch();
}

void ingresar()
{
	int dec;
	clrscr ();
   	ofstream agenda;
      agenda.open("agenda.txt",ios::out|ios::app);
			if (agenda.fail())
         {
				cout<<"Ocurrio un error al abrir el archivo";
            getch ();
      	}else
         	{
					do{
               	clrscr();
      				cout<<"\n\nIngrese Su Nombre: ";
      				gets(contacto.nombre);
      				cout<<"\n\nIngrese su direccion:";
      				gets(contacto.direccion);
      				cout<<"\n\nIngrese su Telefono: ";
      				gets(contacto.telefono);
      				cout<<"\n\nIngrese su Correo Electronico: ";
      				gets(contacto.correo);
         			agenda<<contacto.nombre<<"  "<<contacto.direccion<<"  "<<contacto.telefono<<"  "<<contacto.correo<<"\n\n";
            		cout<<"\n\n desea ingresar otro contacto a la agenda.? ";
            		cout<<"\n\n 1=si, 2=no \n"<<endl;
                  cin>>dec;
            	 	}while (dec==1);
            }
		agenda.close();
getch();
}

void mostrar()
{
	clrscr();
   cout<<"\n";
	ifstream agenda;
	agenda.open("agenda.txt");
	while(!agenda.eof())
	cout<<(char)agenda.get();
   agenda.close();
getch();
}

