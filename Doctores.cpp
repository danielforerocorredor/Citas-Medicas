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
            os << "nombre del doctor: " << myDoc.getName();
            os << "especialidad del doctor: " << myDoc.getEspecialidad();
            for(int i = 0; i < 7; i++){
                os << "en el dia " << i << ":\n";
                os << "\tLa disponibilidad es: " << myDoc.getDispDia(i);
                if(myDoc.getDispDia(i) == false){
                    os << "\t\tocupado con el paciente: " << myDoc.disponibilidadSemanal[i].myPaciente;
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