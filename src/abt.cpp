#include <ros/ros.h>
#include "A_B_T/abt.h"
static const char* xml_text = R"(

 <root main_tree_to_execute = "MainTree" >
     <BehaviorTree ID="MainTree">
        <Sequence name="root">
            <SaySomething     message="start thinking..." />
            <ThinkWhatToSay   text="{the_answer}"/>
            <SetBlackboard   output_key="OtherGoal" value="BB buddy" />
            <SaySomething     message="{OtherGoal}" />
            <SaySomething     message="{the_answer}" />
            <SaySomething2    message="SaySomething2 works too..." />
            <SaySomething2    message="{the_answer}" />
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
  /*
  factory.registerNodeType<ApproachObject>("ApproachObject");
  factory.registerSimpleCondition("CheckBattery", std::bind(CheckBattery));
  GripperInterface gripper;
  factory.registerSimpleAction("OpenGripper", std::bind(&GripperInterface::open, &gripper));
  factory.registerSimpleAction("CloseGripper", std::bind(&GripperInterface::close, &gripper));
  auto tree = factory.createTreeFromText(xml_text);
  tree.tickRoot();
  */ 
  factory.registerNodeType<SaySomething>("SaySomething");
  factory.registerNodeType<ThinkWhatToSay>("ThinkWhatToSay");
  PortsList say_something_ports = { InputPort<std::string>("message") };
  factory.registerSimpleAction("SaySomething2", SaySomethingSimple, say_something_ports );
  auto tree = factory.createTreeFromText(xml_text);
  tree.tickRoot();
  /* 
  factory.registerNodeType<CalculateGoal>("CalculateGoal");
  factory.registerNodeType<PrintTarget>("PrintTarget");
  auto tree = factory.createTreeFromText(xml_text);
  tree.tickRoot();*/
  ros::spin();
  return 0;
}

