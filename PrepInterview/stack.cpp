#include <iostream>

template<typename T>
class Stack
{
    private:

        class Node
        {
            public:
                T data;
                Node *next;
                Node *prior;

                Node(T t)
                {
                    data = t;
                    next = nullptr;
                    prior = nullptr;
                }
        };

        Node *last;
        Node *dynamic_node;


     public:
        
        Stack()
        {
            last = nullptr;
            dynamic_node = nullptr;
        }

        void insert(T t)
        {
            dynamic_node = new Node(t);
            if(last == nullptr)
            {
                last = dynamic_node;
            }
            else
            {
                last -> next = dynamic_node;
                dynamic_node -> prior = last;
                last = last -> next;
            }
        }

        void erase()
        {
            if(last == nullptr) return;
            
            dynamic_node = last;
            last = last -> prior;

            if(last != nullptr) last -> next = nullptr;
            
            delete dynamic_node;
        }

        void print()
        {
            dynamic_node = last;
            while(dynamic_node != nullptr)
            {
                std::cout << dynamic_node -> data << " ";
                dynamic_node = dynamic_node -> prior;
            }
            std::cout << std::endl;
        }
};

int main()
{
    Stack<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.print();
    s.erase();
    s.erase();
    s.erase();
    s.erase();
    s.print();
    s.insert(4);
    s.insert(5);
    s.print();
    s.erase();
    s.insert(6);
    s.print();

    return 0;
}
