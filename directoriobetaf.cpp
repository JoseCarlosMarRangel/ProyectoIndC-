#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#ifdef linux
#define MOSTRAR cat
#endif

using namespace std;

int contador = 0;
ofstream guardar;//referencia para guardar
    ifstream leer; //referencia para lee
    fstream temp; //referencia para un archivo temporal

struct person
{
  //int id = contador;
  string name;
  string address;
  string father_name;
  string mother_name;
  long int mobile_number; // Es mejor ponerlo como string
  string sex;
  string mail;
  string citision_no;
   // (?)

  // Devuelve una string con la info de la persona
  string print_info(void) {
    // Aquí decides el formato que quieres que tenga tu fichero de datos
    string info;

    info = name + "\n" +
             address + "\n" +
             father_name + "\n" +
             mother_name + "\n" +
             to_string(mobile_number) + "\n" +
             sex + "\n" +
             mail + "\n" +
             citision_no + "\n\n";

    return info;
  }
};



class Records {
 public:
   Records(){}

   void addrecord(){
    system("cls||clear");
    
    string file_name = "project.txt";
    ofstream file; // Fichero en el que escribir

    // file_name.c_str() : Nombre del fichero, se usa c_str porque es el tipo que espera la función open
    // ios::app : Flag que indica que lo que se escriba no debe sobrescribir a lo ya escrito
    file.open(file_name.c_str(), ios::app); 

    if (!file.is_open()) {
      cout << "\n Can't open file << " << file_name <<  "\n";
      return;
    }
    
    struct person person;

    

    cout << "\n Enter name: ";
    getchar(); // Consume espacio en blanco
    getline(cin, person.name);

    cout << "\nEnter the address: ";
    getline(cin, person.address);


    cout << "\nEnter father name: ";
    getline(cin, person.father_name);
    
    cout << "\nEnter mother name: ";
    getline(cin, person.mother_name);
    
    do{
    cout << "\nEnter phone no.: ";
    }while(scanf("%ld", &person.mobile_number) != 1);
    //TODO: Comprobar que sea un número correcto


    cout << "Enter sex:";
    cin >> person.sex;
    
    cout << "\nEnter e-mail:";
    cin >> person.mail;

    //TODO: Comprobar que sea un correo
    
    cout << "\nEnter citizen no:";
    cin >> person.citision_no;

    // Storing person
    file << person.print_info();    

    cout << "\nrecord saved";
    contador++;
    file.close();

    cout << "\n\nEnter any key";

    getchar();
    getchar();
    system("cls||clear");
  
 }

  void listrecord(){
  system("cls||clear");
  struct person person;
  FILE* archivo = NULL;
  char c[50];
  int i = 0;
  //c = ['\0', NULL, NULL]
  //c = ['a', '\n', '\0']
  //c = ['b', '\0', '\0']
  archivo = fopen("project.txt", "r");
  if(archivo != NULL){
    cout<<"Archivo abierto"<<endl;
    while( feof(archivo) == 0){
      fscanf(archivo, "%s", c);
      printf("%s\n", c);
      cout << endl;
      i++;
    }
    cout<<endl;
  }

 }

 void searchrecord(){
    system("cls||clear");
    string nombre1;
    struct person person;
    ofstream guardar;//referencia para guardar
    ifstream leer; //referencia para lee
    fstream temp; //referencia para un archivo temporal
    //guardar.open("project.txt", ios::app);
    leer.open("project.txt");
    leer >> person.name>>person.address>>person.father_name>>person.mother_name>>person.mobile_number>>person.sex>>person.mail>>person.citision_no;
    //leer >> person.info;
    bool encontrado = false;
    cout << "Ingresa el Nombre a buscar: " << endl;
    cin >> nombre1;
    cout << "\n***********************\n";

    while(!leer.eof()){
      if(person.name == nombre1){
      encontrado = true;
      cout << "Nombre: " << person.name << endl;
      cout << "Direccion: " << person.address << endl;
      cout << "Apellido Paterno: " << person.father_name << endl;
      cout << "Apellido Materno: " << person.mother_name << endl;
      cout << "Num. de telefono: " << person.mobile_number << endl;
      cout << "Sexo: " << person.sex << endl;
      cout << "e-mail: " << person.mail << endl;
      cout << "Num. ciudadano: " << person.citision_no << endl;
      cout << "********************\n\n";
      }
      leer >> person.name>>person.address>>person.father_name>>person.mother_name>>person.mobile_number>>person.sex>>person.mail>>person.citision_no;   
     }
     if(encontrado = false){
        cout << "Nombre no encontrado" << endl;
        }   
      leer.close();
 }

 void modifyrecord(){
  system("cls||clear"); //limpiar pantalla
  string nombre1;   
  struct person person; //da una instancia a la estructura
  ifstream leer; //referencia para lee
  fstream temp; //referencia para un archivo temporal   
  leer.open("project.txt");//abre fichero original
  temp.open("temp.txt", ios::out | ios::app | ios::binary);//abrimos el temporal tambn
  
  //cout << leer;
  bool encontrado=false;
  cout<<"Ingrese contacto a modificar: "<<endl;
  cin>>nombre1;
  while(!leer.eof())
{

    leer >> person.name
         >> person.address
         >> person.father_name
         >> person.mother_name
         >> person.mobile_number
         >> person.sex
         >> person.mail
         >> person.citision_no;

    //cout<< person.name;
    if(person.name == nombre1)
        {
          encontrado=true;
            cout << "Nombre: " << person.name << endl;
            cout << "Direccion: " << person.address << endl;
            cout << "Apellido Paterno: " << person.father_name << endl;
            cout << "Apellido Materno: " << person.mother_name << endl;
            cout << "Num. de telefono: " << person.mobile_number << endl;
            cout << "Sexo: " << person.sex << endl;
            cout << "e-mail: " << person.mail << endl;
            cout << "Num. ciudadano: " << person.citision_no << endl;
            cout<<endl;
            cout<<"Ingrese el nombre a modificar:"<<endl;
            cin>>person.name;
            cout<<"Ingrese la nueva Direccion"<<endl;
            cin>>person.address;
            cout<<"Ingrese el Apellido Paterno a modificar"<<endl;
            cin>>person.father_name;
            cout<<"Ingrese el Apellido Materno a modificar"<<endl;
            cin>>person.mother_name;
            do{
            cout << "\nIngrese el numero nuevo: ";
            }while(scanf("%ld", &person.mobile_number) != 1);
            cout<<"Ingrese el nuevo Sexo: "<<endl;
            cin>>person.sex;
            cout<<"Ingrese el nuevo correo electronico: "<<endl;
            cin>>person.mail;
            cout<<"Ingrese el nuevo Numero ciudadano: "<<endl;
            cin>>person.citision_no;
            temp<<person.name<<" "<<person.address<<" "<<person.father_name<<" "<<person.mother_name<<" "<<person.mobile_number<<" "<<person.sex<<" "<<person.mail<<" "<<person.citision_no<<endl;
            cout<<endl;
            cout<<"Modificado"<<endl;
            //exit(1);
        }
          else
          {
            temp<<person.name<<" "<<person.address<<" "<<person.father_name<<" "<<person.mother_name<<" "<<person.mobile_number<<" "<<person.sex<<" "<<person.mail<<" "<<person.citision_no<<endl;
          }
              leer>>person.name>>person.address>>person.father_name>>person.mother_name>>person.mobile_number>>person.sex>>person.mail>>person.citision_no;
          }
          if(encontrado = false)
            {
              cout<<"Cedula no encontrada"<<endl;
            }
              leer.close();
              
              temp.close();
              remove("project.txt");
              rename("temp.txt","project.txt");
              
  
}

 void deleterecord(){
  system("cls||clear");
    string nombre1;
    struct person person;
    ofstream guardar;//referencia para guardar
    ifstream leer; //referencia para lee
    fstream temp; //referencia para un archivo temporal  
    leer.open("project.txt");
    temp.open("temp.txt", ios::out | ios::app | ios::binary);
    leer>>person.name>>person.address>>person.father_name>>person.mother_name>>person.mobile_number>>person.sex>>person.mail>>person.citision_no;
    bool encontrado = false;
    cout << "Ingrese el contacto a eliminar: ";
    cin  >> nombre1;
    cout << endl;
    while(!leer.eof()){
      leer >> person.name
           >> person.address
           >> person.father_name
           >> person.mother_name
           >> person.mobile_number
           >> person.sex
           >> person.mail
           >> person.citision_no;

      if(person.name == nombre1){
        encontrado = true;
          cout << "Nombre: " << person.name << endl;
          cout << "Direccion: " << person.address << endl;
          cout << "Apellid Paterno: " << person.father_name << endl;
          cout << "Apellido Materno: " << person.mother_name << endl;
          cout << "Num. de telefono: " << person.mobile_number << endl;
          cout << "Sexo: " << person.sex << endl;
          cout << "e-mail: " << person.mail << endl;
          cout << "Num. ciudadano: " << person.citision_no << endl;
          cout<<endl;
          cout << "Eliminado"<<endl;
          
      }
      else{
        temp<<person.name<<" "<<person.address<<" "<<person.father_name<<" "<<person.mother_name<<" "<<person.mobile_number<<" "<<person.sex<<" "<<person.mail<<" "<<person.citision_no<<endl;
      }
      leer>>person.name>>person.address>>person.father_name>>person.mother_name>>person.mobile_number>>person.sex>>person.mail>>person.citision_no;
    }
    if (encontrado == false)
    {
      cout << "Nombre no encontrado" << endl;
    }
       leer.close();
       
       temp.close();
       remove("project.txt");
       rename("temp.txt", "project.txt");
       
                
  }

};

class directoriobetaf
{
public:
  directoriobetaf(){}
  Records a;
  void menu(int& option){
    system("cls||clear");
    cout << "\n";
    cout << "********Bienvenido a contactos***********" << "\n";
    cout << "\t\t Menu \t\t\n\n";
    cout << "1.Agregar   \t2.Lista   \t3.Modificar  \n4.Buscar \t5.Borrar\t6.Exit \n" ;
    int opc = 0;
    cout << "Dime tu opcion: ";
    cin >> option;


    switch(option){
      case 1:
      
      a.addrecord();
        // system("cls||clear");
        // menu();
        //addrecord();

        break;
      case 2:
        // //Lista
        a.listrecord();
        // system("cls||clear");
        // menu();
        cout << "\nListando records\n";
        break;

      case 3:
        //Modificar
        a.modifyrecord();
        cout << "\nModificando records\n";
        break;


      case 4:
        //Buscar
        a.searchrecord();
        
        break;

      case 5:
        a.deleterecord();
        //Borrar
        cout << "\nBorrando records\n";
        
        break;

      case 6:
        cout << "adiós :)\n";
        return;
        break;

      default:
        cout << "alerta opcion invalida \n";
        break;

    }
    
    cout << "Deseas volver al menu?  1 = si /6 = no \n";
    cout << "\nOpción >";
    cin >> option;

  }
};

int main(void) {

  directoriobetaf b;
  int option = -1;

  while (option != 6) {
    b.menu(option);

  }

  system("cls||clear");

  return 0;
}