/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
Node* solve(vector<vector<int>>&grid,int startrow,int endrow,int startcol,int endcol,int num){
    if(num==1){
        Node* head=new Node(grid[startrow][startcol],true);
        return head;
    }

    //the main concept in this problem is that if all the cells in the node range is same 
    //then donot divide it and return it directly with the cell value as val and left=true and now this is a left node now and if not then divide the whole range of the grid given to us into 4 different nodes 

    bool allsame=true;
    for(int i=startrow;i<endrow;i++){
        for(int j=startcol;j<endcol;j++){
            if(grid[i][j]!=grid[startrow][startcol]){
                allsame=false;
                break;
            }
        }
    }

    if(allsame){
        Node* head=new Node(grid[startrow][startcol],true);
        return head;
    }

    Node* head=new Node();

    head->isLeaf=false;
    head->topLeft=solve(grid,startrow,startrow+num/2,startcol,startcol+num/2,num/2);
    head->bottomLeft=solve(grid,startrow+num/2,endrow,startcol,startcol+num/2,num/2);
    head->topRight=solve(grid,startrow,startrow+num/2,startcol+num/2,endcol,num/2);
    head->bottomRight=solve(grid,startrow+num/2,endrow,startcol+num/2,endcol,num/2);

    head->val=head->topLeft->val;

    return head;
}
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return solve(grid,0,n,0,n,n);
    }
};