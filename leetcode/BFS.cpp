#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main(int argc, char* argv[]){
    //
}


void BFS(Node* node){
   set<Node*> visited;
   queue<Node*> myQueue;
   myQueue.enqueue(node);
   while(!myQueue.empty()){
       node = myQueue.dequeue();
       if (visited.find(node) == visited.end()){
           visit(node);
           visited.insert(node);
           for(Arc* arc : node->arcs){
               myQueue.enqueue(arc->end);
           }
       }
   }
}
