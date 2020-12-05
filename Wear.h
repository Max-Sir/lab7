// Lab2.26.Wear.cpp
//
#pragma once

#include<iomanip>
#include <utility>
using namespace std;

class Wear  // NOLINT(cppcoreguidelines-special-member-functions)
{
public:
	size_t id;
	string name;
	double_t cost;

	bool operator<(const Wear& other)
	{
		return this->cost < other.cost;
	}

	Wear(const Wear& other);

	inline double_t get_cost() const;

	inline string get_name() const;

	inline void set_name(string x);

	inline void set_cost(double_t x);


	inline size_t get_id() const;

	static size_t count;
	inline Wear(string name = "golden ring", double_t cost = 100.0 + rand() % 180);
	inline friend ostream& operator<<(ostream&, const Wear&);
	friend class Customer;
	Wear& operator=(const Wear& other)
	{
		this->id = other.id;
		this->cost = other.cost;
		this->name = other.name;
		return *this;
	}

	friend bool operator==(Wear first, Wear other);
	inline ~Wear();
};

inline Wear::Wear(const Wear& other)
{
	this->id = other.id;
	this->cost = other.cost;
	this->name = other.name;
}

inline double_t Wear::get_cost() const
{
	return this->cost;
}

inline string Wear::get_name() const
{
	return this->name;
}

inline void Wear::set_name(string x)
{
	this->name = std::move(x);
}

inline void Wear::set_cost(double_t x)
{
	this->cost = x;
}

inline size_t Wear::get_id() const
{
	return this->id;
}

inline Wear::Wear(string name, double_t cost) : id(++count+rand()% 150), name(std::move(name)), cost(cost)
{
	srand(time(NULL));
}

inline Wear::~Wear() = default;  // NOLINT(clang-diagnostic-deprecated-copy-dtor)

inline ostream& operator<<(ostream & out, const Wear & w)
{
	string decor = "-";
	for (int i = 0; i < 16; ++i)
	{
		decor += decor[0];
	}
	out << decor << "\nid: " << w.id << "\nname: " << w.name << "\ncost: " << w.cost << "$" << endl << decor << endl;
	return out;
}

inline bool operator==(Wear first, Wear other)
{
	return first.cost == other.cost && first.name == other.name;
}

class Customer
{
public:
	static void set_cost(Wear& w, double_t cost)
	{
		w.cost = cost;
	}
};

size_t Wear::count = 1;
