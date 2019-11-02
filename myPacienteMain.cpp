#include "Paciente.hpp"
#include "Doctores.hpp"
#include <stdlib.h>
#include <iostream> 
using namespace std;

bool checkEspecialidadesRepetidas(string esp, vector<Doctores> vec){
    for(int i = 0; i < vec.size(); i++){
        if(esp == vec[i].getEspecialidad()){
            return false;
        }
    }
    return true;
}

void citasMedicas(){
    string nombres[] = {"Dr. Carlos", "Dr. Juan", "Dr. Pablo", "Dr. Santiago", "Dra. Laura", "Dra. Daniela", "Dra. Sandra", "Dra. Paola"};
    int myRand = rand() % 9;
    //CREACION PACIENTES
    cout << "\n\n\n\n\n";
    bool working = true;
    cout << "ingrese datos de pacientes a los cuales se les agendara cita." << endl;
    vector<Paciente> misPacientes;
    string name;
    int urg;
    string desc;
    bool more = true;
    while(more){
        cout << "\nIngrese el nombre del paciente\n";
        cin >> name;
        cout << "Ingrese el nivel de urgencia.\n";
        cin >> urg;
        cout << "Ingrese la descripcion de los sintomas. \n";
        cin >> desc;
        Paciente P(name, urg, desc);
        P.descripcion += " .";
        misPacientes.push_back(P);
        string resp;
        cout << "desea agregar mas pacientes?" << endl;
        cin >> resp;
        if(resp == "si"){
            more = true;
        }else{
            more = false;
        }
    }
    cout << "\n\nLos pacientes registrados son: \n\n\n";
    for(int i = 0; i < misPacientes.size(); i++){
        cout << misPacientes[i];
        cout << "La especialidad necesaria es: "<< misPacientes[i].getEspecialidadPaciente()<< endl << endl;
    }
    // CREACION DOCTORES
    vector<Doctores> misDoctores;
    for(int i = 0; i < misPacientes.size(); i++){
        if(checkEspecialidadesRepetidas(misPacientes[i].getEspecialidadPaciente(), misDoctores)){
            Doctores D(nombres[myRand],misPacientes[i].getEspecialidadPaciente());
            misDoctores.push_back(D);
        }
    }
    cout << "\n\nLos Doctores registrados son: \n\n\n";
    for(int i = 0; i < misDoctores.size(); i++){
        cout << misDoctores[i] << endl << endl;

    }
    
    

}

int main(){
    
    citasMedicas();


    return 0;
}