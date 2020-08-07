#include <ros/ros.h>
#include "A_B_T/abt.h"
static const char* xml_text = R"(

 <root main_tree_to_execute = "MainTree" >
     <BehaviorTree ID="MainTree">
     <ReactiveSequence>
            <BatteryOK/>
        <Sequence name="root">
            <SaySomething     message="start thinking..." />
            <MoveBase         message="running" />
            <SaySomething     message="Yayy" />
        </Sequence>
     </ReactiveSequence>   
     </BehaviorTree>
 </root>
 )";

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "abt");
  ros::NodeHandle nh;
  using namespace sample;
  BehaviorTreeFactory factory;
  /*
  factory.registerNodeType<ApproachObject>("ApproachObject");
  factory.registerSimpleCondition("CheckBattery", std::bind(CheckBattery));
  GripperInterface gripper;
  factory.registerSimpleAction("OpenGripper", std::bind(&GripperInterface::open, &gripper));
  factory.registerSimpleAction("CloseGripper", std::bind(&GripperInterface::close, &gripper));
  auto tree = factory.createTreeFromText(xml_text);
  tree.tickRoot();
  */ 
  factory.registerNodeType<MoveBase>("MoveBase");
    factory.registerNodeType<SaySomething>("SaySomething");
    factory.registerSimpleCondition("BatteryOK", std::bind(CheckBattery));

    auto tree = factory.createTreeFromText(xml_text);

    NodeStatus status;

    std::cout << "\n--- 1st executeTick() ---" << std::endl;
    status = tree.tickRoot();

    SleepMS(150);
    std::cout << "\n--- 2nd executeTick() ---" << std::endl;
    status = tree.tickRoot();

    SleepMS(150);
    std::cout << "\n--- 3rd executeTick() ---" << std::endl;
    status = tree.tickRoot();

    std::cout << std::endl;
  /* 
  factory.registerNodeType<CalculateGoal>("CalculateGoal");
  factory.registerNodeType<PrintTarget>("PrintTarget");
  auto tree = factory.createTreeFromText(xml_text);
  tree.tickRoot();*/
  ros::spin();
  return 0;
}

