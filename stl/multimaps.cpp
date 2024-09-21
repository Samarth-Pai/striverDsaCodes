#include<iostream>
#include<map>
using namespace std;
int main(){
    multimap<int,string>mm; // same as set but it can have duplicate keys so map[i] cannot be used
    mm.emplace(1,"one");
    mm.insert({1,"two"});
    mm.emplace(1,"three");
    mm.emplace(2,"four");
    mm.emplace(2,"five");
    auto = mm.equal_range(2); // returns an iterator of pairs whose address of key and value are given
    for(auto i = it.first;i!=it.second;i++)
        cout<<i->first<<i->second<<' ';
    cout<<endl;
}