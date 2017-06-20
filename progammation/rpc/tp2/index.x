struct ligne {
        char *nom;
        int tel;
};

struct liste {
        struct ligne tab;
        struct liste * next;
};

typedef struct ligne ligne;
typedef struct liste liste;

 
program NB_PROG {
      version NB_VERS {
	void  affiche_1(char)=1;
	ligne recherche_1(char)=2;
	int ajout_1(ligne)=3;
	liste  liste_1()=4;
	bool_t xdr_ligne(XDR  , struct ligne )=5;
	bool_t xdr_liste(XDR ,struct liste )=6;
	}=1;
 }=34567;
