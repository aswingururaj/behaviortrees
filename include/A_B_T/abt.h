#ifndef ABT_H_
#define ABT_H_

#include "behaviortree_cpp_v3/bt_factory.h"
#include "behaviortree_cpp_v3/behavior_tree.h"
using namespace BT;
namespace sample{
/*struct Position2D 
{ 
  double x;
  double y; 
};
namespace BT
{
    using namespace BT;
    template <> inline Position2D convertFromString(StringView str)
    {
        // The next line should be removed...
        printf("Converting string: \"%s\"\n", str.data() );

        // We expect real numbers separated by semicolons
        auto parts = splitString(str, ';');
        if (parts.size() != 2)
        {
            throw RuntimeError("invalid input)");
        }
        else{
            Position2D output;
            output.x     = convertFromString<double>(parts[0]);
            output.y     = convertFromString<double>(parts[1]);
            return output;
        }
    }
}*/
class ApproachObject : public SyncActionNode
{
  public:
    ApproachObject(const std::string& name) :
        BT::SyncActionNode(name, {})
    {
    }
    NodeStatus tick();
};
BT::NodeStatus CheckBattery();
class GripperInterface
{
public:
    GripperInterface(): _open(true) {}

    NodeStatus open();

    NodeStatus close();

private:
    bool _open;
};
class SaySomething : public SyncActionNode
{
  public:
    SaySomething(const std::string& name, const NodeConfiguration& config)
      : SyncActionNode(name, config)
    { }

    static PortsList providedPorts()
    {
        return { InputPort<std::string>("message") };
    }

    NodeStatus tick();
};
class ThinkWhatToSay : public SyncActionNode
{
  public:
    ThinkWhatToSay(const std::string& name, const NodeConfiguration& config)
      : SyncActionNode(name, config)
    {
    }

    static PortsList providedPorts()
    {
        return { OutputPort<std::string>("text") };
    }
    NodeStatus tick();
};
class MoveBase : public AsyncActionNode
{
  public:
    MoveBase(const std::string& name, const NodeConfiguration& config)
      : AsyncActionNode(name, config)
    { }

    static PortsList providedPorts()
    {
        return { InputPort<std::string>("message") };
    }

    NodeStatus tick();

    void halt();

  private:
    std::atomic_bool _halt_requested;
};
BT::NodeStatus SaySomethingSimple(BT::TreeNode& self);
inline void SleepMS(int ms);
/*
class CalculateGoal: public BT::SyncActionNode
{
public:
    CalculateGoal(const std::string& name, const NodeConfiguration& config):
        SyncActionNode(name,config)
    {}

    static PortsList providedPorts()
    {
        return { OutputPort<Position2D>("goal") };
    }
    BT::NodeStatus tick();
};


class PrintTarget: public BT::SyncActionNode
{
public:
    PrintTarget(const std::string& name, const NodeConfiguration& config):
        SyncActionNode(name,config)
    {}

    static PortsList providedPorts()
    {
        const char*  description = "Simply print the goal on console...";
        return { InputPort<Position2D>("target", description) };
    }

    BT::NodeStatus tick();
};
*/
}


#endif

