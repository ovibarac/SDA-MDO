#pragma once

#include <vector>
#include <iostream>
typedef int TCheie;
typedef int TValoare;

#include <utility>
typedef std::pair<TCheie, TValoare> TElem;

using namespace std;

class IteratorMDO;

typedef bool(*Relatie)(TCheie, TCheie);

#define MAX 40

class MDO {
	friend class IteratorMDO;
    private:
        //marimea tabelei
	    int m;

        //vectorul elementelor
        TElem e[MAX];

        //numarul de elemente
        int lg;

        //functia de dispersie extinsa
        int d(TElem e, int i) const;

        //functia de dispersie
        int hashCode(TElem e) const;

        //constante
        float c1 = 0.5;
        float c2 = 0.5;

        //functia de relatie
        Relatie relatie;

        public:
    void printMDO(){
        for(int i = 0; i<m; i++){
            std::cout<<i<<"   ";
        }
        cout<<'\n';
        for(int i = 0; i<m; i++){
            if(e[i]==pair<int, int>(-100000,-100000))
                std::cout<<"NIL ";
            else
                std::cout<<e[i].first << ','<<e[i].second<<' ';
        }

    }
	// constructorul implicit al MultiDictionarului Ordonat
	MDO(Relatie r);

	// adauga o pereche (cheie, valoare) in MDO
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MDO 
	int dim() const;

	//verifica daca MultiDictionarul Ordonat e vid 
	bool vid() const;

	// se returneaza iterator pe MDO
	// iteratorul va returna perechile in ordine in raport cu relatia de ordine
	IteratorMDO iterator() const;

	// destructorul 	
	~MDO();

};
