#include "Calculator.hpp"
#include "CException.hpp"

/**
 * Konstruktor Calculator. Menginisialisasi stack operand dan operator dengan kosong.
 */
Calculator::Calculator()
{
  opStack = stack<char>();
  valStack = stack<int>();
}

/**
 * Mengecek apakah suatu karakter merupakan operand (suatu digit).
 * 
 * @param c Karakter yang akan dicek.
 * @return bool true jika karakter merupakan digit, false jika bukan.
 * @example IsOperand('1') = true, IsOperand('a') = false
 **/
bool Calculator::IsOperand(char c) const
{
  return isdigit(c);
}

/**
 * Mengembalikan nilai integer dari karakter digit. C pasti merupakan digit.
 * 
 * @param c Karakter digit.
 * @return int Nilai integer dari karakter digit.
 * @example CharToInt('1') = 1.
 */
int Calculator::CharToInt(char c) const
{
  return int(c - '0');
}

/**
 * Mengecek apakah suatu karakter merupakan operator. Operator yang didukung adalah 
 * +, -, *, dan /.
 * 
 * @param c Karakter yang akan dicek.
 * @return bool true jika karakter merupakan operator, false jika bukan.
 */
bool Calculator::IsOperator(char c) const
{
  // Lengkapilah...
  if (c == '+' || c == '-' || c == '*' || c == '/') {
    return true;
  }
  return false;
}

/**
 * Mengembalikan nilai prioritas dari operator. Nilai prioritas adalah sebagai berikut:
 * 
 * | Operator  |           Makna           |   Prioritas   |
 * |           |                           |(Higher better)|
 * |-----------|---------------------------|---------------|
 * | *. /      | perkalian, pembagian      | 2             |
 * | +, -      | penjumlahan, pengurangan  | 1             |
 *  
 * Apabila operator tidak valid, maka return -1,
 * 
 * @param op Operator yang akan dicek. 
 * @return int Nilai prioritas dari operator.
 */
int Calculator::Precedence(char op) const
{
  // Lengkapilah...
  if (IsOperator(op)) {
    if (op == '*' || op == '/') {
      return 2;
    } else {
      return 1;
    }
  } else {
    return -1;
  }
}

/**
 * Mengembalikan hasil dari operasi dua bilangan dengan operator tertentu. Melakukan throw
 * exception jika terjadi pembagian dengan nol. Operator pasti valid.
 * 
 * @param a Bilangan pertama.
 * @param b Bilangan kedua.
 * @param op Operator.
 * @return int Hasil operasi.
 */
int Calculator::ApplyOp(int a, int b, char op) const
{
  // Lengkapilah...
  if (op == '+') {
    return a + b;
  } 
  if (op == '-') {
    return a - b;
  }
  if (op == '*') {
    return a * b;
  }
  if (op == '/') {
    if (b == 0) {
      throw DivideByZeroException();
    } else {
      return a / b;
    }
  }
}

/**
 * Mengosongkan stack operand dan operator.
 */
void Calculator::ClearStacks()
{
  while (!opStack.empty())
    opStack.pop();
  while (!valStack.empty())
    valStack.pop();
}

/**
 * Mengembalikan hasil dari ekspresi aritmetika yang diberikan. 
 * Throw exception apabila ditemukan simbol yang tidak dikenal. 
 * Melakukan print error message sesuai dengan exception yang terjadi (tambahkan endline). 
 * Pastikan stack operand dan operator dikosongkan setelah terjadi exception. 
 * Return 0 jika terjadi exception.
 * 
 * Algoritma proses evaluasi adalah sebagai berikut:
 * 
 * Proses Kalkulasi
 * 1. Lakukan pop pada 2 nilai pada stack operand, sebut saja nilainya A dan B.
 * 2. Lakukan pop pada 1 operasi dari stack operator, misal operasinya adalah “+”.
 * 3. Lakukan operasinya, yaitu A + B dan push hasilnya ke stack operand.
 * 
 * Proses Evaluasi
 * 1. Tiap simbol dari ekspresi aritmetika akan dibaca dari kiri ke kanan.
 * 2. Apabila simbol yang sedang dibaca adalah operand maka simbol tersebut akan di push ke 
 *    stack operand.
 * 3. Apabila simbol yang dibaca adalah operator maka
 *    a. Apabila stack operator kosong maka push simbol tersebut ke dalam stack operator.
 *    b. Apabila stack operator tidak kosong maka
 *       - Apabila tingkat prioritas dari operator sekarang lebih tinggi atau sama dengan 
 *         operator yang ada di top stack maka push operator sekarang ke stack operator.
 *       - Apabila tingkat prioritas dari operator sekarang lebih tinggi kecil dari operator 
 *         yang ada di top stack maka lakukan Proses Kalkulasi (dijelaskan diatas) hingga 
 *         prioritas dari operator sekarang lebih tinggi atau selama stack operator tidak kosong.
 * 4. Apabila simbol yang dibaca adalah “(“ maka push simbol ke dalam stack operator.
 * 5. Apabila simbol yang dibaca adalah “)” maka lakukan Proses Kalkulasi (dijelaskan diatas) 
 *    hingga simbol “(“ yang bersesuaian ditemukan pada stack operator lalu pop simbol “(“.
 * 6. Apabila pembacaan ekpresi aritmetika selesai namun stack operator belum kosong maka 
 *    lakukan Proses Kalkulasi (dijelaskan diatas) hingga stack operator kosong.
 * 7. Nilai yang tersisa pada stack operand adalah hasilnya.
 * 
 * @param tokens Ekspresi aritmetika yang akan dievaluasi.
 * @return int Hasil dari ekspresi aritmetika.
 */
int Calculator::Evaluate(const string& tokens)
{
  int a, b, hasil;
  char o;
  // Kamu dapat melakukan iterasi string dengan cara berikut:
  for (int i = 0; i < tokens.length(); i++) {
    char c = tokens[i];
    // Lakukan sesuatu dengan c
    try {
      if (IsOperand(c)) {
        valStack.push(CharToInt(c));
      } else if (IsOperator(c)) {
        if (opStack.empty()) {
          opStack.push(c);
        } else if (Precedence(c) >= Precedence(opStack.top())){
          opStack.push(c);
        } else {
          while (true) {
            if (Precedence(c) <= Precedence(opStack.top()) || opStack.empty()) {
              break;
            } else {
              a = valStack.top();
              valStack.pop();
              b = valStack.top();
              valStack.pop();
              o = opStack.top();
              opStack.pop();
              hasil = ApplyOp(a, b, o);
              valStack.push(hasil);
            }
            opStack.push(c);

          }
        }
      } else if (c == '(') {
        opStack.push(c);
      } else if (c == ')') {
        while (true) {
          if (opStack.top() == '(' || opStack.empty()) {
            opStack.pop();
            break;
          } else {
            a = valStack.top();
            valStack.pop();
            b = valStack.top();
            valStack.pop();
            o = opStack.top();
            opStack.pop();
            hasil = ApplyOp(a, b, o);
            valStack.push(hasil);
          }
        }
      } else {
        throw SymbolUnidentifiedException();
      }
    } catch(exception& e) {
      cout << e.what() << endl;
      while (!opStack.empty()) {
        opStack.pop();
      }
      while (!valStack.empty()) {
        valStack.pop();
      }
      return 0;
    }

  }
  // Atau dengan cara berikut:
  // int i = 0;
  // while (i < tokens.length()) {
  //   char c = tokens[i];
  //   // Lakukan sesuatu dengan c
  //   i++;
  // }
  while (true) {
    if (opStack.empty()) {
      break;
    } else {
      a = valStack.top();
      valStack.pop();
      b = valStack.top();
      valStack.pop();
      o = opStack.top();
      opStack.pop();
      hasil = ApplyOp(a, b, o);
      valStack.push(hasil);
    }
    
  }
  return valStack.top();
}