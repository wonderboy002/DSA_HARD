#include<unordered_map>
#include<iostream>
#include<string>
using namespace std;
int main(){
    unordered_map<string,int> ages;
    // ages["Nipun"]=21;
    // ages["Vedika"]=11;
    // ages["Walter"]=46;
    // ages["Tony"]=33;
    // // ages.insert(std::make_pair("nanny",13));


    // for (auto x : ages){
    //     cout<<"Key : "<<x.first<<" value : "<<x.second<<endl;
    // }

    /* Another Way of Working with hashmaps*/
    unordered_map<char,int> asc;
    asc.emplace('a',97);
    asc.emplace('A',65);
    asc.emplace('Z',90);
    asc.emplace('z',122);
    asc.emplace('j',122);
    asc.emplace('k',122);

    for (auto x : asc){
        cout<<x.first<<" : "<<x.second<<endl;
    }

    asc.find('t')!=asc.end()?cout<<"Key Present ":cout<<"Key Not Present ";
    return 0;
}