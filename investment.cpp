//
//  main.cpp
//  HW 3
//
//  Created by Anica Wang on 2/3/21.
//

//#include <iostream>
//#include <string>
//using namespace std;

//Your declarations and implementations would go here

class Investment
{
  public:
    Investment(string n, int p);
    virtual ~Investment();
    virtual string description() const = 0;
    string name() const;
    int purchasePrice() const;
    virtual bool fungible() const;
  private:
    string m_name;
    int m_price;
};

Investment::Investment(string n, int p)
{
    m_name = n;
    m_price = p;
}

Investment::~Investment()
{
    int a = 0;
    a++;
}

string Investment::name() const
{
    return m_name;
}

int Investment::purchasePrice() const
{
    return m_price;
}

bool Investment::fungible() const
{
    return false;
}

//non fungible
class Painting: public Investment
{
  public:
    Painting(string n, int p);
    virtual ~Painting();
    virtual string description() const;
};

Painting::Painting(string n, int p)
:Investment(n, p)
{
}

Painting::~Painting()
{
    cout << "Destroying " << this->name() << ", a painting" << endl;
}

string Painting::description() const
{
    return "painting";
}

//fungible
class Stock: public Investment
{
  public:
    Stock(string n1, int p, string n2);
    virtual ~Stock();
    virtual string description() const;
    virtual bool fungible() const;
  private:
    string name2;
};

Stock::Stock(string n1, int p, string n2)
:Investment(n1, p)
{
    name2 = n2;
}

Stock::~Stock()
{
    cout << "Destroying " << this->name() << ", a stock holding" << endl;
}

string Stock::description() const
{
    string s = "stock trading as ";
    s += name2;
    return s;
}

bool Stock::fungible() const
{
    return true;
}

//non fungible
class House: public Investment
{
public:
    House(string n, int p);
    virtual ~House();
    virtual string description() const;
};

House::House(string n, int p)
:Investment(n, p)
{
}

House::~House()
{
    cout << "Destroying the house " << this->name() << endl;
}

string House::description() const
{
    return "house";
}

//void display(const Investment* inv)
//{
//    cout << inv->name();
//    if (inv->fungible())
//        cout << " (fungible)";
//    cout << ": " << inv->description() << " bought for $" << inv->purchasePrice() << endl;
//}
//
//int main()
//{
//    Investment* portfolio[4];
//    portfolio[0] = new Painting("Salvator Mundi", 450300000);
//      // Stock holdings have a name, value, and ticker symbol
//    portfolio[1] = new Stock("Lyft", 50000, "LYFT");
//    portfolio[2] = new Stock("GameStop", 10000, "GME");
//    portfolio[3] = new House("4 Privet Drive", 660000);
//
//    for (int k = 0; k < 4; k++)
//        display(portfolio[k]);
//
//      // Clean up the investments before exiting
//    cout << "Cleaning up" << endl;
//    for (int k = 0; k < 4; k++)
//        delete portfolio[k];
//}
