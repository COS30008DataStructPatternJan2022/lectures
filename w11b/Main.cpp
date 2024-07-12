/* COS30008, Lecture 11, 2022
  - Duc Minh Le: adapted from Main.h in lab 11 to support tree traversal operations
 */

#include <iostream>
#include <string>

using namespace std;

#include "BTree.h"
#include "visitors/PreOrderVisitor.h"
#include "visitors/PostOrderVisitor.h"
#include "visitors/InOrderVisitor.h"

void testBasicOperations() {
    cout << "Test basic semantics." << endl;
    
    using StringBTree = BTree<string>;

    StringBTree root( "Hello World!" );
    StringBTree nodeA( "A" );
    StringBTree nodeB( "B" );

    StringBTree nodeAL( "AL" );
    StringBTree nodeAR( "AR" );

    StringBTree nodeBR( "BR" );

    root.attachLeft( nodeA );
    root.attachRight( nodeB );
    const_cast<StringBTree&>(root.left()).attachLeft( nodeAL );
    const_cast<StringBTree&>(root.left()).attachRight( nodeAR );

    const_cast<StringBTree&>(root.right()).attachRight( nodeBR );

    cout << "Some nodes: " << endl;
    cout << "root:       " << *root << endl;
    cout << "root->L:    " << *root.left() << endl;
    cout << "root->R:    " << *root.right() << endl;
    cout << "root->L->L: " << *root.left().left() << endl;
    cout << "root->R->R: " << *root.right().right() << endl;

    // tree traversal
    cout << endl;
    // cout << "DFS:      < ";
    // root.searchDepthFirst(PreOrderVisitor<string>());
    // cout << ">" << endl;

    TreeVisitor<string> visitor;

    cout << "DFS(pre): < " << endl;
    root.searchDepthFirst(PreOrderVisitor<string>()); cout << endl;
    root.searchDfPre(visitor); cout << endl;
    cout << ">" << endl;

    cout << "DFS(post): < " << endl;
    root.searchDepthFirst(PostOrderVisitor<string>()); cout << endl;
    root.searchDfPost(visitor); cout << endl;
    cout << ">" << endl;

    cout << "DFS(in): < " << endl;
    root.searchDepthFirst(InOrderVisitor<string>()); cout << endl;    
    root.searchDfIn(visitor); cout << endl;
    cout << ">" << endl;

    cout << endl;
    cout << "BFS:< " << endl;
    root.searchBreadthFirst(visitor); cout << endl;
    root.searchBreadthFirst2(visitor); cout << endl;
    cout << ">" << endl;

    // clean up
    const_cast<StringBTree&>(root.right()).detachRight();
    const_cast<StringBTree&>(root.left()).detachLeft();
    const_cast<StringBTree&>(root.left()).detachRight();
    root.detachRight();
    root.detachLeft();

    cout << "All trees are going to be deleted now!" << endl;
}

int main()
{
    testBasicOperations();

    return 0;
}
