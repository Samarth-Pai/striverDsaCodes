#include<iostream>
#include<vector>
using namespace std;
int main(){
    // Declaration of vector
    vector<int> v;
    int a=2,b=3;
    v.push_back(a); // creats a copy of object and appends to the vector
    v.emplace_back(b); // constructs the object and append it directly to the vector instead of calling copy constructor
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<' ';

    vector<pair<int,int>> v1;
    v1.push_back({1,3});
    v1.emplace_back(4,6);
    cout<<endl;

    int n,m;
    cout<<"Enter the size of vector with instance(-1 if want to filled with 0): ";
    cin>>n>>m;
    cout<<"Elements of the vectors: ";
    if(m==-1){
        vector<int>v2(n);
        for(int i=0;i<n;i++)
            cout<<v2[i]<<' ';
    }
    else{
        vector<int>v2(n,m);
        for(int i=0;i<n;i++)
            cout<<v2[i]<<' ';
    }

    vector<int>v3(5,10);
    vector<int>v4(v3); // copying vector v3

    cout<<"\nFor loop(aam zindagi): ";
    for(int i=0;i<v4.size();i++)
        cout<<v4[i]<<' ';

    cout<<"\nFor loop(mentos zindagi): ";
    for(auto ele:v4) // auto is the datatype of the element which is detected automatically, we can explicitally replace auto by int
        cout<<ele<<' ';
    
    // iterators - used to access memory address of a vector
    cout<<endl<<"Iterators\n";
    vector<int>v5 = {1,x     3, 5, 8, 10};
    // v5.begin() is address of index 0
    // v5.end() is address of index n
    vector<int>::iterator it4 = v5.begin();
    it4++;
    cout<<*it4<<endl; // prints 2nd element
    it4+=2;
    cout<<*it4<<endl;
    cout<<*(v5.end()-1);

    // vector<int>::iterator it42 = v5.end(); // moves pointer to nth index
    // vector<int>::iterator it43 = v5.rend(); // moves pointer to -1th index and reverse
    // vector<int>::iterator it44 = v5.rbegin(); // moves pointer to (n-1)th index and reverse

    // vector erase function from m to n+1 where m and n are pointers
    cout<<"\nElements before erasing: ";
    for(auto it:v5)
        cout<<it<<' ';
    v5.erase(v5.begin()+1); // deleting single element
    v5.erase(v5.begin()+2,v5.begin()+4); // deleting multple instances
    cout<<"\nElements after erasing: ";
    for(auto it:v5)
        cout<<it<<' ';
    cout<<endl;

    // Insertion
    v5.insert(v5.begin()+1,5); // inserting single element
    v5.insert(v5.begin()+2,3,6); // inserting mutiple instances
    vector<int>breadPiece{89,199,112, 141, 58};
    v5.insert(v5.begin()+5,breadPiece.begin(),breadPiece.begin()+3); // addition of vector in middle
    cout<<"Elements after insertion: ";
    for(auto it: v5)
        cout<<it<<' ';
    cout<<endl;

    // miscallenous operations
    v5.pop_back(); // removing the last element of the vector
    v5.swap(v4); // swapping two vectors

    v5.clear(); // erases the entire vector

    cout<<"\nElements after pop back: ";
    for(auto i:v4)
        cout<<i<<' ';

    cout<<"\nIs v5 empty? "<<v5.empty();
    cout<<endl;
}