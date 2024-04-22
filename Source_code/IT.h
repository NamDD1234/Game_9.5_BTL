#pragma once

#include <bits/stdc++.h>

using namespace std;

struct SegmentTreeNode
{
    int st, en;
    bool value;
    bool nho, nho_value;
    SegmentTreeNode *lef, *rig;
    SegmentTreeNode(int st, int en) : st(st), en(en), value(0), nho(0), nho_value(0), lef(nullptr), rig(nullptr) {}
};

class SegmentTree
{
private:
    SegmentTreeNode* root;
    SegmentTreeNode* buildTree(int st, int en)
    {
        if (st == en)
            return new SegmentTreeNode(st, en);
        int mid = (st+en)/2;
        auto lef = buildTree(st, mid);
        auto rig = buildTree(mid + 1, en);
        auto node = new SegmentTreeNode(st, en);
        node->lef = lef;
        node->rig = rig;
        node->value = 0;
        return node;
    }

    void updateRange(SegmentTreeNode* node, int st, int en, bool value)
    {
        if (!node || st > node->en|| en< node->st)
            return;
        if (st <= node->st && en>= node->en)
        {
            node->nho_value = value;
            node->nho = 1;
            return;
        }
        if(node->nho)
        {
            node->lef->nho = 1;
            node->rig->nho = 1;
            node->lef->nho_value = node->nho_value;
            node->rig->nho_value = node->nho_value;
            node->nho = 0;
        }
        updateRange(node->lef, st, en, value);
        updateRange(node->rig, st, en, value);
        node->value = max((node->lef->nho)?node->lef->nho_value:node->lef->value,
                          (node->rig->nho)?node->rig->nho_value:node->rig->value);
    }

    bool getRange(SegmentTreeNode* node, int st, int en)
    {
        if (!node || st > node->en|| en< node->st)
            return false;

        if (st <= node->st && en>= node->en)
            return (node->nho)?node->nho_value: node->value;

        if(node->nho)
        {
            node->lef->nho = 1;
            node->rig->nho = 1;
            node->lef->nho_value = node->nho_value;
            node->rig->nho_value = node->nho_value;
            node->nho = 0;
        }

        node->value = max(getRange(node->lef, st, en), getRange(node->rig, st, en));
        return node->value;
    }

    void getClear(SegmentTreeNode* node, int st, int en)
    {
        if (st == en)
        {
            delete node;
            return ;
        }
        int mid = (st + en)/2;
        getClear(node->lef, st, mid);
        getClear(node->rig, mid + 1, en);
        delete node;
    }
public:
    SegmentTree(int n)
    {
        root = buildTree(0, n);
    }

    void updateRange(int st, int en, bool value)
    {
        updateRange(root, st, en, value);
    }

    bool getRange(int st, int en)
    {
        return getRange(root, st, en);
    }
    void getClear(int st, int en)
    {
        return getClear(root, st, en);
    }
};
