 # 2 UZDUOTIS 
 ## Programos paleidimas naudojant `GNU C++ Compiler`
**Tiesiog per terminala**
- `g++ -o run main.cpp `
- `./run`

**Su Makefile**

Programos sudarymas:
- `make`

Sudarytu failu istrynimas:
- `clean`

**Po v0.3**

Programos sudarymas:
- `make`

functions.cpp failo sukompiliavimas:
- `fun`

Sudarytu failu istrynimas:
- `clean`

## Versiju istorija

### [v0.1](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v0.1)
**Pridėta**
- Pirmine programos versija
- .gitignore failas
- Makefile

**Pastebejimas**

Esant tokiam kodui, ciklas veiks, kol ivedami int'ai ir tarkim ivedus raide, jis sustos ir nenuskaitys reiksmes, taciau ivedus float'a, pvz., 2.3 ciklas sustos, bet pries tai nuskaitys reiksme, ja suapvalins iki 2 ir isves i ekrana 

```shell
int x;
    while(cin >> x) {
    cout << x << endl;
    }
```

### [v0.1.1](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v0.1.1)
**Pridėta**
- cmasyvas.cpp file'as, kuriame n.d rezultatai saugomi ne vectoriuje, o masyve

### [v0.2](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v0.2)
**Pridėta**
- Antrine programos versija
- duom.txt failas

Pirmas skaicius nurodo, kiek bus studentu, antras skaicius nurodo, kiek bus n.d pazymiu, o kiekvienos eilutes paskutinis skaitmuo yra egzamino rezultatas

```shell
5 3
vardas1 vardas2 3 6 8 3
vardas2 vardas2 5 7 3 1
vardas3 vardas2 1 6 10 6
vardas4 vardas4 6 4 1 10
vardas5 vardas5 7 4 2 7
```

**Papildyta**
- README.md failas

**Pastebejimas**

Deja, laiku nespejau padaryti vardu rusiavimo ir parasyti tvarkingu komentaru, bet tai padarysiu su kitu commitu arba blogiausiu atveju kitu releas'u.

### [v0.2.1](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v0.2.1)
**Pridėta**
- Pridėtas studentų rūšiavimas pagal vardus

**Papildyta**
- Patobulintas nuskaitymas is failo

Nebereikia pirmu dvieju skaiciu, nurodanciu, kiek bus studentu ir kiek n.d pazymiu jie tures. Dabar kiekvienas studentas gali tureti skirtinga n.d pazymiu kieki, o paskutinis skaicius nurodo egzamino rezultata

```shell
vardas4 vardas 3 6 8 3 6 
vardas3 vardas 5 7 1 4
vardas1 vardas 1 6 10 6 2 6 4 
vardas5 vardas 6 4 5
vardas2 vardas 7 4 2 7
```
### [v0.3](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v0.3)
**Pridėta**
- exception handling
- header ir funkciju failai

**Papildyta**
- updated makefile

### [v0.4](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v0.4)
**Pridėta**
- Ketvirta programos versija
- galimybe generuoti atsitiktinius studentu sarasu failus
- studentu rusiavimas i dvi grupes ir isvedimas i skirtingus failus (vargsiukai ir kietakai)
- programos veikimo laiko matavimas

**Programos veikimo laiko testavimas generuojant skirtingo dydzio duomenu failus**

| Irašų sk.  | Trukmė | 
|----------|-------------|
| 10 | 3ms  |
| 100 | 10ms | 
| 1000 | 42ms | 
| 10000 | 308ms | 
| 100000 | 2930ms | 
| 1000000 | 30431ms | 

### [v0.5](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v0.5)
**Pridėta**
- pridetos persidengiancios funkcijos, todel skaiciavimus galima atlikti su vector, deque ir list tipo konteineriais

**Programos veikimo laiko testavimas naudojant vienodo dydzio duomenu failus, bet skirtingo tipo konteinerius**

| Konteineris | 100000irašų | 500000irašų |
|:---:|:---:|:---:|
| Vector | 2181ms |  10901ms |
| Deque | 2267ms | 11592ms |
| List | 121340ms | error |

 `sitoj versijoje blogai padaryta su list konteineriu, v0.5.1 pataisyta`

### [v0.5.1](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v0.5.1)
**Papildyta**
- buvau pridares nesamoniu su list konteineriu, todel skaiciavimai truko neadekvaciai ilgai, dabar viskas sutvarkyta

| Konteineris | 100000irašų | 500000irašų |
|:---:|:---:|:---:|
| List | 2136ms | 10730ms |

### [v1.0](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v1.0)
**Pridėta**
- antra startegija
- skaiciavimas su std::partition algoritmu

**Programos veikimo laiko testavimas naudojant skirtingo dydzio duomenu failus ir skirtingas strategijas**

**Vector**

| Irašų sk. | 1 strategija | 2 strategija |
|:---:|:---:|:---:|
| 1000 | 26ms | 128ms |
| 10000 | 240ms | 9s |
| 100000 | 2,2s | 897s |
| 1000000 | 22s | Per ilgai |


 **Deque**

| Irašų sk. | 1 strategija | 2 strategija |
|:---:|:---:|:---:|
| 1000 | 24ms | 70ms |
| 10000 | 240ms | 3.5s |
| 100000 | 2,2s | 375s |
| 1000000 | 23s | Per ilgai |


**List**

| Irašų sk. | 1 strategija | 2 strategija |
|:---:|:---:|:---:|
| 1000 | 30ms | 30ms |
| 10000 | 270ms | 212ms |
| 100000 | 2,1s | 2.1s |
| 1000000 | 22s | 21s |

**Skaiciavimu trukme, pritaikius std::partition algoritma vectoriui**

| Irašų sk. | std::partition |
|:---:|:---:|
| 1000 | 26ms | 
| 10000 | 230ms | 
| 100000 | 2,1s | 
| 1000000 | 21s | 

### [PAPILDOMA UZDUOTIS](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v1.1)
**Pridėta**
- raskMinkstus() ir iterpkKietus() funkcijos

| Irašų sk. | raskMinkstus() | iterpkKietus(vector) | terpkKietus(deque) |
|:---:|:---:|:---:|:---:|
| 10000 | 9.2s | 9ms | 13ms |
| 100000 | 894s | 90ms | 150ms |

template <typename T>
class Vector{
private:
    T* elem;        //elementai
    std::size_t sz; //size
    std::size_t cp; //capacity
public:
    /*----CONSTRUCTORS----*/
    Vector() : sz(0), cp(0), elem(nullptr) {}

    //COPY CONSTRUCTOR
    Vector(const Vector& temp) : sz(temp.sz), cp(temp.cp), elem(new T[temp.cp]){
        for (int i=0; i<sz; i++){
            elem[i] = temp.elem[i];
        }
    }

    //MOVE CONSTRUCTOR ?
    Vector(Vector&& temp) : sz(temp.sz), cp(temp.cp), elem(temp.elem){
		temp.elem = nullptr;
		temp.sz = 0;
		temp.cp = 0;
	}
	//INITIALIZER LIST
	Vector(std::initializer_list<T> temp) : sz(temp.size()), cp(temp.size()), elem(new T[temp.size()]) {
        std::copy(temp.begin(), temp.end(), elem);
	}

    //COPY ASSIGNMENT
	Vector<T>& operator=(const Vector& v)
	{
		if (&v == this)
            return *this;
		T* p = new T[v.cp];
		for (auto i = 0; i != v.sz; i++)
			p[i] = v.elem[i];
		delete[] elem;
		elem = p;
		sz = v.sz;
		cp = v.cp;
		return *this;
	}

	//MOVE ASSIGNMENT
	Vector<T>& operator=(Vector&& v)
	{
		if (&v == this)
			return *this;
		delete[] elem;
		elem = v.elem;
		sz = v.sz;
		cp = v.cp;
		v.elem = nullptr;
		v.sz = 0;
		v.cp = 0;
		return *this;
	}

    /*----DESTRUCTOR----*/
    ~Vector() { delete[] elem; }

    //get_allocator                                                                                      TO DO

    /*----ASSIGN----*/
    void assign(std::size_t sz_, const T& value) {
		if (sz < 0) throw std::out_of_range {"Vector::assign - size negali but mazau nei 0"};
		delete[] elem;
		sz = sz_;
		cp = sz_;
		elem = new T[sz];
		std::fill_n(elem, sz, value);
	}

	void assign(std::initializer_list<T> temp) {
		delete[] elem;
		sz = temp.size();
		cp = sz;
		elem = new T[sz];
		std::copy(temp.begin(), temp.end(), elem);
	};

	/*----ELEMENT ACCESS----*/
	T& at(std::size_t i) {
		if (i < 0 || sz < i) throw std::out_of_range {"Vector::at"};
		return elem[i];
	}

	const T& at(std::size_t i) const {
		if (i < 0 || sz < i) throw std::out_of_range {"Vector::at const"};
		return elem[i];
	}

    T& operator[](std::size_t i) {
		if (i < 0 || sz <= i) throw std::out_of_range {"Vector::operator[]"};
		return elem[i];
	}

	const T& operator[](std::size_t i) const {
		if (i < 0 || i<= i) throw std::out_of_range {"Vector::operator[] const"};
		return elem[i];
	}

    T& back() {
        if (sz == 0) throw std::logic_error("Empty container");
        return elem[sz - 1];
    }

	const T& back() const {
	    if (sz == 0) throw std::logic_error("Empty container");
        return elem[sz - 1];
    }

	T& front() {
        if (sz > 0) return elem[0];
        else throw std::logic_error("Empty container");
	}

	const T& front() const {
	    if (sz > 0) return elem[0];
        else throw std::logic_error("Empty container");
    }

	T* data() noexcept { return elem; }

	const T* data() const noexcept { return elem; }

    /*----CAPACITY----*/

    //reik cj su iteratoriais padaryt
	bool empty() const noexcept { return sz == 0; }

	std::size_t size() const noexcept { return sz; };

    std::size_t max_size() const {
        return std::numeric_limits<std::size_t>::max();
    }

	void reserve(std::size_t new_cap) {
		if (cp < new_cap) {
			T *p = new T[new_cap];
			for (auto i = 0; i < sz; i++) {
				p[i] = elem[i];
			}
			delete[] elem;
			elem = p;
			cp = new_cap;
			p = nullptr;
		}
	}

    std::size_t capacity() const noexcept { return cp; };

    void shrink_to_fit(){
        if (sz != cp) {
			T *p = new T[sz];
			for (auto i = 0 ; i < sz; i++) {
				p[i] = elem[i];
			}
			delete[] elem;
			elem = p;
			p = nullptr;
			cp = sz;
		}
    };

    /*----MODIFIERS----*/
    void clear() noexcept {
		for(std::size_t i = 0; i<sz; i++){
            elem[i].~T();
		}
		sz=0;
	}

	//insert                                                                            TO DO
	//emplace                                                                           TO DO
	//erase                                                                             TO DO

	void push_back(const T& value){
		if (sz == cp) {
			reserve((sz+1)*2);
			elem[sz] = value;
			sz++;
		}
		else {
			elem[sz] = value;
			sz++;
		}
	}

    void push_back( T&& value ){
        if (sz == cp) {
			reserve((sz+1)*2);
			elem[sz] = value;
			sz++;
		}
		else {
			elem[sz] = value; //ar std::move(value); ????????????
			sz++;
		}
    }

    //emplace_back                                                                      TO DO

    void pop_back() {
        elem[sz - 1].~T();
        sz--;
    }

    //resize

     void resize(std::size_t count) {
        resize(count, T());
    }

    void resize(std::size_t count, const T& value) {
        if (count < 0)
			throw std::out_of_range{"Vector::resize"};
        if (count > cp) {
            reserve(count);
            for (auto i = sz; i < count; i++) {
                elem[i] = value;
            }
            sz = count;
        }
        if (count < sz) {
            for (auto i = count; i < sz; i++) {
                elem[i].~T();
            }
            T* p = new T[count];
			sz = count;
			for (auto i = 0; i < sz; i++)
			{
				p[i] = elem[i];
			}
			delete[] elem;
			elem = p;
			p = nullptr;
        }
    }

    //swap                                                                               TO DO

    /*----Non-member functions----*/

    //operator==
    //operator!=
    //operator<
    //operator<=
    //operator>
    //operator>=
    //std::swap(std::vector)
    //erase(std::vector)
    //erase_if(std::vector)

    T* begin() noexcept {
        return elem;
    }

    const T* begin() const noexcept {
        return elem;
    }

     T* end() noexcept {
        return elem + sz;
    }

    const T* end() const noexcept {
        return elem + sz;
    }
};
