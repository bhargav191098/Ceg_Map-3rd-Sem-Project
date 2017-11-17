#include<iostream>
using namespace std;
#include "cop1.h"
#include "cop2.h"
int main(){
    for(int i=0;i<29;i++){
        d[i].b=false;
    }
    int count_for_history=0;
    int choice,source,destination,flag=1,flag1=1;
    ceg_map r;
    int flag3=0;
    cout<<"----------Greetings! Here's goodbye to  long walks around the college to find new places within the  college!----------";
    cout<<endl;
    do{
    cout<<"1- View the map."<<endl<<"2- Give source and destination."<<endl<<"3- Pick a food spot!"<<endl <<"4- Find the nearest Exit!"<<endl<<"5- Look at your previous choices!"<<endl<<"0- exit!"<<endl<<"Choice :"<<endl;
    cin>>choice;
    switch(choice){
    case 1:
        break;
    case 2:
        count_for_history++;
        int source1,destination1;
        cout<<"Here's your choice. Give appropriate choice for source and destination."<<endl;
        display();
        cout<<"--Where are you right now?--"<<endl;
        cin>>source1;
        r.bell(source1);
        cout<<"--Where do you want to go?--"<<endl;
        try{
        cin>>destination1;
        //cout<<"destination1 valuue "<<destination1;
        int k=r.check(source1,destination1);
        //cout<<k;
        if(destination1==source1)
            throw 0;
        //if(destination1>28||source>28)
          //  throw -1;
        else if(destination1!=source1 && k==0)
            throw 1;
        }
        catch(int n){
        if(n==1){
            //cout<<"Overruled";
            r.display_route(destination1);
            //cout<<"--You are already there,buddy!--"<<endl;
            //flag=0;
        }
        else{
            //r.display_route(destination);
            if(n==0)
                cout<<"--You are already there,buddy!--"<<endl;
            //if(n==-1)
              //  cout<<"Enter a value within the college!"<<endl;

        }
        }
       // if(flag==1){
            //r.bell(source);
          //  r.display_route(destination);
        //}
        break;
    case 3:
        count_for_history++;
        display();
        cout<<"--Where are you right now? Select from the list!--"<<endl;
        cin>>source;
        r.bell(source);
        try{
        destination=r.resurface();
        int k=r.check(source,destination);
        if(destination==source&&destination!=-1/*&&(r.check(source,destination)==0)*/)
            throw 0;
        else if(destination!=source&&destination!=-1&&k==0/*&&(r.check(source,destination))*/)
            throw 1;
       // else if(r.check(source,destination))
         //   throw 1;
        //else if(r.check(source,destination)==0)
          //  throw 0;
        }
        catch(int p){

            if(p==1){
            //cout<<"hey";
            flag3=1;
            r.display_route(destination);

            }
            else
                if(p==0)
                cout<<"You are already there buddy!";

        }
        break;
    case 4:
        count_for_history++;
        display();
        cout<<"--Where are you right now? Select from the list!--"<<endl;
        cin>>source;
        r.bell(source);
        try{
        destination=r.resurface1();
        int k=r.check(source,destination);
        if(destination==source&&destination!=-1)
            throw 0;
        else if(destination!=source&&destination!=-1&&k==0)
            throw 1;
        }
        catch(int p){
            if(p==1)
            r.display_route(destination);
            else
                cout<<"You are already there buddy!";

        }
        break;
    case 5:
        if(count_for_history==0)
            cout<<"The memory holds no value! You have a clean history!"<<endl;
        else{
            r.display_memory();
        }
    }
    cout<<endl;
    //cout<<"--Enter 1 to continue 0 to exit!--"<<endl;
    //cin>>choice;
    }while(choice);
return 0;
}
