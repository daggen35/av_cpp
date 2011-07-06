#include "smart_pointer.h"
#include <stdio.h>

namespace IDA_Smart_Pointer_I{
  smart_pointer::smart_pointer(int* p): ptr_(p){//defaultparam s�tts i headern
  }
  

  smart_pointer::smart_pointer(const smart_pointer& rhs){//g�r djup kopiering
    copy(rhs);
  }

  smart_pointer::~smart_pointer(){
    delete ptr_;
  }
  
  smart_pointer& smart_pointer::operator=(const smart_pointer& rhs){
    copy(rhs);
    return *this;
  }
  
  int& smart_pointer::operator*() const{//returna inten vi pekar p�, lade till const f�r att kunna anropa
    if(this->ptr_==0){//TODO fatta: anv�nds v�ran op-> eller en standard? borde kunna anv�nda v�ran? typ (*this)-> borde ge ptr_
		//kasta exception??  TODO
		throw 1;
	}
	return *(this->ptr_);
  }

  int* smart_pointer::operator->(){//TODO fatta detta varf�r det inte �r n� argument
    return this->ptr_;
  }

  void smart_pointer::copy(const smart_pointer& p){//djup kopiering
	if(p.ptr_==0){
		this->ptr_=0;
	}else{
		int orginal = *p;//klassens operator*().  p kan vara en tompekare.. ha try-cath s� slipper vi iffen
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
