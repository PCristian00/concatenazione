#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
fstream fin1, fin2, fileout;
char nome1[16];
char nome2[16];

// questa funzione genera dinamicamente una stringa di 32 caratteri
// e la riempie con la stringa risultante dal concatenamento delle
// due stringhe lette rispettivamente al primo ed al secondo argomento;
// restituisce il puntatore al primo elemento della stringa generata
char* concatena(char* s1, char* s2) {
char* cat=new char[32];
char* s=cat;
while (*s1) {*s = *s1; s++; s1++;};
    while (*s2) {*s = *s2; s++; s2++;};
    *s = '\0';
    return cat;
}

// questa funzione tenta di leggere una stringa s da fin
// e restituisce true solo se ci riesce
bool LeggiStringa(fstream& fin, char* s) {
if(fin>>s) return true;
else return false;
}

// questa funzione copia la parola s nel filestream fout e quindi chiama
// la funzione LeggiStringa per tentare di leggere un’altra stringa dal
// filestream fin; restituisce true solo se ci riesce.
bool CopiaStringa(fstream& fout, fstream& fin, char* s) {
fout<<" "<<s;
return LeggiStringa(fin,s);
}

// questo programma chiede i nomi dei due file da fondere ordinatamente
// e genera un terzo file il cui nome risulta dalla loro concatenazione;
// in esso vengono scritte ordinatamente le parole che compaiono nei
// due files aperti in lettura; per svolgere questo compito il programma
// utilizza le funzioni CopiaStringa, LeggiStringa e strcmp
int main() {

/*
    cout<<"Inserire nome file 1:"<<endl;
    cin>>nome1;

    cout<<"Inserire nome file 2:"<<endl;
    cin>>nome2;
*/

    fin1.open("C:\\Users\\Thinkpad User\\CLionProjects\\concatenazione\\dizio.txt",ios::in);
    if(!fin1.is_open()) cout<<"Errore apertura "<<nome1<<endl;

    fin2.open("C:\\Users\\Thinkpad User\\CLionProjects\\concatenazione\\nario.txt",ios::in);
    if(!fin2.is_open()) cout<<"Errore apertura "<<nome2<<endl;
/*
    char *nome3[32];
    *nome3 = concatena(nome1, nome2);
    cout<<"Concat: "<<*nome3<<endl;
*
 */
    fileout.open("C:\\Users\\Thinkpad User\\CLionProjects\\concatenazione\\dizionario.txt",ios::out);
    if(!fileout.is_open()) cout<<"Errore apertura "<<endl;//*nome3<<endl;

    char p1[30], p2[30];
    bool sx=LeggiStringa(fin1,p1);
    bool dx=LeggiStringa(fin2,p2);

    while(sx&&dx)
        if(strcmp(p1,p2)<=0) sx=CopiaStringa(fileout,fin1,p1);
        else dx=CopiaStringa(fileout,fin2,p2);

        fileout<<endl;
        fin1.close();
        fin2.close();
        fileout.close();

        return 0;
}