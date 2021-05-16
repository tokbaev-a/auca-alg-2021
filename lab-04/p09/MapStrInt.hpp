#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <ostream>

class MapStrInt
{
    struct Node
    {
        std::pair<std::string, int> mData;
        Node *mLeft;
        Node *mRight;

        Node(const std::string k, int x, Node *left, Node *right)
            : mData(k, x), mLeft(left), mRight(right)
        {
        }
    };

    Node *mRoot;
    size_t sz;

    void printInOrder(std::ostream &out, Node *root) const
    {
        if (root != nullptr)
        {
            printInOrder(out, root->mLeft);
            out << root->mData.first << ": " << root->mData.second << "\n";
            printInOrder(out, root->mRight);
        }
    }

    void clear(Node *root)
    {
        if (root != nullptr)
        {
            clear(root->mLeft);
            clear(root->mRight);
            delete root;
            --sz;
        }
    }

public:
    MapStrInt()
        : mRoot(nullptr), sz(0)
    {
    }

    ~MapStrInt()
    {
        clear();
    }

    size_t size() const
    {
        return sz;
    }

    int &operator[](const std::string &k)
    {
        bool isLeft = true;
        Node *prev = nullptr;
        Node *cur = mRoot;
        while (cur != nullptr)
        {
            if (cur->mData.first < k)
            {
                isLeft = false;
                prev = cur;
                cur = cur->mRight;
            }
            else if (cur->mData.first > k)
            {
                isLeft = true;
                prev = cur;
                cur = cur->mLeft;
            }
            else
            {
                return cur->mData.second;
            }
        }

        Node *t = new Node(k, 0, nullptr, nullptr);

        if (mRoot == nullptr)
        {
            mRoot = t;
        }
        else if (isLeft)
        {
            prev->mLeft = t;
        }
        else
        {
            prev->mRight = t;
        }
        sz++;
        return t->mData.second;
    }

    void printInOrder(std::ostream &out)
    {
        printInOrder(out, mRoot);
    }

    void clear()
    {
        clear(mRoot);
    }
};