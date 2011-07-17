#include "smart_pointer.h"
#include <stdio.h>
#include <algorithm>
//using namespace IDA_Smart_Pointer_I;

namespace IDA_Smart_Pointer_I{
  smart_pointer::smart_pointer(int* p): ptr_(p){//defaultparam s�tts i headern, TODO: vill vi bara kopiera pekaren? det g�r vi nu + default funkar ej
    printf("skapar en smartpointer");
  }
  

  smart_pointer::smart_pointer(const smart_pointer& rhs){//g�r djup kopiering
    copy(rhs);
  }

  smart_pointer::~smart_pointer(){
    delete ptr_;//delete is nullpointer safe!
  }
  
  smart_pointer& smart_pointer::operator=(const smart_pointer& rhs){//exception safe because of swap
    smart_pointer temp(rhs);
    (*this).swap(temp);
    return *this;
  }

  smart_pointer& smart_pointer::operator=(int* rhs){
    smart_pointer temp(rhs);
    (*this).swap(temp);
    return *this;
  }
  
  int& smart_pointer::operator*() const{//returna inten vi pekar p�, lade till const f�r att kunna anropa
    printf("operator*\n");
    if(ptr_==0){
      fprintf(stderr, "kastar skit fr�n op*");
      throw 1;
    }
    return *ptr_;
  }
  
  int* smart_pointer::operator->() const{//TODO fatta detta varf�r det inte �r n� argument
    printf("operator->\n");
    return ptr_;
  }

  void smart_pointer::copy(const smart_pointer& p){//djup kopiering
    if(p.ptr_==0){
      this->ptr_=0;
    }else{
      int orginal = *p;//klassens operator*().  p kan vara en tompekare.. ha try-cath s� slipper vi iffen
      this->ptr_= new int(orginal);
    }
  }

  void smart_pointer::swap(smart_pointer& p)// throw()
  {
    std::swap(ptr_,p.ptr_);
  }
}
/*
int main(){
  printf("test 1...   ");
  //IDA_Smart_Pointer_I::smart_pointer tom1();//TODO: ska funka men funkar inte, h�r k�rs antaglien en default counstruktor...
  IDA_Smart_Pointer_I::smart_pointer tom2(0);
  printf("tommen har pekare: %p\n",tom2.operator->());
  try{
    *tom2;
  }catch(int a){
    fprintf(stderr,"fick kastad nr %d, borde vara 1\n",a);
  }

  int* x = new int(37);//skapa intpekare
  printf("skapar pekare som pekar p� %p\n",x);
  IDA_Smart_Pointer_I::smart_pointer pek1(x);//smartpekare till inten
  printf("pek1 p� %p\n",pek1.operator->());
  
  IDA_Smart_Pointer_I::smart_pointer pek2(pek1);//anv�nd copy, nu skall de inte peka p� samma utrymme
  IDA_Smart_Pointer_I::
  delete x;//pekar pek1 p� tomt utrymme nu?
  int* a= new int(19);//f�rst�r minnet isf
  printf("pek1 har v�rde %d\n", *pek1);
  printf("pek2 har v�rde %d\n", *pek2);  

  return 0;
}
*/
