#ifndef _Doctores_hpp_
#define _Doctores_hpp_
#include "Paciente.hpp"
#include "citaDia.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Doctores{
    private:
        string nombre;
        string especialidad; 
        vector<citaDia> disponibilidadSemanal;//vector de longitud 7, que representa los dias de la semana, cada uno tiene un valor booleano que muestra si esta disponible o no.
    public: 
        Doctores(string newName, string newEspecialidad);//constructor parametrizado objeto doctores
        friend ostream& operator<<(ostream& os, Doctores& myDoc);
        string getName();
        string getEspecialidad();
        bool getDispDia(int dia);///retorna la disponibilidad de un dia en especifico
        void getPacienteDia(int dia);
        void asignarCita(int dia, Paciente Pacientico);
        int proximaCitaDisp();//retornar el proximo dia libre
};
#endif
