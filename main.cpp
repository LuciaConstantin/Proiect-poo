#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <string.h>
/// sistem de gestionare al unei biblioteci

class carte{
private:
    std::string titlu;
    std::string autor;
    std::string domeniu;
    std::string disponibilitate;
    std::string ISBN;//codul numeric specific fiecarei carti
    std::string limba;///optinonal
    std::string editura;
    int an_aparitie=0;///optional
    std::string nr_inventar;
public:
    carte()= default;
    ~carte()= default;

    carte(const std::string &titlu, const std::string &autor, const std::string &domeniu,
          const std::string &disponibilitate, const std::string &isbn, const std::string &limba,
          const std::string &editura, int anAparitie, const std::string &nrInventar) : titlu(titlu), autor(autor),
                                                                                       domeniu(domeniu),
                                                                                       disponibilitate(disponibilitate),
                                                                                       ISBN(isbn), limba(limba),
                                                                                       editura(editura),
                                                                                       an_aparitie(anAparitie),
                                                                                       nr_inventar(nrInventar) {}


    friend std::ostream &operator<<(std::ostream &os, const carte &carte) {
        os << "titlu: " << carte.titlu << " autor: " << carte.autor << " domeniu: " << carte.domeniu
           << " disponibilitate: " << carte.disponibilitate << " ISBN: " << carte.ISBN << " limba: " << carte.limba
           << " editura: " << carte.editura << " an_aparitie: " << carte.an_aparitie << " nr_inventar: "
           << carte.nr_inventar<<std::endl;
        return os;
    }
    void static afisare_infcarte(const std::vector <carte> &carti)
    {
        std::string Titlu_carte;
        std::cout<<"Pentru ce carte vrei sa aflii informatiile : "<<std::endl;
        getline(std::cin,Titlu_carte);
        int i=0;
        int ok=0;
        for(const carte &cart: carti)
        {   if(std::strcmp(cart.titlu.c_str(),Titlu_carte.c_str())==0)///std::strcmp
            {   ok=1;
                break;
            }
            i++;
        }

        if(ok==0)
            std::cout<<"Cartea nu se gaseste in baza de date"<<std::endl;
        else
        {   std::cout<<"Cartea se gaseste in baza de date si are informatiile: "<<std::endl;
            std::cout<< "titlu: " << carti[i].titlu << " autor: " << carti[i].autor << " domeniu: " << carti[i].domeniu
                     << " disponibilitate: " << carti[i].disponibilitate << " ISBN: " << carti[i].ISBN << " limba: " << carti[i].limba
                     << " editura: " << carti[i].editura << " an_aparitie: " << carti[i].an_aparitie << " nr_inventar: "
                     << carti[i].nr_inventar<<std::endl;}

    }
    void static afisare_cartiAutor(const std::vector <carte> &carti)
    {
        std::cout<<"Cautati cartile dupa autor "<<std::endl;
        std::string Nume_autor;
        getline(std::cin,Nume_autor);
        int ok=0;
        int i=0;
        for(const carte &cart: carti)
        {if(std::strcmp(cart.autor.c_str(),Nume_autor.c_str())==0)///std::strcmp
            {
                std::cout << "Autorul " << Nume_autor << " a scris: " << carti[i].titlu << std::endl;
                ok=1;
            }
            i++;
        }
        if(ok==0)
            std::cout<<"Nu exista autorul "<<Nume_autor<<" in biblioteca noastra"<<std::endl;

    }
    carte(const carte &c)
            : titlu(c.titlu), autor(c.autor), domeniu(c.domeniu), disponibilitate(c.disponibilitate),
              ISBN(c.ISBN), limba(c.limba), editura(c.editura), an_aparitie(c.an_aparitie),
              nr_inventar(c.nr_inventar)
    { }

    // carte  &operator=(const carte &carte) = default;
   carte  &operator=(const carte &carte) {
       /*if (this == &carte) {
           return *this;  // Evitați auto-atribuirea
       }*/
       titlu = carte.titlu;
       autor = carte.autor;
       domeniu = carte.domeniu;
       disponibilitate = carte.disponibilitate;
       ISBN = carte.ISBN;
       limba = carte.limba;
       editura = carte.editura;
       an_aparitie = carte.an_aparitie;
       nr_inventar = carte.nr_inventar;
       return *this;
   }


};

class client{
private:
    std::string nume;
    std::string prenume;
    std::string email;
    std::string nr_telefon;
    std::string data_inscriere;

public:
    client()= default;
    ~client()=default;
    client(const std::string &nume, const std::string &prenume, const std::string &email, const std::string &nrTelefon,
           const std::string &dataInscriere)
            : nume(nume), prenume(prenume), email(email), nr_telefon(nrTelefon), data_inscriere(dataInscriere) {}

    friend std::ostream &operator<<(std::ostream &os, const client &client) {
        os << "nume: " << client.nume << " prenume: " << client.prenume << " email: " << client.email << " nr_telefon: "
           << client.nr_telefon << " data_inscriere: " << client.data_inscriere;
        return os;
    }
    void static gasire_client(const std::vector <client> &clienti)
    {
        std::cout<<"Cautarea unui client in baza de date "<<std::endl;
        std::string Nume_client, Prenume_client;
        std::cout<<"Numele clientului este "<<std::endl;
        getline(std::cin,Nume_client);
        std::cout<<"Prenumele clientului este "<<std::endl;
        getline(std::cin,Prenume_client);
        int ok=0;
        for(const client &cli: clienti)
            if(std::strcmp(cli.nume.c_str(),Nume_client.c_str())==0 && std::strcmp(cli.prenume.c_str(),Prenume_client.c_str())==0)///std::strcmp
            {
                std::cout << "Clientul " << Nume_client <<" "<< Prenume_client <<" exista deja in baza nostra de date " << std::endl;
                ok=1;
                break;
            }

        if(ok==0)
            std::cout<<"Clientul nu exista in baza nostra de date"<<std::endl;

    }

    static void inserare_client( std::vector <client> &clienti)
    {
        std::cout<<"Inserare client "<<std::endl;
        std::string nume, prenume, email, nr_telefon, dataInscriere;
        std::cout<<"Numele: ";
        std::cin>>nume;
        std::cout<<"Prenume: ";
        std::cin>>prenume;
        std::cout<<"email: ";
        std::cin>>email;
        std::cout<<"Numar de telefon: ";
        std::cin>>nr_telefon;
        std::cout<<"Data inscrierii: ";
        std::cin>>dataInscriere;

        client client_nou(nume,prenume,email,nr_telefon,dataInscriere);
        clienti.push_back(client_nou);
        std::ofstream c("client.in",std::ios::app);
        if (c) {
            c << nume << '\n' << prenume << '\n' << email << '\n' << nr_telefon << '\n' << dataInscriere << '\n';
            c.close();
        } else {
            std::cerr << "Nu am putut deschide fișierul de client pentru scriere." << std::endl;
        }

    }

};
class angajat{
private:
    std::string nume;
    std::string prenume;
    std::string CNP;
    std::string adresa;
    std::string email;
    std::string nr_telefon;
    std::string ocupatie;
    std::string data_angajare;
    int salariu=0;
public:
    angajat()=default;
    ~angajat()=default;

    angajat(const std::string &nume, const std::string &prenume, const std::string &cnp, const std::string &adresa,
            const std::string &email, const std::string &nrTelefon, const std::string &ocupatie,
            const std::string &dataAngajare, int salariu)
            : nume(nume), prenume(prenume), CNP(cnp), adresa(adresa), email(email), nr_telefon(nrTelefon),
              ocupatie(ocupatie), data_angajare(dataAngajare), salariu(salariu) {}


    friend std::ostream &operator<<(std::ostream &os, const angajat &angajat) {
        os << "nume: " << angajat.nume << " prenume: " << angajat.prenume << " CNP: " << angajat.CNP << " adresa: "
           << angajat.adresa << " email: " << angajat.email << " nr_telefon: " << angajat.nr_telefon << " ocupatie: "
           << angajat.ocupatie << " data_angajare: " << angajat.data_angajare << " salariu: " << angajat.salariu;
        return os;
    }

    static void modificare_dateAng(std::vector <angajat> &angajati) {
        std::string data_modif, inf_modif, ang_modif;
        std::cout << "Carui angajat vrei sa-i realizezi modificarea: ";
        std::cin >> ang_modif;
        std::cout << "Ce vrei sa modifici?" << std::endl;
        std::cin >> data_modif;
        std::cout << "Introdu modificarea: " << std::endl;
        std::cin>> inf_modif;
        int i = 0;
        bool ok = 0;
        for (angajat &ang: angajati) {
            {
                if (std::strcmp(ang.nume.c_str(), ang_modif.c_str()) == 0){///gasesc angajatul
                    ok = 1;
                    break;
                }
            }
            i++;
        }

        if (ok == 1) {
            if (std::strcmp("adresa", data_modif.c_str()) == 0)
                angajati[i].adresa = inf_modif;
            else if (std::strcmp("email", data_modif.c_str()) == 0)
                angajati[i].email = inf_modif;
            else if (std::strcmp("nr_telefon", data_modif.c_str()) == 0)
                angajati[i].nr_telefon = inf_modif;
            else if (std::strcmp("salariu", data_modif.c_str()) == 0)
                angajati[i].salariu = std::stoi(inf_modif);
            else
                std::cout << "Data " << data_modif << " nu poate fi modificata " << std::endl;
        } else
            std::cout << "Nu se poate realiza modificari asupra angajatului deoarece nu exista ";
        std::ofstream f("angajati.in");
        for (const angajat &ang: angajati)
            f << ang.nume << std::endl << ang.prenume << std::endl << ang.CNP << std::endl << ang.adresa << std::endl << ang.email <<std::endl
              << ang.nr_telefon <<std::endl << ang.ocupatie << std::endl << ang.data_angajare << std::endl << ang.salariu << std::endl;
        f.close();
    }
};


int main() {
    std::ifstream f("carte.in");
    if (!f) {
        std::cerr << "Nu am putut deschide fisierul de intrare." << std::endl;
        return 1;
    }
    std::vector<carte> carti;
    std::string titlu, autor, domeniu, disponibilitate, ISBN, limba, editura, nr_inventar;
    int an_aparitie;
    while (getline(f, titlu)) {
        getline(f, autor);
        getline(f, domeniu);
        getline(f, disponibilitate);
        getline(f, ISBN);
        getline(f, limba);
        getline(f, editura);
        f >> an_aparitie;
        f.ignore();//pt endline
        getline(f, nr_inventar);

        carte carte_noua(titlu, autor, domeniu, disponibilitate, ISBN, limba, editura, an_aparitie, nr_inventar);
        carti.push_back(carte_noua);

    }
    f.close();

   for (const carte &cart: carti)
        std::cout << cart << std::endl;

    ///---------------------------------------

    std::ifstream c("client.in");
    if (!c) {
        std::cerr << "Nu am putut deschide fisierul de intrare." << std::endl;
        return 1;
    }
    std::string nume, prenume, email, nrTelefon, data;
    std::vector<client> clienti;
    while (getline(c, nume)){
        getline(c,prenume);
        getline(c,email);
        getline(c,nrTelefon);
        getline(c,data);
        client client_nou(nume ,prenume, email, nrTelefon, data);
        clienti.push_back(client_nou);
    }
    c.close();
    for(const client &i:clienti)
        std::cout << i<< std::endl;

    std::ifstream a("angajati.in");
    std::string numeAng, prenumeAng, CNP, adresa, emailAng, nr_telefon, ocupatie, data_ang;
    int salariu;
    std::vector <angajat> angajati;
    while(getline(a,numeAng))
    {
        getline(a,prenumeAng);
        getline(a,CNP);
        getline(a,adresa);
        getline(a, emailAng);
        getline(a,nr_telefon);
        getline(a,ocupatie);
        getline(a,data_ang);
        a >> salariu;
        a.ignore();
        angajat angajat_nou(numeAng,prenumeAng,CNP,adresa,emailAng,nr_telefon,ocupatie,data_ang,salariu);
        angajati.push_back(angajat_nou);
    }
    a.close();
    for(const angajat &ang:angajati)
        std::cout<< ang<< std::endl;



    carte crte;
    client cli;
    angajat ang;
    std::cout <<"Prima copiere"<<std::endl;
    carte carte_copiata1(carti[2]);
    std::cout<<carte_copiata1<<std::endl;
    std::cout<<"A doua copiere "<<std::endl;
    carte carte_copiata2=carti[2];
    std::cout<<carte_copiata2<<std::endl;
    crte.afisare_infcarte(carti);
    crte.afisare_cartiAutor(carti);
    cli.gasire_client(clienti);
    cli.inserare_client(clienti);
    ang.modificare_dateAng(angajati);

    return 0;
}

