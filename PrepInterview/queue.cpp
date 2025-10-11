#include <iostream>

template<typename T>
class Queue
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

        Node *first;
        Node *last;
        Node *dynamic_node;

    public:

        Queue()
        {
            first = nullptr;
            last = nullptr;
            dynamic_node = nullptr;
        }

        void insert(T t)
        {
            dynamic_node = new Node(t);
            if(first == nullptr)
            {
                first = dynamic_node;
                last = dynamic_node;
                return;
            }

            last -> next = dynamic_node;
            dynamic_node -> prior = last;
            last = last -> next;
        }

        void erase()
        {
            if(first == nullptr) return;

            if(first == last)
            {
                delete first;
                last = first = nullptr;
                return ;
            }

            first = first -> next;
            dynamic_node = first -> prior;
            delete dynamic_node;
            first -> prior = nullptr;
            
        }

        void print()
        {
            dynamic_node = first;
            while(dynamic_node != nullptr)
            {
                std::cout << dynamic_node -> data << " ";
                dynamic_node = dynamic_node -> next;
            }
            std::cout << std::endl;
        }
};

int main()
{
    Queue<int> s;
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
