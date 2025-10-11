#include <iostream>

template<typename T>
class LinkedList
{
    private:
        class Node
        {
            public:
                T data;
                Node *next;

                Node(T t) : data(t), next(nullptr) {}
        };

        Node *first;
        Node *last;
        Node *dynamic_node;

     public:

        LinkedList()
        {
            first = nullptr;
            last = nullptr;
            dynamic_node = nullptr;
        }

        void insert(T t)
        {
            dynamic_node = new Node(t);
            if(first == NULL) first = last = dynamic_node;
            else
            {
                last -> next = dynamic_node;
                last = last -> next;
            }
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
    LinkedList<int> ll;
    ll.insert(4);
    ll.insert(5);
    ll.print();
    return 0;
}
