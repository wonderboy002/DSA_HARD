#include <bits/stdc++.h>
using namespace std;
void print_permutations(string &str,int i){
    if (i>=str.length()){
        cout<<str<<" ";
        return;
    }

    for (int j=i;j<str.length();j++){
        swap(str[i],str[j]);
        print_permutations(str,i+1);
        swap(str[i],str[j]);
    }
}
int main()
{
    string str="abcd";
    cout<<"All permutations of string are : "<<endl;
    print_permutations(str,0);
    return 0;
}