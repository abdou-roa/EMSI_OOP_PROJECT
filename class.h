#include <string>

using namespace std;

class Produit{

    private: 
        int identifiant;
        string nom;
        string description; 
        float prix_unitaire;
        int quantite;
        
    public: 
        Produit();
        Produit(int identifiant, string nom, string description, float prix_unitaire, int quantite);
        Produit(const Produit& other);
        void saisie_produit();
        void afficher_produit();

        int getIdentifiant() const;
        string getNom() const;
        string getDescription() const;
        float getPrixUnitaire() const;
        int getQuantite() const;

        void setIdentifiant(int id);
        void setNom(const string& name);
        void setDescription(const string& desc);
        void setPrixUnitaire(float price);
        void setQuantite(int quantity);

};

class Client{

    private: 
        int identifiant;
        string nom;
        string prenom;
        string adresse;
    public: 
        Client();
        Client(int identifiant, string nom, string prenom, string adresse);
        Client(Client &C);
        void saisie_Client();
        void afficher_client();
         
        int getIdentifiant() const;
        void setIdentifiant(int id);

        string getNom() const;
        void setNom(const string &n);

        string getPrenom() const;
        void setPrenom(const string &p);

        string getAdresse() const;
        void setAdresse(const string &adr);

};

class Facture{

    private:
        int code;
        Client client;
        int nbr_produits;
        Produit produits[3];
        int jour, mois, annee;
        string etat;

    public:
        Facture();
        Facture(const Facture &F);
        void saisie_Facture();
        void afficher_facture();

        void hasClient(int client_id);

        bool hasProduct(int produit_id);

        void addProduct(const Produit& newProduit);

        void modProduct(int id_prod, const Produit& newProduit);

        void modClient(Client &client);

        float addition();

        void afficher_produits_avec_cond(float prix_max);

        int getCode() const;
        int getNbrProduits() const;
        Produit getProduit(int index) const;
        int getJour() const;
        int getMois() const;
        int getAnnee() const;
        string getEtat() const;
        Client getClient();

        void setCode(int newCode);
        void setIdClient(int newIdClient);
        void setNbrProduits(int newNbrProduits);
        void setNewProduit(const Produit& newProduit);
        void setJour(int newJour);
        void setMois(int newMois);
        void setAnnee(int newAnnee);
        void setEtat(const string& newEtat);
        void setClient(Client &client);
   
};