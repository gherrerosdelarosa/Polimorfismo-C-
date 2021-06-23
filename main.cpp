#include <iostream>
#include <locale>

//Muestra area y el perimetro de dos poligonos llamando al metodo virtual Area y Perimetro 
//declarado en la clase base

/*

   Ejercicio: 
   1- haz un diagrama de clases utilizando DIA (UML)
              Debes modelar 3 clases:

              1- Figura
                 Propiedades: protected float x
                 Métodos:     Figura(float x)   (constructor)
                              float perimetro() (virtual pura)
                              float area()      (virtual pura)

              2- Circulo (hereda de Figura)
                 Propiedades:  -----
                 Métodos:     Circulo(float radio) (constructor -> x = radio)
                              float perimetro()    (devuelve perímetro del circulo)
                              float area();        (devuelve área del circulo)

              3- Cuadrado (hereda de Figura)
                 Propiedades:  -----
                 Métodos:     Cuadrado(float lado) (constructor -> x = lado)
                              float perimetro()    (devuelve peímetro del cuadrado)
                              float area();        (devuelve área del cuadrado)

   2- Crea un programa C++ implementando el diagrama anterior.
              
             1- Define las clases y sus métodos

             2- En el main instancia las dos clases derivadas

             3- Ejecuta para cada objeto los métodos perímetro y área. 


*/


using namespace std;
const double PI = 3.141592;

class Figura{
  protected:
    float x;
  public:
    Figura(float cx=0){
       x = cx;
    }
  
    virtual float Perimetro() = 0;  //Método virtual puro
    virtual float Area() = 0;       //Método virtual puro
};

// Clases derivadas
class Circulo: public Figura{
   public:

   Circulo(float radio){
     x = radio;
   }
   float Perimetro(){
     return 2* PI * x;
   }
   float Area(){
     return PI * x * x;
   }
};

class Cuadrado: public Figura
{

 public:
  Cuadrado(float lado){
    x = lado;
  }
  float Perimetro(){
    return 4 * x;
  }
  float Area(){
    return x * x;
  }
};

int main(){
   setlocale(LC_ALL, "");

   float l, r;

   cout << "Entre el lado del cuadrado" << endl;
   cin >> l;

   cout << "Entre el radio del círculo" << endl;
   cin >> r;

   Cuadrado cuad1(l);
   Circulo  Circ1(r);

   

   cout << "El perimetro del cuadrado es:" << cuad1.Perimetro() << endl;
   cout << "El area del cuadrado es:" << cuad1.Area() << endl;
   
   cout << "El perimetro del circulo es:" << Circ1.Perimetro() << endl;
   cout << "El area del circulo es:" << Circ1.Area() << endl;
   
   //Utilizando polimorfismo dinámico
   cout << "\n\nUtilizando polimorfismo dinámico\n";
   
   Figura *figura;  //Utilizamos la clase base o padre como plantilla. Estamos diciendo: "Creamos un objeto de tipo puntero con dos figuras"
   
   
   figura = &Circ1;   //Asignamos el círculo al puntero figura
   
   cout << "El perimetro del circulo es:" << figura->Perimetro() << endl;
   cout << "El area del circulo es:" << figura->Area() << endl;

  
   //CUADRAD0
   figura = &cuad1;   //Asignamos el cuadrado al puntero figura
   
   cout << "El perimetro del circulo es:" << figura->Perimetro() << endl;
   cout << "El area del circulo es:" << figura->Area() << endl;
   
}
