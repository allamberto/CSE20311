// Ana Lamberto
// Purpose: interface - rational.h - for Rational class
class Rational
{
  public:
    Rational();
    Rational(int, int);
    ~Rational();
    int getNumer();
    int getDenom();
    void setNumer(int);
    void setDenom(int);
    void print();
    Rational add(Rational);
    Rational subtract(Rational);
    Rational multiply(Rational);
    Rational divide(Rational);
    int GCF(int, int);
  private:
    int numer;
    int denom;
};
