#pragma once

#include <cstddef>
#include <string>
#include <sstream>

template <typename T>
class List
{
    struct Node
    {
        Node *mPrev;
        Node *mNext;
        T mData;

        Node(const T &data, Node *prev, Node *next)
            : mPrev(prev), mNext(next), mData(data)
        {
        }
    };

    Node *mHead;
    Node *mTail;
    std::size_t mSize;

public:
    List()
        : mHead(new Node(T(), nullptr, nullptr)), mTail(new Node(T(), nullptr, nullptr)), mSize(0)
    {
        mHead->mNext = mTail;
        mTail->mPrev = mHead;
    }

    List(const List<T> &other)
        : mHead(new Node(T(), nullptr, nullptr)), mTail(new Node(T(), nullptr, nullptr)), mSize(0)
    {
        mHead->mNext = mTail;
        mTail->mPrev = mHead;

        for (auto i = other.begin(); i != other.end(); i++)
        {
            pushBack(*i);
        }
    }

    List(List<T> &&other)
        : mHead(other.mHead), mTail(other.mTail), mSize(other.mSize)
    {
        other.mHead = nullptr;
        other.mTail = nullptr;
        other.mSize = 0;
    }

    List &operator=(const List<T> &other)
    {
        if (this != &other)
        {
            clear();

            for (auto i = other.begin(); i != other.end(); i++)
            {
                pushBack(*i);
            }
        }
        return *this;
    }

    List &operator=(List<T> &&other)
    {
        if (this != &other)
        {
            clear();
            mHead = other.mHead;
            mTail = other.mTail;
            mSize = other.mSize;

            other.mHead = nullptr;
            other.mTail = nullptr;
            other.mSize = 0;
        }

        return *this;
    }

    ~List()
    {
        clear();

        delete mHead;
        delete mTail;
    }

    void clear()
    {
        if (mHead != nullptr && mTail != nullptr)
        {
            while (begin() != end())
            {
                erase(begin());
            }
        }
    }

    std::size_t size() const
    {
        return mSize;
    }

    std::string toStr() const
    {
        std::ostringstream out;

        out << "{";

        Node *p = mHead->mNext;
        for (std::size_t i = 0; i < mSize; i++)
        {
            if (i != 0)
            {
                out << ", ";
            }

            out << p->mData;
            p = p->mNext;
        }

        out << "}";

        return out.str();
    }

    std::string toReverseStr() const
    {
        std::ostringstream out;

        out << "{";

        Node *p = mTail->mPrev;
        for (std::size_t i = 0; i < mSize; i++)
        {
            if (i != 0)
            {
                out << ", ";
            }

            out << p->mData;
            p = p->mPrev;
        }

        out << "}";

        return out.str();
    }

    void pushBack(const T &data)
    {
        insert(end(), data);
    }

    T popBack()
    {
        T t = *(--end());
        erase(--end());
        return t;
    }

    void pushFront(const T &data)
    {
        insert(begin(), data);
    }

    T popFront()
    {
        T t = *begin();
        erase(begin());
        return t;
    }

    class Iter;

    Iter begin() const
    {
        Iter r;
        r.mPtr = mHead->mNext;
        return r;
    }

    Iter end() const
    {
        Iter r;
        r.mPtr = mTail;
        return r;
    }

    Iter insert(Iter p, const T &x)
    {
        Iter t;
        t.mPtr = new Node(x, p.mPtr->mPrev, p.mPtr);
        p.mPtr->mPrev = t.mPtr;
        t.mPtr->mPrev->mNext = t.mPtr;

        ++mSize;

        return t;
    }

    Iter erase(Iter p)
    {
        Iter r = p;
        ++r;

        p.mPtr->mPrev->mNext = p.mPtr->mNext;
        p.mPtr->mNext->mPrev = p.mPtr->mPrev;
        delete p.mPtr;

        --mSize;

        return r;
    }

    class RIter;

    RIter rbegin() const
    {
        RIter r;
        r.mPtr = mTail->mPrev;
        return r;
    }

    RIter rend() const
    {
        RIter r;
        r.mPtr = mHead;
        return r;
    }
};

template <typename T>
class List<T>::Iter
{
    friend class List<T>;
    Node *mPtr;

public:
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    Iter()
        : mPtr(nullptr)
    {
    }

    T &operator*() const
    {
        return mPtr->mData;
    }

    T *operator->() const
    {
        return &(mPtr->mData);
    }

    Iter &operator++()
    {
        mPtr = mPtr->mNext;
        return *this;
    }

    Iter operator++(int)
    {
        Iter r = *this;
        mPtr = mPtr->mNext;
        return r;
    }

    Iter &operator--()
    {
        mPtr = mPtr->mPrev;
        return *this;
    }

    Iter operator--(int)
    {
        Iter r = *this;
        mPtr = mPtr->mPrev;
        return r;
    }

    bool operator==(const Iter &other) const
    {
        return mPtr == other.mPtr;
    }

    bool operator!=(const Iter &other) const
    {
        return !(*this == other);
    }
};

template <typename T>
class List<T>::RIter
{
    friend class List<T>;
    Node *mPtr;

public:
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    RIter()
        : mPtr(nullptr)
    {
    }

    T &operator*() const
    {
        return mPtr->mData;
    }

    T *operator->() const
    {
        return &(mPtr->mData);
    }

    RIter &operator++()
    {
        mPtr = mPtr->mPrev;
        return *this;
    }

    RIter operator++(int)
    {
        RIter r = *this;
        mPtr = mPtr->mPrev;
        return r;
    }

    RIter &operator--()
    {
        mPtr = mPtr->mNext;
        return *this;
    }

    RIter operator--(int)
    {
        RIter r = *this;
        mPtr = mPtr->mNext;
        return r;
    }

    bool operator==(const RIter &other) const
    {
        return mPtr == other.mPtr;
    }

    bool operator!=(const RIter &other) const
    {
        return !(*this == other);
    }
};