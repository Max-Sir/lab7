#include "Wear.h"

#include <utility>

void Wear::randomize()
{
	this->cost = 8 + rand() % 150000;
}

Wear::Wear()
{
    name = 'a' + i;
    id = i;
    i++;
    randomize();
}
Wear::Wear(string a, int b)
{
    name = std::move(a);
    id = i;
    i++;
    cost = b;
}
Wear::~Wear()
{
}
Wear& Wear:: operator=(const Wear it) {
    this->name = it.name;
    this->cost = it.cost;
    this->id = it.id;
    return *this;
}
bool operator==(Wear it1, Wear it2) {
    if (it1.name == it2.name && it1.cost == it2.cost) return true;
    else return false;
}
int Wear::i = 1;
ostream& operator<<(ostream& out, const Wear it) {
    out << "name: " << it.name << " cost:" << it.cost << " ID:" << it.id << endl;
    return out;
}

bool operator<(const Wear& a, const Wear& b)
{
    return a.cost < b.cost;
}
