#include <iostream>
#include "list.h"

void list::append (int val){
  if (p_first==nullptr){
    p_first = new node();
    p_first->element = val;
  }
  else{
    node* p_aux = p_first;
    while (p_aux->p_dir != nullptr){
      p_aux = p_aux->p_dir;
    }
    p_aux->p_dir = new node();
    p_aux->p_dir->element = val;
  }
}

void list::insert(int index, int val){
  if (p_first==nullptr){
    append(val);
  }
  else if (index == 0){
    node* p_ins = new node();
    p_ins->p_dir = p_first;
    p_ins->element = val;
    p_first = p_ins;
  }
  else{
    int count = 0;
    node* p_aux = p_first;
    node* p_prev;
    while (count != index && p_aux->p_dir != nullptr){
      p_prev = p_aux;
      p_aux = p_aux->p_dir;
      count++;
    }
    if (count == index){
      if (p_aux == nullptr){
        p_aux->p_dir = new node();
        p_aux->p_dir->element = val;
      }
      else{
        node* p_ins = new node();
        p_ins->element = val;
        p_ins->p_dir = p_aux;
        p_prev->p_dir = p_ins;
      }
    }
    else if (count == index - 1){
      append(val);
    }
    else{
      std::cout<<"Invalid .insert with index = "<< index << std::endl;
    }
  }
}

void list::supr (int index){
  int count = 0;
  node* p_aux = p_first;
  node* p_prev = p_aux;

  if(index == 0){
    p_first = p_first->p_dir;
    delete p_aux;
    return;
  }
  else{
    while (count != index && p_aux->p_dir != nullptr){
      p_prev = p_aux;
      p_aux = p_aux->p_dir;
      count++;
    }
    if (index == count){
      p_prev->p_dir = p_aux->p_dir;
      delete p_aux;
      return;
    }
  }
}

void list::print(){
  if (p_first==nullptr) return;
  std::cout << p_first->element << std::endl;
  node* p_aux = p_first->p_dir;
  while (p_aux != nullptr){
    std::cout<<p_aux->element<<std::endl;
    p_aux = p_aux->p_dir;
  }
}
