#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include "./array_list.h"
#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions

namespace structures {

template<typename T>
class Relogio : public virtual ArrayList<T> {
public:
    Relogio() {
    
    size =  120;
              }
    Contagem() { //adicionar "segundos" a lista do relógio
    for(int x = 0 , x <= size , x++)
    relogio::push_back(x);
    }
private:
    int size;
    
    
