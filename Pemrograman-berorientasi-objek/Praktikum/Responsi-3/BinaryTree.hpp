#ifndef __BINARY_TREE
#define __BINARY_TREE

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class BinaryTree
{
private:
    T value;
    std::vector<BinaryTree<T>> children;
    int numChildren;

public:
    // Default constructor, set numChildren = 0
    BinaryTree() { this->numChildren = 0; }
    // Copy constructor
    BinaryTree(const BinaryTree<T> &other)
    {
        this->value = other.value;
        this->numChildren = other.numChildren;
        for (auto &child : other.children)
        {
            this->children.push_back(child);
        }
    }
    // Destruktor
    ~BinaryTree()
    {
        this->children.clear();
    }

    // Setter untuk value
    void setValue(const T &v)
    {
        this->value = v;
    }

    /*
    Menambahkan anak binary tree dengan value tertentu.
    Fungsi ini membuat sebuah BinaryTree baru dan menambahkannya ke list of children.
    BinaryTree yang baru dibuat kemudian dikembalikan sebagai return value dari fungsi ini.
    Jika jumlah children sudah lebih dari dua, lemparkan exception "Tidak bisa memiliki lebih dari dua children\n".
    */
    BinaryTree<T> &addChild(T a)
    {
        if (this->numChildren >= 2)
        {
            throw "Tidak bisa memiliki lebih dari dua children\n";
        }

        BinaryTree<T> anak;
        anak.setValue(a);
        this->children.push_back(anak);
        this->numChildren++;
        return this->children[this->numChildren - 1];
    }

    /*
    Operator overloading untuk mencetak isi tree ke ostream.
    Format : <value>(<binary_tree_1>)(<binary_tree_2>)
    Tidak perlu ada newline di akhir.
    Berbagai contoh pencetakan binary tree :
    - Binary tree of integer tanpa children : 5()()
    - Binary tree of integer dengan satu children : 5(7()())()
    - Binary tree of integer dengan dua children : 5(7()())(6()())
    */
    friend ostream &operator<<(ostream &out, BinaryTree<T> bin)
    {
        out << bin.value;

        if (bin.numChildren == 0)
        {
            out << "()()";
        }
        else if (bin.numChildren == 1)
        {
            out << "(" << bin.children[0] << ")()";
        }
        else
        {
            out << "(" << bin.children[0] << ")(" << bin.children[1] << ")";
        }
        return out;
    }
};

#endif