#pragma once

template<class T>
struct Vertex {
    T source;
    T target;
    int weight;
    Vertex();
    Vertex(T source, T target, int weight);
};

template<class T>
Vertex<T>::Vertex() {
    weight = 0;
}


template<class T>
Vertex<T>::Vertex(T source, T target, int weight) {
    this->source = source;
    this->target = target;
    this->weight = weight;
}