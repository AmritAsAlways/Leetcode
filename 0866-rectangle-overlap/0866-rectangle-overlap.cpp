class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int rec1xmin=rec1[0],rec1xmax=rec1[2],rec2xmin=rec2[0],rec2xmax=rec2[2];
        int rec1ymin=rec1[1],rec1ymax=rec1[3],rec2ymin=rec2[1],rec2ymax=rec2[3];

        if(rec1xmin>=rec2xmax || rec2xmin>=rec1xmax || rec1ymin>=rec2ymax || rec2ymin>=rec1ymax) return false;

        return true;
    }
};