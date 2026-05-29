//
// Created by waylon on 5/28/26.
//

#ifndef DUMRARRIA_CAMERA_H
#define DUMRARRIA_CAMERA_H
#include "AppContext.h"
#include "globalDataStructs.h"

class Camera {
private:
    Position drawOffest{0,0};
    BoxSize boxSize{0.0f,0.0f};

public:
    void update(const AppContext &app);

    Position getDrawOffest()const;
};


#endif //DUMRARRIA_CAMERA_H
