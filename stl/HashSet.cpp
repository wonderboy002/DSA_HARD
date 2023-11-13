#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<string> s;
    s.insert("Nipun");
    s.insert("Vedika");
    s.insert("Tony");
    s.insert("Moltisanti");
    s.insert("Corrado");

    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;

    s.erase("Nipun");
    s.erase("Vedika");
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;

    s.find("Corrado")!=s.end()?cout<<"Key Present":cout<<"Key not Present";
    return 0;
}