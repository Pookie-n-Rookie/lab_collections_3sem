#include<iostream>
#include<math.h>
using namespace std;

class Devices 
{
   int x,y,uid,r;
   public:
   Devices()
   {
       this->x = 0;
       this->y = 0;
       this->uid = 0;
       this-> r = 0;
   }

   void get(int a, int b, int c, int d)
   {
       this->x = a;
       this->y = b;
       this->uid = c;
       this-> r = d;
   }

   void Neighbour(Devices a, Devices b)
   {
       double dist = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
       if(dist<r)
       cout << b.uid << " ";
   }

   int getUID()
   {
       return this->uid;
   }
    
};
int main()
{
    Devices arr[10];
    
    for(int i = 0; i < 10; i++)
    {
        int a,b,d;
        cout << "Enter co-ordinates of the " << i+1 << " device : ";
        cin >> a >> b;
        cout << "Enter transmission range of the " << i+1 << " device : ";
        cin >> d;
        arr[i].get(a,b,i+1,d);
    }

    for(int i = 0; i < 10; i++)
    {
        cout << "Neighbours of " << arr[i].getUID() << " are : ";
        for(int j = 0; j < 10; j++)
        {
            if(i!=j)
            {
                arr[i].Neighbour(arr[i],arr[j]);
            }

        }
        cout << "\n";
    }
   return 0;
}
