#include <iostream> 
#include <string>
using namespace std;

// Efficiency test

// cant edit, makes copies
string concat_classic(string a, string b){
    return a+b;
}

// can edit, doesnt make copies
string concat_pointers(string& a, string& b){
    return a+b;
}

// cant edit, doesnt make copies
// this is the desired behaviour
string concat_const_pointers(const string& a,const string& b){
    return a+b;
}

int main(){
string a = "mono_";
string b = "aek";
string c;

c = concat_const_pointers(a,b);
cout << c ;
return 0;
}

// classic = 0.71
// pointers = 0.66
// constant pointers = 0.661