// Weed.cpp
#include "Weed.hpp"

// class Weed {
//    private:
//     int many;  // jumlah kawanan semak, 1 <= many <= 1000

//    public:
//     Weed();       // Membuat Weed dengan jumlah kawanan 1
//     Weed(int n);  // Membuat Weed dengan jumlah kawanan n
//     Weed(const Weed &b);
//     ~Weed();

//     void step();  // Menghasilkan bunyi "kresek..." berulang
//                   // sebanyak n kawanan
// };

Weed::Weed()
{
  this->many = 1;
}

Weed::Weed(int n)
{
  if (n >= 1000)
  {
    this->many = 1000;
  }
  else
  {
    this->many = n;
  }
}

Weed::Weed(const Weed &b)
{
  this->many = b.many;
}

Weed::~Weed()
{
}

void Weed::step()
{
  for (int i = 0; i < this->many; i++)
  {
    std::cout << "kresek...";
  }
  std::cout << std::endl;
}