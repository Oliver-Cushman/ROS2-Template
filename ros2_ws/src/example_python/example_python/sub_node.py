import rclpy
from rclpy.node import Node 
from interfaces.msg import Example

class SubNode(Node):

    def __init__(self):
        super().__init__('pub_node')
        self.subsciber = self.create_subscription(Example, "ExampleTopic", self.subscriber_callback, 10)

    def subscriber_callback(self, message: Example):
        print(message)

def main():
    rclpy.init()
    node = SubNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()