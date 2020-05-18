template<class T>
List<T>::List(){
	ultima = cab = new Celda;
	cab->siguiente = 0;;
}

template<class T>
List<T>::List(const List& l){
	ultima = cab = new Celda;
	Celda *cel = l.cab->sig;

	while (cel->siguiente != 0) {
		ultima->siguiente = new Celda;
		ultima = ultima->siguiente;
		cel = cel->siguiente;
		ultima->elemento = cel->elemento;
	}
	ultima->siguiente = 0;

}

template<class T>
List<T>::~List(){
	Celda *cel;
	while (cab != 0) {
		cel = cab;
		cab = cab->siguiente;
		delete cel;
	}
}

template<class T>
List<T>& List<T>::operator=(const List& l){
	List aux(l);

	Celda cab_aux = cab;
	cab = aux.cab;
	aux.cab = cab_aux;

	Celda ultima_aux = ultima;
	ultima = l.ultima;
	l.ultima = ultima_aux;

	return *this;
}

template<class T>
bool List<T>::vacia()const{
	return (cab->siguiente == 0);
}

template<class T>
void List<T>::pushback(T elem){
	Celda *cel = new Celda;
	cel->elemento = elem;
	cel->siguiente = 0;

	ultima->siguiente = cel;
	ultima = cel;
}

template<class T>
void List<T>::popback(){
	Celda *cel = cab;
	while (cel->siguiente != ultima) {
		cel = cel->siguiente;
	}

	delete ultima;

	cel->siguiente = 0;
	ultima = cel;
}

template<class T>
T& List<T>::getLast(){
	return ultima->elemento;
}

template<class T>
const T& List<T>::getLast()const{
	return ultima->elemento;
}
