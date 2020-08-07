#include <ros/ros.h>
#include "A_B_T/abt.h"
static const char* xml_text = R"(

 <root main_tree_to_execute = "MainTree" >
     <BehaviorTree ID="MainTree">
        <Sequence name="root">
            <CheckBattery />
            <OpenGripper    name="open_gripper"/>
            <ApproachObject name="Fun boys XD"/>
            <CloseGripper   name="close_gripper"/>
        </Sequence>
     </BehaviorTree>
 </root>
 )";

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "abt");
  ros::NodeHandle nh;
  using namespace sample;
  BehaviorTreeFactory factory;
  factory.registerNodeType<ApproachObject>("ApproachObject");
  factory.registerSimpleCondition("CheckBattery", std::bind(CheckBattery));
  GripperInterface gripper;
  factory.registerSimpleAction("OpenGripper", std::bind(&GripperInterface::open, &gripper));
  factory.registerSimpleAction("CloseGripper", std::bind(&GripperInterface::close, &gripper));
  auto tree = factory.createTreeFromText(xml_text);
  tree.tickRoot();
  ros::spin();
  return 0;
}

