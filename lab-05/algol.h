#pragma once

#include <vector>
#include <string>
#include <sstream>

template <typename T>
int partition(std::vector<T> &v, int p, int r)
{
    int q = p;
    for (int u = p; u < r; ++u)
    {
        if (v[u] <= v[r])
        {
            T t = v[u];
            v[u] = v[q];
            v[q] = t;
            ++q;
        }
    }

    T t = v[q];
    v[q] = v[r];
    v[r] = t;

    return q;
}

template <typename T>
void quickSort(std::vector<T> &v, int p, int r)
{
    if (p >= r)
    {
        return;
    }

    int q = partition(v, p, r);
    quickSort(v, p, q - 1);
    quickSort(v, q + 1, r);
}

template <typename T>
void quickSort(std::vector<T> &v)
{
    quickSort(v, 0, v.size() - 1);
}

template <typename T>
int binarySearch(const std::vector<T> &v, T x)
{
    int p = 0;
    int r = v.size() - 1;
    int q;

    while (p <= r)
    {
        q = (p + r) / 2;

        if (v[q] == x)
        {
            return q;
        }
        else if (v[q] > x)
        {
            r = q - 1;
        }
        else if (v[q] < x)
        {
            p = q + 1;
        }
    }

    return -1;
}

template <typename T>
void insertionSort(std::vector<T> &v)
{
    for (int i = 1; i < int(v.size()); ++i)
    {
        T k = v[i];
        int j = i - 1;
        for (; j >= 0 && v[j] > k; --j)
        {
            v[j + 1] = v[j];
        }
        v[j + 1] = k;
    }
}

template <typename Iter>
void print(Iter i, Iter j, std::ostringstream &out)
{
    while (i != j)
    {
        out << *i++ << " ";
    }
}

template <typename T>
void merge(std::vector<T> &v, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<T> a(n1);
    std::vector<T> b(n2);

    for (int i = 0, j = p; i < n1; ++i, ++j)
    {
        a[i] = v[j];
    }

    for (int i = 0, j = q + 1; i < n2; ++i, ++j)
    {
        b[i] = v[j];
    }

    int i = 0;
    int j = 0;
    int k = p;
    for (; i < n1 && j < n2; ++k)
    {
        if (a[i] <= b[j])
        {
            v[k] = a[i++];
        }
        else
        {
            v[k] = b[j++];
        }
    }

    while (i < n1)
    {
        v[k++] = a[i++];
    }
    while (j < n2)
    {
        v[k++] = b[j++];
    }
}

template <typename T>
void mergeSort(std::vector<T> &v, int p, int r)
{
    if (p >= r)
    {
        return;
    }

    int q = (p + r) / 2;
    mergeSort(v, p, q);
    mergeSort(v, q + 1, r);
    merge(v, p, q, r);
}

template <typename T>
void mergeSort(std::vector<T> &v)
{
    mergeSort(v, 0, v.size() - 1);
}

void countKeysEqual(const std::vector<int> &v, std::vector<int> &t)
{
    for (const auto &e : v)
    {
        ++t[e];
    }
}

void countKeysLess(std::vector<int> &t)
{
    int equal1 = t[0];
    int equal2;
    t[0] = 0;

    for (int i = 1; i < int(t.size()); ++i)
    {
        equal2 = t[i];
        t[i] = equal1 + t[i - 1];
        equal1 = equal2;
    }
}

void rearrange(const std::vector<int> &v, std::vector<int> &b, std::vector<int> &t)
{
    for (int i = 0; i < int(v.size()); ++i)
    {
        int key = v[i];
        int index = t[key];
        b[index] = v[i];
        ++t[key];
    }
}

std::vector<int> countingSort(const std::vector<int> &v, int m)
{
    std::vector<int> b(v.size());
    std::vector<int> t(m, 0);

    countKeysEqual(v, t);
    countKeysLess(t);
    rearrange(v, b, t);
    return b;
}