#include "imports.h"
#include "Map.h"
#include "student.h"
int main()
{
    srand(time(0));
    Map<int> map_1;
    Map<double> map_2;
    Map<char> map_3;
    Map<Wear> map_4;
    cout << "int:" << endl;
    map_1.search(5);
    map_1.push(1);
    map_1.push(2);
    map_1.push(5);
    map_1.push(4);
    map_1.push(3);
    Map<int>::Map_Iterator i1;
    i1 = map_1._begin();
    //example of iterator using
    cout << "\nExample of using iterator to output elements of map by for loop:";

    //in the statement was talked that sort must be by keys\
		I sorted be id's, but it's insane and unusefull

    for (int i = 0; i < map_1.Size(); i++) {
        cout << " " << *i1;
        ++i1;
    }
    cout << "\n";
    //example of popping
    map_1.pop();
    map_1.pop();
    i1 = map_1._begin();
    for (int i = 0; i < map_1.Size(); i++) {
        cout << " " << *i1;
        ++i1;
    }
    std::cout << "\n";
    i1 = map_1._begin();
    map_1.Insertion_Sort(map_1);
    i1 = map_1._begin();
    for (int i = 0; i < map_1.Size(); i++) {
        cout << " " << *i1;
        ++i1;
    }
    std::cout << "\n";
    i1 = map_1._begin();
    map_1.search(5);
    cout << "double:" << endl;
    map_2.push(1.4);
    map_2.push(2.9);
    map_2.push(3.2);
    map_2.push(4.1);
    map_2.push(5.6);
    Map<double>::Map_Iterator i2;
    i2 = map_2._begin();
    for (int i = 0; i < map_2.Size(); i++) {
        cout << " " << *i2;
        ++i2;
    }
    map_2.pop();
    map_2.pop();
    i2 = map_2._begin();
    for (int i = 0; i < map_2.Size(); i++) {
        cout << " " << *i2;
        ++i2;
    }
    std::cout << "\n";
    i2 = map_2._begin();
    map_2.Insertion_Sort(map_2);
    i2 = map_2._begin();
    for (int i = 0; i < map_2.Size(); i++) {
        cout << " " << *i2;
        ++i2;
    }
    std::cout << "\n";
    i2 = map_2._begin();
    map_2.search(21);
    cout << "char:" << endl;
    map_3.push('z');
    map_3.push('b');
    map_3.push('a');
    map_3.push('n');
    map_3.push('f');
    map_3.push('m');
    Map<char>::Map_Iterator i3;
    i3 = map_3._begin();
    for (int i = 0; i < map_3.Size(); i++) {
        cout << " " << *i3;
        ++i3;
    }
    map_3.pop();
    map_3.pop();
    i3 = map_3._begin();
    for (int i = 0; i < map_3.Size(); i++) {
        cout << " " << *i3;
        ++i3;
    }
    std::cout << "\n";
    i3 = map_3._begin();
    map_3.Insertion_Sort(map_3);
    i3 = map_3._begin();
    for (int i = 0; i < map_3.Size(); i++) {
        cout << " " << *i3;
        ++i3;
    }
    std::cout << "\n";
    i3 = map_3._begin();
    map_3.search(21);
    cout << "Wear :" << endl;
    class Wear a("red jacket", 2.565), b("Blueprint new jacket", 21.6), c("speed shoes", 900.564), d("Gucci bag", 300.5314), f("T-Shirts with golden Sticker", 1000.51);
    map_4.push(a);
    map_4.push(b);
    map_4.push(c);
    map_4.push(d);
    map_4.push(f);
    Map<Wear>::Map_Iterator i4;
    i4 = map_4._begin();
    for (int i = 0; i < map_4.Size(); i++) {
        cout << " " << *i4 << endl;
        ++i4;
    }
    map_4.pop();
    map_4.pop();
    i4 = map_4._begin();
    for (int i = 0; i < map_4.Size(); i++) {
        cout << " " << *i4 << endl;
        ++i4;
    }
    std::cout << "\n";
    i4 = map_4._begin();
    map_4.pasteSort();
    i4 = map_4._begin();
    for (int i = 0; i < map_4.Size(); i++) {
        cout << " " << *i4 << endl;
        ++i4;
    }
    cout << endl;
    i4 = map_4._begin();
    map_4.search(33);
    return 0;
}