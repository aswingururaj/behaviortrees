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
NodeStatus SaySomething::tick()
    {
        Optional<std::string> msg = getInput<std::string>("message");
        if (!msg)
        {
            throw BT::RuntimeError("missing required input [message]: ", 
                                   msg.error() );
        }
        std::cout << "Robot says: " << msg.value() << std::endl;
        return NodeStatus::SUCCESS;
    }
NodeStatus ThinkWhatToSay::tick()
    {
        setOutput("text", "The answer is 42" );
        return NodeStatus::SUCCESS;
    }
BT::NodeStatus SaySomethingSimple(BT::TreeNode &self)
{
    auto msg = self.getInput<std::string>("message");
    if (!msg)
    {
        throw BT::RuntimeError( "missing required input [message]: ", msg.error() );
    }

    std::cout << "Robot says: " << msg.value() << std::endl;
    return BT::NodeStatus::SUCCESS;
}
/*
NodeStatus CalculateGoal::tick()
    {
        Position2D mygoal = {1.1, 2.3};
        setOutput<Position2D>("goal", mygoal);
        return NodeStatus::SUCCESS;
    }
NodeStatus PrintTarget::tick()
    {
        auto res = getInput<Position2D>("target");
        if( !res )
        {
            throw RuntimeError("error reading port [target]:", res.error());
        }
        Position2D target = res.value();
        printf("Target positions: [ %.1f, %.1f ]\n", target.x, target.y );
        return NodeStatus::SUCCESS;
    }*/
}
