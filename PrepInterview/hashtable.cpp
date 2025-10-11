#include <iostream>

class Hash
{
    private:
        static const int size = 100;
        int a[size];

        int hash(int x)
        {
            return x % size;
        }

     public:

        Hash()
        {
            for(int i=0;i<size;++i) a[i] = -1;
        }

        void insert(int x)
        {
            if(a[hash(x)] != -1)
            {
                // Handle collisions
            }
            else a[hash(x)] = x;

            
        }
};

int main()
{
    Hash h;
    return 0;
}
