// Copyright
#ifndef STRUCTURES_CIRCULAR_LIST_H
#define STRUCTURES_CIRCULAR_LIST_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
#include "./circular_list.h"  //! Linked List

namespace structures {

template<typename T>
//! Classe Circular List
class Semaforo : public virtual CicularList<T> {
 public:
    //! Classe Semáforo
    Semaforo() {
        CicularList(4, )
        // sentinela = new typename LinkedList<T>::Node(10, NULL);
        // LinkedList<T>::head = new typename
        // LinkedList<T>::Node((T)123456, sentinela);
        // sentinela->next(LinkedList<T>::head);
        // LinkedList<T>::size_ = 1;
    }

        //! inserir no início
    void push_front(const T& data) {
        typename LinkedList<T>::Node* novo = new typename
        LinkedList<T>::Node(data, LinkedList<T>::head);
        if (novo == NULL) {
            throw std::out_of_range("Sem Memória!");
        } else {
            LinkedList<T>::head = novo;
            sentinela->next(LinkedList<T>::head);
            LinkedList<T>::size_++;
        }
    }

    virtual T pop_front() {
        if (LinkedList<T>::empty()) {
            throw std::out_of_range("Lista Vazia!");
        }
        typename LinkedList<T>::Node* deletar = LinkedList<T>::head;
        T dadoVolta = LinkedList<T>::head->data();
        LinkedList<T>::head = LinkedList<T>::head->next();
        sentinela->next(LinkedList<T>::head);
        LinkedList<T>::size_--;
        delete deletar;
        return dadoVolta;
    }

    virtual void clear() {
        typename LinkedList<T>::Node::Node* atual;
        typename LinkedList<T>::Node::Node* anterior;
        atual = LinkedList<T>::head->next();
        while (!LinkedList<T>::empty()) {
            anterior = atual;
            atual = atual->next();
            delete anterior;
            LinkedList<T>::size_--;
        }
    }

    //! tamanho da lista
       virtual std::size_t size() const {
           return LinkedList<T>::size_-1;
       }

    //! Nodo sentinela
       typename LinkedList<T>::Node* sentinela;
};


}  //! namespace structures

#endif
