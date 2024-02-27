#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class client {
private:
	string nume;
	int idTatuaj;
	int pretTatuaj;
	int idClient;
public:
	//constructor fara parametrii
	client() {

		this->nume = " ";
		this->idClient = 0;
		this->idTatuaj = 0;
		this->pretTatuaj = 0;
	}

	//constructor cu parametrii
	client(string nume, int idClient, int idTatuaj, int pretTatuaj)
	{
		this->nume = nume;
		this->idClient = idClient;
		this->idTatuaj = idTatuaj;
		this->pretTatuaj = pretTatuaj;
	}
	//constructor de copiere

	client(const client& aux)
	{
		this->nume = aux.nume;
		this->idClient = aux.idClient;
		this->idTatuaj = aux.idTatuaj;
		this->pretTatuaj = aux.pretTatuaj;
	}
	//supraincarcare =

	client& operator =(const client& c)
	{
		this->nume = c.nume;
		this->idClient = c.idClient;
		this->idTatuaj = c.idTatuaj;
		this->pretTatuaj = c.pretTatuaj;

		return*this;
	}

	//gettere
	string getNume()
	{
		return this->nume;
	}
	int getPret()
	{
		return this->pretTatuaj;
	}

	int getIDtatuaj()
	{
		return this->idTatuaj;
	}

	int getIDclient()
	{
		return this->idClient;
	}
	//setter
	void setNume(string nume)
	{
		this->nume = nume;
	}

	void setPret(int pretTatuaj)
	{
		this->pretTatuaj = pretTatuaj;
	}

	void setIDtatuaj(int idTatuaj)
	{
		this->idTatuaj = idTatuaj;
	}

	void setIDclient(int idClient)
	{
		this->idClient = idClient;
	}

	// ostream/istream/virtualizare 

	virtual void display(ostream& os)
	{
		os << "\t\tNumele clientului: " << this->nume << endl;
		os << "\t\tId-ul clientului: " << this->idClient << endl;
		os << "\t\tId-ul tatuajului: " << this->idTatuaj << endl;
		os << "\t\tPretul tatuajului: " << this->pretTatuaj << endl;
	}
	friend ostream& operator<<(ostream& os, client& cl)
	{
		cl.display(os);
		return os;
	}


	virtual void read(istream& is)
	{
		cout << "\t\tNume client: ";
		is >> this->nume;

		cout << "\t\tId client: ";
		is >> this->idClient;

		cout << "\t\tCe id are tatuajul pe care il doreste clientul: ";
		is >> this->idTatuaj;

		cout << "\t\tCe pret are tatuajul: ";
		is >> this->pretTatuaj;

		cout << endl;
	}
	friend istream& operator>>(istream& is, client& cl) {
		cl.read(is);
		return is;
	}

	//supraincarcarea operatorului == (pt clasa Lista)
	bool operator==(const client& alt)
	{
		return this->nume == alt.nume &&
			this->idClient == alt.idClient &&
			this->idTatuaj == alt.idTatuaj &&
			this->pretTatuaj == alt.pretTatuaj;
	}

	//destructor 
	~client() {}


};

class tatuajFinalizat : public client
{
private:
	bool final;
public:
	//constructori 
	tatuajFinalizat() : client()
	{
		this->final = false;
	}

	tatuajFinalizat(string nume, int idClient, int idTatuaj, int pretTatuaj, bool final) : client(nume, idClient, idTatuaj, pretTatuaj)
	{
		this->final = final;
	}

	tatuajFinalizat(const client& client, bool final) : client(client)
	{
		this->final = final;
	}

	//getter si setter
	bool getFinal()
	{
		return final;
	}

	void setFinal(bool final)
	{
		this->final = final;
	}

	//supraincarcare =
	tatuajFinalizat& operator =(const tatuajFinalizat& tf)
	{
		client::operator=(tf);
		this->final = tf.final;
		return*this;
	}

	//virtualizare display/read
	void read(istream& is) override
	{
		client::read(is);
		cout << "\t\t(read) Stare finalizare: ";
		is >> this->final;
	}

	friend istream& operator>>(istream& is, tatuajFinalizat& tf)
	{
		tf.read(is);
		return is;
	}

	void display(ostream& os) override
	{
		client::display(os);
		os << "\t\t(display) Stare finalizare: " << this->final << endl;
		os << endl;
	}

	friend ostream& operator<<(ostream& os, tatuajFinalizat& tf)
	{
		tf.display(os);
		return os;
	}




	//destructor 
	~tatuajFinalizat() {}


};

class tatuajProgramat : public client
{
private:
	bool programat;
public:
	//constructori
	tatuajProgramat() : client()
	{
		this->programat = false;
	}

	tatuajProgramat(string nume, int idClient, int idTatuaj, int pretTatuaj, bool programat) : client(nume, idClient, idTatuaj, pretTatuaj)
	{

		this->programat = programat;
	}

	tatuajProgramat(const client& client, bool programat) : client(client)
	{
		this->programat = programat;

	}

	//getter si setter
	bool getProg()
	{
		return programat;
	}

	void setProg(bool programat)
	{
		this->programat = programat;
	}

	//supraincarcare =
	tatuajProgramat& operator =(const tatuajProgramat& tp)
	{
		client::operator=(tp);
		this->programat = tp.programat;
		return*this;
	}

	//virtualizare display/read 
	void read(istream& is) override
	{
		client::read(is);
		cout << "\t\t(read) Stare programare: ";
		is >> this->programat;
	}

	friend istream& operator>>(istream& is, tatuajProgramat& tf)
	{
		tf.read(is);
		return is;
	}

	void display(ostream& os) override
	{
		client::display(os);
		os << "\t\t(display) Stare programare: " << this->programat << endl;
		os << endl;
	}

	friend ostream& operator<<(ostream& os, tatuajProgramat& tp)
	{
		tp.display(os);
		return os;
	}
	//destructor 
	~tatuajProgramat() {}

};

template <typename T> class listaClienti
{
private:
	vector<T> lista;
public:
	//constructor 

	listaClienti() {}

	//supraincarcare += / -=

	listaClienti& operator+=(const T& client)
	{
		lista.push_back(client);
		return *this;
	}

	listaClienti& operator-=(const T& client)
	{
		auto i = find(lista.begin(), lista.end(), client);
		if (i != lista.end()) {
			lista.erase(i);
		}
		return *this;
	}
	//supraincarcare afisare

	friend ostream& operator<<(ostream& os, listaClienti& lc)
	{
		for (auto i = lc.lista.begin(); i != lc.lista.end(); i++)
		{
			os << *i;
			cout << endl;
		}

		return os;
	}

	//operatorul de acces pe baza de index, pentru citirea unui element din vector de la o pozitie data
	T& operator[](size_t index)
	{
		if (index < lista.size())
		{
			return lista[index];
		}
		else
		{
			cerr << "index out of bounds";
		}
	}

	//serializare in fiseirul binar
	void serialize(const string& fisierLista) {
		ofstream file(fisierLista, ios::binary | ios::out);
		if (!file.is_open()) {
			cerr << "Eroare la deschiderea fisierului pt scriere" << endl;
			return;
		}

		size_t size = lista.size();
		file.write(reinterpret_cast<char*>(&size), sizeof(size_t));

		for (const T& client : lista) {
			file.write(reinterpret_cast<const char*>(&client), sizeof(T));
		}

		file.close();
	}

	void deserialize(const string& fisierLista) {
		ifstream file(fisierLista, ios::binary | ios::in);
		if (!file.is_open()) {
			cerr << "Eroare la deschiderea fisierului pt citire" << endl;
			return;
		}

		size_t size;
		file.read(reinterpret_cast<char*>(&size), sizeof(size_t));

		lista.clear();
		lista.resize(size);

		for (T& client : lista) {
			file.read(reinterpret_cast<char*>(&client), sizeof(T));
		}

		file.close();
	}

	//destrcutor
	~listaClienti() {}
};

int main() {
	//apelarea constructorului fara parametrii

	cout << endl;
	cout << "Constructori fara parametrii" << endl;
	cout << endl;
	client clientfaraparam;
	cin >> clientfaraparam;
	cout << endl;
	cout << "\t\tclient fara param:\n" << clientfaraparam << endl;
	cout << "==============================================================================================================" << endl;
	cout << endl;

	//apelarea constructorului cu parametrii

	client clientparam("john", 1, 101, 50);
	tatuajFinalizat finalparam("john", 1, 101, 50, true);
	tatuajProgramat programparam("john", 1, 101, 50, false);

	cout << "Constructori cu parametrii\n";
	cout << endl;
	cout << "\t\tclient param:\n" << clientparam << endl;
	cout << endl;
	cout << "\t\ttatuaj final param:\n" << finalparam << endl;
	cout << "\t\ttatuaj programat param:\n" << programparam << endl;


	//apelarea constructorilor de copiere

	client clientcopy(clientparam);
	tatuajFinalizat finalcopy(clientparam, true);
	tatuajProgramat progcopy(clientparam, false);
	cout << "==============================================================================================================" << endl;
	cout << endl;
	cout << "Constructor de copiere " << endl;
	cout << endl;
	cout << clientcopy << endl;
	cout << endl;
	cout << finalcopy << endl;
	cout << progcopy << endl;
	cout << "==============================================================================================================" << endl;
	cout << endl;

	//apelare operator =

	client c1("alex", 2, 102, 600);
	client c2;
	c2 = c1;
	cout << "Apelare operator '='" << endl;
	cout << endl;
	cout << c2;
	cout << endl;
	cout << "==============================================================================================================" << endl;
	cout << endl;


	//getter, setter
	cout << "Getter/Setteri " << endl;
	cout << endl;
	cout << "\t\tgetter nume: " << c1.getNume() << endl << endl;
	c1.setNume("teo");
	c1.setIDclient(103);
	c1.setIDtatuaj(3);
	c1.setPret(1000);
	cout << c1;
	cout << endl;
	cout << "==============================================================================================================" << endl;
	cout << endl;

	//clasa vectorului
	cout << "Vector STL/+=/-=" << endl;
	cout << endl;
	client c10("alex", 2, 102, 600);
	client c11("andrei", 2, 102, 600);
	client c12("vali", 2, 102, 600);

	listaClienti<client> lc;

	lc += c10;
	lc += c11;
	lc += c12;

	cout << "\t\tlista clienti: " << endl;
	cout << endl;
	cout << lc;
	cout << "-------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "\t\tlista fara clientul: " << c11.getNume() << endl;
	cout << endl;
	lc -= c11;
	cout << lc;
	cout << endl;
	cout << "==============================================================================================================" << endl;
	cout << endl;

	cout << endl;
	cout << "Supraincarcarea operatorului '[]' " << endl;
	cout << endl;
	cout << "\t\tdati indexul din lista pe care il doriti afisat: ";
	unsigned int index;
	cin >> index;
	cout << endl;
	cout << lc[index] << endl;
	cout << "==============================================================================================================" << endl;
	cout << endl;

	//serializare/deserializare
	listaClienti<client> lcl;

	lcl.serialize("fisierListaClienti.bin");

	lcl = listaClienti<client>();

	lcl.deserialize("fisierListaClienti.bin");
	cout << endl;
	cout << "Serializare/Deserializare din fisierul binar" << endl;
	cout << endl;
	cout << "\t\tDupa deserializare:" << endl;
	cout << endl;
	cout << lc << endl;

}