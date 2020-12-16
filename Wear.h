#pragma once
#include "libs.h"
class Wear
{
public:
    static int i;
    int id;
    std::string name;
    int cost;
public:

    void randomize();
    Wear();
    Wear(std::string a, int b);
    ~Wear();
	bool operator<(Wear& other)
	{
        return this->cost < other.cost;
	}
    Wear& operator=(const Wear it);
    friend bool operator==(Wear it1, Wear it2);
    friend std::ostream& operator<<(std::ostream& out, const Wear it);
    friend bool operator<(const Wear& a, const Wear& b);
};
