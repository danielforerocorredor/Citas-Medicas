#include "Paciente.hpp"
#include <vector>

Paciente::Paciente(){
    nombre = " ";
    nivelUrgencia = 0;
    descripcion = " ";
}//constructor 

ostream& operator<<(ostream& os, Paciente& myPaciente){
    os << "nombre: " <<myPaciente.nombre << endl;
    os << "nivel de urgencia: "<<myPaciente.nivelUrgencia << endl;
    os << "descripcion: "<<myPaciente.descripcion << endl;
    return os;
}

Paciente::Paciente(string Name, int Level, string Description){
    nombre = Name;
    nivelUrgencia = Level;
    descripcion = Description;
}//constructor parametrizado

bool Paciente::operator<(const Paciente B)const{
    if(nivelUrgencia < B.nivelUrgencia){
        return true;
    }else{
        return false;
    }
}//el operador '<' compara los niveles de urgencia de los pacientes

bool Paciente::operator>(const Paciente B){
    if(nivelUrgencia > B.nivelUrgencia){
        return true;
    }else{
        return false;
    }
}//el operador '>' compara los niveles de urgencia de los pacientes

void Paciente::operator=(const Paciente P){
    nombre = P.nombre;
    nivelUrgencia = P.nivelUrgencia;
    descripcion = P.descripcion;
}

string Paciente::getEspecialidadPaciente()const{
    string especialidades[7] = {"Oftalmologia", "Cardiologia", "Neurologia", "Gastroenterologia", "Traumatologia","Neumologia", "General"};
    int numDePalabras = 0;
    string Palabras[numDePalabras];
    string word = "";
    int index=0;
    for(int i = 0; i < descripcion.size()-1 ; i++){
        char x = descripcion.at(i);
        if(x == ' '){
            numDePalabras++;
            Palabras[index]=word;
            word = "";
        }else{
            word = word + x;
        }
     }
    for(int i = 0; i < numDePalabras; ++i){
        if(Palabras[i] == "ojos" || Palabras[i]=="parpado" || Palabras[i]=="pupilas" || Palabras[i] == "iris" || Palabras[i]=="ceguera"){
            return especialidades[0];
        }//Oftalmologia
        else if(Palabras[i] == "corazon" || Palabras[i]=="desmayo" || Palabras[i]=="presion" || Palabras[i] == "taquicardia" || Palabras[i]=="pecho"){
            return especialidades[1];
        }//cardiologia
        else if(Palabras[i] == "cabeza" || Palabras[i]=="cerebro" || Palabras[i]=="tics" || Palabras[i] == "mareo" || Palabras[i]=="temblor"){
            return especialidades[2];
        }//Neurologia
        else if(Palabras[i] == "estomago" || Palabras[i]=="diarrea" || Palabras[i]=="vomito" || Palabras[i] == "gastritis" || Palabras[i]=="apetito"){
            return especialidades[3];
        }//gastroenterologia
        else if(Palabras[i] == "huesos" ||Palabras[i] == "hueso" || Palabras[i]=="musculo" || Palabras[i]=="golpe" || Palabras[i] == "fractura" || Palabras[i]=="lesion"){
            return especialidades[4];
        }//traumatologoa
        else if(Palabras[i] == "pulmones" || Palabras[i]=="nariz" || Palabras[i]=="respirar" || Palabras[i] == "congestion" || Palabras[i]=="flema" || Palabras[i]=="tos"){
            return especialidades[5];
        }//neumologia
        else if (Palabras[i]=="general"){
            return especialidades[6];
        }//general
        else{ return especialidades[6]; }
    }
    return especialidades[6];
}
