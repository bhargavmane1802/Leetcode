
class Robot {
private:
    int w, h;
    int perimeter;
    int pos;
    bool moved;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        // Total steps to make a full loop around the edge
        perimeter = 2 * (w - 1) + 2 * (h - 1); 
        pos = 0;        // Current 1D position along the perimeter
        moved = false;  // Flag to track if the robot has ever moved
    }
    
    void step(int num) {
        pos = (pos + num) % perimeter;
        moved = true; // Once a step is called, the robot has moved
    }
    
    vector<int> getPos() {
        // Bottom Edge: Moving East
        if (pos <= w - 1) {
            return {pos, 0};
        } 
        // Right Edge: Moving North
        else if (pos <= w + h - 2) {
            return {w - 1, pos - (w - 1)};
        } 
        // Top Edge: Moving West
        else if (pos <= 2 * w + h - 3) {
            // Simplified from: (w - 1) - (pos - (w + h - 2))
            return {2 * w + h - 3 - pos, h - 1}; 
        } 
        // Left Edge: Moving South
        else {
            // Simplified from: (h - 1) - (pos - (2 * w + h - 3))
            return {0, perimeter - pos}; 
        }
    }
    
    string getDir() {
        // Special case for the origin:
        if (pos == 0) {
            return moved ? "South" : "East";
        }
        
        // Direction maps directly to the edge the robot is currently traversing
        if (pos <= w - 1) {
            return "East";
        } else if (pos <= w + h - 2) {
            return "North";
        } else if (pos <= 2 * w + h - 3) {
            return "West";
        } else {
            return "South";
        }
    }
};