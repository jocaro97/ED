template<class T>
void PilaMax<T>::poner(const T& t_elem){
	Elemento elem;
	elem.elem = t_elem;
	if (t_elem > max())
		elem.max = t_elem;
	else
		elem.max = max();

	datos.pushback(elem);

}
