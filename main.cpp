#include <iostream>
#include <cstring>
#include <stdexcept>
#include <vector>
using namespace std;

///CLASA JUCATOR
class Jucator
{
//variabilele clasei
private:
    const int idJucator;
    static int CONTORID;
    char *numeJucator;
    int varsta;
    float inaltime;
    double greutate;
    int nrTricou;
    int nrPozitiiJucate;
    char **pozitiiJucator;  //un jucator poate juca pe mai multe pozitii, de exemplu LB (left back)
                            //si CB(centre back), astfel ca acesta variabila memoreaza un vector de siruri de caractere de lungime 2
    int nrGoluri;
    int nrAsisturi;
    int nrMeciuriJucate;
    bool disponibilitate;   //1 daca poate juca, 0 daca este accidentat sau suspendat

public:
    ///CONSTRUCTORI
    //constructorul fara parametri
    Jucator();

    //constructorul cu toti parametrii
    Jucator(char*, int, float, double, int, int, char**, int, int, int, bool);

    //constructor cu parametri 1
    Jucator(char*, int, float, double);

    //constructor cu parametri 2
    Jucator(int, char**, bool);

    //copy constructor
    Jucator (const Jucator&);

    //destructorul
    ~Jucator();

    ///GET-ere

    const int getIdJucator()
    {
        return idJucator;
    }

    static int getCONTORID()
    {
        return CONTORID;
    }

    char* getNumeJucator()
    {
        return numeJucator;
    }

    int getVarsta()
    {
        return varsta;
    }

    float getInaltime()
    {
        return inaltime;
    }

    double getGreutate()
    {
        return greutate;
    }

    int getNrTricou()
    {
        return nrTricou;
    }

    int getNrPozitiiJucate()
    {
        return nrPozitiiJucate;
    }

    char** getPozitiiJucator()
    {
        return pozitiiJucator;
    }

    int getNrGoluri()
    {
        return nrGoluri;
    }

    int getNrAsisturi()
    {
        return nrAsisturi;
    }

    int getNrMeciuriJucate()
    {
        return nrMeciuriJucate;
    }

    bool getDisponibilitate()
    {
        return disponibilitate;
    }

    ///SET-ere

    void setNumeJucator(char*);

    void setVarsta(int varsta)
    {
        this->varsta=varsta;
    }

    void setInaltime(float inaltime)
    {
        this->inaltime=inaltime;
    }

    void setGreutate(double greutate)
    {
        this->greutate=greutate;
    }

    void setNrTricou(int nrTricou)
    {
        this->nrTricou=nrTricou;
    }

    void setNrPozitiiJucate(int nrPozitiiJucate)
    {
        this->nrPozitiiJucate=nrPozitiiJucate;
    }

    void setPozitiiJucator(char**);

    void setNrGoluri(int nrGoluri)
    {
        this->nrGoluri=nrGoluri;
    }

    void setNrAsisturi(int nrAsisturi)
    {
        this->nrAsisturi=nrAsisturi;
    }

    void setNrMeciuriJucate(int nrMeciuriJucate)
    {
        this->nrMeciuriJucate=nrMeciuriJucate;
    }

    void setDisponibilitate(bool disponibilitate)
    {
        this->disponibilitate=disponibilitate;
    }

    ///SUPRAINCARCARI
    //supraincarcarea operatorului =
    Jucator& operator=(const Jucator&);

    //supraincarcarea operatorului <<
    friend ostream& operator<<(ostream&, const Jucator&);

    //supraincarcarea operatorului >>
    friend istream& operator>>(istream&, Jucator&);

    //supraincarcarea operatorului de indexare []
    char* operator[](int);

    //supraincarcare operator ++ preincrementare
    Jucator& operator++();

    //supraincarcare operator ++ postincrementare
    Jucator operator++(int);

    //supraincarcare operator + intre 2 obiecte din clasa Jucator
    Jucator operator+(const Jucator&);

    //supraincarcare operator - pentru 2 obiecte din clasa Jucator
    Jucator operator-(const Jucator&);

    //supraincarcare operator cast implicit
    operator string();

    //supraincarcare operator <
    bool operator<(const Jucator&);

    //supraincarcare operator ==
    bool operator==(const Jucator&);

    ///Functie care returneaza cat de eficient este un jucator,
    ///adica numarul de goluri plus numarul de asisturi raportat la numarul de meciuri jucate

    float EficientaJucator();

};

int Jucator :: CONTORID=0;

///CONSTRUCTORI CLASA JUCATOR
//constructorul fara parametri pentru clasa Jucator
Jucator :: Jucator():idJucator(CONTORID++)
    {
        this->numeJucator=new char[strlen("necunoscut")+1];
        strcpy(this->numeJucator, "necunoscut");
        this->varsta=0;
        this->inaltime=0;
        this->greutate=0;
        this->nrTricou=0;
        this->nrPozitiiJucate=1;
        this->pozitiiJucator=new char*[1];
        this->pozitiiJucator[0]=new char[3];
        strcpy(this->pozitiiJucator[0], "--");
        this->nrGoluri=0;
        this->nrAsisturi=0;
        this->nrMeciuriJucate=0;
        this->disponibilitate=0;
    }

//constructorul cu toti parametrii pentru clasa Jucator
Jucator :: Jucator(char *numeJucator, int varsta, float inaltime, double greutate,
                   int nrTricou, int nrPozitiiJucate, char **pozitiiJucator, int nrGoluri, int nrAsisturi,
                   int nrMeciuriJucate, bool disponibilitate): idJucator(CONTORID++), varsta(varsta),
                   inaltime(inaltime), greutate(greutate), nrTricou(nrTricou), nrPozitiiJucate(nrPozitiiJucate),
                   nrGoluri(nrGoluri), nrAsisturi(nrAsisturi), nrMeciuriJucate(nrMeciuriJucate), disponibilitate(disponibilitate)
    {
        this->numeJucator=new char[strlen(numeJucator)+1];
        strcpy(this->numeJucator, numeJucator);
        this->pozitiiJucator=new char*[nrPozitiiJucate];
        for(int i=0; i<nrPozitiiJucate; i++)
        {
            this->pozitiiJucator[i]=new char[3];
            strcpy(this->pozitiiJucator[i], pozitiiJucator[i]);
        }
    }

//constructorul cu parametri 1, pentru clasa Jucator
Jucator :: Jucator(char *numeJucator, int varsta, float inaltime, double greutate):idJucator(CONTORID++),
                 varsta(varsta), inaltime(inaltime), greutate(greutate)
{
    this->numeJucator=new char[strlen(numeJucator)+1];
    strcpy(this->numeJucator, numeJucator);
    this->nrTricou=0;
    this->nrPozitiiJucate=1;
    this->pozitiiJucator=new char*[1];
    this->pozitiiJucator[0]=new char[3];
    strcpy(this->pozitiiJucator[0], "--");
    this->nrGoluri=0;
    this->nrAsisturi=0;
    this->nrMeciuriJucate=0;
    this->disponibilitate=0;
}

//constructorul cu parametri 2, pentru clasa Jucator
Jucator :: Jucator(int nrPozitiiJucate, char **pozitiiJucator, bool disponibilitate): idJucator(CONTORID++), nrPozitiiJucate(nrPozitiiJucate),
                    disponibilitate(disponibilitate)
{
    this->numeJucator=new char[strlen("necunoscut")+1];
    strcpy(this->numeJucator, "necunoscut");
    this->varsta=0;
    this->inaltime=0;
    this->greutate=0;
    this->nrTricou=0;
    this->pozitiiJucator=new char*[nrPozitiiJucate];
    for(int i=0; i<nrPozitiiJucate; i++)
    {
        this->pozitiiJucator[i]=new char[3];
        strcpy(this->pozitiiJucator[i], pozitiiJucator[i]);
    }
    this->nrGoluri=0;
    this->nrAsisturi=0;
    this->nrMeciuriJucate=0;
}

//copy constructorul pentru clasa Jucator
Jucator :: Jucator (const Jucator &obj):idJucator(CONTORID++)
    {
        this->numeJucator=new char[strlen(obj.numeJucator)+1];
        strcpy(this->numeJucator, obj.numeJucator);
        this->varsta=obj.varsta;
        this->inaltime=obj.inaltime;
        this->greutate=obj.greutate;
        this->nrTricou=obj.nrTricou;
        this->nrPozitiiJucate=obj.nrPozitiiJucate;
        this->pozitiiJucator=new char*[obj.nrPozitiiJucate];
        for(int i=0; i<obj.nrPozitiiJucate; i++)
        {
            this->pozitiiJucator[i]=new char[3];
            strcpy(this->pozitiiJucator[i], obj.pozitiiJucator[i]);
        }
        this->nrGoluri=obj.nrGoluri;
        this->nrAsisturi=obj.nrAsisturi;
        this->nrMeciuriJucate=obj.nrMeciuriJucate;
        this->disponibilitate=obj.disponibilitate;
    }

//destructorul pentru clasa Jucator
Jucator :: ~Jucator()
    {
        if(this->numeJucator!=NULL)
            delete[] this->numeJucator;
        if(this->pozitiiJucator!=NULL)
            delete[] this->pozitiiJucator;
    }


///SET-ere CLASA JUCATOR

void Jucator :: setNumeJucator(char *numeJucator)
    {
        if(this->numeJucator!=NULL)
            delete[] this->numeJucator;
        this->numeJucator=new char[strlen(numeJucator)+1];
        strcpy(this->numeJucator, numeJucator);
    }

void Jucator :: setPozitiiJucator(char **pozitiiJucate)
    {
        if(this->pozitiiJucator!=NULL)
            delete[] this->pozitiiJucator;
        this->pozitiiJucator=new char*[nrPozitiiJucate];
        for(int i=0; i<nrPozitiiJucate; i++)
        {
            this->pozitiiJucator[i]=new char[3];
            strcpy(this->pozitiiJucator[i], pozitiiJucator[i]);
        }
    }

///SUPRAINCARCARI CLASA JUCATORI
//supraincarcarea operatorului = pentru clasa Jucator
Jucator& Jucator :: operator=(const Jucator &obj)
    {
        if(this!=&obj)
        {
            if(this->numeJucator!=NULL)
                delete[] this->numeJucator;
            this->numeJucator=new char[strlen(obj.numeJucator)+1];
            strcpy(this->numeJucator, obj.numeJucator);

            this->varsta=obj.varsta;
            this->inaltime=obj.inaltime;
            this->greutate=obj.greutate;
            this->nrTricou=obj.nrTricou;
            this->nrPozitiiJucate=obj.nrPozitiiJucate;

            if(this->pozitiiJucator!=NULL)
                delete[] this->pozitiiJucator;
            this->pozitiiJucator=new char*[obj.nrPozitiiJucate];
            for(int i=0; i<obj.nrPozitiiJucate; i++)
            {
                this->pozitiiJucator[i]=new char[3];
                strcpy(this->pozitiiJucator[i], obj.pozitiiJucator[i]);
            }

            this->nrGoluri=obj.nrGoluri;
            this->nrAsisturi=obj.nrAsisturi;
            this->nrMeciuriJucate=obj.nrMeciuriJucate;
            this->disponibilitate=obj.disponibilitate;
        }
        return *this;
    }

//supraincarcare opearator << pentru clasa Jucator
ostream& operator<<(ostream &out, const Jucator &obj)
{
    out<<"Id jucator: "<<obj.idJucator<<endl;
    out<<"Nume jucator: "<<obj.numeJucator<<endl;
    out<<"Varsta jucator: "<<obj.varsta<<endl;
    out<<"Inaltime jucator: "<<obj.inaltime<<endl;
    out<<"Greutate jucator: "<<obj.greutate<<endl;
    out<<"Numar tricou: "<<obj.nrTricou<<endl;
    out<<"Numar pozitii pe care poate juca: "<<obj.nrPozitiiJucate<<endl;
    out<<"Pozitile pe care poate juca: ";
    for(int i=0; i<obj.nrPozitiiJucate; i++)
        out<<obj.pozitiiJucator[i]<<" ";
    out<<endl;
    out<<"Numar de goluri inscrise: "<<obj.nrGoluri<<endl;
    out<<"Numar de asisturi: "<<obj.nrAsisturi<<endl;
    out<<"Numar de meciuri jucate: "<<obj.nrMeciuriJucate<<endl;
    out<<"Disponibilitate: "<<obj.disponibilitate<<endl;
    return out;
}

//supraincarcare operator >> pentru clasa Jucator
istream& operator>>(istream& in, Jucator &obj)
{
    //citim numele jucatorului
    cout<<"Nume jucator: ";
    char nume[100];
    in.getline(nume, 100);
    if(obj.numeJucator!=NULL)
        delete[] obj.numeJucator;
    obj.numeJucator=new char[strlen(nume)+1];
    strcpy(obj.numeJucator, nume);

    //citim varsta, inaltimea, greutatea, numar tricou si numarul de pozitii pe care poate juca
    cout<<"Varsta jucator: ";
    in>>obj.varsta;
    cout<<"Inaltime jucator: ";
    in>>obj.inaltime;
    cout<<"Greutate jucator: ";
    in>>obj.greutate;
    cout<<"Numar tricou: ";
    in>>obj.nrTricou;
    cout<<"Numar pozitii pe care poate juca: ";
    in>>obj.nrPozitiiJucate;

    //citim acum pozitiile
    cout<<"Pozitiile pe care poate juca: ";
    if(obj.pozitiiJucator!=NULL)
        delete[] obj.pozitiiJucator;
    obj.pozitiiJucator=new char*[obj.nrPozitiiJucate];
    for(int i=0; i<obj.nrPozitiiJucate; i++)
    {
        obj.pozitiiJucator[i]=new char[3];
        in>>obj.pozitiiJucator[i];
    }

    //citim numarul de goluri, assisturi meciuri si disponibilitatea
    cout<<"Numar de goluri inscrise: ";
    in>>obj.nrGoluri;
    cout<<"Numar de asisturi: ";
    in>>obj.nrAsisturi;
    cout<<"Numar de meciuri jucate: ";
    in>>obj.nrMeciuriJucate;
    cout<<"Disponibilitate: ";
    in>>obj.disponibilitate;
    cout<<endl;
    in.ignore();
    return in;
}

//supraincarcare operator de indexare [] pentru clasa Jucator
char* Jucator :: operator[](int index)
{
    if(index>=0 && index<this->nrPozitiiJucate)
        return this->pozitiiJucator[index];
    else throw runtime_error("Index invalid");
}

//supraincarcare operator ++ preincrementare pentru clasa Jucator
Jucator& Jucator :: operator++()
{
    this->nrMeciuriJucate+=2;
    this->nrGoluri++;
    this->nrAsisturi++;
    this->disponibilitate=!(this->disponibilitate);
    return *this;
}

//supraincarcare operator ++ postincrementare pentru clasa Jucator
Jucator Jucator :: operator++(int)
{
    Jucator copie=*this;
    ++(*this);
    return copie;
}

//supraincarcare operator + pentru 2 obiecte din clasa Jucator
Jucator Jucator :: operator+(const Jucator &obj)
{
    Jucator copie=*this;
    //numele jucatorului1 + numele jucatorului2
    if(copie.numeJucator!=NULL)
        delete[] copie.numeJucator;
    copie.numeJucator=new char[strlen(this->numeJucator)+strlen(obj.numeJucator)+4];
    strcpy(copie.numeJucator, this->numeJucator);
    strcat(copie.numeJucator, " + ");
    strcat(copie.numeJucator, obj.numeJucator);

    //mediile dintre cele 2 valori
    copie.varsta=(this->varsta+obj.varsta)/2;
    copie.inaltime=(this->inaltime+obj.inaltime)/2;
    copie.greutate=(this->greutate+obj.greutate)/2;
    copie.nrTricou=(this->nrTricou+obj.nrTricou)/2;

    //reuniunea fara eliminarea duplicatelor a pozitiilor
    copie.nrPozitiiJucate=this->nrPozitiiJucate+obj.nrPozitiiJucate;
    if(copie.pozitiiJucator!=NULL)
        delete[] copie.pozitiiJucator;
    copie.pozitiiJucator=new char*[copie.nrPozitiiJucate];
    for(int i=0; i<this->nrPozitiiJucate; i++)
    {
        copie.pozitiiJucator[i]=new char[3];
        strcpy(copie.pozitiiJucator[i], this->pozitiiJucator[i]);
    }
    for(int i=this->nrPozitiiJucate; i<copie.nrPozitiiJucate; i++)
    {
        copie.pozitiiJucator[i]=new char[3];
        strcpy(copie.pozitiiJucator[i], obj.pozitiiJucator[i-this->nrPozitiiJucate]);
    }

    //valorile se aduna
    copie.nrGoluri=this->nrGoluri+obj.nrGoluri;
    copie.nrAsisturi=this->nrAsisturi+obj.nrAsisturi;
    copie.nrMeciuriJucate=this->nrMeciuriJucate+obj.nrMeciuriJucate;

    //disponibilitate afirmativa doar daca amandoi sunt disponibili
    copie.disponibilitate=this->disponibilitate & obj.disponibilitate;

    return copie;
}

//supraincarcare operator - pentru 2 obiecte din clasa Jucator
Jucator Jucator :: operator-(const Jucator &obj)
{
    Jucator copie=*this;
    //numele jucatorului1 - numele jucatorului2
    if(copie.numeJucator!=NULL)
        delete[] copie.numeJucator;
    copie.numeJucator=new char[strlen(this->numeJucator)+strlen(obj.numeJucator)+4];
    strcpy(copie.numeJucator, this->numeJucator);
    strcat(copie.numeJucator, " - ");
    strcat(copie.numeJucator, obj.numeJucator);

    //diferenta dintre valori
    copie.varsta=this->varsta-obj.varsta;
    copie.inaltime=this->inaltime-obj.inaltime;
    copie.greutate=this->greutate-obj.greutate;

    copie.nrGoluri=this->nrGoluri-obj.nrGoluri;
    copie.nrAsisturi=this->nrAsisturi-obj.nrAsisturi;
    copie.nrMeciuriJucate=this->nrMeciuriJucate-obj.nrMeciuriJucate;

    //disponibilitate afirmativa doar daca amandoi sunt disponibili
    copie.disponibilitate=this->disponibilitate & obj.disponibilitate;

    return copie;
}

//supraincarcare operator cast implicit pentru clasa Jucator
Jucator :: operator string()
{
    return this->numeJucator;
}

//supraincarcare operator < pentru clasa Jucator
bool Jucator :: operator<(const Jucator &obj)
{
    if(this->nrGoluri>=obj.nrGoluri)
        return 0;
    if(this->nrAsisturi>=obj.nrAsisturi)
        return 0;
    if(this->nrMeciuriJucate>=obj.nrMeciuriJucate)
        return 0;
    return 1;
}

//supraincarcare operator == pentru clasa Jucator
bool Jucator :: operator==(const Jucator &obj)
{
    if(strcmp(this->numeJucator, obj.numeJucator))
        return 0;
    if(this->varsta!=obj.varsta)
        return 0;
    if(this->inaltime!=obj.inaltime)
        return 0;
    if(this->greutate!=obj.greutate)
        return 0;
    if(this->nrTricou!=obj.nrTricou)
        return 0;
    if(this->nrPozitiiJucate!=obj.nrPozitiiJucate)
        return 0;

    for(int i=0; i<this->nrPozitiiJucate; i++)
        if(strcmp(this->pozitiiJucator[i], obj.pozitiiJucator[i]))
            return 0;

    if(this->nrGoluri!=obj.nrGoluri)
        return 0;
    if(this->nrAsisturi!=obj.nrAsisturi)
        return 0;
    if(this->nrMeciuriJucate!=obj.nrMeciuriJucate)
        return 0;
    if(this->disponibilitate!=obj.disponibilitate)
        return 0;

    return 1;

}

//functia EficientaJucator din clasa Jucator
float Jucator :: EficientaJucator()
    {
        float indiceEficienta=0;
        if(this->nrMeciuriJucate!=0)
        {
            indiceEficienta = this->nrGoluri + this->nrAsisturi;
            indiceEficienta = indiceEficienta / this->nrMeciuriJucate;
        }
        return indiceEficienta;
    }

///CLASA STADION
class Stadion
{
//atributele clasei Stadion
private:
    char *numeStadion;
    float suprafataStadion;
    int nrLocuriStadion;
    int *locuriOcupate;

public:
    ///CONSTRUCTORI
    //constructor fara parametri
    Stadion();

    //constructor cu toti parametrii
    Stadion(char*, float, int, int*);

    //constructor cu parametri 1
    Stadion(char*);

    //constructor cu parametri 2
    Stadion(int, int*);

    //copy constructor
    Stadion(const Stadion&);

    //destructor
    ~Stadion();

    ///GET-ere
    char* getNumeStadion()
    {
        return this->numeStadion;
    }

    float getSuprafataStadion()
    {
        return this->suprafataStadion;
    }

    int getNrLocuriStadion()
    {
        return this->nrLocuriStadion;
    }

    int* getLocuriOcupate()
    {
        return this->locuriOcupate;
    }

    ///SET-ere
    void setNumeStadion(char* );

    void setSuprafataStadion(float suprafataStadion)
    {
        this->suprafataStadion=suprafataStadion;
    }

    void setNrLocuriStadion(int nrLocuriStadion)
    {
        this->nrLocuriStadion=nrLocuriStadion;
    }

    void setLocuriOcupate(int*);

    ///SUPRAINCARCARI

    //supraincarcare operator =
    Stadion& operator=(const Stadion&);

    //supraincarcare operator <<
    friend ostream& operator<<(ostream&, const Stadion&);

    //supraincarcare operator >>
    friend istream& operator>>(istream&, Stadion&);

    //supraincarcare operator []
    int operator[](int);

    //supraincarcare operator ++ preincrementare
    Stadion& operator++();

    //supraincarcare operator ++ postincrementare
    Stadion operator++(int);

    //supraincarcare operator + pentru 2 obiecte din clasa
    Stadion operator+(const Stadion&);

    //supraincarcare operator - intre 2 obiecte din clasa
    Stadion operator-(const Stadion&);

    //supraincarcare operator cast
    operator string();

    //supraincarcare operator <
    bool operator<(const Stadion&);

    //supraincarcare operator ==
    bool operator==(const Stadion&);


    ///Functie care returneaza numarul de locuri libere de pe stadion
    int NrLocuriLibere();
};

///CONSTRUCTORI CLASA STADION
//constructor fara parametri pentru clasa Stadion
Stadion :: Stadion()
    {
        this->numeStadion=new char[strlen("necunoscut")+1];
        strcpy(this->numeStadion, "necunoscut");
        this->suprafataStadion=0;
        this->nrLocuriStadion=0;
        this->locuriOcupate=NULL;
    }

//constructor cu toti parametrii
Stadion :: Stadion(char *numeStadion, float suprafataStadion, int nrLocuriStadion, int *locuriOcupate):
            suprafataStadion(suprafataStadion), nrLocuriStadion(nrLocuriStadion)
    {
        this->numeStadion=new char[strlen(numeStadion)+1];
        strcpy(this->numeStadion, numeStadion);
        this->locuriOcupate=new int[nrLocuriStadion];
        for(int i=0; i<nrLocuriStadion; i++)
            this->locuriOcupate[i]=locuriOcupate[i];
    }

//costructor cu parametri 1 pentru clasa Stadion
Stadion ::Stadion(char *numeStadion)
    {
        this->numeStadion=new char[strlen(numeStadion)+1];
        strcpy(this->numeStadion, numeStadion);
        this->suprafataStadion=0;
        this->nrLocuriStadion=0;
        this->locuriOcupate=NULL;
    }

//constructor cu parametri 2 pentru clasa Stadion
Stadion :: Stadion(int nrLocuriStadion, int *locuriOcupate):nrLocuriStadion(nrLocuriStadion)
    {
        this->numeStadion=new char[strlen("necunoscut")+1];
        strcpy(this->numeStadion, "necunoscut");
        this->suprafataStadion=0;
        this->locuriOcupate=new int[nrLocuriStadion];
        for(int i=0; i<nrLocuriStadion; i++)
            this->locuriOcupate[i]=locuriOcupate[i];
    }

//copy constructor pentru clasa Stadion
Stadion :: Stadion(const Stadion &obj)
    {
        this->numeStadion=new char[strlen(obj.numeStadion)+1];
        strcpy(this->numeStadion, obj.numeStadion);
        this->suprafataStadion=obj.suprafataStadion;
        this->nrLocuriStadion=obj.nrLocuriStadion;
        this->locuriOcupate=new int[obj.nrLocuriStadion];
        for(int i=0; i<obj.nrLocuriStadion; i++)
            this->locuriOcupate[i]=obj.locuriOcupate[i];
    }

//destructor pentru clasa Stadion
Stadion :: ~Stadion()
    {
        if(this->numeStadion!=NULL)
            delete[] this->numeStadion;
        if(this->locuriOcupate!=NULL)
            delete[] this->locuriOcupate;
    }

///SET-ere CLASA STADION

void Stadion :: setNumeStadion(char *numeStadion)
    {
        if(this->numeStadion!=NULL)
            delete[] this->numeStadion;
        this->numeStadion=new char[strlen(numeStadion)+1];
        strcpy(this->numeStadion, numeStadion);
    }

void Stadion :: setLocuriOcupate(int *locuriOcupate)
    {
        if(this->locuriOcupate!=NULL)
            delete[] this->locuriOcupate;
        this->locuriOcupate=new int[this->nrLocuriStadion];
        for(int i=0; i<this->nrLocuriStadion; i++)
            this->locuriOcupate[i]=locuriOcupate[i];
    }

///SUPRAINCARCARI CLASA STADION

//supraincarcare operator = pentru clasa Stadion
Stadion& Stadion :: operator=(const Stadion &obj)
    {
        if(this!=&obj)
        {
            if(this->numeStadion!=NULL)
                delete[] this->numeStadion;
            this->numeStadion=new char[strlen(obj.numeStadion)+1];
            strcpy(this->numeStadion, obj.numeStadion);
            this->suprafataStadion=obj.suprafataStadion;
            this->nrLocuriStadion=obj.nrLocuriStadion;
            if(this->locuriOcupate!=NULL)
                delete[] this->locuriOcupate;
            this->locuriOcupate=new int[obj.nrLocuriStadion];
            for(int i=0; i<obj.nrLocuriStadion; i++)
                this->locuriOcupate[i]=obj.locuriOcupate[i];
        }
        return *this;
    }

//supraincarcare operator << pentru clasa Stadion
ostream& operator<<(ostream &out, const Stadion &obj)
    {
        out<<"Nume stadion: "<<obj.numeStadion<<endl;
        out<<"Suprafata stadion: "<<obj.suprafataStadion<<endl;
        out<<"Numar locuri stadion: "<<obj.nrLocuriStadion<<endl;
        for(int i=0; i<obj.nrLocuriStadion; i++)
            if(obj.locuriOcupate[i]==0)
                out<<"Locul "<<i+1<<" este liber"<<endl;
            else out<<"Locul "<<i+1<<" este ocupat"<<endl;
        out<<endl;
        return out;
    }

//supraincarcare operator >> pentru clasa Stadion
istream& operator>>(istream &in, Stadion &obj)
    {
        cout<<"Nume stadion: ";
        char nume[100];
        if(obj.numeStadion!=NULL)
            delete[] obj.numeStadion;
        in.getline(nume,100);
        obj.numeStadion=new char[strlen(nume)+1];
        strcpy(obj.numeStadion, nume);

        cout<<"Suprafata stadion: ";
        in>>obj.suprafataStadion;
        cout<<"Numar locuri stadion: ";
        in>>obj.nrLocuriStadion;

        cout<<"Locuri stadion: ";
        obj.locuriOcupate=new int[obj.nrLocuriStadion];
        for(int i=0; i<obj.nrLocuriStadion; i++)
            in>>obj.locuriOcupate[i];

        in.get();
        return in;
    }

//supraincarcare operator [] pentru clasa Stadion
int Stadion :: operator[](int index)
    {
        if(index>=0 && index<this->nrLocuriStadion)
            return this->locuriOcupate[index];
        else throw runtime_error("Index invalid");
    }

//supraincarcare operator ++ preincrementare pentru clasa Stadion
Stadion& Stadion :: operator++()
    {
        this->nrLocuriStadion++;
        int *v=new int[this->nrLocuriStadion-1];
        for(int i=0; i<this->nrLocuriStadion-1; i++)
            v[i]=this->locuriOcupate[i];
        if(this->locuriOcupate!=NULL)
            delete[] this->locuriOcupate;
        this->locuriOcupate=new int[this->nrLocuriStadion];
        for(int i=0; i<this->nrLocuriStadion-1; i++)
            this->locuriOcupate[i]=v[i];
        this->locuriOcupate[this->nrLocuriStadion-1]=0;
        return *this;
    }

//supraincarcare operator ++ postincrementare pentru clasa Stadion
Stadion Stadion :: operator++(int)
    {
        Stadion copie=*this;
        ++(*this);
        return copie;
    }

//supraincarcarea operatorului + pentru 2 obiecte din clasa Stadion
Stadion Stadion :: operator+(const Stadion &obj)
    {
        Stadion copie=*this;
        //nume stadion 1 + nume stadion 2
        if(copie.numeStadion!=NULL)
            delete[] copie.numeStadion;
        copie.numeStadion=new char[strlen(this->numeStadion)+ strlen(obj.numeStadion)+4];
        strcpy(copie.numeStadion, this->numeStadion);
        strcat(copie.numeStadion, " + ");
        strcat(copie.numeStadion, obj.numeStadion);

        //suprafata adunata
        copie.suprafataStadion=this->suprafataStadion+obj.suprafataStadion;

        //adunare locuri
        copie.nrLocuriStadion=this->nrLocuriStadion+obj.nrLocuriStadion;
        int *v=new int[this->nrLocuriStadion];
        if(copie.locuriOcupate!=NULL)
            delete[] copie.locuriOcupate;
        copie.locuriOcupate=new int[copie.nrLocuriStadion];
        for(int i=0; i<this->nrLocuriStadion; i++)
            copie.locuriOcupate[i]=this->locuriOcupate[i];
        for(int i=this->nrLocuriStadion; i<copie.nrLocuriStadion; i++)
            copie.locuriOcupate[i]=obj.locuriOcupate[i-this->nrLocuriStadion];

        return copie;
    }

//supraincarcare operator - intre 2 obiecte din clasa Stadion
Stadion Stadion :: operator-(const Stadion &obj)
{
    Stadion copie=*this;
    //nume stadion 1 - nume stadion 2
    if(copie.numeStadion!=NULL)
        delete[] copie.numeStadion;
    copie.numeStadion=new char[strlen(this->numeStadion)+strlen(obj.numeStadion)+4];
    strcpy(copie.numeStadion, this->numeStadion);
    strcat(copie.numeStadion, " - ");
    strcat(copie.numeStadion, obj.numeStadion);

    //diferenta de suprafata
    copie.suprafataStadion=this->suprafataStadion-obj.suprafataStadion;

    return copie;
}

//supraincarcare operator cast implicit pentru clasa Stadion
Stadion :: operator string()
    {
        return this->numeStadion;
    }

//supraincarcare operator < pentru clasa Stadion
bool Stadion :: operator<(const Stadion &obj)
    {
        if(this->suprafataStadion>=obj.suprafataStadion)
            return 0;
        if(nrLocuriStadion>=obj.nrLocuriStadion)
            return 0;
        return 1;
    }

//supraincarcare operator == pentru clasa Stadion
bool Stadion :: operator==(const Stadion &obj)
    {
        if(strcmp(this->numeStadion, obj.numeStadion)!=0)
            return 0;
        if(this->suprafataStadion!=obj.suprafataStadion)
            return 0;
        if(this->nrLocuriStadion!=obj.nrLocuriStadion)
            return 0;
        for(int i=0; i<this->nrLocuriStadion; i++)
            if(this->locuriOcupate[i]!=obj.locuriOcupate[i])
                return 0;
        return 1;
    }

//functia NrLocuriLibere din clasa Stadion
int Stadion :: NrLocuriLibere()
    {
        int nrLocuriLibere=0;
        for(int i=0; i<this->nrLocuriStadion; i++)
            if(this->locuriOcupate[i]==0)
                nrLocuriLibere++;
        return nrLocuriLibere;
    }

///CLASA ECHIPA
class Echipa
{
//atributele clasei Echipa
private:
    char *numeEchipa;
    char *numeAntrenor;
    int nrPuncteEchipa;
    int golaverajEchipa;
    Stadion stadionEchipa;
    int nrJucatoriEchipa;
    vector<Jucator> jucatoriEchipa;

public:
    //constructor fara parametri
    Echipa();

    //constructor cu toti parametrii
    Echipa(char*, char*, int, int, Stadion, int, vector<Jucator>);

    //constructor cu parametri 1
    Echipa(char*, Stadion);

    //constructor cu parametri 2
    Echipa(int, vector<Jucator>);

    //copy constructorul
    Echipa(const Echipa &obj);

    //destructor
    ~Echipa();

    ///GET-ere
    int getNrPuncteEchipa()
    {
        return this->nrPuncteEchipa;
    }

    int getGolaverajEchipa()
    {
        return this->golaverajEchipa;
    }

    //supraincarcare operator =
    Echipa& operator=(const Echipa&);

    //supraincarcare operator <<
    friend ostream& operator<<(ostream&, const Echipa&);

    //supraincarcare operator >>
    friend istream& operator>>(istream&, Echipa&);

    //supraincarcare operator []
    Jucator operator[](int);

    //supraincarcare operator ++ preincrementare
    Echipa& operator++();

    //supraincarcare operator ++ postincrementare
    Echipa operator++(int);

    //supraincarcare operator + intre 2 obiecte din clasa
    Echipa operator+(const Echipa&);

    //supraincarcare operator - intre 2 obiecte din clasa
    Echipa operator-(const Echipa&);

    //supraincarcare operator cast
    operator string();

    //supraincarcare operator <
    bool operator<(const Echipa&);

    //supraincarcare operator ==
    bool operator==(const Echipa&);

    ///Functie care ordoneaza descrescator jucatorii dintr-o echipa in functie de eficienta lor
    void OrdonareJucatori();
};

///CONSTRUCTORI CLASA ECHIPA
//constructor fara paramtri pentru clasa Echipa
Echipa :: Echipa()
    {
        this->numeEchipa=new char[strlen("necunoscut")+1];
        strcpy(this->numeEchipa, "necunoscut");
        this->numeAntrenor=new char[strlen("necunoscut")+1];
        strcpy(this->numeAntrenor, "necunoscut");
        this->nrPuncteEchipa=0;
        this->golaverajEchipa=0;
        this->nrJucatoriEchipa=0;
    }

//constructor cu toti parametrii pentru clasa Echipa
Echipa :: Echipa(char *numeEchipa, char *numeAntrenor, int nrPuncteEchipa, int golaverajEchipa,
                 Stadion stadionEchipa, int nrJucatoriEchipa, vector<Jucator> jucatoriEchipa):
                 nrPuncteEchipa(nrPuncteEchipa), golaverajEchipa(golaverajEchipa), stadionEchipa(stadionEchipa),
                 nrJucatoriEchipa(nrJucatoriEchipa), jucatoriEchipa(jucatoriEchipa)
    {
        this->numeEchipa=new char[strlen(numeEchipa)+1];
        strcpy(this->numeEchipa, numeEchipa);
        this->numeAntrenor=new char[strlen(numeAntrenor)+1];
        strcpy(this->numeAntrenor, numeAntrenor);
    }

//construcctor cu parametri 1 pentru clasa Echipa
Echipa :: Echipa(char *numeEchipa, Stadion stadionEchipa): stadionEchipa(stadionEchipa)
    {
        this->numeEchipa=new char[strlen(numeEchipa)+1];
        strcpy(this->numeEchipa, numeEchipa);
        this->numeAntrenor=new char[strlen("necunoscut")+1];
        strcpy(this->numeAntrenor, "necunoscut");
        this->nrPuncteEchipa=0;
        this->golaverajEchipa=0;
        this->nrJucatoriEchipa=0;
    }

//constructor cu parametri 2 pentru clasa Echipa
Echipa :: Echipa(int nrJucatoriEchipa, vector<Jucator> jucatoriEchipa):jucatoriEchipa(jucatoriEchipa),
                nrJucatoriEchipa(nrJucatoriEchipa)
    {
        this->numeEchipa=new char[strlen("necunoscut")+1];
        strcpy(this->numeEchipa, "necunoscut");
        this->numeAntrenor=new char[strlen("necunoscut")+1];
        strcpy(this->numeAntrenor, "necunoscut");
        this->nrPuncteEchipa=0;
        this->golaverajEchipa=0;
    }

//copy constructor pentru clasa Echipa
Echipa :: Echipa(const Echipa &obj)
    {
        this->numeEchipa=new char[strlen(obj.numeEchipa)+1];
        strcpy(this->numeEchipa, obj.numeEchipa);
        this->numeAntrenor=new char[strlen(obj.numeAntrenor)+1];
        strcpy(this->numeAntrenor, obj.numeAntrenor);
        this->nrPuncteEchipa=obj.nrPuncteEchipa;
        this->golaverajEchipa=obj.golaverajEchipa;
        this->stadionEchipa=obj.stadionEchipa;
        this->nrJucatoriEchipa=obj.nrJucatoriEchipa;
        this->jucatoriEchipa=obj.jucatoriEchipa;
    }

//destructor pentru clasa Echipa
Echipa :: ~Echipa()
    {
        if(this->numeEchipa!=NULL)
            delete[] this->numeEchipa;
        if(this->numeAntrenor!=NULL)
            delete[] this->numeAntrenor;
    }

///SUPRAINCARCARI CLASA ECHIPA
//supraincarcare operator = pentru clasa Echipa
Echipa& Echipa :: operator=(const Echipa &obj)
    {
        if(this!=&obj)
            {
                if(this->numeEchipa!=NULL)
                    delete[] this->numeEchipa;
                if(this->numeAntrenor!=NULL)
                    delete[] this->numeAntrenor;
                this->numeEchipa=new char[strlen(obj.numeEchipa)+1];
                strcpy(this->numeEchipa, obj.numeEchipa);
                this->numeAntrenor=new char[strlen(obj.numeAntrenor)+1];
                strcpy(this->numeAntrenor, obj.numeAntrenor);
                this->nrPuncteEchipa=obj.nrPuncteEchipa;
                this->golaverajEchipa=obj.golaverajEchipa;
                this->stadionEchipa=obj.stadionEchipa;
                this->nrJucatoriEchipa=obj.nrJucatoriEchipa;
                this->jucatoriEchipa=obj.jucatoriEchipa;
            }
        return *this;
    }

//supraincarcarea operatorului << pentru clasa Echipa
ostream& operator<<(ostream &out, const Echipa &obj)
{
    out<<"Nume echipa: "<<obj.numeEchipa<<endl;
    out<<"Nume antrenor echipa: "<<obj.numeAntrenor<<endl;
    out<<"Numar puncte castigate: "<<obj.nrPuncteEchipa<<endl;
    out<<"Golaveraj: "<<obj.golaverajEchipa<<endl;
    out<<"STADION "<<endl;
    out<<obj.stadionEchipa;
    out<<"Numar jucatori: "<<obj.nrJucatoriEchipa<<endl;
    for(int i=0; i<obj.nrJucatoriEchipa; i++)
    {
        out<<endl;
        out<<"JUCATOR "<<i+1<<endl;
        out<<obj.jucatoriEchipa[i];
    }
    return out;
}

//supraincarcare operator >> pentru clasa Echipa
istream& operator>>(istream &in, Echipa &obj)
    {
        cout<<"Nume echipa: ";
        if(obj.numeEchipa!=NULL)
            delete[] obj.numeEchipa;
        char nume[100];
        in.getline(nume,100);
        obj.numeEchipa=new char[strlen(nume)+1];
        strcpy(obj.numeEchipa, nume);

        cout<<"Nume antrenor echipa: ";
        if(obj.numeAntrenor!=NULL)
            delete[] obj.numeAntrenor;
        in.getline(nume,100);
        obj.numeAntrenor=new char[strlen(nume)+1];
        strcpy(obj.numeAntrenor, nume);

        cout<<"Numar puncte castigate: ";
        in>>obj.nrPuncteEchipa;
        cout<<"Golaveraj: ";
        in>>obj.golaverajEchipa;
        in.get();

        cout<<"STADION "<<endl;
        in>>obj.stadionEchipa;

        cout<<"Numar jucatori: ";
        in>>obj.nrJucatoriEchipa;
        in.get();

        for(int i=0; i<obj.nrJucatoriEchipa; i++)
        {
            Jucator j1;
            cout<<endl;
            cout<<"JUCATOR "<<i+1<<endl;
            in>>j1;
            obj.jucatoriEchipa.push_back(j1);
        }
        in.get();
        return in;
    }

//supraincarcare operator [] pentru clasa Echipa
Jucator Echipa :: operator[](int index)
    {
        if(index>=0 && index<this->nrJucatoriEchipa)
            return this->jucatoriEchipa[index];
        else throw runtime_error("Invalid index");
    }

//supraincarcare operator ++ preincrementare pentru clasa Echipa
Echipa& Echipa :: operator++()
    {
        this->stadionEchipa++;
        for(int i=0; i<this->nrJucatoriEchipa; i++)
            this->jucatoriEchipa[i]++;
        this->golaverajEchipa+=2;
        this->nrPuncteEchipa+=3;
        return *this;
    }

//supraincarcare operator ++ postincrementare pentru clasa Echipa
Echipa Echipa :: operator++(int)
    {
        Echipa copie=*this;
        ++(*this);
        return copie;
    }

//supraincarcare operator + intre 2 obiecte din clasa Echipa
Echipa Echipa :: operator+(const Echipa &obj)
    {
        Echipa copie=*this;
        //nume echipa 1 + nume echipa 2
        if(copie.numeEchipa!=NULL)
            delete[] copie.numeEchipa;
        copie.numeEchipa=new char[strlen(this->numeEchipa)+ strlen(obj.numeEchipa)+4];
        strcpy(copie.numeEchipa, this->numeEchipa);
        strcat(copie.numeEchipa, " + ");
        strcat(copie.numeEchipa, obj.numeEchipa);

        //la fel ca la numele echipei
        if(copie.numeAntrenor!=NULL)
            delete[] copie.numeAntrenor;
        copie.numeAntrenor=new char[strlen(this->numeAntrenor)+ strlen(obj.numeAntrenor)+4];
        strcpy(copie.numeAntrenor, this->numeAntrenor);
        strcat(copie.numeAntrenor, " + ");
        strcat(copie.numeAntrenor, obj.numeAntrenor);

        //se aduna valorile
        copie.nrPuncteEchipa=this->nrPuncteEchipa+obj.nrPuncteEchipa;
        copie.golaverajEchipa=this->golaverajEchipa+obj.golaverajEchipa;
        copie.stadionEchipa=this->stadionEchipa+obj.stadionEchipa;
        copie.nrJucatoriEchipa=this->nrJucatoriEchipa+obj.nrJucatoriEchipa;

        //reuniune de jucatori
        for(int i=this->nrJucatoriEchipa; i<copie.nrJucatoriEchipa; i++)
            copie.jucatoriEchipa.push_back(obj.jucatoriEchipa[i-this->nrJucatoriEchipa]);

        return copie;
    }

//supraincarcare operator - intre 2 obiecte din clasa Echipa
Echipa Echipa :: operator-(const Echipa &obj)
    {
        Echipa copie = *this;
        //nume echipa 1 - nume echipa 2
        if (copie.numeEchipa != NULL)
            delete[] copie.numeEchipa;
        copie.numeEchipa = new char[strlen(this->numeEchipa) + strlen(obj.numeEchipa) + 4];
        strcpy(copie.numeEchipa, this->numeEchipa);
        strcat(copie.numeEchipa, " - ");
        strcat(copie.numeEchipa, obj.numeEchipa);

        //la fel ca la numele echipei
        if (copie.numeAntrenor != NULL)
            delete[] copie.numeAntrenor;
        copie.numeAntrenor = new char[strlen(this->numeAntrenor) + strlen(obj.numeAntrenor) + 4];
        strcpy(copie.numeAntrenor, this->numeAntrenor);
        strcat(copie.numeAntrenor, " - ");
        strcat(copie.numeAntrenor, obj.numeAntrenor);

        //se scad valorile
        copie.nrPuncteEchipa = this->nrPuncteEchipa - obj.nrPuncteEchipa;
        copie.golaverajEchipa = this->golaverajEchipa - obj.golaverajEchipa;
        copie.stadionEchipa = this->stadionEchipa - obj.stadionEchipa;

        return copie;
    }

//supraincarcare operator cast implicit pentru clasa Echipa
Echipa :: operator string()
    {
        return this->numeEchipa;
    }

//supraincarcare operator < pentru clasa Echipa
bool Echipa :: operator<(const Echipa &obj)
    {
        if(this->nrPuncteEchipa>=obj.nrPuncteEchipa)
            return 0;
        if(this->golaverajEchipa>=obj.golaverajEchipa)
            return 0;
        return 1;
    }

//supraincarcare operator == pentru clasa Echipa
bool Echipa :: operator==(const Echipa &obj)
    {
        if(strcmp(this->numeEchipa, obj.numeEchipa)!=0)
            return 0;
        if(strcmp(this->numeAntrenor, obj.numeAntrenor)!=0)
            return 0;
        if(this->nrPuncteEchipa!=obj.nrPuncteEchipa)
            return 0;
        if(this->golaverajEchipa!=obj.golaverajEchipa)
            return 0;
        if(this->nrJucatoriEchipa!=obj.nrJucatoriEchipa)
            return 0;
        if(this->stadionEchipa==obj.stadionEchipa)
            return 1;
        return 0;
    }

//functia OrdonareJucatori din clasa Echipa
void Echipa :: OrdonareJucatori()
    {
        for(int i=0; i<this->nrJucatoriEchipa-1; i++)
            for(int j=i+1; j<this->nrJucatoriEchipa; j++)
                if(this->jucatoriEchipa[i].EficientaJucator()<this->jucatoriEchipa[j].EficientaJucator())
                {
                    Jucator aux;
                    aux=this->jucatoriEchipa[i];
                    this->jucatoriEchipa[i]=this->jucatoriEchipa[j];
                    this->jucatoriEchipa[j]=aux;
                }
    }

///CLASA LIGA
class Liga
{
private:
    char indexLiga;
    char *numeLiga;
    int nrEchipeLiga;
    vector<Echipa> echipeLiga;

public:
    ///CONSTRUCTORI

    //constructor fara parametri
    Liga();

    //constructor cu toti parametrii
    Liga(char, char*, int, vector<Echipa>);

    //constructor cu parametri 1
    Liga(char*);

    //constructor cu parametri 2
    Liga(int, vector<Echipa>);

    //copy constructor
    Liga(const Liga&);

    //destructor
    ~Liga();

    //geter char
    char getIndexLiga()
    {
        return this->indexLiga;
    }

    //seter char
    void setIndexLiga(char indexLiga)
    {
        this->indexLiga=indexLiga;
    }

    ///SUPRAINCARCARI

    //supraincarcare operator =
    Liga& operator=(const Liga&);

    //supraincarcare operator <<
    friend ostream& operator<<(ostream&, const Liga&);

    //supraincarcare operator >>
    friend istream& operator>>(istream&, Liga&);

    //supraincarcare operator []
    Echipa operator[](int);

    //supraincarcare operator ++ preincrementare
    Liga& operator++();

    //supraincarcare operator ++ postincrementare
    Liga operator++(int);

    //supraincarcare operator + pentru 2 obiecte din clasa
    Liga operator+(const Liga&);

    //supraincarcare operator - pentru 2 obiecte din clasa
    Liga operator-(const Liga&);

    //supraincarcare operator cast implicit
    operator string();

    //supraincarcare operator <
    bool operator<(const Liga&);

    //supraincarcare operator ==
    bool operator==(const Liga&);

    ///Functie care face clasamentul ligii in functie de nr de puncte si golaveraj
    void ClasamentLiga();
};

///CONSTRUCTORI CLASA LIGA
//costructor fara parametri pentru clasa Liga
Liga :: Liga()
    {
        this->indexLiga='X';
        this->numeLiga=new char[strlen("necunoscut")+1];
        strcpy(this->numeLiga, "necunoscut");
        this->nrEchipeLiga=0;
    }

//constructor cu toti parametrii pentru clasa Liga
Liga :: Liga(char indexLiga, char* numeLiga, int nrEchipeLiga, vector<Echipa> echipeLiga):
            indexLiga(indexLiga), nrEchipeLiga(nrEchipeLiga), echipeLiga(echipeLiga)
    {
        this->numeLiga=new char[strlen(numeLiga)+1];
        strcpy(this->numeLiga, numeLiga);
    }

//constructor cu parametri 1 pentru clasa Liga
Liga :: Liga(char *numeLiga)
    {
        this->indexLiga='X';
        this->numeLiga=new char[strlen(numeLiga)+1];
        strcpy(this->numeLiga, numeLiga);
        this->nrEchipeLiga=0;
    }

//constructor cu parametri 2 pentru clasa Liga
Liga :: Liga(int nrEchipeLiga, vector<Echipa> echipeLiga):nrEchipeLiga(nrEchipeLiga), echipeLiga(echipeLiga)
    {
        this->indexLiga='X';
        this->numeLiga=new char[strlen("necunoscut")+1];
        strcpy(this->numeLiga, "necunoscut");
    }

//copy constructor pentru clasa Liga
Liga :: Liga(const Liga &obj)
    {
        this->indexLiga=obj.indexLiga;
        this->numeLiga=new char[strlen(obj.numeLiga)+1];
        strcpy(this->numeLiga, obj.numeLiga);
        this->nrEchipeLiga=obj.nrEchipeLiga;
        this->echipeLiga=obj.echipeLiga;
    }

//destructor pentru clasa Liga
Liga :: ~Liga()
    {
        if(this->numeLiga!=NULL)
            delete[] this->numeLiga;
    }

///SUPRAINCARCARI CLASA LIGA

//supraincarcare operator = pentru clasa Liga
Liga& Liga :: operator=(const Liga &obj)
    {
        if(this!=&obj)
        {
            if(this->numeLiga!=NULL)
                delete[] this->numeLiga;
            this->indexLiga=obj.indexLiga;
            this->numeLiga=new char[strlen(obj.numeLiga)+1];
            strcpy(this->numeLiga, obj.numeLiga);
            this->nrEchipeLiga=obj.nrEchipeLiga;
            this->echipeLiga=obj.echipeLiga;
        }
        return *this;
    }

//supraincarcare operator << pentru clasa Liga
ostream& operator<<(ostream &out, const Liga &obj)
{
    out<<"Index liga: "<<obj.indexLiga<<endl;
    out<<"Nume liga: "<<obj.numeLiga<<endl;
    out<<"Numar echipe din liga: "<<obj.nrEchipeLiga<<endl;
    for(int i=0; i<obj.nrEchipeLiga; i++)
    {
        out<<"ECHIPA "<<i+1<<endl;
        out<<obj.echipeLiga[i];
        out<<endl;
    }

    return out;
}

//supraincarcare operator >> pentru clasa Liga
istream& operator>>(istream &in, Liga &obj)
{
    cout<<"Index liga: ";
    in>>obj.indexLiga;
    in.get();

    cout<<"Nume liga: ";
    if(obj.numeLiga!=NULL)
        delete[] obj.numeLiga;
    char nume[100];
    in.getline(nume, 100);
    obj.numeLiga=new char[strlen(nume)+1];
    strcpy(obj.numeLiga, nume);

    cout<<"Numar de echipe din liga: ";
    in>>obj.nrEchipeLiga;
    in.get();

    for(int i=0; i<obj.nrEchipeLiga; i++)
    {
        cout<<endl;
        cout<<"ECHIPA"<<i+1<<endl;
        Echipa aux;
        in>>aux;
        obj.echipeLiga.push_back(aux);
    }
    return in;
}

//supraincarcare operator [] pentru clasa Liga
Echipa Liga :: operator[](int index)
    {
        if(index>=0 && index<this->nrEchipeLiga)
            return this->echipeLiga[index];
        else throw runtime_error("Index invalid");
    }

//supraincarcare operator ++ preincrementare pentru clasa Liga
Liga& Liga :: operator++()
    {
        if(this->indexLiga!='A')
            this->indexLiga--;
        return *this;
    }

//supraincarcare operator ++ postincremenatare pentru clasa Liga
Liga Liga :: operator++(int)
    {
        Liga copie=*this;
        ++(*this);
        return copie;
    }

//supraincarcare operator + pentru 2 obiecte din clasa Liga
Liga Liga :: operator+(const Liga &obj)
    {
        Liga copie=*this;
        //nume liga 1 + nume liga 2
        if(copie.numeLiga!=NULL)
            delete[] copie.numeLiga;
        copie.numeLiga=new char[strlen(this->numeLiga)+ strlen(obj.numeLiga)+4];
        strcpy(copie.numeLiga, this->numeLiga);
        strcat(copie.numeLiga, " + ");
        strcat(copie.numeLiga, obj.numeLiga);

        copie.nrEchipeLiga=this->nrEchipeLiga+obj.nrEchipeLiga;

        //reuniune de echipe
        for(int i=this->nrEchipeLiga; i<copie.nrEchipeLiga; i++)
            copie.echipeLiga.push_back(obj.echipeLiga[i-this->nrEchipeLiga]);

        return copie;

    }

//supraincarcare operator - pentru 2 obiecte din clasa Liga
Liga Liga :: operator-(const Liga &obj)
    {
        Liga copie=*this;
        //nume liga 1 - nume liga 2
        if(copie.numeLiga!=NULL)
            delete[] copie.numeLiga;
        copie.numeLiga=new char[strlen(this->numeLiga)+ strlen(obj.numeLiga)+4];
        strcpy(copie.numeLiga, this->numeLiga);
        strcat(copie.numeLiga, " - ");
        strcat(copie.numeLiga, obj.numeLiga);

        return copie;
    }

//supraincarcare operator cast implicit pentru clasa Liga
Liga :: operator string()
    {
        return this->numeLiga;
    }

//supraincarcare operator < pentru clasa Liga
bool Liga :: operator<(const Liga &obj)
    {
        if(this->indexLiga<=obj.indexLiga)
            return 0;
        return 1;
    }

//supraincarcare operator == pentru clasa Liga
bool Liga :: operator==(const Liga &obj)
    {
        if(this->indexLiga!=obj.indexLiga)
            return 0;
        if(strcmp(this->numeLiga, obj.numeLiga)!=0)
            return 0;
        if(this->nrEchipeLiga!=obj.nrEchipeLiga)
            return 0;
        return 1;
    }

//functia ClasamentLiga din clasa Liga
void Liga :: ClasamentLiga()
    {
        for(int i=0; i<this->nrEchipeLiga-1; i++)
            for(int j=i+1; j<this->nrEchipeLiga; j++)
            {
                if(this->echipeLiga[i].getNrPuncteEchipa()<this->echipeLiga[j].getNrPuncteEchipa())
                {
                    Echipa aux;
                    aux=this->echipeLiga[i];
                    this->echipeLiga[i]=this->echipeLiga[j];
                    this->echipeLiga[j]=aux;
                }
                if(this->echipeLiga[i].getNrPuncteEchipa()==this->echipeLiga[j].getNrPuncteEchipa())
                    if(this->echipeLiga[i].getGolaverajEchipa()<this->echipeLiga[j].getGolaverajEchipa())
                    {
                        Echipa aux;
                        aux=this->echipeLiga[i];
                        this->echipeLiga[i]=this->echipeLiga[j];
                        this->echipeLiga[j]=aux;
                    }
            }
    }

int main()
{
    char *pozitii1[]={"LW", "ST", "AM"};
    char *pozitii2[]={"RW", "AM"};
    char *pozitii3[]={"ST"};
    Jucator j1("Cristiano Ronaldo", 39, 1.87, 87, 7, 3, pozitii1, 45, 20, 70, 1);
    Jucator j2("Lionel Messi", 36, 1.67, 65, 10, 2, pozitii2, 30, 20, 50, 1);
    Jucator j3("Lewandowski", 37, 1.91, 90, 9, 1, pozitii3, 40, 60, 60, 1);

    int locuri1[]={1, 0, 1, 1};
    int locuri2[]={1, 0, 0};
    Stadion st1("Santiago Bernabeu", 23341, 4, locuri1);
    Stadion st2("Camp Nou", 34123, 3, locuri2);

    vector<Jucator> jucatori1;
    vector<Jucator> jucatori2;
    jucatori1.push_back(j1);
    jucatori2.push_back(j2);
    jucatori2.push_back(j3);

    Echipa e1("Real Madrid", "Ancelloti", 85, 50, st1, 1, jucatori1);
    Echipa e2("Barcelona", "Xavi", 85, 70, st2, 2, jucatori2);

    vector<Echipa> echipe1;
    echipe1.push_back(e1);
    echipe1.push_back(e2);

    Liga l1('A', "La Liga", 2, echipe1);


    char *pozitii4[]={"CM", "AM", "LM", "RM"};
    char *pozitii5[]={"CB", "RB"};
    char *pozitii6[]={"RW"};
    char *pozitii7[]={"GK"};
    Jucator j4("De Bruyne", 32, 1.75, 73, 5, 4, pozitii4, 20, 30, 67, 1);
    Jucator j5("Walker", 29, 1.80, 80, 3, 2, pozitii5, 3, 10, 69, 1);
    Jucator j6("Salah", 32, 1.66, 61, 11, 1, pozitii6, 34, 20, 66, 1);
    Jucator j7("Allison", 31, 1.86, 82, 1, 1, pozitii7, 0, 0, 70, 1);

    int locuri3[]={1, 1, 0, 0, 1};
    int locuri4[]={1, 0, 0, 0};
    Stadion st3("Etihad", 23423, 5, locuri3);
    Stadion st4("Anfield", 324221, 4, locuri4);

    vector<Jucator> jucatori3;
    vector<Jucator> jucatori4;
    jucatori3.push_back(j4);
    jucatori3.push_back(j5);
    jucatori4.push_back(j6);
    jucatori4.push_back(j7);
    Echipa e3("Manchester City", "Guardiola", 76, 40, st3, 2, jucatori3);
    Echipa e4("Liverpool", "Klopp", 78, 39, st4, 2, jucatori4);

    vector<Echipa> echipe2;
    echipe2.push_back(e3);
    echipe2.push_back(e4);
    Liga l2('A', "Premier League", 2, echipe2);


///MENIU INTERACTIV

    vector<Liga> ligi1;
    ligi1.push_back(l1);
    ligi1.push_back(l2);

    cout<<"_________________________________________________________________"<<endl;
    cout<<"                     BUN VENIT"<<endl;
    cout<<"ACEST PROGRAM CONTINE INFORMATII DESPRE 2 LIGI DE FOTBAL"<<endl;
    cout<<endl;
    int k=1;
    while(k==1)
    {
        cout<<"1. Daca doriti sa aflati informatii despre o liga, tastati 1"<<endl;
        cout<<"2. Daca doriti sa adugati o noua liga, tastati 2"<<endl;
        cout<<"3. Daca doriti sa stergeti ultima liga, tastati 3"<<endl;
        cout<<"4. Daca doriti sa schimbati valorile unei ligi, tastati 4"<<endl;
        cout<<"5. Daca doriti sa aflati clasamentul unei ligi, tastati 5"<<endl;
        cout<<"6. Daca doriti sa iesiti, tastati 6"<<endl;
        int comanda;
        cin>>comanda;
        switch(comanda)
        {
            case 1:
            {
                cout<<"Introduceti indexul ligii:"<<endl;
                int index;
                cin>>index;
                index--;
                if(index>=0 && index<ligi1.size())
                    cout<<ligi1[index];
                else cout<<"Index Invalid"<<endl;
                break;
            }

            case 2:
            {
                Liga liga1;
                cin>>liga1;
                ligi1.push_back(liga1);
                break;
            }

            case 3:
            {
                ligi1.pop_back();
                break;
            }

            case 4:
            {
                cout<<"Introduceti indexul ligii:"<<endl;
                int index;
                cin>>index;
                index--;
                if(index>=0 && index<ligi1.size())
                {
                    Liga liga1;
                    cin>>liga1;
                    ligi1[index]=liga1;
                }
                else cout<<"Index Invalid"<<endl;
                break;
            }

            case 5:
            {
                cout<<"Introduceti indexul ligii:"<<endl;
                int index;
                cin>>index;
                index--;
                if(index>=0 && index<ligi1.size())
                {
                    ligi1[index].ClasamentLiga();
                    cout<<ligi1[index];
                }
                else cout<<"Index Invalid"<<endl;
                break;
            }

            case 6:
            {
                k=0;
                break;
            }
        }
    }
    cout<<"__________________________________________________________________";

}
