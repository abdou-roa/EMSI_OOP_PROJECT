#include <iostream>
#include <string>

#include "class.h"

using namespace std;

//Produit
Produit::Produit()
{
    this->identifiant = 0;
    this->nom = "nom";
    this->description = "description";
    this->prix_unitaire = 0;
    this->quantite = 0;
}
Produit::Produit(const Produit& other) {
        this->identifiant = other.identifiant;
        this->nom = other.nom;
        this->description = other.description;
        this->prix_unitaire = other.prix_unitaire;
        this->quantite = other.quantite;
}


Produit::Produit(int identifiant, string nom, string description, float prix_unitaire, int quantite)
{
    this->identifiant = identifiant;
    this->nom = nom;
    this->description = description;
    this->prix_unitaire = prix_unitaire;
    this->quantite = quantite;
}

void Produit::saisie_produit()
{
    cout << "Entrez l'identifiant du produit: ";
    cin >> identifiant;
    cout << "Entrez le nom du produit: " ;
    cin >> nom;
    cout << "Entrez une description du produit: ";
    cin >> description;
    cout << "Entrez le prix unitaire: ";
    cin >> prix_unitaire;
    cout << "Entrez la quantité: ";
    cin >> quantite;
}

void Produit::afficher_produit()
{
    cout  << "identifiant: " << identifiant << "nom: " << nom << "description: " << description << "prix unitaire: " << prix_unitaire << "quantite: " << quantite << endl;
}

int Produit::getIdentifiant() const {
    return identifiant;
}

//produit getters & setters

string Produit::getNom() const {
    return nom;
}

string Produit::getDescription() const {
    return description;
}

float Produit::getPrixUnitaire() const {
    return prix_unitaire;
}

int Produit::getQuantite() const {
    return quantite;
}


void Produit::setIdentifiant(int id) {
    identifiant = id;
}

void Produit::setNom(const string& name) {
    nom = name;
}

void Produit::setDescription(const string& desc) {
    description = desc;
}

void Produit::setPrixUnitaire(float price) {
    prix_unitaire = price;
}

void Produit::setQuantite(int quantity) {
    quantite = quantity;
}



//Client
Client::Client() {
    identifiant = 0;
    nom = "";
    prenom = "";
    adresse = "";
}

Client::Client(int id, string n, string p, string adr) {
    identifiant = id;
    nom = n;
    prenom = p;
    adresse = adr;
}

Client::Client(Client &C) {
    identifiant = C.identifiant;
    nom = C.nom;
    prenom = C.prenom;
    adresse = C.adresse;
}


// client getters and setters
void Client::saisie_Client() {
    cout << "Enter Identifiant: ";
    cin >> identifiant;
    cout << "Enter Nom: ";
    cin >> nom;
    cout << "Enter Prenom: ";
    cin >> prenom;
    cout << "Enter Adresse: ";
    cin >> adresse;
}

void Client::afficher_client() {
    cout << "Identifiant: " << identifiant << endl;
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    cout << "Adresse: " << adresse << endl;
}

int Client::getIdentifiant() const {
    return identifiant;
}

void Client::setIdentifiant(int id) {
    identifiant = id;
}

// Getter and Setter for nom
string Client::getNom() const {
    return nom;
}

void Client::setNom(const string &n) {
    nom = n;
}

// Getter and Setter for prenom
string Client::getPrenom() const {
    return prenom;
}

void Client::setPrenom(const string &p) {
    prenom = p;
}

// Getter and Setter for adresse
string Client::getAdresse() const {
    return adresse;
}

void Client::setAdresse(const string &adr) {
    adresse = adr;
}






//Facture
Facture::Facture(): code(0), client(), jour(0), mois(0), annee(0), produits(){};

Facture::Facture(const Facture& other) 
{
    code = other.code;
    client = other.client;
    nbr_produits = other.nbr_produits;
    jour = other.jour;
    mois = other.mois;
    annee = other.annee;
    etat = other.etat;

    for (int i = 0; i < 3; ++i) {
        produits[i] = other.produits[i];
    }
}

void Facture::saisie_Facture() {

    cout << "Enter Facture details:\n";

    cout << "Code: ";
    cin >> code;

    cout << "ID Client: ";
    //cin >> id_client;
    client.saisie_Client();

    cout << "Number of Products: ";
    cin >> nbr_produits;

    for (int i = 0; i < nbr_produits; ++i) {
        produits[i].saisie_produit();
    }

    cout << "Day: ";
    cin >> jour;

    cout << "Month: ";
    cin >> mois;

    cout << "Year: ";
    cin >> annee;

    cout << "Etat: ";
    cin >> etat;
}

void Facture::afficher_facture() {

    cout << "Facture details:\n";

    cout << "Code: " << code << endl;
    cout << "ID Client: \n";
    client.afficher_client();

    cout << "Number of Products: " << nbr_produits << endl;

    cout << "Products:\n";
    for (int i = 0; i < nbr_produits; ++i) {
        produits[i].afficher_produit();
    }

    cout << "Day: " << jour << endl;
    cout << "Month: " << mois << endl;
    cout << "Year: " << annee << endl;
    cout << "Etat: " << etat << endl;
}

// question n2: tester si la facture apartient a un client
void Facture::hasClient(int client_id)
{
    if(this->client.getIdentifiant() != client_id)
    {
        cout << "client n'a pas cette facture." << endl;
    }
    cout << "client a cette facture." << endl;
}

//question n3_a verifier l'existance d'un produit dans une facture

bool Facture::hasProduct(int produit_id)
{
    bool existe;
    for(int i = 0; i < this->nbr_produits; i++)
    {
        if(this->produits[i].getIdentifiant() == produit_id)
        {
            existe = true;
            break;
        }
        else
        {
            existe = false;
            break;
        }
    }
    return existe;
}

// question n3_b ajouter un produit a la facture en testant l'existance
void Facture::addProduct(const Produit& newProduit)
{
    if (!this->hasProduct(newProduit.getIdentifiant()))
    {
        this->produits[this->getNbrProduits()] = newProduit;
        this->setNbrProduits(this->getNbrProduits() + 1);
    }
    else
        cout << "produit deja existe." << endl;
};

void Facture::modProduct(int id_prod, const Produit& newProduit)
{
    if (this->hasProduct(id_prod))
    {
        this->produits[id_prod] = newProduit;
    }
    else
        cout << "produit n'existe pas dans la facture!" << endl;
}

void Facture::modClient(Client &client)
{
    this->setClient(client);
};

float Facture::addition(){
    float max= 0 ;
    for(int i = 0; i<this->nbr_produits; i++)
        max += produits[i].getPrixUnitaire() * produits[i].getQuantite();
    return max;
};

void Facture::afficher_produits_avec_cond(float prix_max){
    for (int i=0; i<this->nbr_produits; i++){
        if(produits[i].getPrixUnitaire() < prix_max)
            produits[i].afficher_produit();
    }
};

void Facture::modifier_quantite_produit(int quantite, int index){
    if(this->getEtat() != "payee")
        this->getProduit(index).setQuantite(quantite);
    else
    cout << "la facture est deja payee" << endl;
}

void Facture::suprimer_produit_fact(Produit p){
    for(int i = 0; i < nbr_produits; i++)
    {
        if(this->produits[i].getIdentifiant() == p.getIdentifiant()){
            produits[i]  = Produit();
            cout << "produit suprimee!" << endl;
        }
        else
            cout << "produit n'existe pas" << endl;
    }
}
//facture getters & setters
int Facture::getCode() const {
    return code;
}


int Facture::getNbrProduits() const {
    return nbr_produits;
}


int Facture::getJour() const {
    return jour;
}

int Facture::getMois() const {
    return mois;
}

int Facture::getAnnee() const {
    return annee;
}

string Facture::getEtat() const {
    return etat;
}

//to fix later
Client Facture::getClient(){
    return client;
};

void Facture::setCode(int newCode) {
    code = newCode;
}

void Facture::setNbrProduits(int newNbrProduits) {
    nbr_produits = newNbrProduits;
}

void Facture::setJour(int newJour) {
    jour = newJour;
}

void Facture::setMois(int newMois) {
    mois = newMois;
}

void Facture::setAnnee(int newAnnee) {
    annee = newAnnee;
}

void Facture::setEtat(const std::string& newEtat) {
    etat = newEtat;
}

void Facture::setClient(Client &client){
    this->client = client;
}

Produit& Facture::getProduit(int index) {
    for (int i = 0; i < 30; i++)
    {
        if(produits[i].getIdentifiant() == index)
            return this->produits[i];
    }
    static Produit emptyProduct;
    return emptyProduct;
}