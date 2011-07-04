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
    return *(this->ptr_);//om ptr �r null d�?? TODO
  }

  int* smart_pointer::operator->(){//
    return this->ptr_;
  }

  void smart_pointer::copy(const smart_pointer& p){//djup kopiering
    int orginal = *p;//klassens operator*().  p kan vara en tompekare..
    this->ptr_= new int(orginal);//om p inte �r tompekare TODO:if 
  }

  
}

int main(){
  IDA_Smart_Pointer_I::smart_pointer tom1();
  IDA_Smart_Pointer_I::smart_pointer tom2(0);
  int* x = new int(37);
  IDA_Smart_Pointer_I::smart_pointer pek1(x);
  delete x;
  
  return 0;
}
