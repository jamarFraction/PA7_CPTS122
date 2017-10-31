#include <iostream>
#include <stdio.h>


class StackNode{

private:

    template <class T>
    static T data;

    StackNode *nextNode;

    


public:

    //Defualt Constructor
    template <class T>
    StackNode(T passedData = NULL, T* passednextNode = nullptr);

    //Getter for the data
    template <class T>
    T GetData();

    //Setter for the data
    template <class T>
    void SetData(T passedData);

    //Getter for the next Node
    template <class T>
    T* GetNextNode();

    // //Setter for the next Node
    // template <class T>
    // void SetNextNode(T *&passedNode);

};