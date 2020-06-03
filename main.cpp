#include <iostream>
#include<math.h>
#include<list>
using namespace std;
class Pokemon
{
protected:
    float poids;
    string nom;
public:
    Pokemon(string unn,float pds):nom(unn),poids(pds){}
    Pokemon()
    {
        cout<<"Donner le nom de ce pokemon\n";
        cin>>nom;
        cout<<"Donner le poids de ce pokemon\n";
        cin>>poids;
    }
    virtual float calculer_vitesse()=0;
    virtual float calculer_energie_absorb_quotid()=0;
    virtual void afficher()
    {
        cout<<"Je suis "<<nom<<" mon poids est de "<<poids<<" kg ";
    }
    virtual ~Pokemon(){}
};
class terractifs:public Pokemon
{
private:
    float taille;
    int nbre_pattes;
    float coef_vitalite;
public:
    terractifs(string unn,float pds,float tal,int nbr_pt,float coef_vital):Pokemon(unn,pds)
    {
        taille=tal;
        nbre_pattes=nbr_pt;
        coef_vitalite=coef_vital;
    }
    terractifs()
    {
        cout<<"Donner la taille de ce pokemon\n";
        cin>>taille;
        cout<<"Donner le nombre de pattes de ce pokemon\n";
        cin>>nbre_pattes;
        cout<<"Donner le coefficient de vitalite de ce pokemon\n";
        cin>>coef_vitalite;
    }
    float calculer_energie_absorb_quotid()
    {
        float taille2=pow(taille,2);
        return (taille2*coef_vitalite*100);
    }
    float calculer_vitesse()
    {
        float vitesse;
        vitesse=(nbre_pattes*((poids + 1)/10)*2*calculer_energie_absorb_quotid());
        return vitesse;
    }
    void afficher()
    {
        Pokemon::afficher();
        float vitesse;
        vitesse=calculer_vitesse();
        float energie;
        energie=calculer_energie_absorb_quotid();
        cout <<",ma vitesse actuelle est de " <<vitesse<<" km/h, "
        <<"j'absorbe  quotidiennement une énergie de "<<energie<<" , j'ai "<<nbre_pattes<<" de pattes"
        <<" mon taille est de "<<taille<<" m , ma vitalite est de "<<coef_vitalite<<endl;
    }
    bool operator==(terractifs a){return(a.nom==nom);}
};
class dormeurs:public Pokemon
{
private:
    float taille;
    int nbre_pattes;
    float nbre_heures;
public:
    dormeurs(string unn,float pds,float tal,int nbr_pat,float nbre_heur):Pokemon(unn,pds)
    {
        taille=tal;
        nbre_pattes=nbr_pat;
        nbre_heures=nbre_heur;
    }
    dormeurs()
    {
        cout<<"Donner la taille de ce Pokemon\n";
        cin>>taille;
        cout<<"Donner le nombre de pattes de ce Pokemon\n";
        cin>>nbre_pattes;
        cout<<"Donner le nombre d'heures de repos quotidien de ce pokemon\n";
        cin>>nbre_heures;
    }
    float calculer_energie_absorb_quotid()
    {
        float energie;
        energie=pow(taille,2)-(nbre_heures*2);
        return energie;
    }
    float calculer_vitesse()
    {
        float vitesse;
        vitesse=(nbre_pattes*((poids + 1)/10)*2*calculer_energie_absorb_quotid());
        return vitesse;
    }
    void afficher()
    {
        Pokemon::afficher();
        float vitesse;
        vitesse=calculer_vitesse();
        float energie;
        energie=calculer_energie_absorb_quotid();
        cout <<",ma vitesse actuelle est de " <<vitesse<<" km/h, "
        <<"j'absorbe  quotidiennement une énergie de "<<energie<<" , j'ai "<<nbre_pattes<<" de pattes"
        <<" mon taille est de "<<taille<<" m , mon nombre d'heure de repos quotidien est egale "<<nbre_heures<<" h"<<endl;
    }
    bool operator==(dormeurs a){return(a.nom==nom);}
};
class aquatiques:public Pokemon
{
private:
    int nombre_nageoires;
public:
    aquatiques(string unn,float pds,int nbre_nag):Pokemon(unn,pds)
    {
        nombre_nageoires=nbre_nag;
    }
    aquatiques()
    {
        cout<<"Donner le nombre de nageoires de ce pokemon\n";
        cin>>nombre_nageoires;
    }
    float calculer_energie_absorb_quotid()
    {
        return (poids/2);
    }
    float calculer_vitesse()
    {
        float vitesse;
        vitesse=nombre_nageoires*(poids/25)*calculer_energie_absorb_quotid();
        return vitesse;
    }
    void afficher()
    {
        Pokemon::afficher();
        float vitesse;
        vitesse=calculer_vitesse();
        float energie;
        energie=calculer_energie_absorb_quotid();
        cout <<",ma vitesse actuelle est de " <<vitesse<<" km/h, "
        <<"j'absorbe  quotidiennement une énergie de "<<energie<<" , j'ai "<<nombre_nageoires<<" de nageoires"
        <<endl;
    }
    bool operator==(aquatiques a){return(a.nom==nom);}
};
class PokemonWorld
{
private:
    list<terractifs> pokemonworld1;
    list<aquatiques> pokemonworld2;
    list<dormeurs> pokemonworld3;
public:
    void ajouter_terractifs(terractifs a){pokemonworld1.push_back(a);}
    void ajouter_aquatiques(aquatiques a){pokemonworld2.push_back(a);}
    void ajouter_dormeurs(dormeurs a){pokemonworld3.push_back(a);}
    void supprimer_terractifs(terractifs a){pokemonworld1.remove(a);}
    void supprimer_aquatiques(aquatiques a){pokemonworld2.remove(a);}
    void supprimer_dormeurs(dormeurs a){pokemonworld3.remove(a);}
    void supprimer_dernier_terractifs(){pokemonworld1.pop_back();}
    void supprimer_dernier_aquatique(){pokemonworld2.pop_back();}
    void supprimer_dernier_dormeurs(){pokemonworld3.pop_back();}
    float calculer_energie_absorb()
    {
        float energie;
        for(int i=0;i<pokemonworld1.size();i++)
        {
            energie+=pokemonworld1.front().calculer_energie_absorb_quotid();
            pokemonworld1.push_back(pokemonworld1.front());
            pokemonworld1.pop_front();
        }
        for(int i=0;i<pokemonworld2.size();i++)
        {
            energie+=pokemonworld2.front().calculer_energie_absorb_quotid();
            pokemonworld2.push_back(pokemonworld2.front());
            pokemonworld2.pop_front();
        }
        for(int i=0;i<pokemonworld3.size();i++)
        {
            energie+=pokemonworld3.front().calculer_energie_absorb_quotid();
            pokemonworld3.push_back(pokemonworld3.front());
            pokemonworld3.pop_front();
        }
        return energie;
    }
    float calcul_vitesse()
    {
        float vitesse;
        for(int i=0;i<pokemonworld1.size();i++)
        {
            vitesse+=pokemonworld1.front().calculer_vitesse();
            pokemonworld1.push_back(pokemonworld1.front());
            pokemonworld1.pop_front();
        }
        for(int i=0;i<pokemonworld2.size();i++)
        {
            vitesse+=pokemonworld2.front().calculer_vitesse();
            pokemonworld2.push_back(pokemonworld2.front());
            pokemonworld2.pop_front();
        }
        for(int i=0;i<pokemonworld3.size();i++)
        {
            vitesse+=pokemonworld3.front().calculer_vitesse();
            pokemonworld3.push_back(pokemonworld3.front());
            pokemonworld3.pop_front();
        }
        return(vitesse/(pokemonworld1.size()+pokemonworld2.size()+pokemonworld3.size()));
    }
};
int main()
{
}
