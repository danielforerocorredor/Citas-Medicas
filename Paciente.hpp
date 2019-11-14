#ifndef _paciente_hpp_
#define _paciente_hpp_
#include <iostream>
using namespace std;

class Paciente{
    public:
        string nombre;
        int nivelUrgencia; 
        string descripcion; 


        Paciente();
        Paciente(string Name, int Level, string Description);
        friend ostream& operator<<(ostream& os, Paciente& myPaciente);
        bool operator<(const Paciente B)const;
        bool operator>(const Paciente B);
        void operator=(const Paciente P);
        string getEspecialidadPaciente()const;

        
};

#endif


//revisar ordenar por prioridad, retorna un vector de enteros ordenado y deberia retornar un vector de pacientes
//getEspecialidad funciona, mejorar!!!
