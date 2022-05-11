#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>
#include <cmath>

#include <exception>
using namespace std;

const std::pair<int, int> NIL(-100000, -100000);

int MDO::hashCode(TElem e) const{
    return abs(e.first) % m;
}

int MDO::d(TElem e, int i) const{
    int r = floor(hashCode(e) + c1*i + c2*i*i);
    return r % m;
}


MDO::MDO(Relatie r) {
	relatie = r;

    m = MAX;
    lg=0;
    for(int i = 0; i<m; i++){
        e[i]=NIL;
    }
}

void MDO::adauga(TCheie c, TValoare v) {
	TElem elem(c,v);
    int i = 0;
    bool gasit = false;
    do{
        int j = d(elem, i);
//        cout<<elem.first<<' '<<elem.second<<' '<<i<<' '<<j<<'\n';
        if(e[j] == NIL){
            e[j] = elem;
            lg++;
            gasit = true;
        }else{
            if(relatie(elem.first, e[j].first)){
                TElem aux = elem;
                elem = e[j];
                e[j] = aux;
            }
            i++;
        }
    }while(i<m && !gasit);
    do{
        int j = d(elem, i);
        i++;
    }while(i<m);
    if(i==m){
        //REDIMENSIONARE SI REDISPERSIE
        //m*=2 ca sa fie putere de 2
    }
}

vector<TValoare> MDO::cauta(TCheie c) const {
    //O(m)
	TElem ch = std::pair<int,int>(c, 0);
    vector<TValoare> v;
    bool folosite[m];
    for(int i = 0; i<m; i++)
        folosite[i] = false;

    int j;
    for(int i = 0; i<m; i++){
        j = d(ch, i);
        //daca elementul este bun si nu se repeta
        if(e[j] != NIL && e[j].first == c && !folosite[j]){
            v.push_back(e[j].second);
            folosite[j] = true;
        }
    }

	return v;
}

bool MDO::sterge(TCheie c, TValoare v) {
    TElem ch = std::pair<int,int>(c, v);

    int j;
    for(int i = 0; i<m; i++){
        j = d(ch, i);
        //daca elementul este bun si nu se repeta
        if(e[j] != NIL && e[j].first == c && e[j].second == v){
            e[j] = NIL;
            lg--;
            return true;
        }
    }
	return false;
}

int MDO::dim() const {
	return lg;
}

bool MDO::vid() const {
	return lg==0;
}

IteratorMDO MDO::iterator() const {
	return IteratorMDO(*this);
}

MDO::~MDO() {
	/* de adaugat */
}
