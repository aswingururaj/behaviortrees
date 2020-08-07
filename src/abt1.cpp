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
inline void SleepMS(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
NodeStatus MoveBase::tick()
    {
        Optional<std::string> msg = getInput<std::string>("message");
        if (!msg)
        {
            throw BT::RuntimeError("missing required input [message]: ", 
                                   msg.error() );
        }
        std::cout << "Robot says: " << msg.value() << std::endl;
        _halt_requested.store(false);
        int count = 0;
        while (!_halt_requested && count++ < 25)
        {
            SleepMS(10);
        }
        std::cout << "Robot Says: DONE" << std::endl;
        return _halt_requested ? NodeStatus::FAILURE : NodeStatus::SUCCESS;
    }
void MoveBase::halt()
{
    _halt_requested.store(true);
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
