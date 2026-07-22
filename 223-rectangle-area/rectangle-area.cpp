class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int rec1 = 0, rec2 = 0;
        rec1 = (ax2 - ax1) * (ay2 - ay1);
        rec2 = (bx2 - bx1) * (by2 - by1);

        int interArea = 0;
        int overlapWidth = min(ax2, bx2) - max(ax1, bx1);
        int overlapHeight = min(ay2, by2) - max(ay1, by1);

        if(overlapWidth > 0 && overlapHeight > 0)
            interArea = overlapWidth * overlapHeight;
        
        return rec1 + rec2 - interArea;
    }
};

