# include <iostream>
# include <vector>

class MaxHeap
{
    private:
        std::vector<int> a;

        int left(int p) { return (p << 1) + 1; }
        int right(int p) { return (p << 1) + 2; }
        int parent(int p) { return (p - 1) >> 1; }

        void heapifydown(int p)
        {
            int i = p;
            int l = left(p);
            int r = right(p);

            if(l < a.size() && a[l] > a[i]) i = l;
            if(r < a.size() && a[r] > a[i]) i = r;

            if(i != p)
            {
                std::swap(a[i], a[p]);
                heapifydown(i);
            }
        }

    public:

        MaxHeap(){}

        void insert(int x)
        {
            int p = a.size();
            a.push_back(x);

            while(p > 0 && a[p] > a[parent(p)])
            {
                std::swap(a[p], a[parent(p)]);
                p = parent(p);
            }
        }

        void erase()    
        {
            if(a.size() == 0) return;

            std::swap(a[0], a[a.size() - 1]);
            a.pop_back();

            if(a.size() == 0) return;

            heapifydown(0);
        }

        void print()
        {
            for(int i=0;i<(int)a.size();++i) std::cout << a[i] << " ";
            std::cout << std::endl;
        }
};


int main() {
    MaxHeap h;
    h.insert(10);
    h.insert(30);
    h.insert(20);
    h.insert(5);
    h.insert(40);

    h.print();   // Should show a heap-like structure (not sorted)

    h.erase();   // Removes max (40)
    h.print();

    return 0;
}
