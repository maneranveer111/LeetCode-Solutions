class Robot {
private:
    vector<tuple<int, int, string>> path;
    int peri;
    int curr;
    bool moved;

public:
    Robot(int width, int height) {
        peri = 2 * (width - 1) + 2 * (height - 1);
        curr = 0;
        moved = false;

        for (int i = 0; i <= width - 1; i++)
            path.push_back({i, 0, "East"});

        for (int j = 1; j <= height - 1; j++)
            path.push_back({width - 1, j, "North"});

        for (int i = width - 2; i >= 0; i--)
            path.push_back({i, height - 1, "West"});

        for (int j = height - 2; j >= 1; j--)
            path.push_back({0, j, "South"});
    }

    void step(int num) {
        moved = true;
        curr = (curr + num) % peri;
    }

    vector<int> getPos() {
        return {get<0>(path[curr]), get<1>(path[curr])};
    }

    string getDir() {
        if (!moved) return "East";
        if (curr == 0) return "South";
        return get<2>(path[curr]);
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */