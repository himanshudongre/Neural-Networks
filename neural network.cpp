#include <iostream>
using namespace std;
int n,size;
void hebbian();
void percept();
void delta();
class inputs
{
   public:
   float *data;
  inputs()
  {
      data=new float[size];
  }

};
int main()
{
    int ch;
    while(1)
    {
        cout<<endl<<endl;
        cout<<" Welcome To Neural Networks \n ";
        cout<<"Himanshu Dongre 7th Sem CE\n";
        cout<<"*---------------------------*\n";
        cout<<"|Menu                       |\n";
        cout<<"|----                       |\n";
        cout<<"|1.Hebbian                  |\n";
        cout<<"|2.Perceptron               |\n";
        cout<<"|3.Delta                    |\n";
        cout<<"|4.Exit                     |\n";
        cout<<"*---------------------------*\n";
        cout<<"Enter your choice:";
        cin>>ch;

        switch(ch)
        {

            case 1:hebbian();
                   break;
            case 2:percept();
                   break;
            case 3:delta();
                   break;
            case 4:exit(0);
            default:cout<<"WRONG CHOICE!!!TRY AGAIN\n";

        }

    }


}

void hebbian()
{
    int sgn;
    float net,c;
    cout<<"Enter no. of inputs:\n";
    cin>>n;
    cout<<"\nEnter size of weights:";
    cin>>size;
    cout<<"\nEnter initial weight:";
    float *w=new float[size];
    class inputs *x=new inputs[n];
    for(int i=0;i<size;i++)
     {
         cin>>w[i];
     }


    for(int i=0;i<n;i++)
     {

         cout<<"Enter Input "<<i+1<<": ";
          for(int j=0;j<size;j++)
           cin>>x[i].data[j];
     }

     cout<<"Enter learning constant:";
     cin>>c;

     for(int i=0;i<n;i++)
     {
         net=0;
         for(int j=0;j<size;j++)
          net +=(x[i].data[j])*w[j];
          cout<<"\n\nnet"<<i+1<<"="<<net<<" \n\n";

          if(net>=0)
          sgn=1;
          else
          sgn=-1;


          for(int k=0;k<size;k++)
           {
               w[k]=w[k]+(sgn*c*x[i].data[k]);
           }

           for(int k=0;k<size;k++)
           cout<<"Weight"<<k+1<<"="<<w[k]<<" ";
           cout<<endl;
     }

    cout<<"\nFINAL WEIGHT MATRIX IS : ";
    for(int i=0;i<size;i++)
     cout<<endl<<w[i]<<endl;
    delete[] w;
    delete[] x;

}

void percept()
{
    int sgn;
    float net,c;
    cout<<"Enter no. of inputs:\n";
    cin>>n;
    cout<<"\nEnter size of weights:";
    cin>>size;
    cout<<"\nEnter initial weight:";
    float *w=new float[size];
    int *d=new int[n];
    class inputs *x=new inputs[n];
    for(int i=0;i<size;i++)
     {
         cin>>w[i];
     }


    for(int i=0;i<n;i++)
     {

         cout<<"Enter Input "<<i+1<<": ";
          for(int j=0;j<size;j++)
           cin>>x[i].data[j];
         cout<<"\nEnter Desired Output"<<i+1<<": ";
         cin>>d[i];

     }

     cout<<"Enter learning constant:";
     cin>>c;

     for(int i=0;i<n;i++)
     {
         net=0;
         for(int j=0;j<size;j++)
          net +=(x[i].data[j])*w[j];
          cout<<"\n\nnet"<<i+1<<"="<<net<<" \n\n";

          if(net>=0)
          sgn=1;
          else
          sgn=-1;


          for(int k=0;k<size;k++)
           {
               w[k]=w[k]+((d[i]-sgn)*c*x[i].data[k]);
           }

           for(int k=0;k<size;k++)
           cout<<"Weight"<<k+1<<"="<<w[k]<<" ";
           cout<<endl;
     }

    cout<<"\nFINAL WEIGHT MATRIX IS : ";
    for(int i=0;i<size;i++)
     cout<<endl<<w[i]<<endl;
   delete[] w;
   delete[] x;

}


void delta()
{
    int sgn;
    float net,dernet,c;
    cout<<"Enter no. of inputs:\n";
    cin>>n;
    cout<<"\nEnter size of weights:";
    cin>>size;
    cout<<"\nEnter initial weight:";
    float *w=new float[size];
    int *d=new int[n];
    class inputs *x=new inputs[n];
    for(int i=0;i<size;i++)
     {
         cin>>w[i];
     }


    for(int i=0;i<n;i++)
     {

         cout<<"Enter Input "<<i+1<<": ";
          for(int j=0;j<size;j++)
           cin>>x[i].data[j];
         cout<<"\nEnter Desired Output"<<i+1<<": ";
         cin>>d[i];

     }

     cout<<"Enter learning constant:";
     cin>>c;

     for(int i=0;i<n;i++)
     {
         net=0;
         for(int j=0;j<size;j++)
          net +=(x[i].data[j])*w[j];
          cout<<"\n\nnet"<<i+1<<"="<<net<<" \n\n";

          if(net>=0)
          sgn=1;
          else
          sgn=-1;

          dernet=0.500*(1-sgn*sgn);

          for(int k=0;k<size;k++)
           {
               w[k]=w[k]+((d[i]-sgn)*dernet*c*x[i].data[k]);
           }

           for(int k=0;k<size;k++)
           cout<<"Weight"<<k+1<<"="<<w[k]<<" ";
           cout<<endl;
     }

    cout<<"\nFINAL WEIGHT MATRIX IS : ";
    for(int i=0;i<size;i++)
     {
       cout.precision(5);
       cout<<endl<<w[i]<<endl;
     }
  delete[] w;
    delete[] x;

}
