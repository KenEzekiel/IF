#include "Stack.hpp"
#include <iostream>

// inisialisasi di file stack.cpp nya
// bedanya kalo inisialisasi di hpp nya apa?
int Stack::n_stack = 0;

Stack::Stack() : capacity(10)
{
    this->size = 0;
    this->data = new int[this->capacity];
    n_stack += 1;
}

Stack::Stack(int cap) : capacity(cap)
{
    this->size = 0;
    this->data = new int[this->capacity];
    n_stack += 1;
}

Stack::Stack(const Stack &b) : capacity(b.capacity)
{
    this->size = b.size;
    this->data = new int[b.capacity];
    // deep copy
    // is there a more objective approach?
    for (int i = 0; i < this->capacity; i++)
    {
        this->data[i] = b.data[i];
    }
    n_stack += 1;
}

Stack::~Stack()
{
    delete[] this->data;
}

void Stack::push(int x)
{
    if (this->size < this->capacity)
    {
        this->data[this->size] = x;
        this->size++;
    }
}

int Stack::pop()
{
    int top = 0;
    if (this->size > 0)
    {
        this->size--;
        top = this->data[this->size];
    }
    return top;
}