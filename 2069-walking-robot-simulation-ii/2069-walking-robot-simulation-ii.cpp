class Robot {
public:
    int w, h;
    int x, y;
    int dir; // 0=East, 1=North, 2=West, 3=South
    int cycle;

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0; // East
        cycle = 2 * (w + h - 2);
    }
    
    void step(int num) {
        if (cycle == 0) return; // safety (not really needed)

        num %= cycle;

        // Edge case
        if (num == 0) {
            if (x == 0 && y == 0) dir = 3; // South
            return;
        }

        while (num > 0) {
            if (dir == 0) { // East
                int move = min(num, w - 1 - x);
                x += move;
                num -= move;
                if (num > 0) dir = 1;
            } 
            else if (dir == 1) { // North
                int move = min(num, h - 1 - y);
                y += move;
                num -= move;
                if (num > 0) dir = 2;
            } 
            else if (dir == 2) { // West
                int move = min(num, x);
                x -= move;
                num -= move;
                if (num > 0) dir = 3;
            } 
            else { // South
                int move = min(num, y);
                y -= move;
                num -= move;
                if (num > 0) dir = 0;
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        vector<string> dirs = {"East", "North", "West", "South"};
        return dirs[dir];
    }
};