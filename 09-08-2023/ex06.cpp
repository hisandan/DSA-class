#include <iostream>
#include <set>
using namespace std;

int main(){
    set<string> conjunto00 {"iphone", "android", "basic", "landline"};
    set<char>   conjunto01 {'a', 'b', 'c', 'd'};
    set<int>   conjunto02 {1,3,4,5};
    int i=5;

    // for (int i=0; i<4; i++)
    for (auto it=conjunto00.begin(); it!=conjunto00.end(); it++, ++i){
        conjunto02.insert('a'+i);
    }

    cout << "Tamaño del conjunto 00: " << conjunto00.size() << endl;
    cout << "Tamaño del conjunto 01: " << conjunto01.size() << endl;
    cout << "Tamaño del conjunto 02: " << conjunto02.size() << endl;
    return 0;
}