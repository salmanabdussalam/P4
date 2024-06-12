#include <iostream>

using namespace std;

class PersegiPanjang{
private:

    float xmin, xmax, ymin, ymax, area;
     
public:
 
    PersegiPanjang(float X, float Y, float Panjang, float Lebar){
        
     xmin = X - Panjang/2;
     xmax = X + Panjang/2;
     
     ymin = Y - Lebar/2;
     ymax = Y + Lebar/2;
     
     area = Panjang*Lebar;
     
    }
    
    bool iris(const PersegiPanjang& lain) const {
        return (xmax >= lain.xmin) && (xmin <= lain.xmax) && (ymax >= lain.ymin) && (ymin <= lain.ymax);
    }
    
    
    bool operator == (const PersegiPanjang& lain) const {
        if (iris(lain)) {
            return true;
        } else {
            return false;
        }
    }
    

    PersegiPanjang operator + (PersegiPanjang& lain1)
    {
      if(!(*this == lain1)) {return PersegiPanjang(0, 0, 0, 0);}
      float xx = max(xmax, lain1.xmax);
      float xn = min(xmin, lain1.xmin);
      float yx = max(ymax, lain1.ymax);
      float yn = min(ymin, lain1.ymin);
      return PersegiPanjang((xx-xn)/2, (yx-yn)/2, xx-xn, yx-yn);
    }

    float getArea()
    {
      return area;
    }

};


int main()
{
  PersegiPanjang A(5, 6, 2, 3); //x,y,Panjang,Lebar
  PersegiPanjang B(3, 5, 4, 2);
  
  PersegiPanjang C = A + B;
  cout<<"Area : "<<C.getArea()<<endl;
  
  if(A == B){
      cout<<"Beririsan\n";
  }else{
      cout << "tidak Beririsan";
  }
}