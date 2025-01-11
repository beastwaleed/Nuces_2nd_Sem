//Overloading << Operator 

#include<iostream>
#include<string>
using namespace std;

class YoutubeChannel{
    public:
    string name;
    int Subscribers;

    YoutubeChannel(string name, int Subscribers){
        this->name=name;
        this->Subscribers=Subscribers;
        
    }

};

    void operator <<(ostream &print , YoutubeChannel &ytchannel){
        print<<"Name: "<<ytchannel.name<<endl;
        print<<"Subscriber Count: "<<ytchannel.Subscribers<<endl;
        
    }


int main(){
   
    YoutubeChannel yt1("Datalance",20000);
    YoutubeChannel yt2("Second Channel",50000);
    cout<<yt1; //first method to invoke operator overloading function in main
    cout<<"-------------------------------"<<endl;
    operator<<(cout,yt2); //second method to invoke operator overloading function in main


}