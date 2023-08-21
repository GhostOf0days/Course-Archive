#include <cassert>

template <class T>
class Vec{
	public:
		typedef T* iterator;
		typedef unsigned int size_type;
		// default constructor
		Vec(){
			data = new T[2];
			m_size = 0;
			capacity = 2;
		}

		// constructor
		Vec(size_type n, const T& t){
			data = new T[n];
			m_size = n;
			capacity = n;
			for(int i=0; i<n; i++){
				data[i] = t;
			}
		}
		// copy constructor
		Vec(const Vec<T>& other){
			capacity = other.capacity;
			data = new T[capacity];
			m_size = other.m_size;
			for(int i=0; i<m_size; i++){
				data[i] = other.data[i];
			}

		}
		// x=(w=v)
		Vec<T>& operator=(const Vec<T>& other){
			capacity = other.capacity;
			data = new T[capacity];
			m_size = other.m_size;
			for(int i=0; i< m_size; i++){
				data[i] = other.data[i];
			}
			return *this;
		}

		~Vec(){
			delete [] data;
		}

		//T& operator[](int i);
		T& operator[](int i){
			assert(i < m_size);
			//std::cout<<"non const gets called"<<std::endl;
			return data[i];
		}

		// the [] operator. 
		// the const at the beginning, indicates whatever returns by this function can't be changed anywhere in the program (after the function returns).
		// the const at the end, indicates this function does not modify any of the class members. and this const is considered a part of the function signature.
		// in C++, function overloading is based on the number and types of arguments, not on the return type.
		// two functions in the same scope can't have the same signature, but return type is not a part of the function signature.
		const T& operator[](int i) const {
			assert(i < m_size);
			//std::cout<<"const gets called"<<std::endl;
			return data[i];
		}

		size_type size(){
			return m_size;
		}
		void resize(int n){
			if(n < capacity){
				capacity = n;
				return;
			}
			T* temp = new T[n]; 
			for(int i=0; i<m_size; i++){
				temp[i] = data[i];
			}
			delete [] data;
			data = temp;
		}

		void push_back(const T& t){
			if(m_size>=capacity){
				capacity = capacity + capacity;
				resize(capacity);
			}
			data[m_size] = t;
			m_size = m_size + 1;
		}

		void pop_back(){
			m_size = m_size - 1;
		}

		/* iterator implementation */
		void erase(iterator itr){
                        Vec<T>::iterator itr2 = itr;
                        itr2++;
                        while (itr2 != this->end()) {
                                *itr = *itr2;
                                itr++;
                                itr2++;
                        }
                        this->pop_back();
                }
		
		/* subscripting implementation 
		void erase(unsigned int i){
			for(int index=i; index<this->size()-1; index++){
				data[index] = data[index+1];
			}
			this->pop_back();
		}*/

		iterator begin(){
			return data;
		}

		iterator end(){
			return data+m_size;
		}

	private:
		T* data;

		int m_size;	// current size
		int capacity;	// whole capacity

};

// the [] operator
//template <class T>
//T& operator[](int i){
//	assert(i < m_size);
//	return data[i];
//}
