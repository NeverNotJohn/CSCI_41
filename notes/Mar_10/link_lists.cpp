#include <iostream>

using namespace std;

/*

    Linked lists vs Arrays

    arrays:
        length cannot be altered in runtime
        memory in consecutive memory locations

    Linked Lists:
        length CAN be alterred in runtime
        Elements can be kept in any locations but connected
        create objects
        references to link objects

*/

struct node 
{
    int data;
    node *next;                 // Self referential containing same type as itself
};

/*

    HEAD
        First node

    TAIL
        Rest of list after head OR last node in list

    "Head node and tail node contains NO meanignful data but makes sure
    each node has a previous node"

*/


int main() {

}