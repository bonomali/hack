#include <iostream>
#include <set>

using namespace std;

struct Node;
struct Arc;

struct Node{
    set<Arc*> arcs;
}

struct Arc{
    Node* start;
    Node* end;
}

static void dfs(Node* root){
    set<Node*> visited;
    visitDFS(root, visited);
}

static void visitDFS(Node* root, set<Node*>& visited){
   if (visited.find(root) != visited.end() ) return;
   visit(root);
   visited.insert(root);
   for (Arc* arc : root->arcs ){
       if (visited.find(arc->finish) != visited.end()){
           visitDFS(arc->finish, visited);
       }
   }
}

int main(int argc, char* args[]){
    Node* root = new Node;
    dfs(root);
}


