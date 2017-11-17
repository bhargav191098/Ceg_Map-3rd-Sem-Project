#include<stdio.h>
#include<iostream>
#include<limits.h>
#include<string.h>
int time1=0;
using namespace std;
struct memo{
char source1[55];
char destination1[55];
char ro[29][55];
bool b;
int routeend;
int cost;
int time;
}d[28];
struct node{
    int cost,val,from;
}a[29];
class ceg_map{
private:
          int source;
          static int graph[29][29];
          static char dest[29][105];
           public:
        void bell(int n);
        void display_route(int m);
        int resurface();
        int resurface1();
        int mini(int,int,int,int,int);
        int mini1(int,int,int);
        int check(int,int);
        void display_memory();
        struct memo* timesort(struct memo*);

};
int ceg_map::graph[29][29]=
                   {{0,350,200,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,270,200,0,0,0,0,0},
                   {350,0,0,0,0,0,110,0,0,0,0,0,0,0,0,0,80,0,0,0,0,150,0,0,0,0,0,0,0},
                   {200,0,0,180,0,0,260,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,180,0,300,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,300,0,450,210,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,450,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,110,260,0,210,0,0,50,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,50,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,120,0,0,0},
                   {0,0,0,0,0,0,0,100,0,60,0,0,0,0,120,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,60,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,20,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,100,0,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0,80,0,50,51,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0,0,50,0,0,0,0,0,0,0,0,0,0,0,0,0,0,140,0,0},
                   {0,0,0,0,0,0,0,0,0,0,0,51,0,0,35,0,0,0,0,0,0,0,0,0,50,0,100,0,0},
                   {0,0,0,0,0,0,0,0,120,0,0,0,0,35,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,25,0,10,0,0,0,0,0,0,0,0,70,0,0,0},
                   {0,80,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,400,0,0,0,0,0,0,0,80,0,0},
                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,400,0,270,0,0,0,0,0,0,0,380,0},
                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,270,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,60,0,0,0,0,0,0,70},
                   {0,150,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,60,0,130,0,0,0,0,0,0},
                   {270,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,130,0,200,0,0,0,0,0},
                   {200,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,200,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,20,0,0,0,50,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,70,0,0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0,0,0,140,100,0,0,0,80,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,380,0,0,0,0,0,0,0,0,0,60},
                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70,0,0,0,0,0,0,60,0},
                   };

                char ceg_map::dest[29][105]={"Sardar Patel Road Enterance\0",
                                      "Red Building\0",
                                      "Vice Chancellor Office\0",
                                      "ACOE\0",
                                      "Department of Mechanical Engineering\0",
                                      "Aambal Exit\0",
                                      "Department of EEE\0",
                                      "Department of Manufacturing Engineering\0",
                                      "Coffee Hut\0",
                                      "Hostel\0",
                                      "NRI Hostel\0",
                                      "Gurunath Stores\0",
                                      "KVB ATM\0",
                                      "Knowledge Park\0",
                                      "Department of IST\0",
                                      "Department of CSE\0",
                                      "Science & Humanities Block\0",
                                      "Anna University Gym\0",
                                      "Health Center\0",
                                      "Kotturpuram Exit\0",
                                      "CEG Ground\0",
                                      "Cassia Food Court\0",
                                      "Aavin Outlet\0",
                                      "ACT Entrance\0",
                                      "Department of Printing Tech.\0",
                                      "Department of ECE\0",
                                      "Amenities\0",
                                      "Sports Board\0",
                                      "Anna University Library\0",
                                    };


void ceg_map::bell(int n){
    source=n;
    int i,j,k,c=0,temp;
    a[n].cost=0;
    a[n].from=0;
    a[n].val=0;
    for(i=0;i<29;i++){
        if(i!=n){
            a[i].from=0;
            a[i].cost=INT_MAX;
            a[i].val=0;
        }
    }
        while(c<29){
            int minu=999;
            for(i=0;i<29;i++){
                if((minu>a[i].cost)&&(a[i].val==0)){
                    minu = a[i].cost;
                }
                else
                    continue;
            }
            for(i=0;i<29;i++){
                if((minu == a[i].cost)&&(a[i].val==0))
                    break;
                else
                    continue;
            }
            temp=i;
            for(k=0;k<29;k++){
                if(graph[temp][k]!=0&&graph[temp][k]+a[temp].cost<a[k].cost){
                    a[k].cost = graph[temp][k]+a[temp].cost;
                    a[k].from=temp;
                }
                else
                    continue;
            }
            a[temp].val=1;
            c++;
        }
}
void ceg_map::display_route(int m){
        //cout<<"At start.. M value "<<m;

        int index;
        int i,j=0,k=m,l=0,u;
        char route[29][55];
        while(a[m].from!=source){
            m = a[m].from;
            strcpy(route[j++],dest[m]);
            l++;
        }
        /*for(u=0;u<29;u++){
            cout<<"hi2";
            index=((source+m)+u)%29;
            if(d[index].b==false){
                strcpy(d[index].source1,dest[source]);
                for(int y=0;y<j;y++){
                    strcpy(d[index].ro[y],route[y]);
                }
                cout<<"hi3";
                d[index].routeend=l;
                d[index].b=true;
                strcpy(d[index].destination1,dest[m]);
                d[index].cost=a[k].cost;
                break;
            }
        }*/
        //cout<<"m value "<<k;
        index=((source*29)+(k*31))%29;
        //cout<<source*29<<" "<<k*31;
        //cout<<"Hash value"<<index<<" ";
        if(d[index].b==false){
                time1++;
                cout<<endl;
                cout<<"Storing in memory...."<<endl;
                strcpy(d[index].source1,dest[source]);
                for(int y=l-1;y>=0;y--){
                    strcpy(d[index].ro[y],route[y]);
                }
                d[index].time=time1;
                d[index].routeend=l;
                d[index].b=true;
                //cout<<d[index].b;
                strcpy(d[index].destination1,dest[k]);
                //cout<<"Destination copied in hash"<<d[index].destination1;
                d[index].cost=a[k].cost;
            }
        //cout<<"this is printing as usual";
        cout << "Route : " << dest[source]<<"-->";
        for(i=l-1;i>=0;i--)
            cout << " " << route[i]<<"-->";
        cout << " " << dest[k];
        cout << "--------" << a[k].cost<<" meters";
}
int ceg_map::check(int source2,int destination2){
    //cout<<"From check"<<endl;
    int index7=((source2*29)+(destination2*31))%29;
    //cout<<"Hash value in check "<<index7<<" ";
    int l=d[index7].routeend;
    //for(int u=0;u<29;u++){
      //  index=((source2+destination2)+l)%12;

        if(d[index7].b==true){
            cout<<endl;
            cout<<"Retrieving from the memory archives....."<<endl;
            //for(int i=0;i<20;i++)
                //cout<<"..";
            cout << "Route : " << d[index7].source1<<"-->";
        for(int i=0;i<=d[index7].routeend-1;i++)
            cout << " " << d[index7].ro[i]<<"-->";
        cout << " " << d[index7].destination1;
        cout << "--------" << d[index7].cost<<" meters";
        return 1;
        }
    //}
    return 0;
}
void ceg_map::display_memory(){
    int j;
    /*for(j=0;j<29;j++){
        if(d[j].b==true){
            cout<<d[j].source1<<"---"<<d[j].destination1;
            cout<<endl;
        }
    }*/

    struct memo* g=d;
    g=timesort(g);
    int co=1;
    cout<<"--IN CHRONOLOGICAL ORDER--"<<endl;
    for(j=0;j<28;j++){
        if(g[j].b==1){
        cout<<co++<<". "<<g[j].source1<<"---"<<g[j].destination1;
        cout<<endl;
        }
    }
}
struct memo* ceg_map::timesort(struct memo* g){
int i,j=0;
struct memo y1[29];
for(i=0;i<29;i++){
    if(g[i].b==true){
        y1[j++]=g[i];
}
}
int n=j;
for(i=0;i<n;i++){
    if(y1[i].time>y1[i+1].time){
        struct memo temp;
        temp=y1[i];
        y1[i]=y1[i+1];
        y1[i+1]=temp;
    }
}
return y1;
}
