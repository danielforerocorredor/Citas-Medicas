#ifndef _paciente_hpp_
#define _paciente_hpp_
#include <iostream>
using namespace std;

/*

    CLASE QUE REPRESENTA A UN PACIENTE
        - Nombre del paciente (STRING).
        - Grado de urgencia (INT).
        - descripcion de los sintomas (STRING).
*/

class Paciente{
    public:
        string nombre;
        int nivelUrgencia; 
        string descripcion; 


        Paciente();//CONSTRUCTOR (genera un paciente "vacio").
        Paciente(string Name, int Level, string Description);//CONSTRUCTOR PARAMETRIZADO
        friend ostream& operator<<(ostream& os, Paciente& myPaciente);//SOBRECARGA OPERADOR INSERCION
        bool operator<(const Paciente B)const;//SOBRECARGA OPERADOR <
        bool operator>(const Paciente B);//SOBRECARGA OPERADOR >
        void operator=(const Paciente P);//SOBRECARGA OPERADOR =
        string getEspecialidadPaciente()const;//OUTPUT: string con la especialidad que necesita el paciente 

        
};

#endif

