import rclpy
from rclpy.node import Node 
from interfaces.msg import Example

class PubNode(Node):

    def __init__(self):
        super().__init__('pub_node')
        self.publisher = self.create_publisher(Example, "ExampleTopic", 10)
        self.timer = self.create_timer(3.0, self.timer_callback)
        self.count = 0

    def timer_callback(self):
        self.count += 1
        example = Example()
        example.message = self.count
        self.publisher.publish(example)

def main():
    rclpy.init()
    node = PubNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()