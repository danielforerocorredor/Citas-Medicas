#include "Doctores.hpp"

Doctores::Doctores(string newName, string newEspecialidad){
    nombre = newName;
    especialidad = newEspecialidad;
    Paciente Vacio(" ",0, " ");
    citaDia libre(true, Vacio);
    for(int i = 0; i <7; i++){
        disponibilidadSemanal.push_back(libre);
    }
}

ostream& operator<<(ostream& os, Doctores& myDoc){
            string Dias[] = {"lunes", "martes","miercoles","jueves","viernes","sabado","domingo"};
            os << "Nombre del doctor: " << myDoc.getName() << endl;
            os << "Especialidad del doctor: " << myDoc.getEspecialidad() << endl;
            for(int i = 0; i < 7; i++){
                os << "\nEn el dia " << Dias[i] << ":\n";
                if(myDoc.getDispDia(i) == true){
                    os << "\tEstá libre. " << endl;
                }else{
                    os << "\tNo está libre." << endl;
                }
                if(myDoc.getDispDia(i) == false){
                    os << "\t\tOcupado con el paciente: \n" << myDoc.disponibilidadSemanal[i].myPaciente;
                }
            }
    return os;
}

string Doctores::getName(){
    return nombre;
}

string Doctores::getEspecialidad(){
    return especialidad;
}

bool Doctores::getDispDia(int dia){
    return disponibilidadSemanal[dia].disponibilidad;
}

void Doctores::getPacienteDia(int dia){
    Paciente x("no", 0, "nop .");
    if(disponibilidadSemanal[dia].disponibilidad == false){
        cout << disponibilidadSemanal[dia].myPaciente.nombre;
    }
}

void Doctores::asignarCita(int dia, Paciente Pacientico){
    disponibilidadSemanal[dia].disponibilidad = false;
    disponibilidadSemanal[dia].myPaciente = Pacientico;
}

int Doctores::proximaCitaDisp(){
    for(int i = 0; i < 7; i++){
        if(getDispDia(i) == true){
            return i;
        }
    }
    return -1;
}