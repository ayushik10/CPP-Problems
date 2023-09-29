/*  1114. PRINT IN ORDER

Suppose we have a class:

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}

The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

Note:
We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.

Example 1:
Input: nums = [1,2,3]
Output: "firstsecondthird"
Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.

Example 2:
Input: nums = [1,3,2]
Output: "firstsecondthird"
Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.
 

Constraints:
nums is a permutation of [1, 2, 3].
*/



class Foo {
    std::mutex m;
    std::condition_variable cv;
    int turn;
    
public:
    Foo() {
        turn = 0;
    }

    void first(function<void()> printFirst) {
        
        printFirst();
        turn = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        std::unique_lock<std::mutex> lock(m);

        while(turn != 1)
        cv.wait(lock);

        printSecond();
        turn = 2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        std::unique_lock<std::mutex> lock(m);

        while(turn != 2)
        cv.wait(lock);
      
        printThird();
    }
};
