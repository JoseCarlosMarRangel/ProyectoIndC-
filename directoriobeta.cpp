using System;
using System.IO;

namespace Agenda
{
     class Clase
    {
        char resp;
        string salida = "";

        public Clase()
        {
        }

        private void menu()
        {
            Clase C = new Clase();

            do
            {
                salida = "NO";
                Console.Clear();
                Console.WriteLine("==== AGENDA de WILO ======");
                Console.WriteLine("*                         *");
                Console.WriteLine("*  1) NUEVO contacto      *");
                Console.WriteLine("*  2) BORRAR contacto     *");
                Console.WriteLine("*  3) VER mis contactos   *");
                Console.WriteLine("*  4) Salir               *");
                Console.WriteLine("*                         *");
                Console.WriteLine("===========================");
                ConsoleKeyInfo info = Console.ReadKey(true);
                resp = info.KeyChar;
                switch (resp)
                 {
                    case '1': C.Agregar();
                        break;
                    case '2': C.Eliminar(0);
                        break;
                    case '3': C.Eliminar(1);
                        break;
                    case '4': salida = "SI";
                        break;
                    default: Console.WriteLine("\nOpción incorrecta");
                        break;
                 }
            } while (salida != "SI");
        }

        private void Agregar()
        {
            Console.Clear();

            string lectura = "";
            string nombre = "";
            string tel = "";

            Console.WriteLine("Nombre:");
            nombre = Console.ReadLine();
            Console.WriteLine("Teléfono:");
            tel = Console.ReadLine();

            StreamReader lector = new StreamReader("Agenda.txt");            
            StreamWriter escritor = new StreamWriter("AgendaBACK.txt");

            while ((lectura = lector.ReadLine()) != null)
            {
                escritor.WriteLine(lectura);
            }
            lector.Close();

            escritor.WriteLine(nombre);
            escritor.WriteLine(tel);
            escritor.Close();

            File.Delete("Agenda.txt");
            File.Copy("AgendaBACK.txt", "Agenda.txt");
            File.Delete("AgendaBACK.txt");
        }

        private void Eliminar(int num)
        {
            if (num == 0)
            {
              Console.Clear();
              StreamReader lector = new StreamReader("Agenda.txt");

              string lectura = "";
              string busqueda = "";

              while ((lectura = lector.ReadLine()) != null)
              {
                Console.WriteLine(lectura);
                lectura = lector.ReadLine();
                Console.WriteLine(lectura);
                Console.WriteLine("************");
                }
                lector.Close();

                Console.WriteLine("Digita nombre del contacto a borrar");
                busqueda = Console.ReadLine();

                lector = new StreamReader("Agenda.txt");
                StreamWriter escritorback = new StreamWriter("AgendaBACK.txt");
                while ((lectura = lector.ReadLine()) != null)
                {
                    if (lectura == busqueda)
                    {
                        lector.ReadLine();
                    }
                    else
                    {
                        escritorback.WriteLine(lectura);
                    }
                }
                escritorback.Close();
                lector.Close();
                File.Delete("Agenda.txt");
                File.Copy("AgendaBACK.txt", "Agenda.txt");
                File.Delete("AgendaBACK.txt");
            }
            else
            {
                Console.Clear();
                StreamReader lector = new StreamReader("Agenda.txt");

                string lectura = "";

                while ((lectura = lector.ReadLine()) != null)
                {
                  Console.WriteLine(lectura);
                  lectura = lector.ReadLine();
                  Console.WriteLine(lectura);
                  Console.WriteLine("****************************");
                }
                lector.Close();
                Console.WriteLine("'Enter' para ir al menú principal");
                Console.ReadLine();
            }
        }

        static void Main()
        {
          if (!File.Exists("Agenda.txt"))
           {
            StreamWriter escritor = new StreamWriter("Agenda.txt");
            escritor.Close();
           }
           Clase C = new Clase();
           C.menu();
        }
    }
}


