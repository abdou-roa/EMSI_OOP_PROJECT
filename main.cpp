#include <iostream>
#include "class.h"
#include <string>

using namespace std;

Facture N[10];
int nbr_factures = 0;

bool tester_fact_client(Client c){
    for(int i = 0; i < 10; i++){
        if(N[i].getClient().getIdentifiant())
            return true;
    }
    return false;
}

bool tester_fact_tab(Facture fct){
    for (int i = 0; i < 10; i++) {
        if (N[i].getCode() == fct.getCode())
            return true;
    }
    return false;
}

void ajouter_fact_tab(Facture &f){
    N[nbr_factures] = f;
    nbr_factures++;
}

void modifier_etat_fact(int code_fact){
    for(int i = 0; i < 10; i++){
        if(N[i].getCode() == code_fact){

            if(N[i].getEtat() == "payee")
                N[i].setEtat("non payee");
            else
                N[i].setEtat("payee");
                
        }
    }
}

int main(){
    Client c(1, "AMINI", "Abdellah", "Errachidia");
    c.afficher_client();

    Facture f;
    f.saisie_Facture();
    f.afficher_facture();

    Produit p(3, "test3", "test3", 1200, 100);
    
    f.addProduct(p);
    f.afficher_facture();

    Client c2(2, "BEN HALIMA", "Othmane", "Meknes");

    f.modClient(c2);

    f.afficher_facture();

    cout << "totale de la facture " << f.getCode() << " est: " << f.addition() << endl;

    f.afficher_produits_avec_cond(100);

    Client c3 ;
    c3 = f.getClient();
    c3.afficher_client();

    cout << "____________________" << endl;
    Facture f1 = f;
    //question 4
    ajouter_fact_tab(f);
    ajouter_fact_tab(f1);

    for (int i = 0; i < nbr_factures; i++){
        N[i].afficher_facture();
    }
    
    //tester si le tableau a une facture

    if(tester_fact_tab(f))
        cout << "facture de code: " << f.getCode() << " existe dans le tableau" << endl;
    else
        cout << "facture de code: " << f.getCode() << " n'existe pas dans le tableau!!" << endl;

    //tester si un client a passer une facture dans le tableau

    if(tester_fact_client(c3))
        cout << "client d'identifiant: " << c3.getIdentifiant() << " a une facture dans le tableau" << endl;
    else
        cout << "client d'identifiant: " << c3.getIdentifiant() << " n'a pas une facture dans le tableau" << endl;

    //change la facture de code 1
    cout << "_________________" << endl;

    modifier_etat_fact(1);
    for (int i = 0; i < nbr_factures; i++){
        N[i].afficher_facture();
    }
    
    return 0;
}