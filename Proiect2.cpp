#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

class Personaj{
private:
    string numePersonaj;
    string numeActor;
    string descrierePersonaj;
    int varstaPersonaj;
public:
    Personaj();
    Personaj(string, string, string, int);
    Personaj(const Personaj&);
    ~Personaj();
    Personaj &operator=(const Personaj&);
    friend istream& operator>>(istream&, Personaj&);
    friend ostream& operator<<(ostream&, const Personaj&);
    void informatiiPersonaj();
};

Personaj::Personaj():numePersonaj("necunoscut"), numeActor("necunoscut"),
        descrierePersonaj("inexistenta"), varstaPersonaj(0)
{}

Personaj::Personaj(string numePersonaj, string numeActor, string descrierePersonaj, int varstaPersonaj):
    numePersonaj(numePersonaj), numeActor(numeActor),
    descrierePersonaj(descrierePersonaj), varstaPersonaj(varstaPersonaj)
{}

Personaj::Personaj(const Personaj &obj): numePersonaj(obj.numePersonaj), numeActor(obj.numeActor),
        descrierePersonaj(obj.descrierePersonaj), varstaPersonaj(obj.varstaPersonaj)
{}

Personaj& Personaj::operator=(const Personaj &obj)
{
    if(this!=&obj)
    {
        this->numePersonaj=obj.numePersonaj;
        this->numeActor=obj.numeActor;
        this->descrierePersonaj=obj.descrierePersonaj;
        this->varstaPersonaj=obj.varstaPersonaj;
    }
    return *this;
}

istream& operator>>(istream &in, Personaj &obj)
{
    cout<<"Nume personaj: ";
    getline(in,obj.numePersonaj);
    cout<<"Nume actor care il interpreteaza: ";
    getline(in, obj.numeActor);
    cout<<"Descriere personaj: ";
    getline(in,obj.descrierePersonaj);
    cout<<"Varsta personaj: ";
    in>>obj.varstaPersonaj;
    in.ignore();
    return in;
}

ostream& operator<<(ostream &out, const Personaj &obj)
{
    out<<"Nume personaj: "<<obj.numePersonaj<<endl;
    out<<"Nume actor care il interpreteaza: "<<obj.numeActor<<endl;
    cout<<"Descriere personaj: "<<obj.descrierePersonaj<<endl;
    cout<<"Varsta personaj: "<<obj.varstaPersonaj<<endl;
    return out;
}

Personaj::~Personaj(){}

void Personaj::informatiiPersonaj()
{
    cout<<"Personajul "<<this->numePersonaj<<", in varsta de "<<this->varstaPersonaj<<" ani, este interpretat de actorul "<<this->numeActor;
    cout<<this->descrierePersonaj;
}

class Interfata
{
public:
    virtual ostream& afisare(ostream&) const = 0;
    virtual istream& citire(istream&) = 0;
    virtual void Durata() const = 0;
};

class ProductieMedia: public Interfata
{
protected:
    string numeProductie;
    string numeDirector;
    int anLansare;
    int nrOre;
    int nrMinute;
    int nrSecunde;
public:
    ProductieMedia();
    ProductieMedia(string, string, int, int, int, int);
    ProductieMedia(const ProductieMedia&);
    ProductieMedia& operator=(const ProductieMedia&);
    virtual ~ProductieMedia();
    istream& citire(istream&);
    ostream& afisare(ostream&) const;
    friend istream& operator>>(istream&, ProductieMedia&);
    friend ostream& operator<<(ostream&, const ProductieMedia&);
    virtual void Durata() const;
    virtual void Rezolutie() const{}
};

ProductieMedia::ProductieMedia(): numeProductie("necunoscut"), numeDirector("necunoscut"), anLansare(0),
        nrOre(0), nrMinute(0), nrSecunde(0)
{}

ProductieMedia::ProductieMedia(string numeProductie, string numeDirector, int anLansare, int nrOre, int nrMinute,
                               int nrSecunde): numeProductie(numeProductie), numeDirector(numeDirector), anLansare(anLansare),
                                  nrOre(nrOre), nrMinute(nrMinute), nrSecunde(nrSecunde)
{}

ProductieMedia::ProductieMedia(const ProductieMedia &obj): numeProductie(obj.numeProductie), numeDirector(obj.numeDirector),
            anLansare(obj.anLansare), nrOre(obj.nrOre), nrMinute(obj.nrMinute), nrSecunde(obj.nrSecunde)
{}

ProductieMedia& ProductieMedia ::operator=(const ProductieMedia &obj)
        {
            if(this!=&obj)
            {
                this->numeProductie=obj.numeProductie;
                this->numeDirector=obj.numeDirector;
                this->anLansare=obj.anLansare;
                this->nrOre=obj.nrOre;
                this->nrMinute=obj.nrMinute;
                this->nrSecunde=obj.nrSecunde;
            }
            return *this;
        }

istream& ProductieMedia ::citire(istream &in)
{
    cout<<"Numele productiei media: ";
    getline(in, this->numeProductie);
    cout<<"Numele directorului productiei media: ";
    getline(in, this->numeDirector);
    cout<<"Anul in care s-a lansat: ";
    in>>this->anLansare;
    cout<<"Numarul de ore avute: ";
    in>>this->nrOre;
    cout<<"Numarul de minute avute: ";
    in>>this->nrMinute;
    cout<<"Numarul de secunde avute: ";
    in>>this->nrSecunde;
    in.ignore();

    return in;
}

istream& operator>>(istream &in, ProductieMedia &obj)
{
    return obj.citire(in);
}

ostream& ProductieMedia ::afisare(ostream &out) const
{
    out<<"Numele productiei media: "<<this->numeProductie<<endl;
    out<<"Numele directorului productiei media: "<<this->numeDirector<<endl;
    out<<"Anul in care s-a lansat: "<<this->anLansare<<endl;
    out<<"Numarul de ore avute: "<<this->nrOre<<endl;
    out<<"Numarul de minute avute: "<<this->nrMinute<<endl;
    out<<"Numarul de secunde avute: "<<this->nrSecunde<<endl;

    return out;
}

ProductieMedia :: ~ProductieMedia(){}

ostream& operator<<(ostream &out, const ProductieMedia &obj)
{
    return obj.afisare(out);
}

void ProductieMedia::Durata() const
{
    cout<<"Durata productiei este: ";
    if(this->nrOre<10)
        cout<<"0"<<this->nrOre<<":";
    else cout<<this->nrOre<<":";
    if(this->nrMinute<10)
        cout<<"0"<<this->nrMinute<<":";
    else cout<<this->nrMinute<<":";
    if(this->nrSecunde<10)
        cout<<"0"<<this->nrSecunde;
    else cout<<this->nrSecunde;
}

class Melodie: virtual public ProductieMedia
{
protected:
    string numeArtist;
    string genMuzical;
    int nrStrofe;
    int nrVersuri;
public:
    Melodie();
    Melodie(string, string, int, int, int, int, string, string, int, int);
    Melodie(const Melodie&);
    Melodie& operator=(const Melodie&);
    ~Melodie();
    istream& citire(istream&) ;
    ostream& afisare(ostream&) const;
    friend istream& operator>>(istream&, Melodie&);
    friend ostream& operator<<(ostream&, const Melodie&);
    void Durata() const;
    float VersuriPerStrofa();
    void Rezolutie() const{}
};

Melodie::Melodie():ProductieMedia()
{
    this->numeArtist="necunoscut";
    this->genMuzical="necunoscut";
    this->nrStrofe=0;
    this->nrVersuri=0;
}

Melodie::Melodie(string numeProductie, string numeDirector, int anLansare, int nrOre, int nrMinute, int nrSecunde,
                 string numeArtist, string genMuzical, int nrStrofe, int nrVersuri)
        :ProductieMedia(numeProductie, numeDirector, anLansare, nrOre, nrMinute, nrSecunde)
{
    this->numeArtist = numeArtist;
    this->genMuzical = genMuzical;
    this->nrStrofe = nrStrofe;
    this->nrVersuri = nrVersuri;
}

Melodie::Melodie(const Melodie &obj):ProductieMedia(obj)
{
    this->numeArtist=obj.numeArtist;
    this->genMuzical=obj.genMuzical;
    this->nrStrofe=obj.nrStrofe;
    this->nrVersuri=obj.nrVersuri;
}

Melodie& Melodie::operator=(const Melodie &obj)
{
    if(this!=&obj)
    {
        ProductieMedia::operator=(obj);
        this->numeArtist=obj.numeArtist;
        this->genMuzical=obj.genMuzical;
        this->nrStrofe=obj.nrStrofe;
        this->nrVersuri=obj.nrVersuri;
    }
    return *this;
}

Melodie::~Melodie(){}

istream& Melodie::citire(istream &in)
{
    this->ProductieMedia::citire(in);
    cout<<"Numele artistului melodiei: ";
    getline(in, this->numeArtist);
    cout<<"Genul melodiei: ";
    getline(in, this->genMuzical);
    cout<<"Numarul de strofe din melodie: ";
    in>>this->nrStrofe;
    cout<<"Numarul de versuri din melodie: ";
    in>>this->nrVersuri;
    in.ignore();
    return in;
}

istream& operator>>(istream &in, Melodie &obj)
{
    return obj.citire(in);
}

ostream& Melodie::afisare(ostream &out) const
{
    this->ProductieMedia::afisare(out);
    cout<<"Numele artistului melodiei: "<<this->numeArtist<<endl;
    cout<<"Genul melodiei: "<<this->genMuzical<<endl;
    cout<<"Numarul de strofe din melodie: "<<this->nrStrofe<<endl;
    cout<<"Numarul de versuri din melodie: "<<this->nrVersuri<<endl;
    return out;
}

ostream& operator<<(ostream &out, const Melodie &obj)
{
    return obj.afisare(out);
}

void Melodie::Durata() const
{
    cout<<"Durata melodiei este: ";
    if(this->nrMinute<10)
        cout<<"0"<<this->nrMinute<<":";
    else cout<<this->nrMinute<<":";
    if(this->nrSecunde<10)
        cout<<"0"<<this->nrSecunde;
    else cout<<this->nrSecunde;
    cout<<endl;
}

float Melodie::VersuriPerStrofa()
{
    float medie;
    medie=this->nrVersuri/this->nrStrofe;
    return medie;
}

class Videoclip: virtual public ProductieMedia
{
protected:
    string temaVideoclip;
    int rezolutie;
public:
    Videoclip();
    Videoclip(string, string, int, int, int, int, string, int);
    Videoclip(const Videoclip&);
    ~Videoclip();
    Videoclip& operator=(const Videoclip&);
    istream& citire(istream&) override;
    ostream& afisare(ostream&) const override;
    friend istream& operator>>(istream&, Videoclip&);
    friend ostream& operator<<(ostream&, const Videoclip&);
    void Durata() const;
    void Rezolutie() const;
};

Videoclip::Videoclip():ProductieMedia()
{
    this->temaVideoclip="necunoscuta";
    this->rezolutie=0;
}

Videoclip::Videoclip(string numeProductie, string numeDirector, int anLansare, int nrOre, int nrMinute,
                     int nrSecunde, string temaVideoclip, int rezolutie): ProductieMedia(numeProductie, numeDirector, anLansare, nrOre, nrMinute, nrSecunde)
{
    this->temaVideoclip=temaVideoclip;
    this->rezolutie=rezolutie;
}

Videoclip::Videoclip(const Videoclip &obj):ProductieMedia(obj)
{
    this->temaVideoclip=obj.temaVideoclip;
    this->rezolutie=obj.rezolutie;
}

Videoclip::~Videoclip(){}

Videoclip& Videoclip::operator=(const Videoclip &obj)
{
    if(this!=&obj)
    {
        ProductieMedia::operator=(obj);
        this->temaVideoclip=obj.temaVideoclip;
        this->rezolutie=obj.rezolutie;
    }
    return *this;
}

istream& Videoclip::citire(istream &in)
{
    this->ProductieMedia::citire(in);
    cout<<"Tema videoclipului: ";
    getline(in, this->temaVideoclip);
    cout<<"Rezolutia video: ";
    in>>this->rezolutie;
    in.ignore();
    return in;
}

istream& operator>>(istream &in, Videoclip &obj)
{
    return obj.citire(in);
}

ostream& Videoclip::afisare(ostream &out) const
{
    this->ProductieMedia::afisare(out);
    out<<"Tema videoclipului: "<<this->temaVideoclip<<endl;
    out<<"Rezolutia video: "<<this->rezolutie<<endl;
    return out;
}

ostream& operator<<(ostream &out, const Videoclip &obj)
{
    return obj.afisare(out);
}

void Videoclip::Durata() const
{
    cout<<"Durata video este: ";
    if(this->nrOre<10)
        cout<<"0"<<this->nrOre<<":";
    else cout<<this->nrOre<<":";
    if(this->nrMinute<10)
        cout<<"0"<<this->nrMinute<<":";
    else cout<<this->nrMinute<<":";
    if(this->nrSecunde<10)
        cout<<"0"<<this->nrSecunde;
    else cout<<this->nrSecunde;
    cout<<endl;
}

void Videoclip::Rezolutie() const
{
    if(this->rezolutie<720)
        cout<<"Rezolutia video este de tip SD"<<endl;
    if(this->rezolutie>=720 && this->rezolutie<1080)
        cout<<"Rezolutia video este de tip HD"<<endl;
    if(this->rezolutie>=1080  && this->rezolutie<1440)
        cout<<"Rezolutia video este de tip Full HD"<<endl;
    if(this->rezolutie>=1440  && this->rezolutie<2160)
        cout<<"Rezolutia video este de tip Quad HD"<<endl;
    if(this->rezolutie>=2160  && this->rezolutie<4320)
        cout<<"Rezolutia video este de tip 4K"<<endl;
    if(this->rezolutie>=4320)
        cout<<"Rezolutia video este de tip 8K"<<endl;
}

class Film:public Melodie, public Videoclip
{
private:
    string genFilm;
    int nrPersonaje;
    vector <Personaj> personajeFilm;
public:
    Film();
    Film(string, string, int, int, int, int, string, string, int, int, string, int, string, int, vector<Personaj>);
    Film(const Film&);
    Film& operator=(const Film&);
    ~Film();
    istream& citire(istream&) override;
    ostream& afisare(ostream&) const override;
    friend istream& operator>>(istream&, Film&);
    friend ostream& operator<<(ostream&, const Film&);
    void Durata() const;
    void Rezolutie() const;
    string getGenFilm();
};

Film::Film():ProductieMedia(), Melodie(), Videoclip()
{
    this->genFilm="necunoscut";
    this->nrPersonaje=0;
}

Film::Film(string numeProductie, string numeDirector, int anLansare, int nrOre, int nrMinute, int nrSecunde,
           string numeArtist, string genMuzical, int nrStrofe, int nrVersuri, string temaVideoclip, int rezolutie,
           string genFilm, int nrPersonaje, vector<Personaj> personajeFilm): ProductieMedia(numeProductie, numeDirector,
            anLansare, nrOre, nrMinute, nrSecunde), Melodie(numeProductie, numeDirector, anLansare, nrOre, nrMinute, nrSecunde,
            numeArtist, genMuzical, nrStrofe, nrVersuri), Videoclip(numeProductie, numeDirector, anLansare, nrOre, nrMinute, nrSecunde,
            temaVideoclip, rezolutie)
{
    this->genFilm=genFilm;
    this->nrPersonaje=nrPersonaje;
    this->personajeFilm=personajeFilm;
}

Film::Film(const Film &obj):ProductieMedia(obj), Melodie(obj), Videoclip(obj)
{
    this->genFilm=obj.genFilm;
    this->nrPersonaje=obj.nrPersonaje;
    this->personajeFilm=obj.personajeFilm;
}

Film& Film::operator=(const Film &obj)
{
    if(this!=&obj)
    {
        ProductieMedia::operator=(obj);
        Melodie::operator=(obj);
        Videoclip::operator=(obj);
        this->genFilm=obj.genFilm;
        this->nrPersonaje=obj.nrPersonaje;
        this->personajeFilm=obj.personajeFilm;
    }
    return *this;
}

Film::~Film(){}

istream& Film::citire(istream &in)
{
    this->Melodie::citire(in);
    cout<<"Tema filmului: ";
    getline(in, this->temaVideoclip);
    cout<<"Rezolutia video: ";
    in>>this->rezolutie;
    in.ignore();
    cout<<"Genul filmului: ";
    getline(in, this->genFilm);
    cout<<"Numarul personajelor din film: ";
    in>>this->nrPersonaje;
    in.get();
    for(int i=0; i<this->nrPersonaje; i++) {
        cout<<"PERSONAJ "<<i+1<<endl;
        Personaj pers;
        in>>pers;
        this->personajeFilm.push_back(pers);
    }
    in.ignore();
    return in;
}

istream& operator>>(istream &in, Film &obj)
{
    return obj.citire(in);
}

ostream& Film::afisare(ostream &out) const
{
    this->Melodie::afisare(out);
    out<<"Tema filmului: "<<this->temaVideoclip<<endl;
    out<<"Rezolutia video: "<<this->rezolutie<<endl;
    out<<"Genul filmului: "<<this->genFilm<<endl;
    out<<"Numarul personajelor din film: "<<this->nrPersonaje<<endl;
    for(int i=0; i<this->nrPersonaje; i++) {
        out << "PERSONAJ " << i + 1 << endl;
        out << this->personajeFilm[i];
    }
    return out;
}

ostream& operator<<(ostream &out, const Film &obj)
{
    return obj.afisare(out);
}

void Film::Durata() const
{
    this->Videoclip::Durata();
}

void Film::Rezolutie() const
{
    this->Videoclip::Rezolutie();
}

string Film::getGenFilm()
{
    return this->genFilm;
}

int main()
{
    vector <ProductieMedia*> productii;
    cout<<"                     BUN VENIT"<<endl;
    cout<<"ACEST PROGRAM CONTINE INFORMATII DESPRE PRODUCTII MEDIA"<<endl;
    int k=1;
    while(k==1)
    {
        cout<<"_________________________________________________________________"<<endl;
        cout<<"1. Daca doriti sa adugati o noua productie media, tastati 1"<<endl;
        cout<<"2. Daca doriti sa stergeti o productie media, tastati 2"<<endl;
        cout<<"3. Daca doriti sa schimbati valorile unei productii, tastati 3"<<endl;
        cout<<"4. Daca doriti sa afisati toate productiile memorate, tastati 4"<<endl;
        cout<<"5. Daca doriti sa afisati durata unei productii, tastati 5"<<endl;
        cout<<"6. Daca doriti sa aflati tipul rezolutiei unui anumit film sau videoclip, tastati 6"<<endl;
        cout<<"7. Daca doriti sa aflati toate filmele de un anumit gen, tastati 7"<<endl;
        cout<<"8. Daca doriti sa aflati numarul de versuri per strofa, tastati 8"<<endl;
        cout<<"9. Daca doriti sa iesiti, tastati 9"<<endl;
        int comanda;
        cin>>comanda;
        cin.get();
        switch(comanda)
        {
            case 1:
            {
                cout<<"1. Daca doriti sa adugati o noua melodie, tastati 1"<<endl;
                cout<<"2. Daca doriti sa adugati un nou videoclip, tastati 2"<<endl;
                cout<<"3. Daca doriti sa adugati un nou film, tastati 3"<<endl;
                int comanda2;
                cin>>comanda2;
                cin.get();
                if(comanda2==1)
                {
                    productii.push_back(new Melodie);
                    cin >> *productii.back();
                    break;
                }
                else if(comanda2==2)
                {
                    productii.push_back(new Videoclip);
                    cin >> *productii.back();
                    break;
                }
                else if(comanda2==3)
                {
                    productii.push_back(new Film);
                    cin>>*productii.back();
                    break;
                }
                break;
            }
            case 2:
            {
                cout<<"Introduceti indexul productiei pe care doriti sa o stergeti: ";
                int val;
                cin>>val;
                cin.get();
                val--;
                if (val >= 0 && val < productii.size()) {
                    productii.erase(productii.begin() + val);
                    cout << "Productia " << val << " a fost stearsa cu succes";
                }
                else cout<<"Index invalid"<<endl;
                break;
            }

            case 3:
            {
                cout<<"Introduceti indexul productiei pe care doriti sa o modificati: ";
                int val;
                cin>>val;
                cin.get();
                val--;
                if (val >= 0 && val < productii.size()) {
                    cin>>*productii[val];
                }
                else cout<<"Index invalid"<<endl;
                break;
            }

            case 4:
            {
                for (int i = 0; i < productii.size(); i++) {
                    cout<<"PRODUCTIE "<<i+1<<endl;
                    cout << *productii[i] << endl;
                }
                break;
            }

            case 5:
            {
                cout<<"Introduceti indexul productiei: ";
                int val;
                cin>>val;
                cin.get();
                val--;
                if (val >= 0 && val < productii.size()) {
                    productii[val]->Durata();
                }
                else cout<<"Index invalid"<<endl;
                break;
            }

            case 6: {
                cout << "Introduceti indexul videoclipului sau filmului: ";
                int val;
                cin >> val;
                cin.get();
                val--;
                if (val >= 0 && val < productii.size() && typeid(*productii[val])!= typeid(Melodie)) {
                    productii[val]->Rezolutie();
                } else cout << "Index invalid" << endl;
                break;
            }

            case 7:
            {
                cout << "Introduceti genul dorit: ";
                string gen;
                cin >> gen;
                cin.get();
                for (int i = 0; i < productii.size(); i++) {
                    Film *filmPtr = dynamic_cast<Film *>(productii[i]);
                    if(filmPtr && filmPtr->getGenFilm() == gen) {
                        cout << *productii[i]<<endl;
                    }
                }
                break;
            }

            case 8:
            {
                cout << "Introduceti indexul melodiei: ";
                int val;
                cin >> val;
                cin.get();
                val--;
                if (val >= 0 && val < productii.size() && typeid(*productii[val])== typeid(Melodie)) {
                    Melodie *melodiePtr = dynamic_cast<Melodie *>(productii[val]);
                        cout << "Numarul mediu de versuri per strofe este de: " <<melodiePtr->VersuriPerStrofa()<<endl;
                } else cout << "Index invalid" << endl;
                break;
            }

            case 9:
            {
                k=0;
                break;
            }
        }
    }
    cout<<"__________________________________________________________________";
}
