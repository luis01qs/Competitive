# include <iostream>
# include <vector>
# include <algorithm>
# include <random>

int partition(std::vector<int> &a, int l, int r)
{
    int p = a[r];
    int i = l - 1;

    for(int j=l;j<r;++j)
    {
        if(a[j] < p)
        {
            std::swap(a[++i], a[j]);
        }
    }

    std::swap(a[r], a[++i]);
    return i;
}

void quicksort(std::vector<int> &a, int l, int r)
{
    if(l < r)
    {
        int p = partition(a, l, r);

        quicksort(a, l, p-1);
        quicksort(a, p+1, r);
    }
}

void cd(int n)
{
    std::vector<int> a(n);
    for(auto &e:a) e = rand() % 10000;
    std::vector<int> b = a;

    quicksort(a, 0, n-1);
    std::sort(b.begin(), b.end());

    bool val = true;
    for(int i=0;i<n;++i) if(a[i] != b[i]) val = false;
    if(!val) std::cout << "No" << std::endl;
}

int main()
{
    int T = 100;
    int n = 1000;
    srand(time(NULL));
    while(T--)
    {
        cd(n);
    }
}
