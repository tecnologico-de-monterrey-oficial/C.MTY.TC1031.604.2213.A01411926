#ifndef List_h
#define List_h

template <class T>
class List{
    private:
        vector<T> list;
        int size;
    public:
        List();
        List(vector<T> list);
        void add(T a);
        void print();
        void printVector();

};

//Constructor por default
template <class T>
List<T>::List(){
    //inicializar el tamaño de la lista
    size=0;
    cout<<"Constructor por default"<<endl;

}

//constructor con parámetros
template <class T>
List<T>::List(vector<T> list){
    //igualamos la lista de la clase con la lista que recibimos de parámetro
    this->list=list;
    //Actualizamos el tamaño de la lista
    size=list.size();
    cout<<"Constructor con parámetros"<<endl;    
}

//Agrega un elemento a la lista
template <class T>
void List<T>::add(T a){
    //Agregamos el elemento 'a' a la lista
    list.push_back(a);
    //Incrementamos el tamaño de la lista
    size++;
}

//imprimimos la lista
//imprimimos todos los elementos de la lista
//for de c++ que ya conocemos
//for (int i; i<size; i++)
//   cout<<list(i)<<endl;

template <class T>
void List<T>::print(){
    //Imprimimos todos los elementos de la lista
    for (auto el: list){
        cout<<el<<endl;
    }
}

template <class T>
    void List<T>::printVector(){
        for(auto el: list){
            for(auto l: el){
                cout<<l<<endl;
            };
            cout<<endl;
        }    
    }





#endif 