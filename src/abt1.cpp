#include "A_B_T/abt.h"
namespace sample{
    
NodeStatus ApproachObject::tick()
    {
        std::cout << "ApproachObject: " << this->name() << std::endl;
        return NodeStatus::SUCCESS;
    }
NodeStatus CheckBattery()
{
    std::cout << "[ Battery: OK ]" << std::endl;
    return NodeStatus::SUCCESS;
}
NodeStatus GripperInterface::open() 
    {
        _open = true;
        std::cout << "GripperInterface::open" << std::endl;
        return NodeStatus::SUCCESS;
    }

NodeStatus GripperInterface::close() 
    {
        std::cout << "GripperInterface::close" << std::endl;
        _open = false;
        return NodeStatus::SUCCESS;
    }

}
