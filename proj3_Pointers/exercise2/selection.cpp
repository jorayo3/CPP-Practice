#include "CLLNode.h"
#include <iostream>
using namespace std;

int main()
{
    const int N = 8;
    const int K = 3;

    CLLNode* list = 0;
    for (int j = N; j > 0; j--)
    {
        CLLNode* newGuy = new CLLNode(j);
        // TODO: Your code here
        if (j == N) {
            list = newGuy;
        } else {
            list = list->insert(newGuy);
        }
    }
    list->print();

    while (!list->lengthIsOne())
    {
        for (int j = 0; j < K; j++)
        {
            list = list->next();
        }
        list = list->remove();
        // TODO: Your code here

    }
    cout << "Only one person remains: ";
    list->print();

    return 0;
}
