#include "smart_pointer.h"
#include <stdio.h>

namespace IDA_Smart_Pointer_I{
  smart_pointer::smart_pointer(int* p): ptr_(p){//defaultparam sätts i headern
  }
  

  smart_pointer::smart_pointer(const smart_pointer& rhs){//gör djup kopiering
    copy(rhs);
  }

  smart_pointer::~smart_pointer(){
    delete ptr_;
  }
  
  smart_pointer& smart_pointer::operator=(const smart_pointer& rhs){
    copy(rhs);
    return *this;
  }
  
  int& smart_pointer::operator*() const{//returna inten vi pekar på, lade till const för att kunna anropa
    if(this->ptr_==0){//TODO fatta: används våran op-> eller en standard? borde kunna använda våran? typ (*this)-> borde ge ptr_
		//kasta exception??  TODO
		throw 1;
	}
	return *(this->ptr_);
  }

  int* smart_pointer::operator->(){//TODO fatta detta varför det inte är nå argument
    return this->ptr_;
  }

  void smart_pointer::copy(const smart_pointer& p){//djup kopiering
	if(p.ptr_==0){
		this->ptr_=0;
	}else{
		int orginal = *p;//klassens operator*().  p kan vara en tompekare.. ha try-cath så slipper vi iffen
		this->ptr_= new int(orginal);
		}
  }

  
}

int main(){
  IDA_Smart_Pointer_I::smart_pointer tom1();
  IDA_Smart_Pointer_I::smart_pointer tom2(0);
  int* x = new int(37);
  IDA_Smart_Pointer_I::smart_pointer pek1(x);
  delete x;
  fprintf(stderr,"lol");
  printf(" apa");
  return 0;
}
