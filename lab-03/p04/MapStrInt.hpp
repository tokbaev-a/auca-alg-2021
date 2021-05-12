#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>

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

    Node *root;
    size_t sz;

public:
    MapStrInt()
        : root(nullptr), sz(0)
    {
    }

    ~MapStrInt()
    {
        clear();
    }

    int &operator[](const std::string &k)
    {
        bool isLeft = true;
        Node *prev = nullptr;
        Node *cur = root;
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

        if (root == nullptr)
        {
            root = t;
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

    void printInOrder()
    {
        enum class Operation
        {
            goLeft,
            print,
            goRight,
            remove
        };

        std::vector<std::pair<Node *, Operation>> stack;

        stack.emplace_back(root, Operation::goLeft);
        while (!stack.empty())
        {
            auto &back = stack.back();
            if (back.first == nullptr || back.second == Operation::remove)
            {
                stack.pop_back();
            }
            else if (back.second == Operation::goLeft)
            {
                back.second = Operation::print;
                stack.emplace_back(back.first->mLeft, Operation::goLeft);
            }
            else if (back.second == Operation::print)
            {
                std::cout << back.first->mData.first << ": " << back.first->mData.second << "\n";
                back.second = Operation::goRight;
            }
            else if (back.second == Operation::goRight)
            {
                back.second = Operation::remove;
                stack.emplace_back(back.first->mRight, Operation::goLeft);
            }
        }
    }

    void clear()
    {
        enum class Operation
        {
            goLeft,
            goRight,
            remove
        };

        std::vector<std::pair<Node *, Operation>> stack;

        stack.emplace_back(root, Operation::goLeft);
        while (!stack.empty())
        {
            auto &back = stack.back();
            if (back.first == nullptr)
            {
                stack.pop_back();
            }
            else if (back.second == Operation::goLeft)
            {
                back.second = Operation::goRight;
                stack.emplace_back(back.first->mLeft, Operation::goLeft);
            }
            else if (back.second == Operation::goRight)
            {
                back.second = Operation::remove;
                stack.emplace_back(back.first->mRight, Operation::goLeft);
            }
            else if (back.second == Operation::remove)
            {
                delete back.first;
                --sz;
                stack.pop_back();
            }
        }
    }
};