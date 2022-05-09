#include "IteratorMDO.h"
#include "MDO.h"

const std::pair<int, int> NIL(-100000, -100000);

void IteratorMDO::deplasare() {
    while((pozcrt < dict.m) && dict.e[pozcrt] == NIL){
        pozcrt++;
    }
}

IteratorMDO::IteratorMDO(const MDO& d) : dict(d){
    pozcrt = 0;
    deplasare();
}

void IteratorMDO::prim(){
	pozcrt = 0;
    deplasare();
}

void IteratorMDO::urmator(){
	pozcrt++;
    deplasare();
}

bool IteratorMDO::valid() const{
	return pozcrt < dict.m;
}

TElem IteratorMDO::element() const{
	return dict.e[pozcrt];
}


