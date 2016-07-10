#include <stdlib.h>
#include "Moviment.hpp"
using namespace Moviments;
namespace Animations{
class Animation
{
public:
    Moviment *Frames;
    int num_frames;
    int frame;
    Animation(int frames)
    {
        num_frames = frames;
        frame = 0;
        Frames = new Moviment[num_frames];
    }
    Moviment* get_moviment()
    {
        return &(Frames[frame]);
    }
    void Next_Frame()
    {
        frame++;

        frame = frame%num_frames;
        return;

    }
    void Previous_Frame()
    {

        frame = (frame+num_frames-1)%num_frames;
        return;
    }

    Moviment* get_moviment(int posi)
    {
        if(posi>=0 && posi < num_frames)
            return &(Frames[posi]);
        return NULL;
    }


};
}
