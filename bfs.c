#include<stdio.h>

typedef struct Node Node;

struct Node
{
    /* data */
    int value;
    Node * next[2];
    char visited;
};


void create_node(Node * node, int value,Node* next[2]){
    
    node->value=value;
    node->next[0]=next[0];
    node->next[1]=next[1];
    node->visited=0;
}
void bfs(Node *source){
    Node queue[10];
    int first=0;
    int end=1;
    queue[0]=*source;
    while (first<=end && end<10)
    {
        Node node = queue[first];
        node.visited=1;
        first+=1;
        for(int i=0;i<2;i++){
            if(node.next[i] && !node.next[i]->visited){
                queue[end]= *node.next[i];
                end +=1;
            }
        }
        printf("-> %d\n",node.value);
    }
    

}

int main(){
    Node node1;
    Node node2;
    Node node3;
    Node node4;
    Node node5;
    Node node6;
    node1.value=1;
    node2.value=2;
    node3.value=3;
    node4.value=4;
    node5.value=5;
    node6.value=6;

    node1.visited=0;
    node2.visited=0;
    node3.visited=0;
    node4.visited=0;
    node5.visited=0;
    node6.visited=0;

    // create_node(&node1,1,NULL);
    node1.next[0] = &node2;
    node1.next[1] = &node3;
    node3.next[0] = &node4;
    node2.next[0] = &node6;
    node3.next[1] = &node5;
    // printf("node 1 value %d\n",node1.value);
    // printf("node 2 value %d\n",node2.value);
    // printf("node 1 is adjecent to %d\n",(*node1.next[0]).value);
    bfs(&node1);
    

}