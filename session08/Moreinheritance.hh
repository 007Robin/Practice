class Base{
	public:
		int pub_mem();
	protected:
			int prot_mem;
	private:
			char priv_mem;
};

class Sneaky : public Base {        
	friend void clobber(Sneaky &s) {
		s.j = s.prot_mem = 0;     
	}
	friend void clobber(Base &b) { 
		b.prot_mem = 0;          
	}
	int j;                      
	void memfcn(Base &b) { b = *this; }
};
//Public private protected
struct Pub_Derv : public Base{
	int f() {
		return prot_mem;
	}
	char g() {
		return priv_mem;     
	}
	void memfcn(Base &b) { b = *this; }
};
struct Priv_Derv : private Base{
	
	int f1() const {
		return prot_mem;    
	}
	void memfcn(Base &b) { b = *this; }
};
struct Prot_Derv : protected Base {
	void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Public : public Pub_Derv {
	int use_base() {
		return prot_mem;    
	}
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv {
	int use_base() {
		return prot_mem;   
	}
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Protected : protected Prot_Derv {
	void memfcn(Base &b) { b = *this; }
};
