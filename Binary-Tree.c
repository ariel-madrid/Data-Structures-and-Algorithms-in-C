#include <stdio.h>
#include <stdlib.h>

typedef struct Leef
{
    int value;
    struct Leef* leftChild;
    struct Leef* rightChild;
}Leef;

typedef struct Tree
{
    Leef* root;
}Tree;

int insert(Leef* leef, int value)
{
    if(leef->leftChild==NULL && leef->rightChild==NULL)
    {
        
        if (leef->value < value)
        {
            Leef* newRightChild = (Leef*)malloc(sizeof(Leef));
            newRightChild->value = value;
            newRightChild->leftChild = NULL;
            newRightChild->rightChild = NULL;

            leef->rightChild = newRightChild;

            return 1;
            
        }else
        {
            Leef* newLeftChild = (Leef*)malloc(sizeof(Leef));
            newLeftChild->value = value;
            newLeftChild->leftChild = NULL;
            newLeftChild->rightChild = NULL;

            leef->leftChild = newLeftChild;

            return 1;
        }
    }else 
    {
        if (leef->leftChild != NULL && leef->rightChild!=NULL)
        {
            if (leef->value < value)
            {
                insert(leef->leftChild,value);
            }else 
            {
                insert(leef->rightChild,value);
            }
        }

        if (leef->value > value)
        {
            if (leef->leftChild != NULL)
            {
                insert(leef->leftChild,value);
            }else
            {
                Leef* newLeftChild = (Leef*)malloc(sizeof(Leef));
                newLeftChild->value = value;
                newLeftChild->leftChild = NULL;
                newLeftChild->rightChild = NULL;

                leef->leftChild = newLeftChild;

                return 1;
            }
        }else
        {
            if (leef->rightChild != NULL)
            {
                insert(leef->rightChild,value);
            }else
            {
                Leef* newRightChild = (Leef*)malloc(sizeof(Leef));
                newRightChild->value = value;
                newRightChild->leftChild = NULL;
                newRightChild->rightChild = NULL;

                leef->rightChild = newRightChild;

                return 1;
            }
        }
    }
}

int insertValue(Tree* tree, int value)
{
    if (tree->root == NULL)
    {
        Leef* root = (Leef*)malloc(sizeof(Leef));
        root->value = value;
        root->leftChild = NULL;
        root->rightChild = NULL;

        tree->root = root;
    }else 
    {
        //Where we will make the call to a function who in a recursive way insert the value in the correct position of the binary tree.
        return insert(tree->root,value);
    }
}

int main()
{
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;

    if (insertValue(tree,20))
    {
        printf("Value successfully added: %d.\n",tree->root->value);
    }

    if (insertValue(tree,30))
    {
        printf("Value successfully added: %d.\n",tree->root->rightChild->value);
    }

    if (insertValue(tree,10))
    {
        printf("Value successfully added: %d.\n",tree->root->leftChild->value);
    }

    if (insertValue(tree,5))
    {
        printf("Value successfully added: %d.\n",tree->root->leftChild->leftChild->value);
    }

    if (insertValue(tree,15))
    {
        printf("Value successfully added: %d.\n",tree->root->leftChild->rightChild->value);
    }



    return 0;
}