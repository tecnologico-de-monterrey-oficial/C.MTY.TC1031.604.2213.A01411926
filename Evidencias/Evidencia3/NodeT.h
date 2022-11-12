#pragma once

template<class T>
struct NodeT {
    T data;
    NodeT<T>* left;
    NodeT<T>* right;
    NodeT();
    NodeT(T data);
    NodeT(T data, NodeT<T>* left, NodeT<T>* right);
};

template<class T>
NodeT<T>::NodeT() {
    left = nullptr;
    right = nullptr;
}

template<class T>
NodeT<T>::NodeT(T data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
}

template<class T>
NodeT<T>::NodeT(T data, NodeT<T>* left, NodeT<T>* right) {
    this->data = data;
    this->left = left;
    this->right = right;
}