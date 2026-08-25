class Robot {
public:
    int wid;
    int hei;
    int dir = 0;
    vector<string> direction = {"East", "North", "West", "South"};
    int x = 0, y = 0;
    int total = 0;

    Robot(int width, int height) {
        wid = width - 1, hei = height - 1;
        total = 2 * (width + height - 2);
    }
    
    void step(int k) {
        if (total == 0) return;

        k %= total;

        if (k == 0) {
            if (x == 0 && y == 0)
                dir = 3;
            return;
        }

        if (dir == 0) {
            if (x + k <= wid) {
                x = x + k;
                return;
            }
            else {
                int tmp = x;
                dir++;
                dir %= 4;
                x = wid;
                step(tmp + k - wid);
            }
        }
        else if (dir == 1) {
            if (y + k <= hei) {
                y = y + k;
                return;
            }
            else {
                int tmp = y;
                dir++;
                dir %= 4;
                y = hei;
                step(tmp + k - hei);
            }
        }
        else if (dir == 2) {
            if (x - k >= 0) {
                x -= k;
                return;
            }
            else {
                int tmp = x;
                dir++;
                dir %= 4;
                x = 0;
                step(k - tmp);
            }
        }
        else if (dir == 3) {
            if (y - k >= 0) {
                y -= k;
                return;
            }
            else {
                int tmp = y;
                dir++;
                dir %= 4;
                y = 0;
                step(k - tmp);
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return direction[dir];
    }
};