#include "StackNode.h"


template <class T>
StackNode::StackNode(T passedData, T* passednextNode){

    //Set the defualt variables to the constructor default values
    data <T> = passedData;

    //will be nullptr
    nextNode = passednextNode;

}

template <class T>
T StackNode::GetData(){

    return data <T>;

}

template <class T>
void StackNode::SetNextNode(T *&passedNode){

    nextNode = passedNode;



}