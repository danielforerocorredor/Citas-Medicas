#include "Paciente.hpp"
#include "Doctores.hpp"
#include <iostream> 
using namespace std;

int main(){
    cout << endl << endl << endl;

    cout << endl << endl << endl;

    Paciente Paciente_1("sara", 4, "me duelen los ojos .");
    cout << "PACIENTE 1:\n" << Paciente_1 << endl;
    cout << "especialidad necesaria: " << Paciente_1.getEspecialidadPaciente() << endl;

    cout << endl;

    Paciente Paciente_2("lucas", 9, "siento algo en el cerebro .");
    cout << "PACIENTE 2:\n" << Paciente_2 << endl;
    cout << "especialidad necesaria: " << Paciente_2.getEspecialidadPaciente() << endl;

    cout << endl << endl << endl;

    Doctores Doc1("pepe","general");
    //cout << Doc1 << endl;
    cout << Doc1.getName() << endl;
    cout << Doc1.getEspecialidad() << endl; 
    cout << Doc1.getDispDia(0) << endl;
    Doc1.getPacienteDia(0);
    Doc1.asignarCita(0,Paciente_1);
    cout << Doc1.getDispDia(0) << endl;
    Doc1.getPacienteDia(0);
    cout << Doc1.proximaCitaDisp() << endl;




    return 0;
}