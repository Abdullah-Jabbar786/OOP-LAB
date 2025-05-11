#include "iostream"
#include <exception>
using namespace std;


class StackOverflowException : public exception
{
    public:
    const char* what() const noexcept
    {
        return "StackOverflowException - Stack is full!";
    }

};

class StackUnderflowException : public exception
{
    public:
    const char* what() const noexcept
    {
        return "StackUnderflowException - Stack is empty!";
    }

};

template<typename T>
class Stack 
{
private:
    int capacity;
    int top;
    T* data;

public:
    Stack(int size) 
    {
        capacity = size;
        top = -1;
        data = new T[capacity];
    }

    ~Stack() 
    {
        delete[] data;
    }

    // Push method
    void push(const T& item) 
    {
        if(top >= capacity - 1) 
        {
            throw StackOverflowException();
        }
        data[++top] = item;
    }

    // Pop method
    T pop() 
    {
        if (top < 0) 
        {
            throw StackUnderflowException();
        }
        return data[top--];
    }

    bool isEmpty() const 
    {
        return top == -1;
    }

    bool isFull() const 
    {
        return top == capacity - 1;
    }
};


int main() 
{
    Stack<int> stack(2);

    try {
        cout << "Pushing 1...\n";
        stack.push(1);

        cout << "Pushing 2...\n";
        stack.push(2);

        cout << "Pushing 3...\n";
        stack.push(3);
    }
    catch(const StackOverflowException& e) 
    {
        cerr << "Error: " << e.what() << endl;
    }

    try 
    {
        cout << "Popping: " << stack.pop() << "\n";
        cout << "Popping: " << stack.pop() << "\n";
        cout << "Popping: " << stack.pop() << "\n";
    } 
    catch(const StackUnderflowException& e) 
    {
        cerr<<"\nError: " << e.what()<<endl;
    }

    return 0;
}
