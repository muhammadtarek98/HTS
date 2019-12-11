#include<bits/stdc++.h>
using namespace std;
const double n=10,m=2,mx_iter=100,xmin1=0,xmax1=10,elit_size=2,xmin2=0,xmax2=1,OOpos =1e6;
int iter=1;
double X[3][3];
double r[11];
double R;
double CDF,COF,RDF;
double x[11][3];
bool valid(double x1,double x2)
{
  if(((x1-5)*(x1-5)+(x2*x2)-26)>=0&&(x1>=0&&x2>=0&&x1<=10&&x2<=10))
  {
      return true;
  }
  return false;
}
double evaluate(double x1,double x2)
{
  if(valid(x1,x2))
  {
      return (((x1*x1)+x2-11)*((x1*x1)+x2-11))+((x1+(x2*x2)-7)*(x1+(x2*x2)-7));
  }
  return 0;
}
double doubleabs(double R,double ri)
{
    if(R-ri<0)
    {
        return(R-ri)*-1;
    }
    return R-ri;

}
double randMToN(double mn, double mx)
{
    return mn+(rand()/(RAND_MAX/(mx-mn)));
}
int int_rand(int mn, int mx)
{
    int ret=(int)rand();
    if(ret>mx)
    {
        return ret%mx;
    }
    else if(ret<1)
    {
        return (ret*-1)%mn;
    }
    return ret;
}
void intial()
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      x[i][j]=randMToN(xmin1,xmax1);
    }
  }
  for(int i=1;i<=elit_size;i++)
  {
      for(int j=1;j<=m;j++)
       {
        X[i][j]=OOpos;
       }
  }
    int cur_elite=1;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      X[cur_elite][j]=min(X[cur_elite][j],x[i][j]);
      cur_elite=(cur_elite+1)%(int)m;
    }
  }
  ///r[i]
  for(int i=1;i<=n;i++)
  {
    r[i]=randMToN(xmin2,xmax2);
  }
}
void print()
{
      cout<<"the population and variables value :\n";
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cout<<setprecision(4)<<x[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"\n the best so far"<<endl;
  for(int i=1;i<=elit_size;i++)
  {
      for(int j=1;j<=m;j++)
        cout<<X[i][j]<<" ";
    cout<<endl;
  }
  cout<<endl;
  cout<<"the r[i] value :"<<endl;
  for(int i=1;i<=10;i++)
  {
    cout<<setprecision(4)<<r[i]<<" ";
  }
  cout<<endl;

}
void conduction()
{
    /// conduction
        if(iter<=(mx_iter/CDF))
        {
          int k=int_rand(1,10);
          double x1=0,x2=0,xk1=0,xk2=0;
          for(int i=1;i<=n;i++)
          {
            for(int j=1;j<=m;j++)
            {

              if(j==1)
              {
              x1=x[i][j];
              xk1=x[k][j];
              }
              else if(j==2)
              {
                x2=x[i][j];
                xk2=x[k][j];
              }
              if(evaluate(x1,x2)>evaluate(xk1,xk2))
                {
                    x[i][j]=x[k][j]+(-(R*R)*x[k][j]);
                }
            else
            {
                x[i][j]=x[i][j]+(-(R*R)*x[i][j]);
            }
            }
          }

        }
        else if(iter>(mx_iter/CDF))
        {

          double x1=0,x2=0,xk1=0,xk2=0;
            int k=int_rand(1,10);
          for(int i=1;i<=n;i++)
          {
            for(int j=1;j<=m;j++)
            {

              if(j==1)
              {
              x1=x[i][j];
              xk1=x[k][j];
              }
              else if(j==2)
              {
                x2=x[i][j];
                xk2=x[k][j];
              }
              if(evaluate(x1,x2)>evaluate(xk1,xk2))
                {
                    x[i][j]=x[k][j]+(-r[i]*x[k][j]);
                }
            else
            {
                x[i][j]=x[i][j]+(-r[i]*x[i][j]);
            }
            }
          }

        }
}
void radiation()
{
  /// radition
        if(iter<=(mx_iter/RDF))
        {

          double x1=0,x2=0,xk1=0,xk2=0;
        int k=int_rand(1,10);
          for(int i=1;i<=n;i++)
          {
              x1=x[i][1];
              xk1=x[k][1];
                x2=x[i][2];
                xk2=x[k][2];
              if(evaluate(x1,x2)>evaluate(xk1,xk2))
                {
                    x[i][1]=x[i][1]+(R*(x[k][1]-x[i][1]));
                    x[i][2]=x[i][2]+(R*(x[k][2]-x[i][2]));
                }
            else
            {

                  x[i][1]=x[i][1]+(R*(x[k][1]-x[i][1]));
                  x[i][2]=x[i][2]+(R*(x[k][2]-x[i][2]));
                }

        }
        }
        else if(iter>(mx_iter/RDF))
        {

          double x1=0,x2=0,xk1=0,xk2=0;
            int k=(int)rand()%10;
          for(int i=1;i<=n;i++)
          {
              x1=x[i][1];
              xk1=x[k][1];
                x2=x[i][2];
                xk2=x[k][2];
              if(evaluate(x1,x2)>evaluate(xk1,xk2))
                {
                  x[i][1]=x[i][1]+(r[i]*(x[k][1]-x[i][1]));
                  x[i][2]=x[i][2]+(r[i]*(x[k][2]-x[i][2]));
                }
            else
            {
              x[i][1]=x[i][1]+(r[i]*(x[k][1]-x[i][1]));
              x[i][2]=x[i][2]+(r[i]*(x[k][2]-x[i][2]));
            }
            }

        }
}
void convection()
{
    /// convection
      if(iter<=(mx_iter/COF))
      {
          for(int i=1;i<=n;i++)
          {
            for(int j=1;j<=m;j++)
            {
              x[i][j]=x[i][j]+R*( doubleabs(R,r[i]));
            }
          }
      }
      else if(iter>(mx_iter/COF))
      {
          for(int i=1;i<=n;i++)
          {
            for(int j=1;j<=m;j++)
            {
                x[i][j]=x[i][j]+R*( 1+round(r[i]));
            }
          }
      }

      }
void greedy()
{
    int cur_elite=1;
    for(int i=1;i<=n;i++)
    {
         X[1][1]=min(X[1][1],x[i][1]);
         X[1][2]=min(X[1][2],x[i][2]);
         X[2][1]=min(X[2][1],x[i][1]);
         X[2][2]=min(X[2][2],x[i][2]);
        cur_elite=(cur_elite+1)%(int)elit_size;
    }
}
int main()
{
  intial();
  print();
  while(iter<=mx_iter)
    {
      double cur_R=(float)rand();
      if(cur_R>1)
      {
      //cur_R=cur_R%1.0;
      R=fmod(cur_R,1.0);
      }
      else if(cur_R<0)
      {
      cur_R=(cur_R*-1.0);
      R=fmod(cur_R,1.0);
      }
      else
      {
        R=cur_R;
      }
      if(R>=0&&R<=0.3333)
      {
          conduction();
      }
      else if(R>0.3333&&R<=0.6666)
      {
          radiation();
      }
      else if(R>0.6666&&R<=1)
      {
          convection();
      }
      greedy();
      iter++;
    }
    print();
    system("pause");
  return 0;
}
