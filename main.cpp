#include <iostream>
#include "class.h"
#include <string>

using namespace std;

Facture N[10];

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

    Client c3 = f.getClient();
    c3.afficher_client();

    //question 4

    return 0;
}