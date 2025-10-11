# include <iostream>
# include <vector>
# include <algorithm>
# include <random>

void merge(std::vector<int> &a, int l, int m, int r)
{
    int n = r - l + 1;
    std::vector<int> b(n);

    int i = l, j = m + 1;
    for(int k=0;k<n;++k)
    {
        if(i == m+1) b[k] = a[j++];
        else if(j == r+1) b[k] = a[i++];
        else if(a[j] < a[i]) b[k] = a[j++];
        else b[k] = a[i++];
    }

    for(int k=0;k<n;++k) a[l+k] = b[k];
}

void mergesort(std::vector<int> &a, int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(a, l, m);
        mergesort(a, m+1, r);
        merge(a, l, m, r);
    }
}

void cd(int n)
{
    std::vector<int> a(n);
    for(auto &e:a) e = rand() % 10000;
    std::vector<int> b = a;

    mergesort(a, 0, n-1);
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
