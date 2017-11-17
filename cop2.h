#include<iostream>
#include<limits.h>
#include<algorithm>
int u[25];//21 11 13 8 22
using namespace std;
int ceg_map::resurface(){

    for(int y=0;y<25;y++)
        u[y]=a[y].cost;
    int c1;
    int ct=0;
    LOOP:int i=mini(u[21],u[11],u[13],u[8],u[22]);
    ct++;
    if(ct==1)
    cout<<dest[i]<<" is the nearest place! Place a 1 if you wanna go ahead with this Eating spot or a 0 if you wanna look for another!"<<endl;
    else
    cout<<dest[i]<<" is the next nearest place! Place a 1 if you wanna go ahead with this Eating spot or a 0 if you wanna look for another!"<<endl;
    cin>>c1;
    if(c1==1)
        return i;
    else
    while(c1!=1&&ct<5){
        u[i]=9999;
        goto LOOP;
    }
    if(ct>4){
        cout<<"You seemed to have said no for everything! :( "<<endl;
        return -1;
    }

}
int ceg_map::mini(int a,int b,int c,int d,int e){
    int min1=std::min(a, std::min(b, std::min(c, std::min(d,e))));
    if(min1==a)
        return 21;
    if(min1==b)
        return 11;
    if(min1==c)
        return 13;
    if(min1==d)
        return 8;
    if(min1==e)
        return 22;

}
void display(){
                                      cout<<"0-Sardar Patel Road Enterance"<<endl;
                                      cout<<"1-Red Building"<<endl;
                                      cout<<"2-Vice Chancellor Office"<<endl;
                                      cout<<"3-ACOE"<<endl;
                                      cout<<"4-Department of Mechanical Engineering"<<endl;
                                      cout<<"5-Aambal Exit"<<endl;
                                      cout<<"6-Department of EEE"<<endl;
                                      cout<<"7-Department of Manufacturing Engineering"<<endl;
                                      cout<<"8-Coffee Hut"<<endl;
                                      cout<<"9-Hostel"<<endl;
                                      cout<<"10-NRI Hostel"<<endl;
                                      cout<<"11-Gurunath Stores"<<endl;
                                      cout<<"12-KVB ATM"<<endl;
                                      cout<<"13-Knowledge Park"<<endl;
                                      cout<<"14-Department of IST"<<endl;
                                      cout<<"15-Department of CSE"<<endl;
                                      cout<<"16-Science & Humanities Block"<<endl;
                                      cout<<"17-Anna University Gym"<<endl;
                                      cout<<"18-Health Center"<<endl;
                                      cout<<"19-Kotturpuram Exit"<<endl;
                                      cout<<"20-CEG Ground"<<endl;
                                      cout<<"21-Cassia Food Court"<<endl;
                                      cout<<"22-Aavin Outlet\0"<<endl;
                                      cout<<"23-ACT Entrance\0"<<endl;
                                      cout<<"24-Department of Printing Tech."<<endl;
                                      cout<<"25-Department of ECE"<<endl;
                                      cout<<"26-Amenities"<<endl;
                                      cout<<"27-Sports Board"<<endl;
                                      cout<<"28-Anna University Library"<<endl;


}
int ceg_map::resurface1(){

    for(int y=0;y<25;y++)
        u[y]=a[y].cost;
    int c1;
    int ct=0;
    LOOP:int i=mini1(u[5],u[0],u[19]);
    ct++;
    if(ct==1)
    cout<<dest[i]<<" is the nearest Exit! Place a 1 if you wanna go ahead with this Exit or a 0 if you wanna look for another!"<<endl;
    else
    cout<<dest[i]<<" is the next nearest Exit! Place a 1 if you wanna go ahead with this Eating spot or a 0 if you wanna look for another!"<<endl;
    cin>>c1;
    if(c1==1)
        return i;
    else
    while(c1!=1&&ct<3){
        u[i]=9999;
        goto LOOP;
    }
    if(ct>2){
        cout<<"You seemed to have said no for everything! :( "<<endl;
        return -1;
    }

}
int ceg_map::mini1(int a,int b,int c){
    int min1=std::min(a, std::min(b,c));
    if(min1==a)
        return 5;
    if(min1==b)
        return 0;
    if(min1==c)
        return 19;
}

