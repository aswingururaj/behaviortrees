#ifndef ABT_H_
#define ABT_H_

#include "behaviortree_cpp_v3/bt_factory.h"
#include "behaviortree_cpp_v3/behavior_tree.h"
using namespace BT;
namespace sample{

class ApproachObject : public BT::SyncActionNode
{
  public:
    ApproachObject(const std::string& name) :
        BT::SyncActionNode(name, {})
    {
    }
    BT::NodeStatus tick();
};
BT::NodeStatus CheckBattery();
class GripperInterface
{
public:
    GripperInterface(): _open(true) {}

    NodeStatus open();

    NodeStatus close();

private:
    bool _open; // shared information
};


}


#endif

